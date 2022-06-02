#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmifunctionnumberanddevicenumber.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmionboarddevicesextendeddevicetypeandenabled.h>



struct DmiOnboardDevicesExtendedEntry
{
    DmiEntryHeader                                header;
    DmiStringId                                   referenceDesignation;
    DmiOnboardDevicesExtendedDeviceTypeAndEnabled deviceTypeAndEnabled;
    u8                                            deviceTypeInstance;
    u16                                           segmentGroupNumber;
    u8                                            busNumber;
    DmiFunctionNumberAndDeviceNumber              functionNumberAndDeviceNumber;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIONBOARDDEVICESEXTENDEDENTRY_H
