// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014028C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014028C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1014028C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014028D = 0x1014028D,
    SUBDEVICE_101402BE = 0x101402BE,
    SUBDEVICE_101402C0 = 0x101402C0,
    SUBDEVICE_1014030D = 0x1014030D
};



inline const char8* enumToString(PciSubDevice1014028C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014028C::NONE:               return "NONE";
        case PciSubDevice1014028C::SUBDEVICE_1014028D: return "SUBDEVICE_1014028D";
        case PciSubDevice1014028C::SUBDEVICE_101402BE: return "SUBDEVICE_101402BE";
        case PciSubDevice1014028C::SUBDEVICE_101402C0: return "SUBDEVICE_101402C0";
        case PciSubDevice1014028C::SUBDEVICE_1014030D: return "SUBDEVICE_1014030D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1014028C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1014028C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014028C::SUBDEVICE_1014028D: return "Dual Channel PCI-X DDR SAS RAID Adapter (572E)";
        case PciSubDevice1014028C::SUBDEVICE_101402BE: return "Dual Channel PCI-X DDR u320 SCSI RAID Adapter (571B)";
        case PciSubDevice1014028C::SUBDEVICE_101402C0: return "Dual Channel PCI-X DDR u320 SCSI Adapter (571A)";
        case PciSubDevice1014028C::SUBDEVICE_1014030D: return "PCI-X DDR Auxiliary Cache Adapter (575B)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014028C_H
