#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKFREQUENCY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKFREQUENCY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciHyperTransportLinkFrequency: u8
{
    _200_MHZ        = 0,
    _300_MHZ        = 1,
    _400_MHZ        = 2,
    _500_MHZ        = 3,
    _600_MHZ        = 4,
    _800_MHZ        = 5,
    _1000_MHZ       = 6,
    _1200_MHZ       = 7,
    _1400_MHZ       = 8,
    _1600_MHZ       = 9,
    _1800_MHZ       = 10,
    _2000_MHZ       = 11,
    _2200_MHZ       = 12,
    _2400_MHZ       = 13,
    _2600_MHZ       = 14,
    VENDOR_SPECIFIC = 15
};



inline const char8* enumToString(PciHyperTransportLinkFrequency frequency) // TEST: NO
{
    // COMMON_LT((" | frequency = %u", frequency)); // Commented to avoid bad looking logs



    switch (frequency)
    {
        case PciHyperTransportLinkFrequency::_200_MHZ:        return "_200_MHZ";
        case PciHyperTransportLinkFrequency::_300_MHZ:        return "_300_MHZ";
        case PciHyperTransportLinkFrequency::_400_MHZ:        return "_400_MHZ";
        case PciHyperTransportLinkFrequency::_500_MHZ:        return "_500_MHZ";
        case PciHyperTransportLinkFrequency::_600_MHZ:        return "_600_MHZ";
        case PciHyperTransportLinkFrequency::_800_MHZ:        return "_800_MHZ";
        case PciHyperTransportLinkFrequency::_1000_MHZ:       return "_1000_MHZ";
        case PciHyperTransportLinkFrequency::_1200_MHZ:       return "_1200_MHZ";
        case PciHyperTransportLinkFrequency::_1400_MHZ:       return "_1400_MHZ";
        case PciHyperTransportLinkFrequency::_1600_MHZ:       return "_1600_MHZ";
        case PciHyperTransportLinkFrequency::_1800_MHZ:       return "_1800_MHZ";
        case PciHyperTransportLinkFrequency::_2000_MHZ:       return "_2000_MHZ";
        case PciHyperTransportLinkFrequency::_2200_MHZ:       return "_2200_MHZ";
        case PciHyperTransportLinkFrequency::_2400_MHZ:       return "_2400_MHZ";
        case PciHyperTransportLinkFrequency::_2600_MHZ:       return "_2600_MHZ";
        case PciHyperTransportLinkFrequency::VENDOR_SPECIFIC: return "VENDOR_SPECIFIC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciHyperTransportLinkFrequency frequency) // TEST: NO
{
    // COMMON_LT((" | frequency = %u", frequency)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", (u8)frequency, enumToString(frequency));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKFREQUENCY_H
