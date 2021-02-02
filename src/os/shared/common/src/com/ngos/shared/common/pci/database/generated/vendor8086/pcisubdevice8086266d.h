// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086266D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025006A = 0x1025006A,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C099C = 0x103C099C
};



inline const char8* enumToString(PciSubDevice8086266D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086266D::NONE:               return "NONE";
        case PciSubDevice8086266D::SUBDEVICE_1025006A: return "SUBDEVICE_1025006A";
        case PciSubDevice8086266D::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice8086266D::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086266D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086266D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086266D::SUBDEVICE_1025006A: return "Conexant AC'97 CoDec (in Acer TravelMate 2410 serie laptop)";
        case PciSubDevice8086266D::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice8086266D::SUBDEVICE_103C099C: return "NX6110/NC6120";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266D_H
