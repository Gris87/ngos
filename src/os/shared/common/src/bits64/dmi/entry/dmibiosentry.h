#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



struct DmiBiosEntry
{
    DmiEntryHeader header;
    u8             vendor;
    u8             version;
    u16            startingAddressSegment;
    u8             releaseDate;
    u8             romSize;
    u64            characteristics;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIBIOSENTRY_H
