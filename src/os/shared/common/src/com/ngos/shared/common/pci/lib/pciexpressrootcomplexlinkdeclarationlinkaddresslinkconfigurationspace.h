#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H



#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace
{
    u8 encodedNumberOfBusNumberBitsReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return encodedNumberOfBusNumberBits == 0 ? 8 : encodedNumberOfBusNumberBits;
    }

    u8 busNumberReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        u8 numberOfBits = encodedNumberOfBusNumberBitsReal();

        return (value64 >> 20) & (SIZE_BY_BITS(numberOfBits) - 1);
    }

    u64 configurationSpaceBaseAddressReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        u8 numberOfBits = encodedNumberOfBusNumberBitsReal();

        return value64 >> (20 + numberOfBits);
    }



    union
    {
        struct
        {
            u64 encodedNumberOfBusNumberBits  : 3;
            u64 __reserved                    : 9;
            u64 functionNumber                : 3;
            u64 deviceNumber                  : 5;
            u64 busNumber                     : 8;
            u64 configurationSpaceBaseAddress : 36;
        };

        u64 value64;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H
