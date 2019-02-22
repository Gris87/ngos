#ifndef UEFI_UEFIRESETTYPE_H
#define UEFI_UEFIRESETTYPE_H



#include <ngos/types.h>



enum class UefiResetType: u32
{
    COLD,
    WARM,
    SHUTDOWN
};



#endif // UEFI_UEFIRESETTYPE_H
