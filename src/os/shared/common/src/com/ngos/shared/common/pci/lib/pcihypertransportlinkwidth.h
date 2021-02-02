#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKWIDTH_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKWIDTH_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciHyperTransportLinkWidth: bad_uint8
{
    _8_BITS       = 0,
    _16_BITS      = 1,
    _32_BITS      = 3,
    _2_BITS       = 4,
    _4_BITS       = 5,
    NOT_CONNECTED = 7
};



inline const char8* enumToString(PciHyperTransportLinkWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    switch (width)
    {
        case PciHyperTransportLinkWidth::_8_BITS:       return "8_BITS";
        case PciHyperTransportLinkWidth::_16_BITS:      return "16_BITS";
        case PciHyperTransportLinkWidth::_32_BITS:      return "32_BITS";
        case PciHyperTransportLinkWidth::_2_BITS:       return "2_BITS";
        case PciHyperTransportLinkWidth::_4_BITS:       return "4_BITS";
        case PciHyperTransportLinkWidth::NOT_CONNECTED: return "NOT_CONNECTED";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciHyperTransportLinkWidth width) // TEST: NO
{
    // COMMON_LT((" | width = %u", width)); // Commented to avoid bad looking logs



    static char8 res[21];

    sprintf(res, "0x%02X (%s)", (bad_uint8)width, enumToString(width));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTLINKWIDTH_H
