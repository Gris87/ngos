#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressactivestatepowermanagementsupport.h>
#include <com/ngos/shared/common/pci/lib/pciexpressl0sexitlatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpressl1exitlatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkspeed.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkwidth.h>



struct PciExpressLinkCapability
{
    union
    {
        struct
        {
            u32 supportedLinkSpeeds                     : 4; // TODO: Use enum PciExpressLinkSpeed
            u32 maximumLinkWidth                        : 6; // TODO: Use enum PciExpressLinkWidth
            u32 aspmSupport                             : 2; // TODO: Use enum PciExpressActiveStatePowerManagementSupport
            u32 l0sExitLatency                          : 3; // TODO: Use enum PciExpressL0sExitLatency
            u32 l1ExitLatency                           : 3; // TODO: Use enum PciExpressL1ExitLatency
            u32 clockPowerManagement                    : 1;
            u32 surpriseDownErrorReportingCapable       : 1;
            u32 dataLinkLayerLinkActiveReportingCapable : 1;
            u32 linkBandwidthNotificationCapability     : 1;
            u32 aspmOptionalityCompliance               : 1;
            u32 __reserved                              : 1;
            u32 portNumber                              : 8;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCAPABILITY_H
