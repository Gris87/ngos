#ifndef UEFI_UEFIINPUTKEY_H
#define UEFI_UEFIINPUTKEY_H



#include <ngos/types.h>
#include <uefi/types.h>
#include <uefi/uefiinputkeyscancode.h>



#define KEY_TAB   0x0009
#define KEY_ENTER 0x000D



struct UefiInputKey
{
    UefiInputKeyScanCode scanCode;
    char16               unicodeChar;
};



#endif // UEFI_UEFIINPUTKEY_H
