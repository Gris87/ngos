#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACEBLOCKCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACEBLOCKCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcihypertransporterrorhandlingflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransporthostsecondaryinterfacecommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransporthostsecondaryinterfacefeatureflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkconfig.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkerrorandfrequencyunion.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkfrequencycapabilityflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportrevision.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciHyperTransportHostSecondaryInterfaceBlockCapability
{
    PciCapabilityHeader                                 header;
    PciHyperTransportHostSecondaryInterfaceCommand      command;
    PciHyperTransportLinkControl                        linkControl;
    PciHyperTransportLinkConfig                         linkConfig;
    PciHyperTransportRevision                           revisionId;
    PciHyperTransportLinkErrorAndFrequencyUnion         linkErrorAndFrequency;
    PciHyperTransportLinkFrequencyCapabilityFlags       linkFrequencyCapability;
    PciHyperTransportHostSecondaryInterfaceFeatureFlags feature;
    u16                                                 __reserved;
    u16                                                 enumerationScratchpad;
    PciHyperTransportErrorHandlingFlags                 errorHandling;
    u8                                                  memoryBaseUpper;
    u8                                                  memoryLimitUpper;
    u16                                                 __reserved2;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTHOSTSECONDARYINTERFACEBLOCKCAPABILITY_H
