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
            bad_uint16 attentionButtonPressedEnable      : 1;
            bad_uint16 powerFaultDetectedEnable          : 1;
            bad_uint16 mrlSensorChangedEnable            : 1;
            bad_uint16 presenceDetectChangedEnable       : 1;
            bad_uint16 commandCompletedInterruptEnable   : 1;
            bad_uint16 hotPlugInterruptEnable            : 1;
            bad_uint16 attentionIndicatorControl         : 2; // TODO: Use enum PciExpressIndicatorControl
            bad_uint16 powerIndicatorControl             : 2; // TODO: Use enum PciExpressIndicatorControl
            bad_uint16 powerControllerControl            : 1; // TODO: Use enum PciExpressPowerControllerControl
            bad_uint16 electromechanicalInterlockControl : 1;
            bad_uint16 dataLinkLayerStateChangedEnable   : 1;
            bad_uint16 __reserved                        : 3;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTCONTROL_H
