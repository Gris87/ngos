#ifndef UEFI_UEFISIMPLETEXTOUTPUTMODE_H
#define UEFI_UEFISIMPLETEXTOUTPUTMODE_H



#include <ngos/types.h>



struct UefiSimpleTextOutputMode
{
    i32  maxMode;
    i32  mode;
    i32  attribute;
    i32  cursorColumn;
    i32  cursorRow;
    bool cursorVisible;
};



#endif // UEFI_UEFISIMPLETEXTOUTPUTMODE_H
