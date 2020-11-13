#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCAPABILITIES_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCAPABILITIES_H



#include <com/ngos/shared/common/pci/lib/pciexpressactivestatepowermanagementsupport.h>
#include <com/ngos/shared/common/pci/lib/pciexpressl0sexitlatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpressl1exitlatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkspeed.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkwidth.h>



struct PciExpressRootComplexInternalLinkControlLinkCapabilities
{
    union
    {
        struct
        {
            u32 supportedLinkSpeeds : 4; // TODO: Use enum PciExpressLinkSpeed
            u32 maximumLinkWidth    : 6; // TODO: Use enum PciExpressLinkWidth
            u32 aspmSupport         : 2; // TODO: Use enum PciExpressActiveStatePowerManagementSupport
            u32 l0sExitLatency      : 3; // TODO: Use enum PciExpressL0sExitLatency
            u32 l1ExitLatency       : 3; // TODO: Use enum PciExpressL1ExitLatency
            u32 __reserved          : 14;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCAPABILITIES_H
