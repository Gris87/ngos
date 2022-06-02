#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmigroupassociationsitem.h>



struct DmiGroupAssociationsEntry
{
    DmiEntryHeader           header;
    DmiStringId              groupName;
    DmiGroupAssociationsItem items[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
