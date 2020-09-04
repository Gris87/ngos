#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcihypertransportcommand.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciHyperTransportCapability
{
    PciCapabilityHeader      header;
    PciHyperTransportCommand command;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTCAPABILITY_H
