// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4168E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4168E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4168E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140492 = 0x10140492,
    SUBDEVICE_103C1798 = 0x103C1798,
    SUBDEVICE_103C17A5 = 0x103C17A5,
    SUBDEVICE_103C18D3 = 0x103C18D3,
    SUBDEVICE_103C1930 = 0x103C1930,
    SUBDEVICE_103C1931 = 0x103C1931,
    SUBDEVICE_103C1932 = 0x103C1932,
    SUBDEVICE_103C1933 = 0x103C1933,
    SUBDEVICE_103C193A = 0x103C193A,
    SUBDEVICE_103C3382 = 0x103C3382,
    SUBDEVICE_103C339D = 0x103C339D,
    SUBDEVICE_193D1003 = 0x193D1003,
    SUBDEVICE_193D1006 = 0x193D1006,
    SUBDEVICE_193D100F = 0x193D100F
};



inline const char8* enumToString(PciSubDevice14E4168E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4168E::NONE:               return "NONE";
        case PciSubDevice14E4168E::SUBDEVICE_10140492: return "SUBDEVICE_10140492";
        case PciSubDevice14E4168E::SUBDEVICE_103C1798: return "SUBDEVICE_103C1798";
        case PciSubDevice14E4168E::SUBDEVICE_103C17A5: return "SUBDEVICE_103C17A5";
        case PciSubDevice14E4168E::SUBDEVICE_103C18D3: return "SUBDEVICE_103C18D3";
        case PciSubDevice14E4168E::SUBDEVICE_103C1930: return "SUBDEVICE_103C1930";
        case PciSubDevice14E4168E::SUBDEVICE_103C1931: return "SUBDEVICE_103C1931";
        case PciSubDevice14E4168E::SUBDEVICE_103C1932: return "SUBDEVICE_103C1932";
        case PciSubDevice14E4168E::SUBDEVICE_103C1933: return "SUBDEVICE_103C1933";
        case PciSubDevice14E4168E::SUBDEVICE_103C193A: return "SUBDEVICE_103C193A";
        case PciSubDevice14E4168E::SUBDEVICE_103C3382: return "SUBDEVICE_103C3382";
        case PciSubDevice14E4168E::SUBDEVICE_103C339D: return "SUBDEVICE_103C339D";
        case PciSubDevice14E4168E::SUBDEVICE_193D1003: return "SUBDEVICE_193D1003";
        case PciSubDevice14E4168E::SUBDEVICE_193D1006: return "SUBDEVICE_193D1006";
        case PciSubDevice14E4168E::SUBDEVICE_193D100F: return "SUBDEVICE_193D100F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4168E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4168E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4168E::SUBDEVICE_10140492: return "PCIe2 2-port 10 GbE BaseT RJ45 Adapter (FC EN0W; CCIN 2CC4)";
        case PciSubDevice14E4168E::SUBDEVICE_103C1798: return "Flex-10 10Gb 2-port 530FLB Adapter [Meru]";
        case PciSubDevice14E4168E::SUBDEVICE_103C17A5: return "Flex-10 10Gb 2-port 530M Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C18D3: return "Ethernet 10Gb 2-port 530T Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C1930: return "FlexFabric 10Gb 2-port 534FLR-SFP+ Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C1931: return "StoreFabric CN1100R Dual Port Converged Network Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C1932: return "FlexFabric 10Gb 2-port 534FLB Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C1933: return "FlexFabric 10Gb 2-port 534M Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C193A: return "FlexFabric 10Gb 2-port 533FLR-T Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C3382: return "Ethernet 10Gb 2-port 530FLR-SFP+ Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_103C339D: return "Ethernet 10Gb 2-port 530SFP+ Adapter";
        case PciSubDevice14E4168E::SUBDEVICE_193D1003: return "530F-B";
        case PciSubDevice14E4168E::SUBDEVICE_193D1006: return "530F-L";
        case PciSubDevice14E4168E::SUBDEVICE_193D100F: return "NIC-ETH522i-Mb-2x10G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4168E_H
