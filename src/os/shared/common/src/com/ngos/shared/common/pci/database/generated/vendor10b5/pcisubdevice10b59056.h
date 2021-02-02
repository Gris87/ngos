// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59056_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59056_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59056: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B52979 = 0x10B52979,
    SUBDEVICE_10B53268 = 0x10B53268,
    SUBDEVICE_10B53334 = 0x10B53334,
    SUBDEVICE_10B53352 = 0x10B53352,
    SUBDEVICE_10B53353 = 0x10B53353,
    SUBDEVICE_10B53354 = 0x10B53354,
    SUBDEVICE_10B53355 = 0x10B53355,
    SUBDEVICE_10B53415 = 0x10B53415,
    SUBDEVICE_10B53493 = 0x10B53493,
    SUBDEVICE_10B53565 = 0x10B53565,
    SUBDEVICE_1369C001 = 0x1369C001,
    SUBDEVICE_1369C201 = 0x1369C201,
    SUBDEVICE_14B4D10A = 0x14B4D10A,
    SUBDEVICE_14B4D128 = 0x14B4D128,
    SUBDEVICE_14B4D140 = 0x14B4D140,
    SUBDEVICE_1A0E006F = 0x1A0E006F
};



inline const char8* enumToString(PciSubDevice10B59056 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59056::NONE:               return "NONE";
        case PciSubDevice10B59056::SUBDEVICE_10B52979: return "SUBDEVICE_10B52979";
        case PciSubDevice10B59056::SUBDEVICE_10B53268: return "SUBDEVICE_10B53268";
        case PciSubDevice10B59056::SUBDEVICE_10B53334: return "SUBDEVICE_10B53334";
        case PciSubDevice10B59056::SUBDEVICE_10B53352: return "SUBDEVICE_10B53352";
        case PciSubDevice10B59056::SUBDEVICE_10B53353: return "SUBDEVICE_10B53353";
        case PciSubDevice10B59056::SUBDEVICE_10B53354: return "SUBDEVICE_10B53354";
        case PciSubDevice10B59056::SUBDEVICE_10B53355: return "SUBDEVICE_10B53355";
        case PciSubDevice10B59056::SUBDEVICE_10B53415: return "SUBDEVICE_10B53415";
        case PciSubDevice10B59056::SUBDEVICE_10B53493: return "SUBDEVICE_10B53493";
        case PciSubDevice10B59056::SUBDEVICE_10B53565: return "SUBDEVICE_10B53565";
        case PciSubDevice10B59056::SUBDEVICE_1369C001: return "SUBDEVICE_1369C001";
        case PciSubDevice10B59056::SUBDEVICE_1369C201: return "SUBDEVICE_1369C201";
        case PciSubDevice10B59056::SUBDEVICE_14B4D10A: return "SUBDEVICE_14B4D10A";
        case PciSubDevice10B59056::SUBDEVICE_14B4D128: return "SUBDEVICE_14B4D128";
        case PciSubDevice10B59056::SUBDEVICE_14B4D140: return "SUBDEVICE_14B4D140";
        case PciSubDevice10B59056::SUBDEVICE_1A0E006F: return "SUBDEVICE_1A0E006F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59056 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59056 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59056::SUBDEVICE_10B52979: return "CellinkBlade 11 - CPCI board VoATM AAL1";
        case PciSubDevice10B59056::SUBDEVICE_10B53268: return "IXXAT iPC-I XC16/PCIe CAN Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53334: return "Cambridge Pixel HPx Radar Input Card";
        case PciSubDevice10B59056::SUBDEVICE_10B53352: return "Alpermann+Velte PCL PCIe HD: Timecode Reader Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53353: return "Alpermann+Velte PCL PCIe D: Timecode Reader Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53354: return "Alpermann+Velte PCL PCIe LV: Timecode Reader Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53355: return "Alpermann+Velte PCL PCIe L: Timecode Reader Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53415: return "Alpermann+Velte PCIe TS: Time Synchronisation Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53493: return "Alpermann+Velte PCL PCIe 3G: Timecode Reader Board";
        case PciSubDevice10B59056::SUBDEVICE_10B53565: return "Cambridge Pixel HPx Radar Output Card";
        case PciSubDevice10B59056::SUBDEVICE_1369C001: return "LX6464ES";
        case PciSubDevice10B59056::SUBDEVICE_1369C201: return "LX1616ES";
        case PciSubDevice10B59056::SUBDEVICE_14B4D10A: return "DekTec DTA-110T";
        case PciSubDevice10B59056::SUBDEVICE_14B4D128: return "Dektec DTA-140";
        case PciSubDevice10B59056::SUBDEVICE_14B4D140: return "Dektec DTA-140";
        case PciSubDevice10B59056::SUBDEVICE_1A0E006F: return "Dektec DTA-111";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59056_H
