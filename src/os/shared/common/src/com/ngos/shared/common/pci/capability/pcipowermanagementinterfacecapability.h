#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIPOWERMANAGEMENTINTERFACECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIPOWERMANAGEMENTINTERFACECAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcipowermanagementbridgesupportextensions.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementcapabilities.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementcontrolstatus.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciPowerManagementInterfaceCapability
{
    PciCapabilityHeader                       header;
    PciPowerManagementCapabilities            capabilities;
    PciPowerManagementControlStatus           controlStatus;
    PciPowerManagementBridgeSupportExtensions bridgeExtention;
    bad_uint8                                        data;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIPOWERMANAGEMENTINTERFACECAPABILITY_H
