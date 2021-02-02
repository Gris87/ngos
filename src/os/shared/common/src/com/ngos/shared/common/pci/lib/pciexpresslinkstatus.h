#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS_H



#include <com/ngos/shared/common/pci/lib/pciexpresslinkspeed.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkwidth.h>



struct PciExpressLinkStatus
{
    union
    {
        struct
        {
            bad_uint16 currentLinkSpeed              : 4; // TODO: Use enum PciExpressLinkSpeed
            bad_uint16 negotiatedLinkWidth           : 6; // TODO: Use enum PciExpressLinkWidth
            bad_uint16 undefined                     : 1;
            bad_uint16 linkTraining                  : 1;
            bad_uint16 slotClockConfiguration        : 1;
            bad_uint16 dataLinkLayerLinkActive       : 1;
            bad_uint16 linkBandwidthManagementStatus : 1;
            bad_uint16 linkAutonomousBandwidthStatus : 1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS_H
