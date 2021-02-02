#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCONTROL_H



#include <com/ngos/shared/common/pci/lib/pciexpressactivestatepowermanagementcontrol.h>



struct PciExpressRootComplexInternalLinkControlLinkControl
{
    union
    {
        struct
        {
            bad_uint16 aspmControl   : 2; // TODO: Use enum PciExpressActiveStatePowerManagementControl
            bad_uint16 __reserved    : 5;
            bad_uint16 extendedSynch : 1;
            bad_uint16 __reserved2   : 8;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKCONTROL_H
