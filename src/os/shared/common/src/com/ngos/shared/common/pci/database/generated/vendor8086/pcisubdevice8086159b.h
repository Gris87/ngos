// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086159B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086159B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086159B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_113702BE = 0x113702BE,
    SUBDEVICE_1BD40057 = 0x1BD40057,
    SUBDEVICE_1BD40058 = 0x1BD40058,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_80864001 = 0x80864001,
    SUBDEVICE_80864002 = 0x80864002
};



inline const char8* enumToString(PciSubDevice8086159B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086159B::NONE:               return "NONE";
        case PciSubDevice8086159B::SUBDEVICE_113702BE: return "SUBDEVICE_113702BE";
        case PciSubDevice8086159B::SUBDEVICE_1BD40057: return "SUBDEVICE_1BD40057";
        case PciSubDevice8086159B::SUBDEVICE_1BD40058: return "SUBDEVICE_1BD40058";
        case PciSubDevice8086159B::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice8086159B::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice8086159B::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice8086159B::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice8086159B::SUBDEVICE_80864001: return "SUBDEVICE_80864001";
        case PciSubDevice8086159B::SUBDEVICE_80864002: return "SUBDEVICE_80864002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086159B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086159B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086159B::SUBDEVICE_113702BE: return "E810XXVDA2 2x25/10 GbE SFP28 PCIe NIC";
        case PciSubDevice8086159B::SUBDEVICE_1BD40057: return "Ethernet Network Adapter E810-XXVAM2";
        case PciSubDevice8086159B::SUBDEVICE_1BD40058: return "Ethernet Network Adapter E810-XXVAM2 for OCP 3.0";
        case PciSubDevice8086159B::SUBDEVICE_80860001: return "Ethernet 25G 2P E810-XXV OCP";
        case PciSubDevice8086159B::SUBDEVICE_80860002: return "Ethernet 25G 2P E810-XXV Adapter";
        case PciSubDevice8086159B::SUBDEVICE_80860003: return "Ethernet Network Adapter E810-XXV-2";
        case PciSubDevice8086159B::SUBDEVICE_80860005: return "Ethernet Network Adapter E810-XXV-2 for OCP 3.0";
        case PciSubDevice8086159B::SUBDEVICE_80864001: return "Ethernet Network Adapter E810-XXV-2";
        case PciSubDevice8086159B::SUBDEVICE_80864002: return "Ethernet Network Adapter E810-XXV-2 for OCP 3.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086159B_H
