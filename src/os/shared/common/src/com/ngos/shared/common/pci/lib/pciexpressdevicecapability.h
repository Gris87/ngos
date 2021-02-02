#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressendpointl0sacceptablelatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpressendpointl1acceptablelatency.h>
#include <com/ngos/shared/common/pci/lib/pciexpressextendedtagfield.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspayloadsize.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerscale.h>



struct PciExpressDeviceCapability
{
    union
    {
        struct
        {
            bad_uint32 maximumPayloadSizeSupported  : 3; // TODO: Use enum PciExpressPayloadSize
            bad_uint32 phantomFunctionsSupported    : 2;
            bad_uint32 extendedTagFieldSupported    : 1; // TODO: Use enum PciExpressExtendedTagField
            bad_uint32 endpointL0sAcceptableLatency : 3; // TODO: Use enum PciExpressEndpointL0sAcceptableLatency
            bad_uint32 endpointL1AcceptableLatency  : 3; // TODO: Use enum PciExpressEndpointL1AcceptableLatency
            bad_uint32 undefined                    : 3;
            bad_uint32 roleBasedErrorReporting      : 1;
            bad_uint32 __reserved                   : 2;
            bad_uint32 capturedSlotPowerLimitValue  : 8;
            bad_uint32 capturedSlotPowerLimitScale  : 2; // TODO: Use enum PciExpressPowerScale
            bad_uint32 functionLevelResetCapability : 1;
            bad_uint32 __reserved2                  : 3;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY_H
