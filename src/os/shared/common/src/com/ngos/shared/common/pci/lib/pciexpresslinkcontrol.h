#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressactivestatepowermanagementcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressreadcompletionboundary.h>



struct PciExpressLinkControl
{
    union
    {
        struct
        {
            u16 aspmControl                            : 2; // TODO: Use enum PciExpressActiveStatePowerManagementControl
            u16 __reserved                             : 1;
            u16 readCompletionBoundary                 : 1; // TODO: Use enum PciExpressReadCompletionBoundary
            u16 linkDisable                            : 1;
            u16 retrainLink                            : 1;
            u16 commonClockConfiguration               : 1;
            u16 extendedSynch                          : 1;
            u16 enableClockPowerManagement             : 1;
            u16 hardwareAutonomousWidthDisable         : 1;
            u16 linkBandwidthManagementInterruptEnable : 1;
            u16 linkAutonomousBandwidthInterruptEnable : 1;
            u16 __reserved2                            : 4;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL_H
