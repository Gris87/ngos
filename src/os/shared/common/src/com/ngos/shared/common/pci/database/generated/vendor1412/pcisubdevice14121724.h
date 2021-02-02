// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCISUBDEVICE14121724_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCISUBDEVICE14121724_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14121724: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B00200 = 0x10B00200,
    SUBDEVICE_14121724 = 0x14121724,
    SUBDEVICE_14123630 = 0x14123630,
    SUBDEVICE_14123631 = 0x14123631,
    SUBDEVICE_14123632 = 0x14123632,
    SUBDEVICE_153B1145 = 0x153B1145,
    SUBDEVICE_153B1147 = 0x153B1147,
    SUBDEVICE_153B1150 = 0x153B1150,
    SUBDEVICE_153B1153 = 0x153B1153,
    SUBDEVICE_17AB1906 = 0x17AB1906,
    SUBDEVICE_270FF641 = 0x270FF641,
    SUBDEVICE_270FF645 = 0x270FF645,
    SUBDEVICE_31304154 = 0x31304154
};



inline const char8* enumToString(PciSubDevice14121724 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14121724::NONE:               return "NONE";
        case PciSubDevice14121724::SUBDEVICE_10B00200: return "SUBDEVICE_10B00200";
        case PciSubDevice14121724::SUBDEVICE_14121724: return "SUBDEVICE_14121724";
        case PciSubDevice14121724::SUBDEVICE_14123630: return "SUBDEVICE_14123630";
        case PciSubDevice14121724::SUBDEVICE_14123631: return "SUBDEVICE_14123631";
        case PciSubDevice14121724::SUBDEVICE_14123632: return "SUBDEVICE_14123632";
        case PciSubDevice14121724::SUBDEVICE_153B1145: return "SUBDEVICE_153B1145";
        case PciSubDevice14121724::SUBDEVICE_153B1147: return "SUBDEVICE_153B1147";
        case PciSubDevice14121724::SUBDEVICE_153B1150: return "SUBDEVICE_153B1150";
        case PciSubDevice14121724::SUBDEVICE_153B1153: return "SUBDEVICE_153B1153";
        case PciSubDevice14121724::SUBDEVICE_17AB1906: return "SUBDEVICE_17AB1906";
        case PciSubDevice14121724::SUBDEVICE_270FF641: return "SUBDEVICE_270FF641";
        case PciSubDevice14121724::SUBDEVICE_270FF645: return "SUBDEVICE_270FF645";
        case PciSubDevice14121724::SUBDEVICE_31304154: return "SUBDEVICE_31304154";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14121724 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14121724 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14121724::SUBDEVICE_10B00200: return "Hollywood@Home 7.1";
        case PciSubDevice14121724::SUBDEVICE_14121724: return "Albatron PX865PE 7.1";
        case PciSubDevice14121724::SUBDEVICE_14123630: return "M-Audio Revolution 7.1";
        case PciSubDevice14121724::SUBDEVICE_14123631: return "M-Audio Revolution 5.1";
        case PciSubDevice14121724::SUBDEVICE_14123632: return "M-Audio Audiophile 192";
        case PciSubDevice14121724::SUBDEVICE_153B1145: return "Aureon 7.1 Space";
        case PciSubDevice14121724::SUBDEVICE_153B1147: return "Aureon 5.1 Sky";
        case PciSubDevice14121724::SUBDEVICE_153B1150: return "PHASE 22";
        case PciSubDevice14121724::SUBDEVICE_153B1153: return "Aureon 7.1 Universe";
        case PciSubDevice14121724::SUBDEVICE_17AB1906: return "PSC 724 [Ultimate Edge]";
        case PciSubDevice14121724::SUBDEVICE_270FF641: return "ZNF3-150";
        case PciSubDevice14121724::SUBDEVICE_270FF645: return "ZNF3-250";
        case PciSubDevice14121724::SUBDEVICE_31304154: return "MAYA 44 MKII";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCISUBDEVICE14121724_H
