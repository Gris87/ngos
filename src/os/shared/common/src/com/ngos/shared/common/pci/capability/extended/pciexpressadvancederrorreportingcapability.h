#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSADVANCEDERRORREPORTINGCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSADVANCEDERRORREPORTINGCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressadvancederrorcapabilitiesandcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpresscorrectableerrorflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrooterrorcommandflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrooterrorstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpressuncorrectableerrorflags.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressAdvancedErrorReportingCapability
{
    PciExtendedCapabilityHeader                   header;
    PciExpressUncorrectableErrorFlags             uncorrectableErrorStatus;
    PciExpressUncorrectableErrorFlags             uncorrectableErrorMask;
    PciExpressUncorrectableErrorFlags             uncorrectableErrorSeverity;
    PciExpressCorrectableErrorFlags               correctableErrorStatus;
    PciExpressCorrectableErrorFlags               correctableErrorMask;
    PciExpressAdvancedErrorCapabilitiesAndControl advancedErrorCapabilitiesAndControl;
    bad_uint32                                           headerLog[4];
    PciExpressRootErrorCommandFlags               rootErrorCommand;
    PciExpressRootErrorStatus                     rootErrorStatus;
    bad_uint16                                           errorSourceIdentification;
    bad_uint16                                           correctableErrorSourceIdentification;
    bad_uint32                                           tlpPrefixLog[4];
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSADVANCEDERRORREPORTINGCAPABILITY_H
