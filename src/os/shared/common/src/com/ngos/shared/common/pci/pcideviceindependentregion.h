#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/pciheadertype.h>



struct PciDeviceIndependentRegion
{
    u16 vendorId;
    u16 deviceId;
    u16 command;
    u16 status;
    u8  revisionId;
    u8  classCode[3];
    u8  cacheLineSize;
    u8  latencyTimer;

    union
    {
        struct
        {
            u8 headerType:      7; // TODO: Use enum PciHeaderType
            u8 isMultiFunction: 1;
        };

        u8 headerTypeAndIsMultiFunction;
    };

    u8  builtInSelfTest;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIDEVICEINDEPENDENTREGION_H
