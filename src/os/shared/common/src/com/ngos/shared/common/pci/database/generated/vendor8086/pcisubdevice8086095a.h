// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086095A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086095A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086095A: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861010 = 0x80861010,
    SUBDEVICE_80865000 = 0x80865000,
    SUBDEVICE_80865002 = 0x80865002,
    SUBDEVICE_8086500A = 0x8086500A,
    SUBDEVICE_80865010 = 0x80865010,
    SUBDEVICE_80865012 = 0x80865012,
    SUBDEVICE_80865020 = 0x80865020,
    SUBDEVICE_8086502A = 0x8086502A,
    SUBDEVICE_80865090 = 0x80865090,
    SUBDEVICE_80865100 = 0x80865100,
    SUBDEVICE_80865102 = 0x80865102,
    SUBDEVICE_8086510A = 0x8086510A,
    SUBDEVICE_80865110 = 0x80865110,
    SUBDEVICE_80865112 = 0x80865112,
    SUBDEVICE_80865190 = 0x80865190,
    SUBDEVICE_80865400 = 0x80865400,
    SUBDEVICE_80865410 = 0x80865410,
    SUBDEVICE_80865412 = 0x80865412,
    SUBDEVICE_80865420 = 0x80865420,
    SUBDEVICE_80865490 = 0x80865490,
    SUBDEVICE_80865510 = 0x80865510,
    SUBDEVICE_80865590 = 0x80865590,
    SUBDEVICE_80869000 = 0x80869000,
    SUBDEVICE_8086900A = 0x8086900A,
    SUBDEVICE_80869010 = 0x80869010,
    SUBDEVICE_80869012 = 0x80869012,
    SUBDEVICE_80869110 = 0x80869110,
    SUBDEVICE_80869112 = 0x80869112,
    SUBDEVICE_80869210 = 0x80869210,
    SUBDEVICE_80869310 = 0x80869310,
    SUBDEVICE_80869400 = 0x80869400,
    SUBDEVICE_80869410 = 0x80869410,
    SUBDEVICE_80869510 = 0x80869510
};



inline const char8* enumToString(PciSubDevice8086095A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086095A::NONE:               return "NONE";
        case PciSubDevice8086095A::SUBDEVICE_80861010: return "SUBDEVICE_80861010";
        case PciSubDevice8086095A::SUBDEVICE_80865000: return "SUBDEVICE_80865000";
        case PciSubDevice8086095A::SUBDEVICE_80865002: return "SUBDEVICE_80865002";
        case PciSubDevice8086095A::SUBDEVICE_8086500A: return "SUBDEVICE_8086500A";
        case PciSubDevice8086095A::SUBDEVICE_80865010: return "SUBDEVICE_80865010";
        case PciSubDevice8086095A::SUBDEVICE_80865012: return "SUBDEVICE_80865012";
        case PciSubDevice8086095A::SUBDEVICE_80865020: return "SUBDEVICE_80865020";
        case PciSubDevice8086095A::SUBDEVICE_8086502A: return "SUBDEVICE_8086502A";
        case PciSubDevice8086095A::SUBDEVICE_80865090: return "SUBDEVICE_80865090";
        case PciSubDevice8086095A::SUBDEVICE_80865100: return "SUBDEVICE_80865100";
        case PciSubDevice8086095A::SUBDEVICE_80865102: return "SUBDEVICE_80865102";
        case PciSubDevice8086095A::SUBDEVICE_8086510A: return "SUBDEVICE_8086510A";
        case PciSubDevice8086095A::SUBDEVICE_80865110: return "SUBDEVICE_80865110";
        case PciSubDevice8086095A::SUBDEVICE_80865112: return "SUBDEVICE_80865112";
        case PciSubDevice8086095A::SUBDEVICE_80865190: return "SUBDEVICE_80865190";
        case PciSubDevice8086095A::SUBDEVICE_80865400: return "SUBDEVICE_80865400";
        case PciSubDevice8086095A::SUBDEVICE_80865410: return "SUBDEVICE_80865410";
        case PciSubDevice8086095A::SUBDEVICE_80865412: return "SUBDEVICE_80865412";
        case PciSubDevice8086095A::SUBDEVICE_80865420: return "SUBDEVICE_80865420";
        case PciSubDevice8086095A::SUBDEVICE_80865490: return "SUBDEVICE_80865490";
        case PciSubDevice8086095A::SUBDEVICE_80865510: return "SUBDEVICE_80865510";
        case PciSubDevice8086095A::SUBDEVICE_80865590: return "SUBDEVICE_80865590";
        case PciSubDevice8086095A::SUBDEVICE_80869000: return "SUBDEVICE_80869000";
        case PciSubDevice8086095A::SUBDEVICE_8086900A: return "SUBDEVICE_8086900A";
        case PciSubDevice8086095A::SUBDEVICE_80869010: return "SUBDEVICE_80869010";
        case PciSubDevice8086095A::SUBDEVICE_80869012: return "SUBDEVICE_80869012";
        case PciSubDevice8086095A::SUBDEVICE_80869110: return "SUBDEVICE_80869110";
        case PciSubDevice8086095A::SUBDEVICE_80869112: return "SUBDEVICE_80869112";
        case PciSubDevice8086095A::SUBDEVICE_80869210: return "SUBDEVICE_80869210";
        case PciSubDevice8086095A::SUBDEVICE_80869310: return "SUBDEVICE_80869310";
        case PciSubDevice8086095A::SUBDEVICE_80869400: return "SUBDEVICE_80869400";
        case PciSubDevice8086095A::SUBDEVICE_80869410: return "SUBDEVICE_80869410";
        case PciSubDevice8086095A::SUBDEVICE_80869510: return "SUBDEVICE_80869510";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086095A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086095A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086095A::SUBDEVICE_80861010: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865000: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865002: return "Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_8086500A: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865010: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865012: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865020: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_8086502A: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865090: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865100: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865102: return "Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_8086510A: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865110: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865112: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865190: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865400: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865410: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865412: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865420: return "Dual Band Wireless-N 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865490: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865510: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80865590: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869000: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_8086900A: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869010: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869012: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869110: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869112: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869210: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869310: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869400: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869410: return "Dual Band Wireless-AC 7265";
        case PciSubDevice8086095A::SUBDEVICE_80869510: return "Dual Band Wireless-AC 7265";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086095A_H
