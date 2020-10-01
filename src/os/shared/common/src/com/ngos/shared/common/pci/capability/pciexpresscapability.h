#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXPRESSCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXPRESSCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpresscapabilityregister.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicecontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdevicestatusflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcapability.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkstatus.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciExpressCapability
{
    PciCapabilityHeader          header;
    PciExpressCapabilityRegister capability;
    PciExpressDeviceCapability   deviceCapability;
    PciExpressDeviceControl      deviceControl;
    PciExpressDeviceStatusFlags  deviceStatus;
    PciExpressLinkCapability     linkCapability;
    PciExpressLinkControl        linkControl;
    PciExpressLinkStatus         linkStatus;

    //    PCI_REG_PCIE_SLOT_CAPABILITY    slotCapability;
    //    PCI_REG_PCIE_SLOT_CONTROL       slotControl;
    //    PCI_REG_PCIE_SLOT_STATUS        slotStatus;
    //    PCI_REG_PCIE_ROOT_CONTROL       rootControl;
    //    PCI_REG_PCIE_ROOT_CAPABILITY    rootCapability;
    //    PCI_REG_PCIE_ROOT_STATUS        rootStatus;
    //    PCI_REG_PCIE_DEVICE_CAPABILITY2 deviceCapability2;
    //    PCI_REG_PCIE_DEVICE_CONTROL2    deviceControl2;
    //    u16                             deviceStatus2;
    //    PCI_REG_PCIE_LINK_CAPABILITY2   linkCapability2;
    //    PCI_REG_PCIE_LINK_CONTROL2      linkControl2;
    //    PCI_REG_PCIE_LINK_STATUS2       linkStatus2;
    //    u32                             slotCapability2;
    //    u16                             slotControl2;
    //    u16                             slotStatus2;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIEXPRESSCAPABILITY_H
