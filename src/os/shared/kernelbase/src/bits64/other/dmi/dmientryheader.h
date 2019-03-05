#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYHEADER_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYHEADER_H



#include <kernelbase/src/bits64/other/dmi/dmientrytype.h>
#include <ngos/types.h>



struct DmiEntryHeader
{
    DmiEntryType type;
    u8           length;
    u16          handle;
} __attribute__((packed));



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYHEADER_H
