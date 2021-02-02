#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelarbitrationselect.h>



struct PciExpressVirtualChannelPortVirtualChannelControl
{
    union
    {
        struct
        {
            bad_uint16 loadVirtualChannelArbitrationTable: 1;
            bad_uint16 virtualChannelArbitrationSelect:    3; // TODO: Use enum PciExpressVirtualChannelArbitrationSelect
            bad_uint16 __reserved:                         12;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNELPORTVIRTUALCHANNELCONTROL_H
