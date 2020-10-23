#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressextendedtagfield.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspayloadsize.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrequestsize.h>



struct PciExpressDeviceControl
{
    union
    {
        struct
        {
            u16 correctableErrorReportingEnable                            : 1;
            u16 nonFatalErrorReportingEnable                               : 1;
            u16 fatalErrorReportingEnable                                  : 1;
            u16 unsupportedRequestReportingEnable                          : 1;
            u16 enableRelaxedOrdering                                      : 1;
            u16 maximumPayloadSize                                         : 3; // TODO: Use enum PciExpressPayloadSize
            u16 extendedTagFieldEnable                                     : 1; // TODO: Use enum PciExpressExtendedTagField
            u16 phantomFunctionsEnable                                     : 1;
            u16 auxPowerPmEnable                                           : 1;
            u16 enableNoSnoop                                              : 1;
            u16 maximumReadRequestSize                                     : 3; // TODO: Use enum PciExpressRequestSize
            u16 bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset : 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL_H
