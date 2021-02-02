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
            bad_uint32 basePower  : 8;
            bad_uint32 dataScale  : 2; // TODO: Use enum PciExpressPowerScale
            bad_uint32 pmSubState : 3; // TODO: Use enum PciExpressPowerBudgetingPowerManagementSubState
            bad_uint32 pmState    : 2; // TODO: Use enum PciExpressPowerBudgetingPowerManagementState
            bad_uint32 type       : 3; // TODO: Use enum PciExpressPowerBudgetingType
            bad_uint32 powerRail  : 3; // TODO: Use enum PciExpressPowerBudgetingPowerRail
            bad_uint32 __reserved : 11;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERBUDGETINGDATA_H
