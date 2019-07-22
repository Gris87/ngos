#ifndef USB_BOOT_MAKER_SRC_OTHER_STATE_H
#define USB_BOOT_MAKER_SRC_OTHER_STATE_H



#include <Qt>



enum class State: quint8
{
    INITIAL            = 0,
    GET_LATEST_VERSION = 1,
    GET_FILE_LIST      = 2,
    DOWNLOAD           = 3,
    BURNING            = 4
};



inline const char* stateToString(State state) // TEST: NO
{
    switch (state)
    {
        case State::INITIAL:            return "INITIAL";
        case State::GET_LATEST_VERSION: return "GET_LATEST_VERSION";
        case State::GET_FILE_LIST:      return "GET_FILE_LIST";
        case State::DOWNLOAD:           return "DOWNLOAD";
        case State::BURNING:            return "BURNING";

        default: return "UNKNOWN";
    }
}



#endif // USB_BOOT_MAKER_SRC_OTHER_STATE_H
