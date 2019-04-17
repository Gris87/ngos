#ifndef USB_BOOT_MAKER_SRC_OTHER_STATE_H
#define USB_BOOT_MAKER_SRC_OTHER_STATE_H



#include <Qt>



enum class State: quint8
{
    INITIAL,
    GET_LATEST_VERSION,
    GET_FILE_LIST,
    DOWNLOAD,
    BURNING
};



#endif // USB_BOOT_MAKER_SRC_OTHER_STATE_H
