#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICES_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICES_H



#include <common/src/bits64/dmi/dmientryheader.h>
#include <common/src/bits64/dmi/entry/lib/dmionboarddevicesdevice.h>



struct DmiOnboardDevicesEntry
{
    DmiEntryHeader          header;
    DmiOnboardDevicesDevice device[1];
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIONBOARDDEVICES_H
