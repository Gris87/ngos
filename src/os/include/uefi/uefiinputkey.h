#ifndef UEFI_UEFIINPUTKEY_H
#define UEFI_UEFIINPUTKEY_H



#include <ngos/types.h>
#include <uefi/types.h>



struct UefiInputKey
{
    u16    scanCode;
    char16 unicodeChar;
};



#endif // UEFI_UEFIINPUTKEY_H
