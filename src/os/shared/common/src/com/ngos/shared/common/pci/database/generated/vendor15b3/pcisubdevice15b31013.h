// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B31013: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101404F7 = 0x101404F7,
    SUBDEVICE_15B30003 = 0x15B30003,
    SUBDEVICE_15B30005 = 0x15B30005,
    SUBDEVICE_15B30006 = 0x15B30006,
    SUBDEVICE_15B30007 = 0x15B30007,
    SUBDEVICE_15B30008 = 0x15B30008,
    SUBDEVICE_15B30033 = 0x15B30033,
    SUBDEVICE_15B30034 = 0x15B30034,
    SUBDEVICE_15B30050 = 0x15B30050
};



inline const char8* enumToString(PciSubDevice15B31013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31013::NONE:               return "NONE";
        case PciSubDevice15B31013::SUBDEVICE_101404F7: return "SUBDEVICE_101404F7";
        case PciSubDevice15B31013::SUBDEVICE_15B30003: return "SUBDEVICE_15B30003";
        case PciSubDevice15B31013::SUBDEVICE_15B30005: return "SUBDEVICE_15B30005";
        case PciSubDevice15B31013::SUBDEVICE_15B30006: return "SUBDEVICE_15B30006";
        case PciSubDevice15B31013::SUBDEVICE_15B30007: return "SUBDEVICE_15B30007";
        case PciSubDevice15B31013::SUBDEVICE_15B30008: return "SUBDEVICE_15B30008";
        case PciSubDevice15B31013::SUBDEVICE_15B30033: return "SUBDEVICE_15B30033";
        case PciSubDevice15B31013::SUBDEVICE_15B30034: return "SUBDEVICE_15B30034";
        case PciSubDevice15B31013::SUBDEVICE_15B30050: return "SUBDEVICE_15B30050";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B31013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B31013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31013::SUBDEVICE_101404F7: return "PCIe3 2-port 100 GbE (NIC and RoCE) QSFP28 Adapter for Power";
        case PciSubDevice15B31013::SUBDEVICE_15B30003: return "Mellanox Technologies ConnectX-4 Stand-up single-port 40GbE MCX413A-BCAT";
        case PciSubDevice15B31013::SUBDEVICE_15B30005: return "Mellanox Technologies ConnectX-4 Stand-up single-port 40GbE MCX415A-BCAT";
        case PciSubDevice15B31013::SUBDEVICE_15B30006: return "MCX416A-BCAT, ConnectX-4 EN, 40/56GbE 2P, PCIe3.0 x16";
        case PciSubDevice15B31013::SUBDEVICE_15B30007: return "ConnectX-4 EN network interface card, 40/56GbE dual-port QSFP28, PCIe3.0 x16, tall bracket";
        case PciSubDevice15B31013::SUBDEVICE_15B30008: return "ConnectX-4 Stand-up dual-port 100GbE MCX416A-CCAT";
        case PciSubDevice15B31013::SUBDEVICE_15B30033: return "ConnectX-4 VPI IB EDR/100 GbE Single Port QSFP28 Adapter";
        case PciSubDevice15B31013::SUBDEVICE_15B30034: return "ConnectX-4 VPI IB EDR/100 GbE Dual Port QSFP28 Adapter";
        case PciSubDevice15B31013::SUBDEVICE_15B30050: return "ConnectX-4 100 GbE Dual Port QSFP28 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31013_H
