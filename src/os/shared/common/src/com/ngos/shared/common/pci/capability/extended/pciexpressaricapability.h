#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSARICAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSARICAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressaricapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressaricontrolregister.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressAriCapability
{
    PciExtendedCapabilityHeader     header;
    PciExpressAriCapabilityRegister capability;
    PciExpressAriControlRegister    control;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSARICAPABILITY_H
