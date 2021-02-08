// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3376_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3376_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice105A3376: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043809E = 0x1043809E
};



inline const char8* enumToString(PciSubDevice105A3376 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A3376::NONE:               return "NONE";
        case PciSubDevice105A3376::SUBDEVICE_1043809E: return "SUBDEVICE_1043809E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice105A3376 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice105A3376 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice105A3376::SUBDEVICE_1043809E: return "A7V8X motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCISUBDEVICE105A3376_H
