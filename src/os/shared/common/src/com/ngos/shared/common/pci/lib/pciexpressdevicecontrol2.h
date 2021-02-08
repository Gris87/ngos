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
            u16 completionTimeoutValue         : 4; // TODO: Use enum PciExpressCompletionTimeout
            u16 completionTimeoutDisable       : 1;
            u16 ariForwardingEnable            : 1;
            u16 atomicOpRequesterEnable        : 1;
            u16 atomicOpEgressBlocking         : 1;
            u16 idoRequestEnable               : 1;
            u16 idoCompletionEnable            : 1;
            u16 ltrMechanismEnable             : 1;
            u16 emergencyPowerReductionRequest : 1;
            u16 tenBitTagRequesterEnable       : 1;
            u16 obff                           : 2;
            u16 endEndTlpPrefixBlocking        : 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL2_H
