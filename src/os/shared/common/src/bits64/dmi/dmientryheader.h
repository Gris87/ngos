#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMIENTRYHEADER_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMIENTRYHEADER_H



#include <common/src/bits64/dmi/dmientrytype.h>
#include <ngos/types.h>



struct DmiEntryHeader
{
    DmiEntryType type;
    u8           length;
    u16          handle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMIENTRYHEADER_H
