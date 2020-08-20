#ifndef COM_NGOS_SHARED_COMMON_PCI_PCICAPABILITYHEADER_H
#define COM_NGOS_SHARED_COMMON_PCI_PCICAPABILITYHEADER_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcicapability.h>



struct PciCapabilityHeader
{
    PciCapability capabilityId;
    u8            nextCapabilityPointer;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCICAPABILITYHEADER_H
