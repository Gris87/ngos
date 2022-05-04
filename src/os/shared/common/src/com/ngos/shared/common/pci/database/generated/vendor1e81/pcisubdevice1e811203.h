// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E81_PCISUBDEVICE1E811203_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E81_PCISUBDEVICE1E811203_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1E811203: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1E81A121 = 0x1E81A121,
    SUBDEVICE_1E81A122 = 0x1E81A122,
    SUBDEVICE_1E81A123 = 0x1E81A123,
    SUBDEVICE_1E81A124 = 0x1E81A124,
    SUBDEVICE_1E81A125 = 0x1E81A125,
    SUBDEVICE_1E81A211 = 0x1E81A211,
    SUBDEVICE_1E81A212 = 0x1E81A212,
    SUBDEVICE_1E81A213 = 0x1E81A213,
    SUBDEVICE_1E81A214 = 0x1E81A214
};



inline const char8* enumToString(PciSubDevice1E811203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E811203::NONE:               return "NONE";
        case PciSubDevice1E811203::SUBDEVICE_1E81A121: return "SUBDEVICE_1E81A121";
        case PciSubDevice1E811203::SUBDEVICE_1E81A122: return "SUBDEVICE_1E81A122";
        case PciSubDevice1E811203::SUBDEVICE_1E81A123: return "SUBDEVICE_1E81A123";
        case PciSubDevice1E811203::SUBDEVICE_1E81A124: return "SUBDEVICE_1E81A124";
        case PciSubDevice1E811203::SUBDEVICE_1E81A125: return "SUBDEVICE_1E81A125";
        case PciSubDevice1E811203::SUBDEVICE_1E81A211: return "SUBDEVICE_1E81A211";
        case PciSubDevice1E811203::SUBDEVICE_1E81A212: return "SUBDEVICE_1E81A212";
        case PciSubDevice1E811203::SUBDEVICE_1E81A213: return "SUBDEVICE_1E81A213";
        case PciSubDevice1E811203::SUBDEVICE_1E81A214: return "SUBDEVICE_1E81A214";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1E811203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1E811203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1E811203::SUBDEVICE_1E81A121: return "NVMe SSD UHXXXa series U.2 960GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A122: return "NVMe SSD UHXXXa series U.2 1920GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A123: return "NVMe SSD UHXXXa series U.2 3840GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A124: return "NVMe SSD UHXXXa series U.2 7680GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A125: return "NVMe SSD UHXXXa series U.2 15360GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A211: return "NVMe SSD UHXXXa series U.2 800GBÂ";
        case PciSubDevice1E811203::SUBDEVICE_1E81A212: return "NVMe SSD UHXXXa series U.2 1600GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A213: return "NVMe SSD UHXXXa series U.2 3200GB";
        case PciSubDevice1E811203::SUBDEVICE_1E81A214: return "NVMe SSD UHXXXa series U.2 6400GB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E81_PCISUBDEVICE1E811203_H
