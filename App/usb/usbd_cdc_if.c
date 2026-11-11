#include "usbd_core.h"
#include "usbd_cdc.h"
#ifdef ENABLE_FEAT_F4HWN_USB_AUDIO
#include "usb_audio.h"
#include "usbd_audio_if.h"
#endif

/*!< endpoint address */
#define CDC_IN_EP  0x81
#define CDC_OUT_EP 0x02
#define CDC_INT_EP 0x83

#define USBD_VID           0x36b7
#define USBD_PID           0xFFFF
#define USBD_MAX_POWER     100
#define USBD_LANGID_STRING 1033

#ifdef ENABLE_FEAT_F4HWN_USB_AUDIO
/* The radio as a USB microphone, NEXT TO the serial port: CDC keeps
 * interfaces 0 and 1, audio takes 2 and 3. Dropping CDC would take appload,
 * UV Studio, K5Viewer and every afbridge mode with it. */
#define AUDIO_IN_EP       0x84      /* CDC holds 0x81, 0x02 and 0x83 */
#define AUDIO_FREQ        8000u
#define AUDIO_IN_MPS      18u       /* 9 samples: the asynchronous ceiling */
#define AUDIO_AC_INTF     0x02
#define AUDIO_AS_INTF     0x03
#define AUDIO_IN_TERM     0x01
#define AUDIO_OUT_TERM    0x02
/* The AudioControl macro emits its own IAD, interface and header; the two
 * terminals and the AudioStreaming interface follow it. */
#define AUDIO_AC_TOTAL    (0x09 + AUDIO_SIZEOF_AC_INPUT_TERMINAL_DESC + \
                           AUDIO_SIZEOF_AC_OUTPUT_TERMINAL_DESC)
#define USB_AUDIO_SIZE    (AUDIO_AC_DESCRIPTOR_INIT_LEN(1) + \
                           AUDIO_SIZEOF_AC_INPUT_TERMINAL_DESC + \
                           AUDIO_SIZEOF_AC_OUTPUT_TERMINAL_DESC + \
                           AUDIO_AS_DESCRIPTOR_INIT_LEN(1))
#define USB_INTF_COUNT    0x04
#define USB_BCD_DEVICE    0x0101    /* Windows caches descriptors per VID/PID */
#else
#define USB_AUDIO_SIZE    0
#define USB_INTF_COUNT    0x02
#define USB_BCD_DEVICE    0x0100
#endif

/*!< config descriptor size */
#define USB_CONFIG_SIZE (9 + CDC_ACM_DESCRIPTOR_LEN + USB_AUDIO_SIZE)

uint8_t dma_in_ep_idx  = (CDC_IN_EP & 0x7f);
uint8_t dma_out_ep_idx = CDC_OUT_EP;

/*!< global descriptor */
static const uint8_t cdc_descriptor[] = {
    USB_DEVICE_DESCRIPTOR_INIT(USB_2_0, 0xEF, 0x02, 0x01, USBD_VID, USBD_PID, USB_BCD_DEVICE, 0x01),
    USB_CONFIG_DESCRIPTOR_INIT(USB_CONFIG_SIZE, USB_INTF_COUNT, 0x01, USB_CONFIG_BUS_POWERED, USBD_MAX_POWER),
    CDC_ACM_DESCRIPTOR_INIT(0x00, CDC_INT_EP, CDC_OUT_EP, CDC_IN_EP, 0x02),
#ifdef ENABLE_FEAT_F4HWN_USB_AUDIO
    /* AudioControl: one streaming interface in the collection, and the
     * minimal topology - microphone in, USB streaming out, no feature unit. */
    AUDIO_AC_DESCRIPTOR_INIT(AUDIO_AC_INTF, 0x02, AUDIO_AC_TOTAL, 0x00, AUDIO_AS_INTF),
    AUDIO_AC_INPUT_TERMINAL_DESCRIPTOR_INIT(AUDIO_IN_TERM, AUDIO_INTERM_MIC, 0x01, 0x0000),
    AUDIO_AC_OUTPUT_TERMINAL_DESCRIPTOR_INIT(AUDIO_OUT_TERM, AUDIO_TERMINAL_STREAMING, AUDIO_IN_TERM),
    AUDIO_AS_IN_ASYNC_DESCRIPTOR_INIT(AUDIO_AS_INTF, AUDIO_OUT_TERM, 0x01, AUDIO_IN_EP,
                                      AUDIO_IN_MPS, 0x01, AUDIO_SAMPLE_FREQ_3B(AUDIO_FREQ)),
#endif
    ///////////////////////////////////////
    /// string0 descriptor
    ///////////////////////////////////////
    USB_LANGID_INIT(USBD_LANGID_STRING),
    ///////////////////////////////////////
    /// string1 descriptor
    ///////////////////////////////////////
    0x0A,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    'P', 0x00,                  /* wcChar0 */
    'U', 0x00,                  /* wcChar1 */
    'Y', 0x00,                  /* wcChar2 */
    'A', 0x00,                  /* wcChar3 */
    ///////////////////////////////////////
    /// string2 descriptor
    ///////////////////////////////////////
    0x1C,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    'P', 0x00,                  /* wcChar0 */
    'U', 0x00,                  /* wcChar1 */
    'Y', 0x00,                  /* wcChar2 */
    'A', 0x00,                  /* wcChar3 */
    ' ', 0x00,                  /* wcChar4 */
    'C', 0x00,                  /* wcChar5 */
    'D', 0x00,                  /* wcChar6 */
    'C', 0x00,                  /* wcChar7 */
    ' ', 0x00,                  /* wcChar8 */
    'D', 0x00,                  /* wcChar9 */
    'E', 0x00,                  /* wcChar10 */
    'M', 0x00,                  /* wcChar11 */
    'O', 0x00,                  /* wcChar12 */
    ///////////////////////////////////////
    /// string3 descriptor
    ///////////////////////////////////////
    0x16,                       /* bLength */
    USB_DESCRIPTOR_TYPE_STRING, /* bDescriptorType */
    '2', 0x00,                  /* wcChar0 */
    '0', 0x00,                  /* wcChar1 */
    '2', 0x00,                  /* wcChar2 */
    '2', 0x00,                  /* wcChar3 */
    '1', 0x00,                  /* wcChar4 */
    '2', 0x00,                  /* wcChar5 */
    '3', 0x00,                  /* wcChar6 */
    '4', 0x00,                  /* wcChar7 */
    '5', 0x00,                  /* wcChar8 */
    '6', 0x00,                  /* wcChar9 */
#ifdef CONFIG_USB_HS
    ///////////////////////////////////////
    /// device qualifier descriptor
    ///////////////////////////////////////
    0x0a,
    USB_DESCRIPTOR_TYPE_DEVICE_QUALIFIER,
    0x00,
    0x02,
    0x00,
    0x00,
    0x00,
    0x40,
    0x01,
    0x00,
#endif
    0x00
};

USB_MEM_ALIGNX uint8_t read_buffer[128];
// USB_MEM_ALIGNX uint8_t write_buffer[4];

static cdc_acm_rx_buf_t client_rx_buf = {0};

#ifdef ENABLE_FEAT_F4HWN_OVERLAY_APPS
/* Bytes received since boot (overlay apps detect a lapped ring with it) and
 * host configurations since boot (each enumeration counts one). */
volatile uint32_t cdc_acm_rx_total = 0;
volatile uint8_t  cdc_acm_config_count = 0;
#endif

volatile bool ep_tx_busy_flag = false;

#ifdef CONFIG_USB_HS
#define CDC_MAX_MPS 512
#else
#define CDC_MAX_MPS 64
#endif

void usbd_configure_done_callback(void)
{
#ifdef ENABLE_FEAT_F4HWN_OVERLAY_APPS
    cdc_acm_config_count++;
#endif
    /* setup first out ep read transfer */
    usbd_ep_start_read(CDC_OUT_EP, read_buffer, sizeof(read_buffer));
}

void usbd_cdc_acm_bulk_out(uint8_t ep, uint32_t nbytes)
{
    cdc_acm_rx_buf_t *rx_buf = &client_rx_buf;
    if (nbytes && rx_buf->buf)
    {
        const uint8_t *buf = read_buffer;
#ifdef ENABLE_FEAT_F4HWN_OVERLAY_APPS
        cdc_acm_rx_total += nbytes;
#endif
        uint32_t pointer = *rx_buf->write_pointer;
        while (nbytes)
        {
            const uint32_t rem = rx_buf->size - pointer;
            if (0 == rem)
            {
                pointer = 0;
                continue;
            }

            uint32_t size = rem < nbytes ? rem : nbytes;
            memcpy(rx_buf->buf + pointer, buf, size);
            buf += size;
            nbytes -= size;
            pointer += size;
        }

        *rx_buf->write_pointer = pointer;
    }

    /* setup next out ep read transfer */
    usbd_ep_start_read(CDC_OUT_EP, read_buffer, sizeof(read_buffer));
}

void usbd_cdc_acm_bulk_in(uint8_t ep, uint32_t nbytes)
{
    if ((nbytes % CDC_MAX_MPS) == 0 && nbytes) {
        /* send zlp */
        usbd_ep_start_write(CDC_IN_EP, NULL, 0);
    } else {
        ep_tx_busy_flag = false;
    }
}

/*!< endpoint call back */
struct usbd_endpoint cdc_out_ep = {
    .ep_addr = CDC_OUT_EP,
    .ep_cb = usbd_cdc_acm_bulk_out
};

struct usbd_endpoint cdc_in_ep = {
    .ep_addr = CDC_IN_EP,
    .ep_cb = usbd_cdc_acm_bulk_in
};

struct usbd_interface intf0;
struct usbd_interface intf1;

void cdc_acm_init(cdc_acm_rx_buf_t rx_buf)
{
    // client_rx_buf = rx_buf;
    memcpy(&client_rx_buf, &rx_buf, sizeof(cdc_acm_rx_buf_t));
    *client_rx_buf.write_pointer = 0;

    usbd_desc_register(cdc_descriptor);
    usbd_add_interface(usbd_cdc_acm_init_intf(&intf0));
    usbd_add_interface(usbd_cdc_acm_init_intf(&intf1));
    usbd_add_endpoint(&cdc_out_ep);
    usbd_add_endpoint(&cdc_in_ep);
#ifdef ENABLE_FEAT_F4HWN_USB_AUDIO
    /* After the CDC pair, so the interfaces number 0, 1 then 2, 3 as the
     * descriptor above declares them. */
    USBAUDIO_Init();
#endif
    usbd_initialize();
}

volatile uint8_t dtr_enable = 0;

void usbd_cdc_acm_set_dtr(uint8_t intf, bool dtr)
{
    if (dtr) {
        dtr_enable = 1;
    } else {
        dtr_enable = 0;
    }
}

void cdc_acm_data_send_with_dtr(const uint8_t *buf, uint32_t size)
{
    if (dtr_enable && 0 != size)
    {
        ep_tx_busy_flag = true;
        usbd_ep_start_write(CDC_IN_EP, buf, size);
        uint32_t timeout = 100000;
        while (ep_tx_busy_flag && --timeout)
            ;
        if (!timeout) {
            ep_tx_busy_flag = false;
            dtr_enable = 0;  // Consider USB disconnected
        }
    }
}

void cdc_acm_data_send_with_dtr_async(const uint8_t *buf, uint32_t size)
{
    if (0 != size)
    {
        usbd_ep_start_write(CDC_IN_EP, buf, size);
    }
}

#ifdef ENABLE_FEAT_F4HWN_OVERLAY_APPS
/* Overlay apps: start a send the caller waits for (ep_tx_busy_flag clears when
 * the host has taken it).  Whatever a timed-out send left in the FIFO is
 * cancelled first.  Unlike cdc_acm_data_send_with_dtr, a host that is slow to
 * read never clears dtr_enable: the caller gives up with cdc_acm_cancel_send. */
void cdc_acm_cancel_send(void)
{
    /* A few cycles: the endpoint index is shared with the ISR.  PRIMASK is
     * restored, not cleared: a caller that masked interrupts keeps them so. */
    const uint32_t primask = __get_PRIMASK();
    __disable_irq();
    usbd_ep_cancel_write(CDC_IN_EP);
    ep_tx_busy_flag = false;
    __set_PRIMASK(primask);
}

bool cdc_acm_start_send(const uint8_t *buf, uint32_t size)
{
    cdc_acm_cancel_send();
    ep_tx_busy_flag = true;
    if (usbd_ep_start_write(CDC_IN_EP, buf, size) == 0)
        return true;
    ep_tx_busy_flag = false;
    return false;
}
#endif
