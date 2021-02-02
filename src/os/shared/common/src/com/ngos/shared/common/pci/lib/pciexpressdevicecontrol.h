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
            bad_uint16 correctableErrorReportingEnable                            : 1;
            bad_uint16 nonFatalErrorReportingEnable                               : 1;
            bad_uint16 fatalErrorReportingEnable                                  : 1;
            bad_uint16 unsupportedRequestReportingEnable                          : 1;
            bad_uint16 enableRelaxedOrdering                                      : 1;
            bad_uint16 maximumPayloadSize                                         : 3; // TODO: Use enum PciExpressPayloadSize
            bad_uint16 extendedTagFieldEnable                                     : 1; // TODO: Use enum PciExpressExtendedTagField
            bad_uint16 phantomFunctionsEnable                                     : 1;
            bad_uint16 auxPowerPmEnable                                           : 1;
            bad_uint16 enableNoSnoop                                              : 1;
            bad_uint16 maximumReadRequestSize                                     : 3; // TODO: Use enum PciExpressRequestSize
            bad_uint16 bridgeConfigurationRetryEnableOrInitiateFunctionLevelReset : 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICECONTROL_H
