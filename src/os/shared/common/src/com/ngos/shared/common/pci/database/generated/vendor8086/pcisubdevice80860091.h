// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860091_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860091_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860091: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865201 = 0x80865201,
    SUBDEVICE_80865205 = 0x80865205,
    SUBDEVICE_80865206 = 0x80865206,
    SUBDEVICE_80865207 = 0x80865207,
    SUBDEVICE_80865221 = 0x80865221,
    SUBDEVICE_80865225 = 0x80865225,
    SUBDEVICE_80865226 = 0x80865226
};



inline const char8* enumToString(PciSubDevice80860091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860091::NONE:               return "NONE";
        case PciSubDevice80860091::SUBDEVICE_80865201: return "SUBDEVICE_80865201";
        case PciSubDevice80860091::SUBDEVICE_80865205: return "SUBDEVICE_80865205";
        case PciSubDevice80860091::SUBDEVICE_80865206: return "SUBDEVICE_80865206";
        case PciSubDevice80860091::SUBDEVICE_80865207: return "SUBDEVICE_80865207";
        case PciSubDevice80860091::SUBDEVICE_80865221: return "SUBDEVICE_80865221";
        case PciSubDevice80860091::SUBDEVICE_80865225: return "SUBDEVICE_80865225";
        case PciSubDevice80860091::SUBDEVICE_80865226: return "SUBDEVICE_80865226";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860091 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860091::SUBDEVICE_80865201: return "Centrino Advanced-N 6230 AGN";
        case PciSubDevice80860091::SUBDEVICE_80865205: return "Centrino Advanced-N 6230 BGN";
        case PciSubDevice80860091::SUBDEVICE_80865206: return "Centrino Advanced-N 6230 ABG";
        case PciSubDevice80860091::SUBDEVICE_80865207: return "Centrino Advanced-N 6230 BG";
        case PciSubDevice80860091::SUBDEVICE_80865221: return "Centrino Advanced-N 6230 AGN";
        case PciSubDevice80860091::SUBDEVICE_80865225: return "Centrino Advanced-N 6230 BGN";
        case PciSubDevice80860091::SUBDEVICE_80865226: return "Centrino Advanced-N 6230 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860091_H
