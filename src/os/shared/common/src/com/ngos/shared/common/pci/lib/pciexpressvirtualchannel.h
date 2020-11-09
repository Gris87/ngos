#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNEL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNEL_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcecapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcecontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelvirtualchannelresourcestatusflags.h>



struct PciExpressVirtualChannel
{
    PciExpressVirtualChannelVirtualChannelResourceCapability  virtualChannelResourceCapability;
    PciExpressVirtualChannelVirtualChannelResourceControl     virtualChannelResourceControl;
    u16                                                       __reserved;
    PciExpressVirtualChannelVirtualChannelResourceStatusFlags virtualChannelResourceStatus;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSVIRTUALCHANNEL_H
