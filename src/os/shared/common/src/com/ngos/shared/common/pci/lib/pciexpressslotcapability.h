#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCAPABILITY_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressSlotCapability
{
    union
    {
        struct
        {
            u32 attentionButtonPresent            : 1;
            u32 powerControllerPresent            : 1;
            u32 mrlSensorPresent                  : 1;
            u32 attentionIndicatorPresent         : 1;
            u32 powerIndicatorPresent             : 1;
            u32 hotPlugSurprise                   : 1;
            u32 hotPlugCapable                    : 1;
            u32 slotPowerLimitValue               : 8;
            u32 slotPowerLimitScale               : 2; // TODO: Use enum PciExpressSlotPowerLimitScale
            u32 electromechanicalInterlockPresent : 1;
            u32 noCommandCompletedSupport         : 1;
            u32 physicalSlotNumber                : 13;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCAPABILITY_H
