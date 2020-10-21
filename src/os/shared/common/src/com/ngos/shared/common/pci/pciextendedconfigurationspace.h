#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCONFIGURATIONSPACE_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCONFIGURATIONSPACE_H



#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExtendedConfigurationSpace
{
    PciExtendedCapabilityHeader capability;
    u8                          data[3836];
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCONFIGURATIONSPACE_H
