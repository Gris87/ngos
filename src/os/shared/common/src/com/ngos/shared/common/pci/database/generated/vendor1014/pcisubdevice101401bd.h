// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101401BD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101401BD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101401BD: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101401BD = 0x101401BD,
    SUBDEVICE_101401BE = 0x101401BE,
    SUBDEVICE_101401BF = 0x101401BF,
    SUBDEVICE_10140208 = 0x10140208,
    SUBDEVICE_1014020E = 0x1014020E,
    SUBDEVICE_1014022E = 0x1014022E,
    SUBDEVICE_10140258 = 0x10140258,
    SUBDEVICE_10140259 = 0x10140259
};



inline const char8* enumToString(PciSubDevice101401BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101401BD::NONE:               return "NONE";
        case PciSubDevice101401BD::SUBDEVICE_101401BD: return "SUBDEVICE_101401BD";
        case PciSubDevice101401BD::SUBDEVICE_101401BE: return "SUBDEVICE_101401BE";
        case PciSubDevice101401BD::SUBDEVICE_101401BF: return "SUBDEVICE_101401BF";
        case PciSubDevice101401BD::SUBDEVICE_10140208: return "SUBDEVICE_10140208";
        case PciSubDevice101401BD::SUBDEVICE_1014020E: return "SUBDEVICE_1014020E";
        case PciSubDevice101401BD::SUBDEVICE_1014022E: return "SUBDEVICE_1014022E";
        case PciSubDevice101401BD::SUBDEVICE_10140258: return "SUBDEVICE_10140258";
        case PciSubDevice101401BD::SUBDEVICE_10140259: return "SUBDEVICE_10140259";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101401BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101401BD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101401BD::SUBDEVICE_101401BD: return "ServeRAID 4Lx";
        case PciSubDevice101401BD::SUBDEVICE_101401BE: return "ServeRAID-4M";
        case PciSubDevice101401BD::SUBDEVICE_101401BF: return "ServeRAID-4L";
        case PciSubDevice101401BD::SUBDEVICE_10140208: return "ServeRAID-4Mx";
        case PciSubDevice101401BD::SUBDEVICE_1014020E: return "ServeRAID-4Lx";
        case PciSubDevice101401BD::SUBDEVICE_1014022E: return "ServeRAID-4H";
        case PciSubDevice101401BD::SUBDEVICE_10140258: return "ServeRAID-5i";
        case PciSubDevice101401BD::SUBDEVICE_10140259: return "ServeRAID-5i";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE101401BD_H
