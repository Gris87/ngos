#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSADVANCEDERRORCAPABILITIESANDCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSADVANCEDERRORCAPABILITIESANDCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressAdvancedErrorCapabilitiesAndControl
{
    union
    {
        struct
        {
            bad_uint32 firstErrorPointer              : 5;
            bad_uint32 ecrcGenerationCapable          : 1;
            bad_uint32 ecrcGenerationEnable           : 1;
            bad_uint32 ecrcCheckCapable               : 1;
            bad_uint32 ecrcCheckEnable                : 1;
            bad_uint32 multipleHeaderRecordingCapable : 1;
            bad_uint32 multipleHeaderRecordingEnable  : 1;
            bad_uint32 tlpPrefixLogPresent            : 1;
            bad_uint32 __reserved                     : 20;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSADVANCEDERRORCAPABILITIESANDCONTROL_H
