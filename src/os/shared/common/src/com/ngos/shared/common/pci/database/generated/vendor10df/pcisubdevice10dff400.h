// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF400_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF400_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DFF400: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DFF401 = 0x10DFF401,
    SUBDEVICE_10DFF402 = 0x10DFF402,
    SUBDEVICE_10DFF403 = 0x10DFF403,
    SUBDEVICE_10DFF404 = 0x10DFF404,
    SUBDEVICE_10DFF405 = 0x10DFF405,
    SUBDEVICE_10DFF406 = 0x10DFF406,
    SUBDEVICE_10DFF410 = 0x10DFF410,
    SUBDEVICE_10DFF411 = 0x10DFF411,
    SUBDEVICE_10DFF418 = 0x10DFF418,
    SUBDEVICE_10DFF419 = 0x10DFF419,
    SUBDEVICE_159002D5 = 0x159002D5,
    SUBDEVICE_159002D6 = 0x159002D6
};



inline const char8* enumToString(PciSubDevice10DFF400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFF400::NONE:               return "NONE";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF401: return "SUBDEVICE_10DFF401";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF402: return "SUBDEVICE_10DFF402";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF403: return "SUBDEVICE_10DFF403";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF404: return "SUBDEVICE_10DFF404";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF405: return "SUBDEVICE_10DFF405";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF406: return "SUBDEVICE_10DFF406";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF410: return "SUBDEVICE_10DFF410";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF411: return "SUBDEVICE_10DFF411";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF418: return "SUBDEVICE_10DFF418";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF419: return "SUBDEVICE_10DFF419";
        case PciSubDevice10DFF400::SUBDEVICE_159002D5: return "SUBDEVICE_159002D5";
        case PciSubDevice10DFF400::SUBDEVICE_159002D6: return "SUBDEVICE_159002D6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DFF400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DFF400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DFF400::SUBDEVICE_10DFF401: return "LPe35000-M2 1-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF402: return "LPe35002-M2 2-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF403: return "LPe36000-M64 1-Port 64Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF404: return "LPe36002-M64 2-Port 64Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF405: return "LPe35004-M2 4-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF406: return "LPe35004-X6 4-Port Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF410: return "LPe35002-M2-D 2-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF411: return "LPe35000-M2-D 1-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF418: return "LPe35000-M2-L 1-Port 32Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_10DFF419: return "LPe35002-M2-L 2-Port 32Gb PCIe Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_159002D5: return "StoreFabric SN1610E 1-Port 32Gb Fibre Channel Adapter";
        case PciSubDevice10DFF400::SUBDEVICE_159002D6: return "StoreFabric SN1610E 2-Port 32Gb Fibre Channel Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DFF400_H
