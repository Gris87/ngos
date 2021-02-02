#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCONTROLSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCONTROLSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementdatascale.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementdataselect.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementpowerstate.h>



struct PciPowerManagementControlStatus
{
    union
    {
        struct
        {
            bad_uint16 powerState:              2; // TODO: Use enum PciPowerManagementPowerState
            bad_uint16 __reservedForPciExpress: 1;
            bad_uint16 noSoftReset:             1;
            bad_uint16 __reserved:              4;
            bad_uint16 enablePme:               1;
            bad_uint16 dataSelect:              4; // TODO: Use enum PciPowerManagementDataSelect
            bad_uint16 dataScale:               2; // TODO: Use enum PciPowerManagementDataScale
            bad_uint16 pmeStatus:               1;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCONTROLSTATUS_H
