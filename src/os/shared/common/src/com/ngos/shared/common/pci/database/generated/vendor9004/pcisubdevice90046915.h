// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90046915_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90046915_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90046915: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90040008 = 0x90040008,
    SUBDEVICE_90040009 = 0x90040009,
    SUBDEVICE_90040010 = 0x90040010,
    SUBDEVICE_90040018 = 0x90040018,
    SUBDEVICE_90040019 = 0x90040019,
    SUBDEVICE_90040020 = 0x90040020,
    SUBDEVICE_90040028 = 0x90040028,
    SUBDEVICE_90048008 = 0x90048008,
    SUBDEVICE_90048009 = 0x90048009,
    SUBDEVICE_90048010 = 0x90048010,
    SUBDEVICE_90048018 = 0x90048018,
    SUBDEVICE_90048019 = 0x90048019,
    SUBDEVICE_90048020 = 0x90048020,
    SUBDEVICE_90048028 = 0x90048028
};



inline const char8* enumToString(PciSubDevice90046915 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90046915::NONE:               return "NONE";
        case PciSubDevice90046915::SUBDEVICE_90040008: return "SUBDEVICE_90040008";
        case PciSubDevice90046915::SUBDEVICE_90040009: return "SUBDEVICE_90040009";
        case PciSubDevice90046915::SUBDEVICE_90040010: return "SUBDEVICE_90040010";
        case PciSubDevice90046915::SUBDEVICE_90040018: return "SUBDEVICE_90040018";
        case PciSubDevice90046915::SUBDEVICE_90040019: return "SUBDEVICE_90040019";
        case PciSubDevice90046915::SUBDEVICE_90040020: return "SUBDEVICE_90040020";
        case PciSubDevice90046915::SUBDEVICE_90040028: return "SUBDEVICE_90040028";
        case PciSubDevice90046915::SUBDEVICE_90048008: return "SUBDEVICE_90048008";
        case PciSubDevice90046915::SUBDEVICE_90048009: return "SUBDEVICE_90048009";
        case PciSubDevice90046915::SUBDEVICE_90048010: return "SUBDEVICE_90048010";
        case PciSubDevice90046915::SUBDEVICE_90048018: return "SUBDEVICE_90048018";
        case PciSubDevice90046915::SUBDEVICE_90048019: return "SUBDEVICE_90048019";
        case PciSubDevice90046915::SUBDEVICE_90048020: return "SUBDEVICE_90048020";
        case PciSubDevice90046915::SUBDEVICE_90048028: return "SUBDEVICE_90048028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90046915 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90046915 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90046915::SUBDEVICE_90040008: return "ANA69011A/TX 10/100";
        case PciSubDevice90046915::SUBDEVICE_90040009: return "ANA69011A/TX 10/100";
        case PciSubDevice90046915::SUBDEVICE_90040010: return "ANA62022 2-port 10/100";
        case PciSubDevice90046915::SUBDEVICE_90040018: return "ANA62044 4-port 10/100";
        case PciSubDevice90046915::SUBDEVICE_90040019: return "ANA62044 4-port 10/100";
        case PciSubDevice90046915::SUBDEVICE_90040020: return "ANA62022 2-port 10/100";
        case PciSubDevice90046915::SUBDEVICE_90040028: return "ANA69011A/TX 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048008: return "ANA69011A/TX 64 bit 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048009: return "ANA69011A/TX 64 bit 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048010: return "ANA62022 2-port 64 bit 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048018: return "ANA62044 4-port 64 bit 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048019: return "ANA62044 4-port 64 bit 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048020: return "ANA62022 2-port 64 bit 10/100";
        case PciSubDevice90046915::SUBDEVICE_90048028: return "ANA69011A/TX 64 bit 10/100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90046915_H
