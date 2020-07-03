#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTMODE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTMODE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiSimpleTextOutputMode
{
    i32  maxMode;
    i32  mode;
    i32  attribute;
    i32  cursorColumn;
    i32  cursorRow;
    bool cursorVisible;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTMODE_H
