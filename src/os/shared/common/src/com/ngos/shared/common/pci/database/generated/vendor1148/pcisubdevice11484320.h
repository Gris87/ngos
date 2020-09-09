// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484320_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484320_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11484320: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11480121 = 0x11480121,
    SUBDEVICE_11480221 = 0x11480221,
    SUBDEVICE_11480321 = 0x11480321,
    SUBDEVICE_11480421 = 0x11480421,
    SUBDEVICE_11480621 = 0x11480621,
    SUBDEVICE_11480721 = 0x11480721,
    SUBDEVICE_11480821 = 0x11480821,
    SUBDEVICE_11480921 = 0x11480921,
    SUBDEVICE_11481121 = 0x11481121,
    SUBDEVICE_11481221 = 0x11481221,
    SUBDEVICE_11483221 = 0x11483221,
    SUBDEVICE_11485021 = 0x11485021,
    SUBDEVICE_11485041 = 0x11485041,
    SUBDEVICE_11485043 = 0x11485043,
    SUBDEVICE_11485051 = 0x11485051,
    SUBDEVICE_11485061 = 0x11485061,
    SUBDEVICE_11485071 = 0x11485071,
    SUBDEVICE_11489521 = 0x11489521,
    SUBDEVICE_12592916 = 0x12592916
};



inline const char8* enumToString(PciSubDevice11484320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11484320::NONE:               return "NONE";
        case PciSubDevice11484320::SUBDEVICE_11480121: return "SUBDEVICE_11480121";
        case PciSubDevice11484320::SUBDEVICE_11480221: return "SUBDEVICE_11480221";
        case PciSubDevice11484320::SUBDEVICE_11480321: return "SUBDEVICE_11480321";
        case PciSubDevice11484320::SUBDEVICE_11480421: return "SUBDEVICE_11480421";
        case PciSubDevice11484320::SUBDEVICE_11480621: return "SUBDEVICE_11480621";
        case PciSubDevice11484320::SUBDEVICE_11480721: return "SUBDEVICE_11480721";
        case PciSubDevice11484320::SUBDEVICE_11480821: return "SUBDEVICE_11480821";
        case PciSubDevice11484320::SUBDEVICE_11480921: return "SUBDEVICE_11480921";
        case PciSubDevice11484320::SUBDEVICE_11481121: return "SUBDEVICE_11481121";
        case PciSubDevice11484320::SUBDEVICE_11481221: return "SUBDEVICE_11481221";
        case PciSubDevice11484320::SUBDEVICE_11483221: return "SUBDEVICE_11483221";
        case PciSubDevice11484320::SUBDEVICE_11485021: return "SUBDEVICE_11485021";
        case PciSubDevice11484320::SUBDEVICE_11485041: return "SUBDEVICE_11485041";
        case PciSubDevice11484320::SUBDEVICE_11485043: return "SUBDEVICE_11485043";
        case PciSubDevice11484320::SUBDEVICE_11485051: return "SUBDEVICE_11485051";
        case PciSubDevice11484320::SUBDEVICE_11485061: return "SUBDEVICE_11485061";
        case PciSubDevice11484320::SUBDEVICE_11485071: return "SUBDEVICE_11485071";
        case PciSubDevice11484320::SUBDEVICE_11489521: return "SUBDEVICE_11489521";
        case PciSubDevice11484320::SUBDEVICE_12592916: return "SUBDEVICE_12592916";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11484320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11484320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11484320::SUBDEVICE_11480121: return "Marvell RDK-8001 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480221: return "Marvell RDK-8002 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480321: return "Marvell RDK-8003 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480421: return "Marvell RDK-8004 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480621: return "Marvell RDK-8006 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480721: return "Marvell RDK-8007 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480821: return "Marvell RDK-8008 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11480921: return "Marvell RDK-8009 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11481121: return "Marvell RDK-8011 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11481221: return "Marvell RDK-8012 Adapter";
        case PciSubDevice11484320::SUBDEVICE_11483221: return "SK-9521 V2.0 10/100/1000Base-T Adapter";
        case PciSubDevice11484320::SUBDEVICE_11485021: return "SK-9821 V2.0 Gigabit Ethernet 10/100/1000Base-T Adapter";
        case PciSubDevice11484320::SUBDEVICE_11485041: return "SK-9841 V2.0 Gigabit Ethernet 1000Base-LX Adapter";
        case PciSubDevice11484320::SUBDEVICE_11485043: return "SK-9843 V2.0 Gigabit Ethernet 1000Base-SX Adapter";
        case PciSubDevice11484320::SUBDEVICE_11485051: return "SK-9851 V2.0 Gigabit Ethernet 1000Base-SX Adapter";
        case PciSubDevice11484320::SUBDEVICE_11485061: return "SK-9861 V2.0 Gigabit Ethernet 1000Base-SX Adapter";
        case PciSubDevice11484320::SUBDEVICE_11485071: return "SK-9871 V2.0 Gigabit Ethernet 1000Base-ZX Adapter";
        case PciSubDevice11484320::SUBDEVICE_11489521: return "SK-9521 10/100/1000Base-T Adapter";
        case PciSubDevice11484320::SUBDEVICE_12592916: return "AT-2916T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1148_PCISUBDEVICE11484320_H
