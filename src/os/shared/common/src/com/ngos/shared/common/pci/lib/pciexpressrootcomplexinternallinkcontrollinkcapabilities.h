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
            bad_uint32 supportedLinkSpeeds : 4; // TODO: Use enum PciExpressLinkSpeed
            bad_uint32 maximumLinkWidth    : 6; // TODO: Use enum PciExpressLinkWidth
            bad_uint32 aspmSupport         : 2; // TODO: Use enum PciExpressActiveStatePowerManagementSupport
            bad_uint32 l0sExitLatency      : 3; // TODO: Use enum PciExpressL0sExitLatency
            bad_uint32 l1ExitLatency       : 3; // TODO: Use enum PciExpressL1ExitLatency
            bad_uint32 __reserved          : 14;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCAPABILITIES_H
