#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITYANDCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITYANDCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddresscapabilityflags.h>
#include <com/ngos/shared/common/pci/lib/pciexpressresizablebaseaddresscontrol.h>



struct PciExpressResizableBaseAddressCapabilityAndControl
{
    PciExpressResizableBaseAddressCapabilityFlags capability;
    PciExpressResizableBaseAddressControl         control;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSRESIZABLEBASEADDRESSCAPABILITYANDCONTROL_H
