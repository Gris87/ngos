#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTBRIDGESUPPORTEXTENSIONS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTBRIDGESUPPORTEXTENSIONS_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciPowerManagementBridgeSupportExtensions
{
    union
    {
        struct
        {
            bad_uint8 __reserved:           6;
            bad_uint8 b2B3ForD3Hot:         1;
            bad_uint8 busPowerClockControl: 1;
        };

        bad_uint8 value8;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTBRIDGESUPPORTEXTENSIONS_H
