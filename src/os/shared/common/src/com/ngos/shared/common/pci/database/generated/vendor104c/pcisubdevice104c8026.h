// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8026_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8026_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8026: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250035 = 0x10250035,
    SUBDEVICE_1025003C = 0x1025003C,
    SUBDEVICE_103C0025 = 0x103C0025,
    SUBDEVICE_103C006A = 0x103C006A,
    SUBDEVICE_1043808D = 0x1043808D
};



inline const char8* enumToString(PciSubDevice104C8026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8026::NONE:               return "NONE";
        case PciSubDevice104C8026::SUBDEVICE_10250035: return "SUBDEVICE_10250035";
        case PciSubDevice104C8026::SUBDEVICE_1025003C: return "SUBDEVICE_1025003C";
        case PciSubDevice104C8026::SUBDEVICE_103C0025: return "SUBDEVICE_103C0025";
        case PciSubDevice104C8026::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";
        case PciSubDevice104C8026::SUBDEVICE_1043808D: return "SUBDEVICE_1043808D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8026 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8026::SUBDEVICE_10250035: return "TravelMate 660";
        case PciSubDevice104C8026::SUBDEVICE_1025003C: return "Aspire 2001WLCi (Compaq CL50 motherboard)";
        case PciSubDevice104C8026::SUBDEVICE_103C0025: return "XE4500 Notebook";
        case PciSubDevice104C8026::SUBDEVICE_103C006A: return "NX9500";
        case PciSubDevice104C8026::SUBDEVICE_1043808D: return "A7V333 mainboard.";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8026_H
