#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCONTROLSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCONTROLSTATUS_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/lib/pcipowermanagementpowerstate.h>



struct PciPowerManagementControlStatus
{
    union
    {
        struct
        {
            u16 powerState:              2; // TODO: Use enum PciPowerManagementPowerState
            u16 __reservedForPciExpress: 1;
            u16 noSoftReset:             1;
            u16 __reserved:              4;
            u16 enablePme:               1;
            u16 dataSelect:              4;
            u16 dataScale:               2;
            u16 pmeStatus:               1;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTCONTROLSTATUS_H
