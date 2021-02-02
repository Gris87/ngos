// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C803C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3
};



inline const char8* enumToString(PciSubDevice104C803C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C803C::NONE:               return "NONE";
        case PciSubDevice104C803C::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice104C803C::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C803C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C803C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C803C::SUBDEVICE_103C309F: return "nx9420";
        case PciSubDevice104C803C::SUBDEVICE_103C30A3: return "Compaq nw8440";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803C_H
