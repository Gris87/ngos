#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIVENDORCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIVENDORCAPABILITY_H



#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciVendorCapability
{
    PciCapabilityHeader header;
    u8                  length;
    u8                  __reserved;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIVENDORCAPABILITY_H
