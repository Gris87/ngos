#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIMEMORYDESCRIPTOR_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIMEMORYDESCRIPTOR_H



#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiMemoryDescriptor
{
    u32                  type;
    u32                  __pad;
    efi_physical_address physicalStart;
    efi_virtual_address  virtualStart;
    u64                  numberOfPages;
    u64                  attribute;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIMEMORYDESCRIPTOR_H
