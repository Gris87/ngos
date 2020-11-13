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
            u16 currentLinkSpeed              : 4; // TODO: Use enum PciExpressLinkSpeed
            u16 negotiatedLinkWidth           : 6; // TODO: Use enum PciExpressLinkWidth
            u16 undefined                     : 1;
            u16 linkTraining                  : 1;
            u16 slotClockConfiguration        : 1;
            u16 dataLinkLayerLinkActive       : 1;
            u16 linkBandwidthManagementStatus : 1;
            u16 linkAutonomousBandwidthStatus : 1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKSTATUS_H
