#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmigroupassociationsgroup.h>



struct DmiGroupAssociationsEntry
{
    DmiEntryHeader            header;
    u8                        groupNameStringId;
    DmiGroupAssociationsGroup group[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
