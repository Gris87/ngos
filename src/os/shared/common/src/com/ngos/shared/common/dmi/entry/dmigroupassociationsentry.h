#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmigroupassociationsitem.h>



struct DmiGroupAssociationsEntry
{
    DmiEntryHeader           header;
    DmiStringId              groupName;
    DmiGroupAssociationsItem items[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
