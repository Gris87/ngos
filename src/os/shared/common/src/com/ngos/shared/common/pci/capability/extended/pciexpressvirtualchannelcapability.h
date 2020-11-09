#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSVIRTUALCHANNELCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSVIRTUALCHANNELCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannel.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelcapability1.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelcapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressvirtualchannelportvirtualchannelstatusflags.h>
#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressVirtualChannelCapability
{
    PciExtendedCapabilityHeader                           header;
    PciExpressVirtualChannelPortVirtualChannelCapability1 portVirtualChannelCapability1;
    PciExpressVirtualChannelPortVirtualChannelCapability2 portVirtualChannelCapability2;
    PciExpressVirtualChannelPortVirtualChannelControl     portVirtualChannelControl;
    PciExpressVirtualChannelPortVirtualChannelStatusFlags portVirtualChannelStatus;
    PciExpressVirtualChannel                              capability[0];
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSVIRTUALCHANNELCAPABILITY_H
