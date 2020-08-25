#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIACCELERATEDGRAPHICSPORTCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIACCELERATEDGRAPHICSPORTCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportcommand.h>
#include <com/ngos/shared/common/pci/lib/pciacceleratedgraphicsportstatus.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciAcceleratedGraphicsPortCapability
{
    PciCapabilityHeader               header;
    u8                                revision;
    u8                                __reserved;
    PciAcceleratedGraphicsPortStatus  status;
    PciAcceleratedGraphicsPortCommand command;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIACCELERATEDGRAPHICSPORTCAPABILITY_H
