#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpresscompletiontimeoutrangeflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphcompleterflags.h>



struct PciExpressDeviceCapability2
{
    union
    {
        struct
        {
            u32 completionTimeoutRangesSupported              : 4; // TODO: Use flags PciExpressCompletionTimeoutRangeFlags
            u32 completionTimeoutDisableSupported             : 1;
            u32 ariForwardingSupported                        : 1;
            u32 atomicOpRoutingSupported                      : 1;
            u32 atomicOp32CompleterSupported                  : 1;
            u32 atomicOp64CompleterSupported                  : 1;
            u32 cas128CompleterSupported                      : 1;
            u32 noRoEnabledPrPrPassing                        : 1;
            u32 ltrMechanismSupported                         : 1;
            u32 tphCompleterSupported                         : 2; // TODO: Use flags PciExpressTphCompleterFlags
            u32 lnSystemCls                                   : 2;
            u32 tenBitTagCompleterSupported                   : 1;
            u32 tenBitTagRequesterSupported                   : 1;
            u32 obff                                          : 2;
            u32 extendedFmtFieldSupported                     : 1;
            u32 endEndTlpPrefixSupported                      : 1;
            u32 maxEndEndTlpPrefixes                          : 2;
            u32 emergencyPowerReductionSupported              : 2;
            u32 emergencyPowerReductionInitializationRequired : 1;
            u32 __reserved                                    : 4;
            u32 frsSupported                                  : 1;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY2_H
