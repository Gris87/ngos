#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECONTROL_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressVirtualChannelVirtualChannelResourceControl
{
    union
    {
        struct
        {
            u32 tcVcMap:                  8;
            u32 __reserved:               8;
            u32 loadPortArbitrationTable: 1;
            u32 portArbitrationSelect:    3;
            u32 __reserved2:              4;
            u32 virtualChannelId:         3;
            u32 __reserved3:              4;
            u32 virtualChannelEnable:     1;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECONTROL_H
