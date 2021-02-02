#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpresscompletiontimeout.h>



struct PciExpressDeviceControl2
{
    union
    {
        struct
        {
            bad_uint16 completionTimeoutValue         : 4; // TODO: Use enum PciExpressCompletionTimeout
            bad_uint16 completionTimeoutDisable       : 1;
            bad_uint16 ariForwardingEnable            : 1;
            bad_uint16 atomicOpRequesterEnable        : 1;
            bad_uint16 atomicOpEgressBlocking         : 1;
            bad_uint16 idoRequestEnable               : 1;
            bad_uint16 idoCompletionEnable            : 1;
            bad_uint16 ltrMechanismEnable             : 1;
            bad_uint16 emergencyPowerReductionRequest : 1;
            bad_uint16 tenBitTagRequesterEnable       : 1;
            bad_uint16 obff                           : 2;
            bad_uint16 endEndTlpPrefixBlocking        : 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL2_H
