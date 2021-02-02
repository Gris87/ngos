#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEHEADERTYPEREGION_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEHEADERTYPEREGION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>



struct PciDeviceHeaderTypeRegion
{
    bad_uint32       baseAddressRegisters[6];
    bad_uint32       cardInformationStructurePointer;
    PciVendor subsystemVendorID;
    bad_uint16       subsystemID;
    bad_uint32       expansionRomBaseAddress;
    bad_uint8        capabilitiesPointer;
    bad_uint8        __reserved[3];
    bad_uint32       __reserved2;
    bad_uint8        interruptLine;
    bad_uint8        interruptPin;
    bad_uint8        minGrant;
    bad_uint8        maxLatency;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEHEADERTYPEREGION_H
