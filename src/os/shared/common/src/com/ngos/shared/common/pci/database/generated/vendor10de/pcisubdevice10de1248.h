// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1248_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1248_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1248: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_152D0930 = 0x152D0930,
    SUBDEVICE_17C010E7 = 0x17C010E7,
    SUBDEVICE_17C010E8 = 0x17C010E8,
    SUBDEVICE_17C010EA = 0x17C010EA,
    SUBDEVICE_18540890 = 0x18540890,
    SUBDEVICE_18540891 = 0x18540891,
    SUBDEVICE_18541795 = 0x18541795,
    SUBDEVICE_18541796 = 0x18541796,
    SUBDEVICE_18543005 = 0x18543005
};



inline const char8* enumToString(PciSubDevice10DE1248 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1248::NONE:               return "NONE";
        case PciSubDevice10DE1248::SUBDEVICE_152D0930: return "SUBDEVICE_152D0930";
        case PciSubDevice10DE1248::SUBDEVICE_17C010E7: return "SUBDEVICE_17C010E7";
        case PciSubDevice10DE1248::SUBDEVICE_17C010E8: return "SUBDEVICE_17C010E8";
        case PciSubDevice10DE1248::SUBDEVICE_17C010EA: return "SUBDEVICE_17C010EA";
        case PciSubDevice10DE1248::SUBDEVICE_18540890: return "SUBDEVICE_18540890";
        case PciSubDevice10DE1248::SUBDEVICE_18540891: return "SUBDEVICE_18540891";
        case PciSubDevice10DE1248::SUBDEVICE_18541795: return "SUBDEVICE_18541795";
        case PciSubDevice10DE1248::SUBDEVICE_18541796: return "SUBDEVICE_18541796";
        case PciSubDevice10DE1248::SUBDEVICE_18543005: return "SUBDEVICE_18543005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1248 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1248 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1248::SUBDEVICE_152D0930: return "GeForce GT 635M";
        case PciSubDevice10DE1248::SUBDEVICE_17C010E7: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_17C010E8: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_17C010EA: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_18540890: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_18540891: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_18541795: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_18541796: return "GeForce GT 555M";
        case PciSubDevice10DE1248::SUBDEVICE_18543005: return "GeForce GT 555M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1248_H
