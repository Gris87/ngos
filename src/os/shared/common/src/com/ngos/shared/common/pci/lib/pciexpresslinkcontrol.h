#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressactivestatepowermanagementcontrol.h>
#include <com/ngos/shared/common/pci/lib/pciexpressreadcompletionboundary.h>



struct PciExpressLinkControl
{
    union
    {
        struct
        {
            bad_uint16 aspmControl                            : 2; // TODO: Use enum PciExpressActiveStatePowerManagementControl
            bad_uint16 __reserved                             : 1;
            bad_uint16 readCompletionBoundary                 : 1; // TODO: Use enum PciExpressReadCompletionBoundary
            bad_uint16 linkDisable                            : 1;
            bad_uint16 retrainLink                            : 1;
            bad_uint16 commonClockConfiguration               : 1;
            bad_uint16 extendedSynch                          : 1;
            bad_uint16 enableClockPowerManagement             : 1;
            bad_uint16 hardwareAutonomousWidthDisable         : 1;
            bad_uint16 linkBandwidthManagementInterruptEnable : 1;
            bad_uint16 linkAutonomousBandwidthInterruptEnable : 1;
            bad_uint16 __reserved2                            : 4;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL_H
