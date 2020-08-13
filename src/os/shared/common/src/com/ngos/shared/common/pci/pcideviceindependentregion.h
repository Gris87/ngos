#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/pcivendor.h>
#include <com/ngos/shared/common/pci/pciheadertype.h>



struct PciDeviceIndependentRegion
{
    PciVendor vendorId;
    u16       deviceId;
    u16       command; // TODO: Should be flags
    u16       status; // TODO: Should be flags
    u8        revisionId;
    u8        classCode[3];
    u8        cacheLineSize;
    u8        latencyTimer;

    union
    {
        struct
        {
            u8 headerType:      7; // TODO: Use enum PciHeaderType
            u8 isMultiFunction: 1;
        };

        u8 headerTypeAndIsMultiFunction;
    };

    u8  builtInSelfTest; // TODO: Should be union
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
