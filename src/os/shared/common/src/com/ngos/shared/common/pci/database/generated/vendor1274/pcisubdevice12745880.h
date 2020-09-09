// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCISUBDEVICE12745880_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCISUBDEVICE12745880_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12745880: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12742000 = 0x12742000,
    SUBDEVICE_12742003 = 0x12742003,
    SUBDEVICE_12745880 = 0x12745880,
    SUBDEVICE_12748001 = 0x12748001,
    SUBDEVICE_1458A000 = 0x1458A000,
    SUBDEVICE_14626880 = 0x14626880,
    SUBDEVICE_270F2001 = 0x270F2001,
    SUBDEVICE_270F2200 = 0x270F2200,
    SUBDEVICE_270F7040 = 0x270F7040
};



inline const char8* enumToString(PciSubDevice12745880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12745880::NONE:               return "NONE";
        case PciSubDevice12745880::SUBDEVICE_12742000: return "SUBDEVICE_12742000";
        case PciSubDevice12745880::SUBDEVICE_12742003: return "SUBDEVICE_12742003";
        case PciSubDevice12745880::SUBDEVICE_12745880: return "SUBDEVICE_12745880";
        case PciSubDevice12745880::SUBDEVICE_12748001: return "SUBDEVICE_12748001";
        case PciSubDevice12745880::SUBDEVICE_1458A000: return "SUBDEVICE_1458A000";
        case PciSubDevice12745880::SUBDEVICE_14626880: return "SUBDEVICE_14626880";
        case PciSubDevice12745880::SUBDEVICE_270F2001: return "SUBDEVICE_270F2001";
        case PciSubDevice12745880::SUBDEVICE_270F2200: return "SUBDEVICE_270F2200";
        case PciSubDevice12745880::SUBDEVICE_270F7040: return "SUBDEVICE_270F7040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12745880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12745880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12745880::SUBDEVICE_12742000: return "Creative CT4810 [Sound Blaster AudioPCI 128]";
        case PciSubDevice12745880::SUBDEVICE_12742003: return "Creative SoundBlaster AudioPCI 128";
        case PciSubDevice12745880::SUBDEVICE_12745880: return "Creative CT4750 [Sound Blaster PCI 128]";
        case PciSubDevice12745880::SUBDEVICE_12748001: return "Sound Blaster 16PCI 4.1ch";
        case PciSubDevice12745880::SUBDEVICE_1458A000: return "5880 AudioPCI On Motherboard 6OXET";
        case PciSubDevice12745880::SUBDEVICE_14626880: return "5880 AudioPCI On Motherboard MS-6188 1.00";
        case PciSubDevice12745880::SUBDEVICE_270F2001: return "5880 AudioPCI On Motherboard 6CTR";
        case PciSubDevice12745880::SUBDEVICE_270F2200: return "5880 AudioPCI On Motherboard 6WTX";
        case PciSubDevice12745880::SUBDEVICE_270F7040: return "5880 AudioPCI On Motherboard 6ATA4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1274_PCISUBDEVICE12745880_H
