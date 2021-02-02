// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0012_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0012_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0012: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11863A03 = 0x11863A03,
    SUBDEVICE_11863A04 = 0x11863A04,
    SUBDEVICE_11863A05 = 0x11863A05,
    SUBDEVICE_126C8031 = 0x126C8031,
    SUBDEVICE_13854400 = 0x13854400,
    SUBDEVICE_1B47AA00 = 0x1B47AA00
};



inline const char8* enumToString(PciSubDevice168C0012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0012::NONE:               return "NONE";
        case PciSubDevice168C0012::SUBDEVICE_11863A03: return "SUBDEVICE_11863A03";
        case PciSubDevice168C0012::SUBDEVICE_11863A04: return "SUBDEVICE_11863A04";
        case PciSubDevice168C0012::SUBDEVICE_11863A05: return "SUBDEVICE_11863A05";
        case PciSubDevice168C0012::SUBDEVICE_126C8031: return "SUBDEVICE_126C8031";
        case PciSubDevice168C0012::SUBDEVICE_13854400: return "SUBDEVICE_13854400";
        case PciSubDevice168C0012::SUBDEVICE_1B47AA00: return "SUBDEVICE_1B47AA00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0012::SUBDEVICE_11863A03: return "AirPro DWL-A650 Wireless Cardbus Adapter (rev.B)";
        case PciSubDevice168C0012::SUBDEVICE_11863A04: return "AirPro DWL-AB650 Multimode Wireless Cardbus Adapter";
        case PciSubDevice168C0012::SUBDEVICE_11863A05: return "AirPro DWL-AB520 Multimode Wireless PCI Adapter";
        case PciSubDevice168C0012::SUBDEVICE_126C8031: return "2201 Mobile Adapter";
        case PciSubDevice168C0012::SUBDEVICE_13854400: return "WAB501 802.11ab Wireless CardBus Card";
        case PciSubDevice168C0012::SUBDEVICE_1B47AA00: return "8460 802.11ab Wireless CardBus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0012_H
