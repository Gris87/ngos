// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10448_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10448_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C10448: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140131 = 0x10140131,
    SUBDEVICE_10338066 = 0x10338066,
    SUBDEVICE_13E00030 = 0x13E00030,
    SUBDEVICE_13E00040 = 0x13E00040,
    SUBDEVICE_16682400 = 0x16682400
};



inline const char8* enumToString(PciSubDevice11C10448 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10448::NONE:               return "NONE";
        case PciSubDevice11C10448::SUBDEVICE_10140131: return "SUBDEVICE_10140131";
        case PciSubDevice11C10448::SUBDEVICE_10338066: return "SUBDEVICE_10338066";
        case PciSubDevice11C10448::SUBDEVICE_13E00030: return "SUBDEVICE_13E00030";
        case PciSubDevice11C10448::SUBDEVICE_13E00040: return "SUBDEVICE_13E00040";
        case PciSubDevice11C10448::SUBDEVICE_16682400: return "SUBDEVICE_16682400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C10448 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C10448 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C10448::SUBDEVICE_10140131: return "Lucent Win Modem";
        case PciSubDevice11C10448::SUBDEVICE_10338066: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10448::SUBDEVICE_13E00030: return "56k Voice Modem";
        case PciSubDevice11C10448::SUBDEVICE_13E00040: return "LT WinModem 56k Data+Fax+Voice+Dsvd";
        case PciSubDevice11C10448::SUBDEVICE_16682400: return "LT WinModem 56k (MiniPCI Ethernet+Modem)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C10448_H
