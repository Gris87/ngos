#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressendpointl0sacceptablelatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpressendpointl1acceptablelatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpressextendedtagfield.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspayloadsize.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotpowerlimitscale.h>



struct PciExpressDeviceCapability
{
    union
    {
        struct
        {
            u32 maximumPayloadSizeSupported  : 3; // TODO: Use enum PciExpressPayloadSize
            u32 phantomFunctionsSupported    : 2;
            u32 extendedTagFieldSupported    : 1; // TODO: Use enum PciExpressExtendedTagField
            u32 endpointL0sAcceptableLatency : 3; // TODO: Use enum PciExpressEndpointL0sAcceptableLatency
            u32 endpointL1AcceptableLatency  : 3; // TODO: Use enum PciExpressEndpointL1AcceptableLatency
            u32 undefined                    : 3;
            u32 roleBasedErrorReporting      : 1;
            u32 __reserved                   : 2;
            u32 capturedSlotPowerLimitValue  : 8;
            u32 capturedSlotPowerLimitScale  : 2; // TODO: Use enum PciExpressSlotPowerLimitScale
            u32 functionLevelReset           : 1;
            u32 __reserved2                  : 3;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY_H
