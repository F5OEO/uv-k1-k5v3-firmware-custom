#!/usr/bin/env python3
# Copyright 2026 Evariste F5OEO
# https://github.com/F5OEO
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
#     Unless required by applicable law or agreed to in writing, software
#     distributed under the License is distributed on an "AS IS" BASIS,
#     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#     See the License for the specific language governing permissions and
#     limitations under the License.
"""Say a real FFVL weather beacon's wind on the air.

    ./beacon_ffvl.py 5111              # fetch, then transmit through the radio
    ./beacon_ffvl.py 5111 -n           # build the audio, do not transmit
    ./beacon_ffvl.py 5111 -a           # transmit through the Voice TX app
    ./beacon_ffvl.py 5111 --print      # just the figures, no voice at all
    ./beacon_ffvl.py --list            # the beacons reporting right now
    ./beacon_ffvl.py --list jarzay     # search all of them by name, id or dept

It reads the Federation Francaise de Vol Libre's beacon network, published as
open data (Licence Ouverte 2.0, Etalab) at

    https://www.data.gouv.fr/datasets/reseau-de-balises-meteo-de-la-ffvl-\
federation-francaise-de-vol-libre

as two files: balises.json, the 644 stations and where they are, refreshed
daily, and releves.json, one latest reading per station, refreshed every five
minutes.  A station that has stopped reporting simply drops out of releves.json,
so the file is the list of what is alive.  The figures handed to beacon_wind.sh
are vitesseVentMoy, directVentMoy and vitesseVentMax - km/h and degrees the
wind blows FROM, which is exactly what that script expects.

AGE.  data.gouv.fr serves a crawled copy, not the federation's live feed, so a
reading arrives older than its station sent it.  Measured over the 188 live
stations on 2026-11-12: 7 min at best, 12 min typically, 35 min at worst.  A
reading older than --max-age (an hour by default) is refused rather than
announced, because wind read out as current when it is two hours old is worse
than silence.  The age is always printed, so a cron log shows what went out.

Nothing is cached but balises.json, which changes daily; releves.json is
fetched every run.
"""
import argparse, datetime, json, os, re, subprocess, sys, time, unicodedata
import urllib.request

HERE = os.path.dirname(os.path.abspath(__file__))
# The stable data.gouv.fr resource permalinks; both 302 to a dated snapshot
# under static.data.gouv.fr.  Overridable so a key holder can point this at the
# federation's own live feed instead.
BALISES = os.environ.get("FFVL_BALISES",
    "https://www.data.gouv.fr/api/1/datasets/r/8d795154-9145-4ab2-99de-6768a36f31ea")
RELEVES = os.environ.get("FFVL_RELEVES",
    "https://www.data.gouv.fr/api/1/datasets/r/047b2ab9-627f-4e5f-9d68-5b948433c61d")
CACHE = os.environ.get("FFVL_CACHE",
    os.path.join(os.environ.get("TMPDIR", "/tmp"), "ffvl-cache"))
UA = "beacon_ffvl/1.0 (+https://github.com/F5OEO)"


def fetch(url, cache_name=None, max_age=0):
    """The JSON at url, from the cache if one is young enough."""
    path = os.path.join(CACHE, cache_name) if cache_name else None
    if path and max_age and os.path.exists(path) \
            and time.time() - os.path.getmtime(path) < max_age:
        return json.load(open(path, "rb"))
    req = urllib.request.Request(url, headers={"User-Agent": UA})
    raw = urllib.request.urlopen(req, timeout=30).read()
    doc = json.loads(raw)
    if path:
        os.makedirs(CACHE, exist_ok=True)
        tmp = path + ".new"
        open(tmp, "wb").write(raw)      # written whole, then moved: a cron run
        os.replace(tmp, path)           # never reads a half-written cache
    return doc


def stations():
    """idBalise -> station.  Cached for six hours; the file changes daily."""
    return {s["idBalise"]: s for s in
            fetch(BALISES, "balises.json", 6*3600)}


def readings():
    """idbalise -> latest reading.  Never cached."""
    return {r["idbalise"]: r for r in fetch(RELEVES)}


def say_name(nom):
    """A station name as it should be read aloud.

    The names are typed by 600 different clubs and show it.  Each rule below
    fixes something a text-to-speech voice gets wrong, and nothing else - no
    rule guesses at an expansion, so "Chatillon / Seine" stays two words and
    does not become "Chatillon-sur-Seine".
    """
    n = unicodedata.normalize("NFC", nom)
    n = n.replace(" ", " ").replace("’", "'")  # nbsp, curly apostrophe
    n = re.sub(r"[()\[\]]", " ", n)       # brackets: keep the words, drop the marks
    n = n.replace("/", " ")               # or the voice says "slash"
    n = re.sub(r"\s+-\s+", ", ", n)       # a dash between words is a pause
    n = re.sub(r"\s+", " ", n).strip(" ,-")
    if not any(c.islower() for c in n):   # ALL CAPS reads as an acronym
        n = n.title()
    return n


def age_of(reading):
    t = datetime.datetime.fromisoformat(reading["date"])
    return (datetime.datetime.now(t.tzinfo) - t).total_seconds()


def human_age(s):
    s = int(s)
    return f"{s} s" if s < 90 else f"{s//60} min" if s < 5400 else f"{s/3600:.1f} h"


def do_list(pattern):
    sta, rel = stations(), readings()
    if pattern:
        p = pattern.lower()
        sel = [s for s in sta.values() if p in s["nom"].lower()
               or p == str(s["idBalise"]) or p == (s.get("departement") or "").lower()]
        what = f"matching {pattern!r}"
    else:
        sel = [sta[i] for i in rel if i in sta]
        what = "reporting now"
    print(f"{len(sel)} beacons {what}"
          f"  ({len(rel)} of {len(sta)} are live)\n")
    print(f"{'id':>6}  {'dept':4} {'name':34} {'alt':>5}  wind (km/h)   age")
    for s in sorted(sel, key=lambda s: (s.get("departement") or "", s["nom"])):
        r = rel.get(s["idBalise"])
        if r and r.get("vitesseVentMoy") is not None:
            w = (f"{r['vitesseVentMoy']:3d}/{r['vitesseVentMax']:3d}"
                 f" {r['directVentMoy']:3d}deg")
            age = human_age(age_of(r))
        else:
            w, age = ("  -  (no wind)" if r else "  -  (silent)"), ""
        print(f"{s['idBalise']:6d}  {s.get('departement') or '--':4} "
              f"{s['nom'][:34]:34} {s['altitude']:5d}  {w:13} {age:>7}"
              f"{'  [maintenance]' if s.get('en_maintenance') else ''}")
    return 0


def main():
    ap = argparse.ArgumentParser(
        description=__doc__.splitlines()[0],
        epilog="The figures are the federation's; what the radio says is yours "
               "to stand behind.")
    ap.add_argument("id", nargs="?", type=int, help="idBalise of the station")
    ap.add_argument("-n", action="store_true",
                    help="build the audio, do not transmit")
    ap.add_argument("-a", action="store_true",
                    help="transmit through the Voice TX app, not the firmware")
    ap.add_argument("--print", dest="only_print", action="store_true",
                    help="print the reading and stop")
    ap.add_argument("--list", nargs="?", const="", metavar="PATTERN",
                    help="list live beacons, or search all by name/id/dept")
    ap.add_argument("--max-age", type=float, default=3600.0, metavar="S",
                    help="refuse a reading older than this (0 disables)")
    ap.add_argument("--site", help="override the name the voice says")
    a = ap.parse_args()

    if a.list is not None:
        return do_list(a.list)
    if a.id is None:
        ap.error("give a beacon id, or --list to find one")

    sta, rel = stations(), readings()
    s = sta.get(a.id)
    if s is None:
        print(f"no beacon {a.id} in the network ({len(sta)} known) - "
              f"try --list", file=sys.stderr)
        return 2
    r = rel.get(a.id)
    if r is None:
        print(f"beacon {a.id} ({s['nom']}) is not reporting: it is absent from "
              f"releves.json, where {len(rel)} stations are", file=sys.stderr)
        return 3

    age = age_of(r)
    site = a.site or say_name(s["nom"])
    print(f"  balise {a.id}: {s['nom']} ({s.get('departement') or '--'}, "
          f"{s['altitude']} m)" + (" [en maintenance]"
                                   if s.get("en_maintenance") else ""))
    print(f"  releve {r['date']}, il y a {human_age(age)}")
    mean, mx, direct = (r.get("vitesseVentMoy"), r.get("vitesseVentMax"),
                        r.get("directVentMoy"))
    print(f"  vent {mean}/{mx} km/h  {direct}deg"
          + (f"  {r['temperature']} C" if r.get("temperature") is not None else ""))
    if site != s["nom"]:
        print(f"  dit: {site!r}")

    if mean is None or mx is None or direct is None:
        print(f"beacon {a.id} sent a reading with no wind in it "
              f"(moy={mean} max={mx} dir={direct}) - nothing to announce",
              file=sys.stderr)
        return 3
    if a.max_age and age > a.max_age:
        print(f"the reading is {human_age(age)} old, over the "
              f"{human_age(a.max_age)} limit - not announcing stale wind "
              f"(--max-age 0 to override)", file=sys.stderr)
        return 4
    if a.only_print:
        return 0

    cmd = [os.path.join(HERE, "beacon_wind.sh"),
           str(int(round(mean))), str(int(round(direct))), str(int(round(mx)))]
    if a.n:
        cmd.append("-n")
    elif a.a:
        cmd.append("-a")
    env = dict(os.environ, SITE=site)
    # Flushed first, or a cron log shows the announcement before the reading it
    # came from: stdout is block-buffered the moment it is a pipe, so our own
    # lines would sit in the buffer until exit while the child writes straight
    # to the file.
    sys.stdout.flush()
    return subprocess.call(cmd, env=env)


if __name__ == "__main__":
    sys.exit(main())
