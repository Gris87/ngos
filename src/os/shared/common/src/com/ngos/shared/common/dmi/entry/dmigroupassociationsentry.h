#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmigroupassociationsitem.h>



struct DmiGroupAssociationsEntry
{
    DmiEntryHeader           header;
    DmiStringId              groupName;
    DmiGroupAssociationsItem items[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIGROUPASSOCIATIONSENTRY_H
