// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12FB_PCIDEVICE12FB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12FB_PCIDEVICE12FB_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12FB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_00F5 = 0x00F5,
    DEVICE_02AD = 0x02AD,
    DEVICE_2ADC = 0x2ADC,
    DEVICE_3100 = 0x3100,
    DEVICE_3500 = 0x3500,
    DEVICE_4D4F = 0x4D4F,
    DEVICE_8120 = 0x8120,
    DEVICE_DA62 = 0xDA62,
    DEVICE_DB62 = 0xDB62,
    DEVICE_DC62 = 0xDC62,
    DEVICE_DD62 = 0xDD62,
    DEVICE_EDDC = 0xEDDC,
    DEVICE_FA01 = 0xFA01
};



inline const char8* enumToString(PciDevice12FB device12FB) // TEST: NO
{
    // COMMON_LT((" | device12FB = %u", device12FB)); // Commented to avoid bad looking logs



    switch (device12FB)
    {
        case PciDevice12FB::NONE:        return "NONE";
        case PciDevice12FB::DEVICE_0001: return "DEVICE_0001";
        case PciDevice12FB::DEVICE_00F5: return "DEVICE_00F5";
        case PciDevice12FB::DEVICE_02AD: return "DEVICE_02AD";
        case PciDevice12FB::DEVICE_2ADC: return "DEVICE_2ADC";
        case PciDevice12FB::DEVICE_3100: return "DEVICE_3100";
        case PciDevice12FB::DEVICE_3500: return "DEVICE_3500";
        case PciDevice12FB::DEVICE_4D4F: return "DEVICE_4D4F";
        case PciDevice12FB::DEVICE_8120: return "DEVICE_8120";
        case PciDevice12FB::DEVICE_DA62: return "DEVICE_DA62";
        case PciDevice12FB::DEVICE_DB62: return "DEVICE_DB62";
        case PciDevice12FB::DEVICE_DC62: return "DEVICE_DC62";
        case PciDevice12FB::DEVICE_DD62: return "DEVICE_DD62";
        case PciDevice12FB::DEVICE_EDDC: return "DEVICE_EDDC";
        case PciDevice12FB::DEVICE_FA01: return "DEVICE_FA01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12FB device12FB) // TEST: NO
{
    // COMMON_LT((" | device12FB = %u", device12FB)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12FB, enumToString(device12FB));

    return res;
}



inline const char8* enumToHumanString(PciDevice12FB device12FB) // TEST: NO
{
    // COMMON_LT((" | device12FB = %u", device12FB)); // Commented to avoid bad looking logs



    switch (device12FB)
    {
        case PciDevice12FB::DEVICE_0001: return "PMC-MAI";
        case PciDevice12FB::DEVICE_00F5: return "F5 Dakar";
        case PciDevice12FB::DEVICE_02AD: return "PMC-2MAI";
        case PciDevice12FB::DEVICE_2ADC: return "ePMC-2ADC";
        case PciDevice12FB::DEVICE_3100: return "PRO-3100";
        case PciDevice12FB::DEVICE_3500: return "PRO-3500";
        case PciDevice12FB::DEVICE_4D4F: return "Modena";
        case PciDevice12FB::DEVICE_8120: return "ePMC-8120";
        case PciDevice12FB::DEVICE_DA62: return "Daytona C6201 PCI (Hurricane)";
        case PciDevice12FB::DEVICE_DB62: return "Ingliston XBIF";
        case PciDevice12FB::DEVICE_DC62: return "Ingliston PLX9054";
        case PciDevice12FB::DEVICE_DD62: return "Ingliston JTAG/ISP";
        case PciDevice12FB::DEVICE_EDDC: return "ePMC-MSDDC";
        case PciDevice12FB::DEVICE_FA01: return "ePMC-FPGA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12FB_PCIDEVICE12FB_H
