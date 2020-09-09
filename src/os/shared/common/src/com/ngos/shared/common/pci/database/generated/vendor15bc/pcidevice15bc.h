// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15BC_PCIDEVICE15BC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15BC_PCIDEVICE15BC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor15bc/pcisubdevice15bc0105.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15BC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0103 = 0x0103,
    DEVICE_0105 = 0x0105,
    DEVICE_1100 = 0x1100,
    DEVICE_2922 = 0x2922,
    DEVICE_2928 = 0x2928,
    DEVICE_2929 = 0x2929
};



inline const char8* enumToString(PciDevice15BC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15BC::NONE:        return "NONE";
        case PciDevice15BC::DEVICE_0100: return "DEVICE_0100";
        case PciDevice15BC::DEVICE_0103: return "DEVICE_0103";
        case PciDevice15BC::DEVICE_0105: return "DEVICE_0105";
        case PciDevice15BC::DEVICE_1100: return "DEVICE_1100";
        case PciDevice15BC::DEVICE_2922: return "DEVICE_2922";
        case PciDevice15BC::DEVICE_2928: return "DEVICE_2928";
        case PciDevice15BC::DEVICE_2929: return "DEVICE_2929";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15BC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15BC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15BC::DEVICE_0100: return "HPFC-5600 Tachyon DX2+ FC";
        case PciDevice15BC::DEVICE_0103: return "QX4 PCI Express quad 4-gigabit Fibre Channel controller";
        case PciDevice15BC::DEVICE_0105: return "Celerity FC-44XS/FC-42XS/FC-41XS/FC-44ES/FC-42ES/FC-41ES";
        case PciDevice15BC::DEVICE_1100: return "E8001-66442 PCI Express CIC";
        case PciDevice15BC::DEVICE_2922: return "64 Bit, 133MHz PCI-X Exerciser & Protocol Checker";
        case PciDevice15BC::DEVICE_2928: return "64 Bit, 66MHz PCI Exerciser & Analyzer";
        case PciDevice15BC::DEVICE_2929: return "64 Bit, 133MHz PCI-X Analyzer & Exerciser";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice15BC device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15BC::DEVICE_0100: return "Unknown device";
        case PciDevice15BC::DEVICE_0103: return "Unknown device";
        case PciDevice15BC::DEVICE_0105: return enumToHumanString((PciSubDevice15BC0105)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice15BC::DEVICE_1100: return "Unknown device";
        case PciDevice15BC::DEVICE_2922: return "Unknown device";
        case PciDevice15BC::DEVICE_2928: return "Unknown device";
        case PciDevice15BC::DEVICE_2929: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15BC_PCIDEVICE15BC_H
