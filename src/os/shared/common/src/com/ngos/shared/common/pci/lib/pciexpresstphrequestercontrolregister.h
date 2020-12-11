#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCONTROLREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCONTROLREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpresstphrequesterstmodeselect.h>
#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestertphrequesterenable.h>



struct PciExpressTphRequesterControlRegister
{
    union
    {
        struct
        {
            u32 stModeSelect       : 3; // TODO: Use enum PciExpressTphRequesterStModeSelect
            u32 __reserved         : 5;
            u32 tphRequesterEnable : 2; // TODO: Use enum PciExpressTphRequesterTphRequesterEnable
            u32 __reserved2        : 22;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCONTROLREGISTER_H
