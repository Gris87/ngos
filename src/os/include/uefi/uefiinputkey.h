#ifndef UEFI_UEFIINPUTKEY_H
#define UEFI_UEFIINPUTKEY_H



#include <ngos/types.h>
#include <uefi/types.h>
#include <uefi/uefiinputkeyscancode.h>



#define KEY_TAB   u'\t'
#define KEY_ENTER u'\n'



struct UefiInputKey
{
    UefiInputKeyScanCode scanCode;
    char16               unicodeChar;
};



#endif // UEFI_UEFIINPUTKEY_H
