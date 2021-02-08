// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE11C2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE11C2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE11C2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043845B = 0x1043845B,
    SUBDEVICE_14622874 = 0x14622874,
    SUBDEVICE_156911C2 = 0x156911C2,
    SUBDEVICE_19DA1281 = 0x19DA1281,
    SUBDEVICE_38423657 = 0x38423657,
    SUBDEVICE_38423658 = 0x38423658
};



inline const char8* enumToString(PciSubDevice10DE11C2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE11C2::NONE:               return "NONE";
        case PciSubDevice10DE11C2::SUBDEVICE_1043845B: return "SUBDEVICE_1043845B";
        case PciSubDevice10DE11C2::SUBDEVICE_14622874: return "SUBDEVICE_14622874";
        case PciSubDevice10DE11C2::SUBDEVICE_156911C2: return "SUBDEVICE_156911C2";
        case PciSubDevice10DE11C2::SUBDEVICE_19DA1281: return "SUBDEVICE_19DA1281";
        case PciSubDevice10DE11C2::SUBDEVICE_38423657: return "SUBDEVICE_38423657";
        case PciSubDevice10DE11C2::SUBDEVICE_38423658: return "SUBDEVICE_38423658";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE11C2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE11C2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE11C2::SUBDEVICE_1043845B: return "GeForce GTX 650 Ti Boost DirectCU II OC";
        case PciSubDevice10DE11C2::SUBDEVICE_14622874: return "GeForce GTX 650 Ti Boost TwinFrozr II OC";
        case PciSubDevice10DE11C2::SUBDEVICE_156911C2: return "GeForce GTX 650 Ti Boost OC";
        case PciSubDevice10DE11C2::SUBDEVICE_19DA1281: return "GeForce GTX 650 Ti Boost OC";
        case PciSubDevice10DE11C2::SUBDEVICE_38423657: return "GeForce GTX 650 Ti Boost";
        case PciSubDevice10DE11C2::SUBDEVICE_38423658: return "GeForce GTX 650 Ti Boost Superclocked";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE11C2_H
