#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTREVISION_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTREVISION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciHyperTransportRevision: bad_uint8
{
    NONE   = 0,
    _1_00  = 0x20,
    _1_01  = 0x21,
    _1_02  = 0x22,
    _1_03  = 0x23,
    _1_04  = 0x24,
    _1_05  = 0x25,
    _1_10  = 0x2A,
    _2_00  = 0x40,
    _3_00  = 0x60
};



inline const char8* enumToString(PciHyperTransportRevision revision) // TEST: NO
{
    // COMMON_LT((" | revision = %u", revision)); // Commented to avoid bad looking logs



    switch (revision)
    {
        case PciHyperTransportRevision::NONE:  return "NONE";
        case PciHyperTransportRevision::_1_00: return "1_00";
        case PciHyperTransportRevision::_1_01: return "1_01";
        case PciHyperTransportRevision::_1_02: return "1_02";
        case PciHyperTransportRevision::_1_03: return "1_03";
        case PciHyperTransportRevision::_1_04: return "1_04";
        case PciHyperTransportRevision::_1_05: return "1_05";
        case PciHyperTransportRevision::_1_10: return "1_10";
        case PciHyperTransportRevision::_2_00: return "2_00";
        case PciHyperTransportRevision::_3_00: return "3_00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciHyperTransportRevision revision) // TEST: NO
{
    // COMMON_LT((" | revision = %u", revision)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (bad_uint8)revision, enumToString(revision));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTREVISION_H
