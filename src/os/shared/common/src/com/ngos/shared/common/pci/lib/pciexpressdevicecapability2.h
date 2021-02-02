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
            bad_uint32 completionTimeoutRangesSupported              : 4; // TODO: Use flags PciExpressCompletionTimeoutRangeFlags
            bad_uint32 completionTimeoutDisableSupported             : 1;
            bad_uint32 ariForwardingSupported                        : 1;
            bad_uint32 atomicOpRoutingSupported                      : 1;
            bad_uint32 atomicOp32CompleterSupported                  : 1;
            bad_uint32 atomicOp64CompleterSupported                  : 1;
            bad_uint32 cas128CompleterSupported                      : 1;
            bad_uint32 noRoEnabledPrPrPassing                        : 1;
            bad_uint32 ltrMechanismSupported                         : 1;
            bad_uint32 tphCompleterSupported                         : 2; // TODO: Use flags PciExpressTphCompleterFlags
            bad_uint32 lnSystemCls                                   : 2;
            bad_uint32 tenBitTagCompleterSupported                   : 1;
            bad_uint32 tenBitTagRequesterSupported                   : 1;
            bad_uint32 obff                                          : 2;
            bad_uint32 extendedFmtFieldSupported                     : 1;
            bad_uint32 endEndTlpPrefixSupported                      : 1;
            bad_uint32 maxEndEndTlpPrefixes                          : 2;
            bad_uint32 emergencyPowerReductionSupported              : 2;
            bad_uint32 emergencyPowerReductionInitializationRequired : 1;
            bad_uint32 __reserved                                    : 4;
            bad_uint32 frsSupported                                  : 1;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECAPABILITY2_H
