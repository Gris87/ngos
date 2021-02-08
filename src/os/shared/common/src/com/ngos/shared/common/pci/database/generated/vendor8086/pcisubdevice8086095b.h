// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086095B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086095B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086095B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80865200 = 0x80865200,
    SUBDEVICE_80865202 = 0x80865202,
    SUBDEVICE_8086520A = 0x8086520A,
    SUBDEVICE_80865210 = 0x80865210,
    SUBDEVICE_80865212 = 0x80865212,
    SUBDEVICE_80865290 = 0x80865290,
    SUBDEVICE_80865302 = 0x80865302,
    SUBDEVICE_80865310 = 0x80865310,
    SUBDEVICE_80869200 = 0x80869200
};



inline const char8* enumToString(PciSubDevice8086095B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086095B::NONE:               return "NONE";
        case PciSubDevice8086095B::SUBDEVICE_80865200: return "SUBDEVICE_80865200";
        case PciSubDevice8086095B::SUBDEVICE_80865202: return "SUBDEVICE_80865202";
        case PciSubDevice8086095B::SUBDEVICE_8086520A: return "SUBDEVICE_8086520A";
        case PciSubDevice8086095B::SUBDEVICE_80865210: return "SUBDEVICE_80865210";
        case PciSubDevice8086095B::SUBDEVICE_80865212: return "SUBDEVICE_80865212";
        case PciSubDevice8086095B::SUBDEVICE_80865290: return "SUBDEVICE_80865290";
        case PciSubDevice8086095B::SUBDEVICE_80865302: return "SUBDEVICE_80865302";
        case PciSubDevice8086095B::SUBDEVICE_80865310: return "SUBDEVICE_80865310";
        case PciSubDevice8086095B::SUBDEVICE_80869200: return "SUBDEVICE_80869200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086095B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086095B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086095B::SUBDEVICE_80865200: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095B::SUBDEVICE_80865202: return "Wireless-N 7265";
        case PciSubDevice8086095B::SUBDEVICE_8086520A: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095B::SUBDEVICE_80865210: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095B::SUBDEVICE_80865212: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095B::SUBDEVICE_80865290: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095B::SUBDEVICE_80865302: return "Wireless-N 7265";
        case PciSubDevice8086095B::SUBDEVICE_80865310: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095B::SUBDEVICE_80869200: return "Dual Band Wireless-AC 7265";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086095B_H
