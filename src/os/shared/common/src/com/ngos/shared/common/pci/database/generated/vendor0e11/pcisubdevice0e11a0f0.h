// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11A0F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11A0F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0E11A0F0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B0F3 = 0x0E11B0F3
};



inline const char8* enumToString(PciSubDevice0E11A0F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11A0F0::NONE:               return "NONE";
        case PciSubDevice0E11A0F0::SUBDEVICE_0E11B0F3: return "SUBDEVICE_0E11B0F3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0E11A0F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0E11A0F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11A0F0::SUBDEVICE_0E11B0F3: return "ProLiant DL360";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11A0F0_H
