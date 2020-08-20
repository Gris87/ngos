#ifndef COM_NGOS_SHARED_COMMON_PCI_PCICONFIGURATIONSPACE_H
#define COM_NGOS_SHARED_COMMON_PCI_PCICONFIGURATIONSPACE_H



#include <com/ngos/shared/common/pci/pcibridgecontrolregister.h>
#include <com/ngos/shared/common/pci/pcicardbuscontrolregister.h>
#include <com/ngos/shared/common/pci/pcideviceheadertyperegion.h>
#include <com/ngos/shared/common/pci/pcideviceindependentregion.h>



struct PciConfigurationSpace
{
    PciDeviceIndependentRegion header;

    union
    {
        PciDeviceHeaderTypeRegion device;
        PciBridgeControlRegister  bridge;
        PciCardBusControlRegister cardBus;
    };

    u8 data[190];
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCICONFIGURATIONSPACE_H
