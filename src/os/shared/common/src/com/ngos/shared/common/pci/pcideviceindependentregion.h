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
    bad_uint16                deviceId;
    PciCommandFlags    command;
    PciStatus          status;
    bad_uint8                 revisionId;
    bad_uint8                 classCode[3];
    bad_uint8                 cacheLineSize;
    bad_uint8                 latencyTimer;
    PciHeaderTypeUnion headerType;
    PciBuiltInSelfTest builtInSelfTest;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
