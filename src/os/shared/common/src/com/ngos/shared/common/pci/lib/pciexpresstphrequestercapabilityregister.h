#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H



#include <com/ngos/shared/common/pci/lib/pciexpresstphrequestersttablelocation.h>



struct PciExpressTphRequesterCapabilityRegister
{
    bad_uint16 stTableSizeReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return stTableSize + 1;
    }



    union
    {
        struct
        {
            bad_uint32 noStModeSupported             : 1;
            bad_uint32 interruptVectorModeSupported  : 1;
            bad_uint32 deviceSpecificModeSupported   : 1;
            bad_uint32 __reserved                    : 5;
            bad_uint32 extendedTphRequesterSupported : 1;
            bad_uint32 stTableLocation               : 2; // TODO: Use enum PciExpressTphRequesterStTableLocation
            bad_uint32 __reserved2                   : 5;
            bad_uint32 stTableSize                   : 11;
            bad_uint32 __reserved3                   : 5;
        };

        bad_uint32 value32;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSTPHREQUESTERCAPABILITYREGISTER_H
