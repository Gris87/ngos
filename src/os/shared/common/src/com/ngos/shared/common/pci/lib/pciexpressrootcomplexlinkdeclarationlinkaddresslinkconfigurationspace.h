#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H



#include <com/ngos/shared/common/ngos/types.h>



struct PciExpressRootComplexLinkDeclarationLinkAndressConfigurationSpace
{
    bad_uint8 encodedNumberOfBusNumberBitsReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        return encodedNumberOfBusNumberBits == 0 ? 8 : encodedNumberOfBusNumberBits;
    }

    bad_uint8 busNumberReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        bad_uint8 numberOfBits = encodedNumberOfBusNumberBitsReal();

        return (value64 >> 20) & ((1ULL << numberOfBits) - 1);
    }

    bad_uint64 configurationSpaceBaseAddressReal()
    {
        // COMMON_LT(("")); // Commented to avoid too frequent logs



        bad_uint8 numberOfBits = encodedNumberOfBusNumberBitsReal();

        return value64 >> (20 + numberOfBits);
    }



    union
    {
        struct
        {
            bad_uint64 encodedNumberOfBusNumberBits  : 3;
            bad_uint64 __reserved                    : 9;
            bad_uint64 functionNumber                : 3;
            bad_uint64 deviceNumber                  : 5;
            bad_uint64 busNumber                     : 8;
            bad_uint64 configurationSpaceBaseAddress : 36;
        };

        bad_uint64 value64;
    };
};



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSROOTCOMPLEXLINKDECLARATIONLINKADDRESSLINKCONFIGURATIONSPACE_H
