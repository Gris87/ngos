// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860D58_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860D58_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860D58: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860001 = 0x80860001
};



inline const char8* enumToString(PciSubDevice80860D58 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860D58::NONE:               return "NONE";
        case PciSubDevice80860D58::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80860D58::SUBDEVICE_80860001: return "SUBDEVICE_80860001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860D58 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860D58 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860D58::SUBDEVICE_80860000: return "Ethernet Controller XXV710 Intel(R) FPGA Programmable Acceleration Card N3000 for Networking";
        case PciSubDevice80860D58::SUBDEVICE_80860001: return "Ethernet Controller XXV710 Intel(R) FPGA Programmable Acceleration Card N3000 for Networking";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860D58_H
