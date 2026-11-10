
# Firmware pour les Quansheng UVK5v3 et UVK1 spécial FFVL

Attention, ce firmware ne marche pas sur les ancien model uvk5 : Soyez sur que c'est une version 3.

## Étapes pour flasher le firmware

- Connectez votre radio à votre ordinateur à l'aide d'un câble de programmation USB compatible (USB-C ou câble USB double jack de type Baofeng/Kenwood).
- Assurez-vous que votre radio est en **mode DFU (mode flash)** : quand vous l'allumez, appuyez sur PTT en meme temps. Dans ce mode, la lumière s'allume et l'écran n'affiche rien.
- Télécharger le fichier https://github.com/F5OEO/uv-k1-k5v3-firmware-custom/releases/download/latest/f5oeo.ffvl.bin
- Utilisez un navigateur de bureau compatible Web Serial, tel que Chrome, Brave, Edge, Opera ou Firefox 151+.
- Ouvrez la vue [Flash Firmware](https://armel.github.io/uvstudio/#flash) dans UV Studio.
- Selectionnez "Choisir fichier ou choose file" et pointez sur le fichier f5oeo.ffvl.bin que vous venez de télécharger
- Cliquez sur `Flash Firmware`, puis sélectionnez le port série associé à votre radio.
- La barre de progression vous guidera tout au long des étapes de flashage. La lumiere soit clignoter pendant l'étape de flashage.

Une fois terminé, votre radio redémarre avec le nouveau firmware.

# Crédits

Ce dépôt est un fork du [firmware personnalisé de F4HWN](https://github.com/armel/uv-k5-firmware-custom), qui était lui-même un fork du [firmware personnalisé d'Egzumer](https://github.com/egzumer/uv-k5-firmware-custom). Il étend le travail réalisé pour le UV-K5 V1 (basé sur le microcontrôleur DP32G030) et l'adapte aux nouveaux UV-K1 et UV-K5 V3 conçus autour du microcontrôleur PY32F071. C'est le résultat du travail conjoint de [@muzkr](https://github.com/muzkr) et [@armel](https://github.com/armel).

Many thanks to various people:

* [Muzkr](https://github.com/muzkr)
* [Mrkusypl](https://github.com/mrkusypl)
* [Andrej](https://github.com/Tunas1337)
* [Egzumer](https://github.com/egzumer)
* [OneOfEleven](https://github.com/OneOfEleven)
* [DualTachyon](https://github.com/DualTachyon)
* [Mikhail](https://github.com/fagci)
* [Manuel](https://github.com/manujedi)
* @wagner
* @Lohtse Shar
* [@Matoz](https://github.com/spm81)
* @Davide
* @Ismo OH2FTG
* [OneOfEleven](https://github.com/OneOfEleven)
* @d1ced95
* and others I forget

## License

Copyright 2023 Dual Tachyon
https://github.com/DualTachyon

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
