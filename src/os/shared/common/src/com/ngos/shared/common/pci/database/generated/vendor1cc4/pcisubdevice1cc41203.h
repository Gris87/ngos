// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCISUBDEVICE1CC41203_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCISUBDEVICE1CC41203_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1CC41203: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1CC4A121 = 0x1CC4A121,
    SUBDEVICE_1CC4A122 = 0x1CC4A122,
    SUBDEVICE_1CC4A123 = 0x1CC4A123,
    SUBDEVICE_1CC4A124 = 0x1CC4A124,
    SUBDEVICE_1CC4A125 = 0x1CC4A125,
    SUBDEVICE_1CC4A211 = 0x1CC4A211,
    SUBDEVICE_1CC4A212 = 0x1CC4A212,
    SUBDEVICE_1CC4A213 = 0x1CC4A213,
    SUBDEVICE_1CC4A214 = 0x1CC4A214
};



inline const char8* enumToString(PciSubDevice1CC41203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CC41203::NONE:               return "NONE";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A121: return "SUBDEVICE_1CC4A121";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A122: return "SUBDEVICE_1CC4A122";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A123: return "SUBDEVICE_1CC4A123";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A124: return "SUBDEVICE_1CC4A124";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A125: return "SUBDEVICE_1CC4A125";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A211: return "SUBDEVICE_1CC4A211";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A212: return "SUBDEVICE_1CC4A212";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A213: return "SUBDEVICE_1CC4A213";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A214: return "SUBDEVICE_1CC4A214";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1CC41203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1CC41203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A121: return "NVMe SSD UHXXXa series U.2 960GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A122: return "NVMe SSD UHXXXa series U.2 1920GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A123: return "NVMe SSD UHXXXa series U.2 3840GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A124: return "NVMe SSD UHXXXa series U.2 7680GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A125: return "NVMe SSD UHXXXa series U.2 15360GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A211: return "NVMe SSD UHXXXa series U.2 800GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A212: return "NVMe SSD UHXXXa series U.2 1600GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A213: return "NVMe SSD UHXXXa series U.2 3200GB";
        case PciSubDevice1CC41203::SUBDEVICE_1CC4A214: return "NVMe SSD UHXXXa series U.2 6400GB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC4_PCISUBDEVICE1CC41203_H
