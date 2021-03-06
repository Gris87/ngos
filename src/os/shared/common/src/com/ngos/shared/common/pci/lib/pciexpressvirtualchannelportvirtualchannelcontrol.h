#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelarbitrationselect.h>



struct PciExpressVirtualChannelPortVirtualChannelControl
{
    union
    {
        struct
        {
            u16 loadVirtualChannelArbitrationTable: 1;
            u16 virtualChannelArbitrationSelect:    3; // TODO: Use enum PciExpressVirtualChannelArbitrationSelect
            u16 __reserved:                         12;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCONTROL_H
