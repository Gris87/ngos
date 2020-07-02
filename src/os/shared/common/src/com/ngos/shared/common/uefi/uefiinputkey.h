#ifndef UEFI_UEFIINPUTKEY_H
#define UEFI_UEFIINPUTKEY_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefiinputkeyscancode.h>



#define KEY_TAB   0x0009
#define KEY_ENTER 0x000D
#define KEY_SPACE 0x0020



struct UefiInputKey
{
    UefiInputKeyScanCode scanCode;
    char16               unicodeChar;
};



#endif // UEFI_UEFIINPUTKEY_H
