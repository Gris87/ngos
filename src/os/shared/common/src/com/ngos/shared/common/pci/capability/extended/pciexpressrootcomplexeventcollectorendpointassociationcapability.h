#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXEVENTCOLLECTORENDPOINTASSOCIATIONCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXEVENTCOLLECTORENDPOINTASSOCIATIONCAPABILITY_H



#include <com/ngos/shared/common/pci/pciextendedcapabilityheader.h>



struct PciExpressRootComplexEventCollectorEndpointAssociationCapability
{
    PciExtendedCapabilityHeader header;
    bad_uint32                         associationBitmapForRootComplexIntegratedDevices;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_EXTENDED_PCIEXPRESSROOTCOMPLEXEVENTCOLLECTORENDPOINTASSOCIATIONCAPABILITY_H
