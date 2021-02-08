#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestersttablelocation.h>



struct PciExpressTphRequesterCapabilityRegister
{
    u16 stTableSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return stTableSize + 1;
    }



    union
    {
        struct
        {
            u32 noStModeSupported             : 1;
            u32 interruptVectorModeSupported  : 1;
            u32 deviceSpecificModeSupported   : 1;
            u32 __reserved                    : 5;
            u32 extendedTphRequesterSupported : 1;
            u32 stTableLocation               : 2; // TODO: Use enum PciExpressTphRequesterStTableLocation
            u32 __reserved2                   : 5;
            u32 stTableSize                   : 11;
            u32 __reserved3                   : 5;
        };

        u32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H
