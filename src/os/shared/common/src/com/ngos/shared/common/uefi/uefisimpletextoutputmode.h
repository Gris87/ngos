#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTMODE_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiSimpleTextOutputMode
{
    bad_int32  maxMode;
    bad_int32  mode;
    bad_int32  attribute;
    bad_int32  cursorColumn;
    bad_int32  cursorRow;
    bool cursorVisible;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFISIMPLETEXTOUTPUTMODE_H
