#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationcapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationcontrolregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdynamicpowerallocationstatusregister.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressDynamicPowerAllocationCapability
{
    PciExtendedCapabilityHeader                        header;
    PciExpressDynamicPowerAllocationCapabilityRegister capability;
    bad_uint32                                                latencyIndicator;
    PciExpressDynamicPowerAllocationStatusRegister     status;
    PciExpressDynamicPowerAllocationControlRegister    control;
    bad_uint8                                                 substatePowerAllocation[0];
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSDYNAMICPOWERALLOCATIONCAPABILITY_H
