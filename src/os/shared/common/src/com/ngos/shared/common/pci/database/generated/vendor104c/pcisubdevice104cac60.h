// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC60_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC60_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC60: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_175C5100 = 0x175C5100,
    SUBDEVICE_175C6100 = 0x175C6100,
    SUBDEVICE_175C6200 = 0x175C6200,
    SUBDEVICE_175C8800 = 0x175C8800,
    SUBDEVICE_186F3001 = 0x186F3001,
    SUBDEVICE_186F3005 = 0x186F3005,
    SUBDEVICE_186F3101 = 0x186F3101,
    SUBDEVICE_186F3105 = 0x186F3105
};



inline const char8* enumToString(PciSubDevice104CAC60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC60::NONE:               return "NONE";
        case PciSubDevice104CAC60::SUBDEVICE_175C5100: return "SUBDEVICE_175C5100";
        case PciSubDevice104CAC60::SUBDEVICE_175C6100: return "SUBDEVICE_175C6100";
        case PciSubDevice104CAC60::SUBDEVICE_175C6200: return "SUBDEVICE_175C6200";
        case PciSubDevice104CAC60::SUBDEVICE_175C8800: return "SUBDEVICE_175C8800";
        case PciSubDevice104CAC60::SUBDEVICE_186F3001: return "SUBDEVICE_186F3001";
        case PciSubDevice104CAC60::SUBDEVICE_186F3005: return "SUBDEVICE_186F3005";
        case PciSubDevice104CAC60::SUBDEVICE_186F3101: return "SUBDEVICE_186F3101";
        case PciSubDevice104CAC60::SUBDEVICE_186F3105: return "SUBDEVICE_186F3105";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC60::SUBDEVICE_175C5100: return "ASI51xx Audio Adapter";
        case PciSubDevice104CAC60::SUBDEVICE_175C6100: return "ASI61xx Audio Adapter";
        case PciSubDevice104CAC60::SUBDEVICE_175C6200: return "ASI62xx Audio Adapter";
        case PciSubDevice104CAC60::SUBDEVICE_175C8800: return "ASi88xx Audio Adapter";
        case PciSubDevice104CAC60::SUBDEVICE_186F3001: return "WR-G303 PCI radio receiver";
        case PciSubDevice104CAC60::SUBDEVICE_186F3005: return "WR-G305 PCI radio receiver";
        case PciSubDevice104CAC60::SUBDEVICE_186F3101: return "WR-G313 PCI radio receiver";
        case PciSubDevice104CAC60::SUBDEVICE_186F3105: return "WR-G315 PCI radio receiver";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC60_H
