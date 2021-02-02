// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268A8: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250442 = 0x10250442,
    SUBDEVICE_10250451 = 0x10250451,
    SUBDEVICE_1025050A = 0x1025050A,
    SUBDEVICE_1025050B = 0x1025050B,
    SUBDEVICE_1025050C = 0x1025050C,
    SUBDEVICE_1025050E = 0x1025050E,
    SUBDEVICE_1025050F = 0x1025050F,
    SUBDEVICE_10250513 = 0x10250513,
    SUBDEVICE_10250514 = 0x10250514,
    SUBDEVICE_10250515 = 0x10250515,
    SUBDEVICE_10250516 = 0x10250516,
    SUBDEVICE_10250525 = 0x10250525,
    SUBDEVICE_10250526 = 0x10250526,
    SUBDEVICE_1025056D = 0x1025056D,
    SUBDEVICE_1028048F = 0x1028048F,
    SUBDEVICE_10280490 = 0x10280490,
    SUBDEVICE_102804B9 = 0x102804B9,
    SUBDEVICE_102804BA = 0x102804BA,
    SUBDEVICE_103C159B = 0x103C159B,
    SUBDEVICE_144DC0AD = 0x144DC0AD
};



inline const char8* enumToString(PciSubDevice100268A8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268A8::NONE:               return "NONE";
        case PciSubDevice100268A8::SUBDEVICE_10250442: return "SUBDEVICE_10250442";
        case PciSubDevice100268A8::SUBDEVICE_10250451: return "SUBDEVICE_10250451";
        case PciSubDevice100268A8::SUBDEVICE_1025050A: return "SUBDEVICE_1025050A";
        case PciSubDevice100268A8::SUBDEVICE_1025050B: return "SUBDEVICE_1025050B";
        case PciSubDevice100268A8::SUBDEVICE_1025050C: return "SUBDEVICE_1025050C";
        case PciSubDevice100268A8::SUBDEVICE_1025050E: return "SUBDEVICE_1025050E";
        case PciSubDevice100268A8::SUBDEVICE_1025050F: return "SUBDEVICE_1025050F";
        case PciSubDevice100268A8::SUBDEVICE_10250513: return "SUBDEVICE_10250513";
        case PciSubDevice100268A8::SUBDEVICE_10250514: return "SUBDEVICE_10250514";
        case PciSubDevice100268A8::SUBDEVICE_10250515: return "SUBDEVICE_10250515";
        case PciSubDevice100268A8::SUBDEVICE_10250516: return "SUBDEVICE_10250516";
        case PciSubDevice100268A8::SUBDEVICE_10250525: return "SUBDEVICE_10250525";
        case PciSubDevice100268A8::SUBDEVICE_10250526: return "SUBDEVICE_10250526";
        case PciSubDevice100268A8::SUBDEVICE_1025056D: return "SUBDEVICE_1025056D";
        case PciSubDevice100268A8::SUBDEVICE_1028048F: return "SUBDEVICE_1028048F";
        case PciSubDevice100268A8::SUBDEVICE_10280490: return "SUBDEVICE_10280490";
        case PciSubDevice100268A8::SUBDEVICE_102804B9: return "SUBDEVICE_102804B9";
        case PciSubDevice100268A8::SUBDEVICE_102804BA: return "SUBDEVICE_102804BA";
        case PciSubDevice100268A8::SUBDEVICE_103C159B: return "SUBDEVICE_103C159B";
        case PciSubDevice100268A8::SUBDEVICE_144DC0AD: return "SUBDEVICE_144DC0AD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268A8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268A8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268A8::SUBDEVICE_10250442: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250451: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1025050A: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1025050B: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1025050C: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1025050E: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1025050F: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250513: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250514: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250515: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250516: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250525: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_10250526: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1025056D: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_1028048F: return "Radeon HD 6870M";
        case PciSubDevice100268A8::SUBDEVICE_10280490: return "Radeon HD 6870M";
        case PciSubDevice100268A8::SUBDEVICE_102804B9: return "Radeon HD 6870M";
        case PciSubDevice100268A8::SUBDEVICE_102804BA: return "Radeon HD 6870M";
        case PciSubDevice100268A8::SUBDEVICE_103C159B: return "Radeon HD 6850M";
        case PciSubDevice100268A8::SUBDEVICE_144DC0AD: return "Radeon HD 6850M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A8_H
