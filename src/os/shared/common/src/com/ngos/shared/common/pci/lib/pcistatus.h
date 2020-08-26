#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCISTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCISTATUS_H



#include <com/ngos/shared/common/pci/lib/pcideviceselecttiming.h>



struct PciStatus
{
    union
    {
        struct
        {
            u16 __reserved:            3;
            u16 interruptStatus:       1;
            u16 capabilitiesList:      1;
            u16 support64MHz:          1;
            u16 __reserved1:           1;
            u16 fastBackToBackCapable: 1;
            u16 masterDataParityError: 1;
            u16 deviceSelectTiming:    2; // TODO: Use enum PciDeviceSelectTiming
            u16 signaledTargetAbort:   1;
            u16 receivedTargetAbort:   1;
            u16 receivedMasterAbort:   1;
            u16 signaledSystemError:   1;
            u16 detectedParityError:   1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCISTATUS_H
