// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94025_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94025_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC94025: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_105A7203 = 0x105A7203,
    SUBDEVICE_11862900 = 0x11862900,
    SUBDEVICE_14328102 = 0x14328102,
    SUBDEVICE_1FC93015 = 0x1FC93015
};



inline const char8* enumToString(PciSubDevice1FC94025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94025::NONE:               return "NONE";
        case PciSubDevice1FC94025::SUBDEVICE_105A7203: return "SUBDEVICE_105A7203";
        case PciSubDevice1FC94025::SUBDEVICE_11862900: return "SUBDEVICE_11862900";
        case PciSubDevice1FC94025::SUBDEVICE_14328102: return "SUBDEVICE_14328102";
        case PciSubDevice1FC94025::SUBDEVICE_1FC93015: return "SUBDEVICE_1FC93015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC94025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC94025 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94025::SUBDEVICE_105A7203: return "SANLink3 NBase-T1";
        case PciSubDevice1FC94025::SUBDEVICE_11862900: return "DXE-810T 10GBase-T Ethernet Adapter";
        case PciSubDevice1FC94025::SUBDEVICE_14328102: return "10 Gigabit Ethernet PCI Express Adapter";
        case PciSubDevice1FC94025::SUBDEVICE_1FC93015: return "Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94025_H
