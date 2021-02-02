#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKSTATUS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKSTATUS_H



#include <com/ngos/shared/common/pci/lib/pciexpresslinkspeed.h>
#include <com/ngos/shared/common/pci/lib/pciexpresslinkwidth.h>



struct PciExpressRootComplexInternalLinkControlLinkStatus
{
    union
    {
        struct
        {
            bad_uint16 currentLinkSpeed    : 4; // TODO: Use enum PciExpressLinkSpeed
            bad_uint16 negotiatedLinkWidth : 6; // TODO: Use enum PciExpressLinkWidth
            bad_uint16 __reserved          : 6;
        };

        bad_uint16 value16;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXINTERNALLINKCONTROLLINKSTATUS_H
