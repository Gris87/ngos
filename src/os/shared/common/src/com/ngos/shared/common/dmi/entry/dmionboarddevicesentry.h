#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICESENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICESENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesdevice.h>



struct DmiOnboardDevicesEntry
{
    DmiEntryHeader          header;
    DmiOnboardDevicesDevice devices[0];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICESENTRY_H
