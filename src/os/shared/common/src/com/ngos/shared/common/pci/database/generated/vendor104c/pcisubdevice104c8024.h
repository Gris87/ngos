// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8024_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8024_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8024: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107D6620 = 0x107D6620,
    SUBDEVICE_14438024 = 0x14438024,
    SUBDEVICE_14581000 = 0x14581000
};



inline const char8* enumToString(PciSubDevice104C8024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8024::NONE:               return "NONE";
        case PciSubDevice104C8024::SUBDEVICE_107D6620: return "SUBDEVICE_107D6620";
        case PciSubDevice104C8024::SUBDEVICE_14438024: return "SUBDEVICE_14438024";
        case PciSubDevice104C8024::SUBDEVICE_14581000: return "SUBDEVICE_14581000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8024::SUBDEVICE_107D6620: return "Winfast DV2000 FireWire Controller";
        case PciSubDevice104C8024::SUBDEVICE_14438024: return "FireBoard Blue";
        case PciSubDevice104C8024::SUBDEVICE_14581000: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8024_H
