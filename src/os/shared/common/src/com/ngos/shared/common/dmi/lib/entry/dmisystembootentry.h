#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMBOOTENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMBOOTENTRY_H



#include <com/ngos/shared/common/dmi/lib/dmientryheader.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmisystembootstatus.h>



struct DmiSystemBootEntry
{
    DmiEntryHeader      header;
    u8                  __reserved[6];
    DmiSystemBootStatus bootStatus;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMISYSTEMBOOTENTRY_H
