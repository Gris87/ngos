#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIINPUTKEY_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIINPUTKEY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefiinputkeyscancode.h>



#define KEY_TAB   0x0009
#define KEY_ENTER 0x000D
#define KEY_SPACE 0x0020



struct UefiInputKey
{
    UefiInputKeyScanCode scanCode;
    char16               unicodeChar;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIINPUTKEY_H
