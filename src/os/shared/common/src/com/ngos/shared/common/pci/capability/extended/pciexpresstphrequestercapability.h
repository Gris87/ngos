#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSTPHREQUESTERCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSTPHREQUESTERCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestercapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestercontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestersttableentry.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressTphRequesterCapability
{
    PciExtendedCapabilityHeader              header;
    PciExpressTphRequesterCapabilityRegister capability;
    PciExpressTphRequesterControlRegister    control;
    PciExpressTphRequesterStTableEntry       stTableEntries[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSTPHREQUESTERCAPABILITY_H
