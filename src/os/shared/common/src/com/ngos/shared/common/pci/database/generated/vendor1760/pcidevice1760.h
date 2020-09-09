// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1760_PCIDEVICE1760_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1760_PCIDEVICE1760_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1760: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0121 = 0x0121,
    DEVICE_0122 = 0x0122,
    DEVICE_0123 = 0x0123,
    DEVICE_0141 = 0x0141,
    DEVICE_0142 = 0x0142,
    DEVICE_0143 = 0x0143,
    DEVICE_0144 = 0x0144,
    DEVICE_0214 = 0x0214,
    DEVICE_0215 = 0x0215,
    DEVICE_0216 = 0x0216,
    DEVICE_0217 = 0x0217,
    DEVICE_0240 = 0x0240,
    DEVICE_0241 = 0x0241,
    DEVICE_0242 = 0x0242,
    DEVICE_0243 = 0x0243,
    DEVICE_0244 = 0x0244,
    DEVICE_0245 = 0x0245,
    DEVICE_0303 = 0x0303,
    DEVICE_0800 = 0x0800,
    DEVICE_FF00 = 0xFF00
};



inline const char8* enumToString(PciDevice1760 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1760::NONE:        return "NONE";
        case PciDevice1760::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1760::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1760::DEVICE_0121: return "DEVICE_0121";
        case PciDevice1760::DEVICE_0122: return "DEVICE_0122";
        case PciDevice1760::DEVICE_0123: return "DEVICE_0123";
        case PciDevice1760::DEVICE_0141: return "DEVICE_0141";
        case PciDevice1760::DEVICE_0142: return "DEVICE_0142";
        case PciDevice1760::DEVICE_0143: return "DEVICE_0143";
        case PciDevice1760::DEVICE_0144: return "DEVICE_0144";
        case PciDevice1760::DEVICE_0214: return "DEVICE_0214";
        case PciDevice1760::DEVICE_0215: return "DEVICE_0215";
        case PciDevice1760::DEVICE_0216: return "DEVICE_0216";
        case PciDevice1760::DEVICE_0217: return "DEVICE_0217";
        case PciDevice1760::DEVICE_0240: return "DEVICE_0240";
        case PciDevice1760::DEVICE_0241: return "DEVICE_0241";
        case PciDevice1760::DEVICE_0242: return "DEVICE_0242";
        case PciDevice1760::DEVICE_0243: return "DEVICE_0243";
        case PciDevice1760::DEVICE_0244: return "DEVICE_0244";
        case PciDevice1760::DEVICE_0245: return "DEVICE_0245";
        case PciDevice1760::DEVICE_0303: return "DEVICE_0303";
        case PciDevice1760::DEVICE_0800: return "DEVICE_0800";
        case PciDevice1760::DEVICE_FF00: return "DEVICE_FF00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1760 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1760 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1760::DEVICE_0101: return "PCD-7004 Digital Bi-Directional Ports PCI Card";
        case PciDevice1760::DEVICE_0102: return "PCD-7104 Digital Input & Output PCI Card";
        case PciDevice1760::DEVICE_0121: return "PCT-7303A PC card with IRC counters";
        case PciDevice1760::DEVICE_0122: return "PCT-7408A PC card with counters and timers";
        case PciDevice1760::DEVICE_0123: return "PCT-7424 PCI card with standard counters";
        case PciDevice1760::DEVICE_0141: return "PCA7208AL - Analog Inputs/Outputs";
        case PciDevice1760::DEVICE_0142: return "PCA7208AS - Analog inputs/Outputs";
        case PciDevice1760::DEVICE_0143: return "PCA7408AL - Analog Inputs/Outputs";
        case PciDevice1760::DEVICE_0144: return "PCA7408AS - Analog Inputs/Outputs";
        case PciDevice1760::DEVICE_0214: return "PCT-7424C (F0) PC card with standard counters";
        case PciDevice1760::DEVICE_0215: return "PCT-7424C (F1) PC card with standard counters";
        case PciDevice1760::DEVICE_0216: return "PCT-7424E (F0) PC card with standard counters";
        case PciDevice1760::DEVICE_0217: return "PCT-7424E (F1) PC card with standard counters";
        case PciDevice1760::DEVICE_0240: return "PCA7428CL_F0 - analog Inputs";
        case PciDevice1760::DEVICE_0241: return "PCA7428CL_F1 - analog Inputs";
        case PciDevice1760::DEVICE_0242: return "PCA7428CS_F0 - Analog Inputs/Outputs non isolated";
        case PciDevice1760::DEVICE_0243: return "PCA7428CS_F1 - Analog Inputs/Outputs non isolated";
        case PciDevice1760::DEVICE_0244: return "PCA7428CE_F0 - Analog Inputs isolated";
        case PciDevice1760::DEVICE_0245: return "PCA7428CE_F1 - Analog Inputs isolated";
        case PciDevice1760::DEVICE_0303: return "PCD-7006C Digital Input & Output PCI Card";
        case PciDevice1760::DEVICE_0800: return "PCD8006 - PCIe digital Inputs/Outputs";
        case PciDevice1760::DEVICE_FF00: return "CTU CAN FD PCIe Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1760_PCIDEVICE1760_H
