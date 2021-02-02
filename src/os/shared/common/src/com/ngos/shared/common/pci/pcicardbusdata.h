#ifndef COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSDATA_H
#define COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSDATA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>



struct PciCardBusData
{
    PciVendor subsystemVendorID;
    bad_uint16       subsystemID;
    bad_uint32       legacyBase;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCICARDBUSDATA_H
