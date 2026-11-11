
add_library(CherryUSB INTERFACE)
target_include_directories(CherryUSB INTERFACE 
    core 
    port 
    common
    class/cdc
)
target_sources(CherryUSB INTERFACE
    core/usbd_core.c
    port/usb_dc_py32.c
    class/cdc/usbd_cdc.c
)
# The audio class ships with CherryUSB and compiles clean against this core;
# it is built only for the edition that asks for it (ENABLE_FEAT_F4HWN_USB_AUDIO).
if(ENABLE_FEAT_F4HWN_USB_AUDIO)
    target_include_directories(CherryUSB INTERFACE class/audio)
    target_sources(CherryUSB INTERFACE class/audio/usbd_audio.c)
endif()
target_link_libraries(CherryUSB INTERFACE CMSIS)
