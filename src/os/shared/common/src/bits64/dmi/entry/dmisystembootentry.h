#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMBOOTENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMBOOTENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmisystembootstatus.h>



struct DmiSystemBootEntry
{
    DmiEntryHeader      header;
    u8                  __reserved[6];
    DmiSystemBootStatus bootStatus;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMISYSTEMBOOTENTRY_H
