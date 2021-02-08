#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressindicatorcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowercontrollercontrol.h>



struct PciExpressSlotControl
{
    union
    {
        struct
        {
            u16 attentionButtonPressedEnable      : 1;
            u16 powerFaultDetectedEnable          : 1;
            u16 mrlSensorChangedEnable            : 1;
            u16 presenceDetectChangedEnable       : 1;
            u16 commandCompletedInterruptEnable   : 1;
            u16 hotPlugInterruptEnable            : 1;
            u16 attentionIndicatorControl         : 2; // TODO: Use enum PciExpressIndicatorControl
            u16 powerIndicatorControl             : 2; // TODO: Use enum PciExpressIndicatorControl
            u16 powerControllerControl            : 1; // TODO: Use enum PciExpressPowerControllerControl
            u16 electromechanicalInterlockControl : 1;
            u16 dataLinkLayerStateChangedEnable   : 1;
            u16 __reserved                        : 3;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCONTROL_H
