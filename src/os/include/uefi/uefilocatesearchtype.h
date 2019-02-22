#ifndef UEFI_UEFILOCATESEARCHTYPE_H
#define UEFI_UEFILOCATESEARCHTYPE_H



#include <ngos/types.h>



enum class UefiLocateSearchType: u32
{
    ALL_HANDLES,
    BY_REGISTER_NOTIFY,
    BY_PROTOCOL
};



#endif // UEFI_UEFILOCATESEARCHTYPE_H
