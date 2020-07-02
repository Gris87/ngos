#ifndef UEFI_UEFIINPUTKEYSCANCODE_H
#define UEFI_UEFIINPUTKEYSCANCODE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiInputKeyScanCode: u16
{
    NONE      = 0,
    UP        = 0x0001,
    DOWN      = 0x0002,
    RIGHT     = 0x0003,
    LEFT      = 0x0004,
    HOME      = 0x0005,
    END       = 0x0006,
    INSERT    = 0x0007,
    DELETE    = 0x0008,
    PAGE_UP   = 0x0009,
    PAGE_DOWN = 0x000A,
    F1        = 0x000B,
    F2        = 0x000C,
    F3        = 0x000D,
    F4        = 0x000E,
    F5        = 0x000F,
    F6        = 0x0010,
    F7        = 0x0011,
    F8        = 0x0012,
    F9        = 0x0013,
    F10       = 0x0014,
    F11       = 0x0015,
    F12       = 0x0016,
    ESC       = 0x0017,
    BREAK     = 0x0048
};



inline const char8* enumToString(UefiInputKeyScanCode code) // TEST: NO
{
    switch (code)
    {
        case UefiInputKeyScanCode::NONE:      return "NONE";
        case UefiInputKeyScanCode::UP:        return "UP";
        case UefiInputKeyScanCode::DOWN:      return "DOWN";
        case UefiInputKeyScanCode::RIGHT:     return "RIGHT";
        case UefiInputKeyScanCode::LEFT:      return "LEFT";
        case UefiInputKeyScanCode::HOME:      return "HOME";
        case UefiInputKeyScanCode::END:       return "END";
        case UefiInputKeyScanCode::INSERT:    return "INSERT";
        case UefiInputKeyScanCode::DELETE:    return "DELETE";
        case UefiInputKeyScanCode::PAGE_UP:   return "PAGE_UP";
        case UefiInputKeyScanCode::PAGE_DOWN: return "PAGE_DOWN";
        case UefiInputKeyScanCode::F1:        return "F1";
        case UefiInputKeyScanCode::F2:        return "F2";
        case UefiInputKeyScanCode::F3:        return "F3";
        case UefiInputKeyScanCode::F4:        return "F4";
        case UefiInputKeyScanCode::F5:        return "F5";
        case UefiInputKeyScanCode::F6:        return "F6";
        case UefiInputKeyScanCode::F7:        return "F7";
        case UefiInputKeyScanCode::F8:        return "F8";
        case UefiInputKeyScanCode::F9:        return "F9";
        case UefiInputKeyScanCode::F10:       return "F10";
        case UefiInputKeyScanCode::F11:       return "F11";
        case UefiInputKeyScanCode::F12:       return "F12";
        case UefiInputKeyScanCode::ESC:       return "ESC";
        case UefiInputKeyScanCode::BREAK:     return "BREAK";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiInputKeyScanCode code) // TEST: NO
{
    static char8 res[19];

    sprintf(res, "0x%04X (%s)", code, enumToString(code));

    return res;
}



#endif



#endif // UEFI_UEFIINPUTKEYSCANCODE_H
