#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCAPABILITY_H



#include <com/ngos/shared/common/pci/lib/pciexpresspowerscale.h>



struct PciExpressSlotCapability
{
    union
    {
        struct
        {
            bad_uint32 attentionButtonPresent            : 1;
            bad_uint32 powerControllerPresent            : 1;
            bad_uint32 mrlSensorPresent                  : 1;
            bad_uint32 attentionIndicatorPresent         : 1;
            bad_uint32 powerIndicatorPresent             : 1;
            bad_uint32 hotPlugSurprise                   : 1;
            bad_uint32 hotPlugCapable                    : 1;
            bad_uint32 slotPowerLimitValue               : 8;
            bad_uint32 slotPowerLimitScale               : 2; // TODO: Use enum PciExpressPowerScale
            bad_uint32 electromechanicalInterlockPresent : 1;
            bad_uint32 noCommandCompletedSupport         : 1;
            bad_uint32 physicalSlotNumber                : 13;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCAPABILITY_H
