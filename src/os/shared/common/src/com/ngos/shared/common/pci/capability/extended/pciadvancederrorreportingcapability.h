#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIADVANCEDERRORREPORTINGCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIADVANCEDERRORREPORTINGCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressuncorrectableerrorflags.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciAdvancedErrorReportingCapability
{
    PciExtendedCapabilityHeader       header;
    PciExpressUncorrectableErrorFlags uncorrectableErrorStatus;
    PciExpressUncorrectableErrorFlags uncorrectableErrorMask;
    PciExpressUncorrectableErrorFlags uncorrectableErrorSeverity;
    u32                               correctableErrorStatus;
    u32                               correctableErrorMask;
    u32                               advancedErrorCapabilitiesAndControl;
    u32                               headerLog[4];
    u32                               rootErrorCommand;
    u32                               rootErrorStatus;
    u16                               errorSourceIdentification;
    u16                               correctableErrorSourceIdentification;
    u32                               tlpPrefixLog[4];
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIADVANCEDERRORREPORTINGCAPABILITY_H
