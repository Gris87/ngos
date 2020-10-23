#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL2_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pciexpressdeemphasis.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkspeed.h>



struct PciExpressLinkControl2
{
    union
    {
        struct
        {
            u16 targetLinkSpeed                : 4; // TODO: Use enum PciExpressLinkSpeed
            u16 enterCompliance                : 1;
            u16 hardwareAutonomousSpeedDisable : 1;
            u16 selectableDeemphasis           : 1; // TODO: Use enum PciExpressDeemphasis
            u16 transmitMargin                 : 3;
            u16 enterModifiedCompliance        : 1;
            u16 complianceSos                  : 1;
            u16 complianceDeemphasis           : 4; // TODO: Use enum PciExpressDeemphasis
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL2_H
