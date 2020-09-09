// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086107B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086007B = 0x8086007B,
    SUBDEVICE_8086107B = 0x8086107B
};



inline const char8* enumToString(PciSubDevice8086107B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107B::NONE:               return "NONE";
        case PciSubDevice8086107B::SUBDEVICE_8086007B: return "SUBDEVICE_8086007B";
        case PciSubDevice8086107B::SUBDEVICE_8086107B: return "SUBDEVICE_8086107B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086107B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086107B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086107B::SUBDEVICE_8086007B: return "PRO/1000 MB Dual Port Server Connection";
        case PciSubDevice8086107B::SUBDEVICE_8086107B: return "PRO/1000 MB Dual Port Server Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086107B_H
