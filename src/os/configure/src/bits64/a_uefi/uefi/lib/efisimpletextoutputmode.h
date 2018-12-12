#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLETEXTOUTPUTMODE_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLETEXTOUTPUTMODE_H



#include <ngos/types.h>



struct EfiSimpleTextOutputMode
{
    i32  maxMode;
    i32  mode;
    i32  attribute;
    i32  cursorColumn;
    i32  cursorRow;
    bool cursorVisible;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFISIMPLETEXTOUTPUTMODE_H
