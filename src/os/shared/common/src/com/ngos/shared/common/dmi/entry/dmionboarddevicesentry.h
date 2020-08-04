#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevice.h>



struct DmiOnboardDevicesEntry
{
    DmiEntryHeader          header;
    DmiOnboardDevicesDevice devices[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESENTRY_H
