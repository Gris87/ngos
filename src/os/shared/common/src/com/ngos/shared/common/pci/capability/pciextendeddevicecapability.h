#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXTENDEDDEVICECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXTENDEDDEVICECAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciextendeddevicecommand.h>
#include <com/ngos/shared/common/pci/lib/pciextendeddevicestatus.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciExtendedDeviceCapability
{
    PciCapabilityHeader      header;
    PciExtendedDeviceCommand command;
    PciExtendedDeviceStatus  status;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXTENDEDDEVICECAPABILITY_H
