#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H



#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>



struct UefiMemoryDescriptor
{
    UefiMemoryType type;
    bad_uint32            __pad;
    bad_uint64            physicalStart;
    bad_uint64            virtualStart;
    bad_uint64            numberOfPages;
    bad_uint64            attribute;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H
