#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBUILTINSELFTEST_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBUILTINSELFTEST_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciBuiltInSelfTest
{
    union
    {
        struct
        {
            bad_uint8 completionCode: 4;
            bad_uint8 __reserved:     2;
            bad_uint8 startBist:      1;
            bad_uint8 capable:        1;
        };

        bad_uint8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIBUILTINSELFTEST_H
