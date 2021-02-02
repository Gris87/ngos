#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSDEVICESERIALNUMBERCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSDEVICESERIALNUMBERCAPABILITY_H



#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressDeviceSerialNumberCapability
{
    PciExtendedCapabilityHeader header;
    bad_uint64                         serialNumber;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSDEVICESERIALNUMBERCAPABILITY_H
