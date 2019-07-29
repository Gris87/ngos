#ifndef USB_BOOT_MAKER_SRC_OTHER_USBBOOTMAKERSTATE_H
#define USB_BOOT_MAKER_SRC_OTHER_USBBOOTMAKERSTATE_H



#include <Qt>
#include <ngos/types.h>



enum class UsbBootMakerState: quint8
{
    INITIAL            = 0,
    GET_LATEST_VERSION = 1,
    GET_FILE_LIST      = 2,
    DOWNLOAD           = 3,
    BURNING            = 4
};



inline const char8* usbBootMakerStateToString(UsbBootMakerState state) // TEST: NO
{
    switch (state)
    {
        case UsbBootMakerState::INITIAL:            return "INITIAL";
        case UsbBootMakerState::GET_LATEST_VERSION: return "GET_LATEST_VERSION";
        case UsbBootMakerState::GET_FILE_LIST:      return "GET_FILE_LIST";
        case UsbBootMakerState::DOWNLOAD:           return "DOWNLOAD";
        case UsbBootMakerState::BURNING:            return "BURNING";

        default: return "UNKNOWN";
    }
}



#endif // USB_BOOT_MAKER_SRC_OTHER_USBBOOTMAKERSTATE_H
