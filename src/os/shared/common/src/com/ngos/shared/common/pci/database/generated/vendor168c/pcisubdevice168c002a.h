// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C002A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C002A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C002A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07774F05 = 0x07774F05,
    SUBDEVICE_103C3041 = 0x103C3041,
    SUBDEVICE_103C3042 = 0x103C3042,
    SUBDEVICE_105BE006 = 0x105BE006,
    SUBDEVICE_105BE01F = 0x105BE01F,
    SUBDEVICE_106B008F = 0x106B008F,
    SUBDEVICE_11AD6600 = 0x11AD6600,
    SUBDEVICE_144F7141 = 0x144F7141,
    SUBDEVICE_168C0203 = 0x168C0203,
    SUBDEVICE_1A320303 = 0x1A320303,
    SUBDEVICE_1A320306 = 0x1A320306,
    SUBDEVICE_1A3B1067 = 0x1A3B1067,
    SUBDEVICE_1A3B1071 = 0x1A3B1071,
    SUBDEVICE_1A3B1081 = 0x1A3B1081
};



inline const char8* enumToString(PciSubDevice168C002A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C002A::NONE:               return "NONE";
        case PciSubDevice168C002A::SUBDEVICE_07774F05: return "SUBDEVICE_07774F05";
        case PciSubDevice168C002A::SUBDEVICE_103C3041: return "SUBDEVICE_103C3041";
        case PciSubDevice168C002A::SUBDEVICE_103C3042: return "SUBDEVICE_103C3042";
        case PciSubDevice168C002A::SUBDEVICE_105BE006: return "SUBDEVICE_105BE006";
        case PciSubDevice168C002A::SUBDEVICE_105BE01F: return "SUBDEVICE_105BE01F";
        case PciSubDevice168C002A::SUBDEVICE_106B008F: return "SUBDEVICE_106B008F";
        case PciSubDevice168C002A::SUBDEVICE_11AD6600: return "SUBDEVICE_11AD6600";
        case PciSubDevice168C002A::SUBDEVICE_144F7141: return "SUBDEVICE_144F7141";
        case PciSubDevice168C002A::SUBDEVICE_168C0203: return "SUBDEVICE_168C0203";
        case PciSubDevice168C002A::SUBDEVICE_1A320303: return "SUBDEVICE_1A320303";
        case PciSubDevice168C002A::SUBDEVICE_1A320306: return "SUBDEVICE_1A320306";
        case PciSubDevice168C002A::SUBDEVICE_1A3B1067: return "SUBDEVICE_1A3B1067";
        case PciSubDevice168C002A::SUBDEVICE_1A3B1071: return "SUBDEVICE_1A3B1071";
        case PciSubDevice168C002A::SUBDEVICE_1A3B1081: return "SUBDEVICE_1A3B1081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C002A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C002A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C002A::SUBDEVICE_07774F05: return "SR71-X 802.11abgn Wireless ExpressCard Adapter [AR9280]";
        case PciSubDevice168C002A::SUBDEVICE_103C3041: return "AR5BHB92-H 802.11abgn Wireless Half-size Mini PCIe Card [AR9280]";
        case PciSubDevice168C002A::SUBDEVICE_103C3042: return "AzureWave AW-NE773 802.11abgn Wireless Half-size Mini PCIe Card [AR9280]";
        case PciSubDevice168C002A::SUBDEVICE_105BE006: return "T77H053.00 802.11bgn Wireless Mini PCIe Card [AR9281]";
        case PciSubDevice168C002A::SUBDEVICE_105BE01F: return "T77H047.31 802.11bgn Wireless Half-size Mini PCIe Card [AR9283]";
        case PciSubDevice168C002A::SUBDEVICE_106B008F: return "AirPort Extreme";
        case PciSubDevice168C002A::SUBDEVICE_11AD6600: return "WN6600A 802.11bgn Wireless Mini PCIe Card [AR9281]";
        case PciSubDevice168C002A::SUBDEVICE_144F7141: return "WLL6080 802.11bgn Wireless Mini PCIe Card [AR9281]";
        case PciSubDevice168C002A::SUBDEVICE_168C0203: return "DW1525 802.11abgn WLAN PCIe Card [AR9280]";
        case PciSubDevice168C002A::SUBDEVICE_1A320303: return "EM303 802.11bgn Wireless Mini PCIe Card [AR9281]";
        case PciSubDevice168C002A::SUBDEVICE_1A320306: return "EM306 802.11bgn Wireless Half-size Mini PCIe Card [AR9283]";
        case PciSubDevice168C002A::SUBDEVICE_1A3B1067: return "AW-NE771 802.11bgn Wireless Mini PCIe Card [AR9281]";
        case PciSubDevice168C002A::SUBDEVICE_1A3B1071: return "AW-NE772 802.11abgn Wireless Mini PCIe Card [AR9280]";
        case PciSubDevice168C002A::SUBDEVICE_1A3B1081: return "AW-NE773 802.11abgn Wireless Half-size Mini PCIe Card [AR9280]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C002A_H
