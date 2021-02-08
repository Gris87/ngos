#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/lib/pcibuiltinselftest.h>
#include <com/ngos/shared/common/pci/lib/pcicommandflags.h>
#include <com/ngos/shared/common/pci/lib/pciheadertypeunion.h>
#include <com/ngos/shared/common/pci/lib/pcistatus.h>



struct PciDeviceIndependentRegion
{
    PciVendor          vendorId;
    u16                deviceId;
    PciCommandFlags    command;
    PciStatus          status;
    u8                 revisionId;
    u8                 classCode[3];
    u8                 cacheLineSize;
    u8                 latencyTimer;
    PciHeaderTypeUnion headerType;
    PciBuiltInSelfTest builtInSelfTest;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
