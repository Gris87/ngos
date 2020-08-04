#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesextendeddevicetype.h>



struct DmiOnboardDevicesExtendedEntry
{
    DmiEntryHeader header;
    DmiStringId    referenceDesignation;

    union
    {
        struct
        {
            u8 deviceType: 7; // TODO: Use enum DmiOnboardDevicesExtendedDeviceType
            u8 enabled:    1;
        };

        u8 deviceTypeAndEnabled;
    };

    u8  deviceTypeInstance;
    u16 segmentGroupNumber;
    u8  busNumber;

    union
    {
        struct
        {
            u8 functionNumber: 3;
            u8 deviceNumber:   5;
        };

        u8 functionNumberAndDeviceNumber;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H
