#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGDATA_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGDATA_H



#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingpowermanagementstate.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingpowermanagementsubstate.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingpowerrail.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerbudgetingtype.h>
#include <com/ngos/shared/common/pci/lib/pciexpresspowerscale.h>



struct PciExpressPowerBudgetingData
{
    union
    {
        struct
        {
            u32 basePower  : 8;
            u32 dataScale  : 2; // TODO: Use enum PciExpressPowerScale
            u32 pmSubState : 3; // TODO: Use enum PciExpressPowerBudgetingPowerManagementSubState
            u32 pmState    : 2; // TODO: Use enum PciExpressPowerBudgetingPowerManagementState
            u32 type       : 3; // TODO: Use enum PciExpressPowerBudgetingType
            u32 powerRail  : 3; // TODO: Use enum PciExpressPowerBudgetingPowerRail
            u32 __reserved : 11;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGDATA_H
