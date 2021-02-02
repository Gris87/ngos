#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCISTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCISTATUS_H



#include <com/ngos/shared/common/pci/lib/pcideviceselecttiming.h>



struct PciStatus
{
    union
    {
        struct
        {
            bad_uint16 __reserved:            3;
            bad_uint16 interruptStatus:       1;
            bad_uint16 capabilitiesList:      1;
            bad_uint16 support64MHz:          1;
            bad_uint16 __reserved2:           1;
            bad_uint16 fastBackToBackCapable: 1;
            bad_uint16 masterDataParityError: 1;
            bad_uint16 deviceSelectTiming:    2; // TODO: Use enum PciDeviceSelectTiming
            bad_uint16 signaledTargetAbort:   1;
            bad_uint16 receivedTargetAbort:   1;
            bad_uint16 receivedMasterAbort:   1;
            bad_uint16 signaledSystemError:   1;
            bad_uint16 detectedParityError:   1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCISTATUS_H
