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
            bad_uint32 stModeSelect       : 3; // TODO: Use enum PciExpressTphRequesterStModeSelect
            bad_uint32 __reserved         : 5;
            bad_uint32 tphRequesterEnable : 2; // TODO: Use enum PciExpressTphRequesterTphRequesterEnable
            bad_uint32 __reserved2        : 22;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCONTROLREGISTER_H
