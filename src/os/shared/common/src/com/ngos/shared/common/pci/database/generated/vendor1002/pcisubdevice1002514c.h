// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002514C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002514C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002514C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002003A = 0x1002003A,
    SUBDEVICE_1002013A = 0x1002013A,
    SUBDEVICE_148C2026 = 0x148C2026,
    SUBDEVICE_16810010 = 0x16810010,
    SUBDEVICE_174B7149 = 0x174B7149,
    SUBDEVICE_17870F08 = 0x17870F08
};



inline const char8* enumToString(PciSubDevice1002514C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002514C::NONE:               return "NONE";
        case PciSubDevice1002514C::SUBDEVICE_1002003A: return "SUBDEVICE_1002003A";
        case PciSubDevice1002514C::SUBDEVICE_1002013A: return "SUBDEVICE_1002013A";
        case PciSubDevice1002514C::SUBDEVICE_148C2026: return "SUBDEVICE_148C2026";
        case PciSubDevice1002514C::SUBDEVICE_16810010: return "SUBDEVICE_16810010";
        case PciSubDevice1002514C::SUBDEVICE_174B7149: return "SUBDEVICE_174B7149";
        case PciSubDevice1002514C::SUBDEVICE_17870F08: return "SUBDEVICE_17870F08";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002514C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002514C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002514C::SUBDEVICE_1002003A: return "Radeon R200 QL [Radeon 8500 LE]";
        case PciSubDevice1002514C::SUBDEVICE_1002013A: return "Radeon 8500";
        case PciSubDevice1002514C::SUBDEVICE_148C2026: return "R200 QL [Radeon 8500 Evil Master II Multi Display Edition]";
        case PciSubDevice1002514C::SUBDEVICE_16810010: return "Radeon 8500 [3D Prophet 8500 128Mb]";
        case PciSubDevice1002514C::SUBDEVICE_174B7149: return "Radeon 8500 LE";
        case PciSubDevice1002514C::SUBDEVICE_17870F08: return "Radeon R200 QL [PowerMagic Radeon 8500]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002514C_H
