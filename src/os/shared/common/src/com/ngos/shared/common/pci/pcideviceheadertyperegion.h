#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEHEADERTYPEREGION_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEHEADERTYPEREGION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>



struct PciDeviceHeaderTypeRegion
{
    u32       baseAddressRegisters[6];
    u32       cardInformationStructurePointer;
    PciVendor subsystemVendorID;
    u16       subsystemID;
    u32       expansionRomBaseAddress;
    u8        capabilitiesPointer;
    u8        reserved[3];
    u32       reserved2;
    u8        interruptLine;
    u8        interruptPin;
    u8        minGrant;
    u8        maxLatency;
};



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEHEADERTYPEREGION_H
