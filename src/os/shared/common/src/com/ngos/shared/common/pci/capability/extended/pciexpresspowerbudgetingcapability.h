#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSPOWERBUDGETINGCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSPOWERBUDGETINGCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingcapabilityflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingdata.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressPowerBudgetingCapability
{
    PciExtendedCapabilityHeader             header;
    u8                                      dataSelect;
    u8                                      __reserved[3];
    PciExpressPowerBudgetingData            data;
    PciExpressPowerBudgetingCapabilityFlags powerBudgetCapability;
    u8                                      __reserved2[3];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSPOWERBUDGETINGCAPABILITY_H
