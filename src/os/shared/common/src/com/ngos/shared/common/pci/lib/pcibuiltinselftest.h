#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBUILTINSELFTEST_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBUILTINSELFTEST_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciBuiltInSelfTest
{
    union
    {
        struct
        {
            u8 completionCode: 4;
            u8 reserved:       2;
            u8 startBist:      1;
            u8 capable:        1;
        };

        u8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBUILTINSELFTEST_H
