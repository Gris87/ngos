// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1AB11_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1AB11_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C1AB11: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11C1AB12 = 0x11C1AB12,
    SUBDEVICE_11C1AB13 = 0x11C1AB13,
    SUBDEVICE_11C1AB15 = 0x11C1AB15,
    SUBDEVICE_11C1AB16 = 0x11C1AB16
};



inline const char8* enumToString(PciSubDevice11C1AB11 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C1AB11::NONE:               return "NONE";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB12: return "SUBDEVICE_11C1AB12";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB13: return "SUBDEVICE_11C1AB13";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB15: return "SUBDEVICE_11C1AB15";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB16: return "SUBDEVICE_11C1AB16";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C1AB11 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C1AB11 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB12: return "WaveLAN 11abg Cardbus card (Model 1102)";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB13: return "WaveLAN 11abg MiniPCI card (Model 0512)";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB15: return "WaveLAN 11abg Cardbus card (Model 1106)";
        case PciSubDevice11C1AB11::SUBDEVICE_11C1AB16: return "WaveLAN 11abg MiniPCI card (Model 0516)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C1AB11_H
