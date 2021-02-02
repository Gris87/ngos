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
            bad_uint16 targetLinkSpeed                : 4; // TODO: Use enum PciExpressLinkSpeed
            bad_uint16 enterCompliance                : 1;
            bad_uint16 hardwareAutonomousSpeedDisable : 1;
            bad_uint16 selectableDeemphasis           : 1; // TODO: Use enum PciExpressDeemphasis
            bad_uint16 transmitMargin                 : 3;
            bad_uint16 enterModifiedCompliance        : 1;
            bad_uint16 complianceSos                  : 1;
            bad_uint16 complianceDeemphasis           : 4; // TODO: Use enum PciExpressDeemphasis
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSLINKCONTROL2_H
