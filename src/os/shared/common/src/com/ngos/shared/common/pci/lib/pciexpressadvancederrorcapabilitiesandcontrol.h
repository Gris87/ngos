#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSADVANCEDERRORCAPABILITIESANDCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSADVANCEDERRORCAPABILITIESANDCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressAdvancedErrorCapabilitiesAndControl
{
    union
    {
        struct
        {
            u32 firstErrorPointer              : 5;
            u32 ecrcGenerationCapable          : 1;
            u32 ecrcGenerationEnable           : 1;
            u32 ecrcCheckCapable               : 1;
            u32 ecrcCheckEnable                : 1;
            u32 multipleHeaderRecordingCapable : 1;
            u32 multipleHeaderRecordingEnable  : 1;
            u32 tlpPrefixLogPresent            : 1;
            u32 __reserved                     : 20;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSADVANCEDERRORCAPABILITIESANDCONTROL_H
