#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXPRESSCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXPRESSCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpresscapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecontrol2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicestatus2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicestatusflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcontrol2.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkstatus2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcapabilityflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootcontrolflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpressrootstatus.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotcapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotcapability2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotcontrol2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotstatus2.h>
#include <com/ngos/shared/common/pci/lib/pciexpressslotstatusflags.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciExpressCapability
{
    PciCapabilityHeader           header;
    PciExpressCapabilityRegister  capability;
    PciExpressDeviceCapability    deviceCapability;
    PciExpressDeviceControl       deviceControl;
    PciExpressDeviceStatusFlags   deviceStatus;
    PciExpressLinkCapability      linkCapability;
    PciExpressLinkControl         linkControl;
    PciExpressLinkStatus          linkStatus;
    PciExpressSlotCapability      slotCapability;
    PciExpressSlotControl         slotControl;
    PciExpressSlotStatusFlags     slotStatus;
    PciExpressRootControlFlags    rootControl;
    PciExpressRootCapabilityFlags rootCapability;
    PciExpressRootStatus          rootStatus;
    PciExpressDeviceCapability2   deviceCapability2;
    PciExpressDeviceControl2      deviceControl2;
    PciExpressDeviceStatus2       deviceStatus2;
    PciExpressLinkCapability2     linkCapability2;
    PciExpressLinkControl2        linkControl2;
    PciExpressLinkStatus2         linkStatus2;
    PciExpressSlotCapability2     slotCapability2;
    PciExpressSlotControl2        slotControl2;
    PciExpressSlotStatus2         slotStatus2;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXPRESSCAPABILITY_H
