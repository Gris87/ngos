#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportarbitrationselect.h>



struct PciExpressVirtualChannelVirtualChannelResourceControl
{
    union
    {
        struct
        {
            bad_uint32 tcVcMap:                  8;
            bad_uint32 __reserved:               8;
            bad_uint32 loadPortArbitrationTable: 1;
            bad_uint32 portArbitrationSelect:    3; // TODO: Use enum PciExpressVirtualChannelPortArbitrationSelect
            bad_uint32 __reserved2:              4;
            bad_uint32 virtualChannelId:         3;
            bad_uint32 __reserved3:              4;
            bad_uint32 virtualChannelEnable:     1;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELVIRTUALCHANNELRESOURCECONTROL_H
