#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressactivestatepowermanagementcontrol.h>



struct PciExpressRootComplexInternalLinkControlLinkControl
{
    union
    {
        struct
        {
            u16 aspmControl   : 2; // TODO: Use enum PciExpressActiveStatePowerManagementControl
            u16 __reserved    : 5;
            u16 extendedSynch : 1;
            u16 __reserved2   : 8;
        };

        u16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCONTROL_H
