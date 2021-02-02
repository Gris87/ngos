#ifndef COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIVITALPRODUCTDATACAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIVITALPRODUCTDATACAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pcivitalproductdataaddressunion.h>
#include <com/ngos/shared/common/pci/pcicapabilityheader.h>



struct PciVitalProductDataCapability
{
    PciCapabilityHeader             header;
    PciVitalProductDataAddressUnion address;
    bad_uint32                             data;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_CAPABILITY_PCIVITALPRODUCTDATACAPABILITY_H
