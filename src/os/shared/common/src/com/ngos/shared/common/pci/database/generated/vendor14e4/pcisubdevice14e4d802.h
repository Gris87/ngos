// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4D802_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4D802_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4D802: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14E48021 = 0x14E48021,
    SUBDEVICE_14E48023 = 0x14E48023,
    SUBDEVICE_14E48024 = 0x14E48024,
    SUBDEVICE_14E48028 = 0x14E48028,
    SUBDEVICE_1BB00021 = 0x1BB00021
};



inline const char8* enumToString(PciSubDevice14E4D802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4D802::NONE:               return "NONE";
        case PciSubDevice14E4D802::SUBDEVICE_14E48021: return "SUBDEVICE_14E48021";
        case PciSubDevice14E4D802::SUBDEVICE_14E48023: return "SUBDEVICE_14E48023";
        case PciSubDevice14E4D802::SUBDEVICE_14E48024: return "SUBDEVICE_14E48024";
        case PciSubDevice14E4D802::SUBDEVICE_14E48028: return "SUBDEVICE_14E48028";
        case PciSubDevice14E4D802::SUBDEVICE_1BB00021: return "SUBDEVICE_1BB00021";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4D802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4D802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4D802::SUBDEVICE_14E48021: return "Stingray Dual-Port 25Gb Ethernet PCIe SmartNIC w16GB DRAM (Part No BCM958802A8046C)";
        case PciSubDevice14E4D802::SUBDEVICE_14E48023: return "PS410T-H04 NetXtreme-S 4x10G 10GBaseT PCIe SmartNIC";
        case PciSubDevice14E4D802::SUBDEVICE_14E48024: return "Stingray Dual-Port 25Gb Ethernet PCIe SmartNIC w4GB DRAM (Part No BCM958802A8044C)";
        case PciSubDevice14E4D802::SUBDEVICE_14E48028: return "Stingray Dual-Port 25Gb Ethernet PCIe SmartNIC w8GB DRAM (Part No BCM958802A8048C)";
        case PciSubDevice14E4D802::SUBDEVICE_1BB00021: return "HPE SimpliVity Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4D802_H
