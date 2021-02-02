#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACEBLOCKCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACEBLOCKCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcihypertransporterrorhandlingflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkconfig.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkerrorandfrequencyunion.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportlinkfrequencycapabilityflags.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportrevision.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportslaveprimaryinterfacecommand.h>
#include <com/ngos/shared/common/pci/lib/pcihypertransportslaveprimaryinterfacefeatureflags.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciHyperTransportSlavePrimaryInterfaceBlockCapability
{
    PciCapabilityHeader                                header;
    PciHyperTransportSlavePrimaryInterfaceCommand      command;
    PciHyperTransportLinkControl                       linkControl0;
    PciHyperTransportLinkConfig                        linkConfig0;
    PciHyperTransportLinkControl                       linkControl1;
    PciHyperTransportLinkConfig                        linkConfig1;
    PciHyperTransportRevision                          revisionId;
    PciHyperTransportLinkErrorAndFrequencyUnion        linkErrorAndFrequency0;
    PciHyperTransportLinkFrequencyCapabilityFlags      linkFrequencyCapability0;
    PciHyperTransportSlavePrimaryInterfaceFeatureFlags feature;
    PciHyperTransportLinkErrorAndFrequencyUnion        linkErrorAndFrequency1;
    PciHyperTransportLinkFrequencyCapabilityFlags      linkFrequencyCapability1;
    bad_uint16                                                enumerationScratchpad;
    PciHyperTransportErrorHandlingFlags                errorHandling;
    bad_uint8                                                 memoryBaseUpper;
    bad_uint8                                                 memoryLimitUpper;
    bad_uint8                                                 busNumber;
    bad_uint8                                                 __reserved;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIHYPERTRANSPORTSLAVEPRIMARYINTERFACEBLOCKCAPABILITY_H
