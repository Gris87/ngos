#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYCLOCKFREQUENCY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYCLOCKFREQUENCY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExtendedBridgeSecondaryClockFrequency: u8
{
    CONVENTIONAL_MODE = 0,
    _66_MHZ           = 1,
    _100_MHZ          = 2,
    _133_MHZ          = 3
};



inline const char8* enumToString(PciExtendedBridgeSecondaryClockFrequency frequency) // TEST: NO
{
    // COMMON_LT((" | frequency = %u", frequency)); // Commented to avoid bad looking logs



    switch (frequency)
    {
        case PciExtendedBridgeSecondaryClockFrequency::CONVENTIONAL_MODE: return "CONVENTIONAL_MODE";
        case PciExtendedBridgeSecondaryClockFrequency::_66_MHZ:           return "_66_MHZ";
        case PciExtendedBridgeSecondaryClockFrequency::_100_MHZ:          return "_100_MHZ";
        case PciExtendedBridgeSecondaryClockFrequency::_133_MHZ:          return "_133_MHZ";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExtendedBridgeSecondaryClockFrequency frequency) // TEST: NO
{
    // COMMON_LT((" | frequency = %u", frequency)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", (u8)frequency, enumToString(frequency));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXTENDEDBRIDGESECONDARYCLOCKFREQUENCY_H
