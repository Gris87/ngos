// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCISUBDEVICE1BB10100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCISUBDEVICE1BB10100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1BB10100: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1BB10101 = 0x1BB10101,
    SUBDEVICE_1BB10103 = 0x1BB10103,
    SUBDEVICE_1BB10105 = 0x1BB10105,
    SUBDEVICE_1BB10106 = 0x1BB10106,
    SUBDEVICE_1BB10107 = 0x1BB10107,
    SUBDEVICE_1BB10108 = 0x1BB10108,
    SUBDEVICE_1BB10121 = 0x1BB10121,
    SUBDEVICE_1BB10123 = 0x1BB10123,
    SUBDEVICE_1BB10125 = 0x1BB10125,
    SUBDEVICE_1BB10126 = 0x1BB10126,
    SUBDEVICE_1BB10127 = 0x1BB10127,
    SUBDEVICE_1BB10128 = 0x1BB10128,
    SUBDEVICE_1BB10131 = 0x1BB10131,
    SUBDEVICE_1BB10132 = 0x1BB10132,
    SUBDEVICE_1BB10141 = 0x1BB10141,
    SUBDEVICE_1BB10142 = 0x1BB10142,
    SUBDEVICE_1BB10151 = 0x1BB10151,
    SUBDEVICE_1BB10152 = 0x1BB10152,
    SUBDEVICE_1BB101A1 = 0x1BB101A1
};



inline const char8* enumToString(PciSubDevice1BB10100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1BB10100::NONE:               return "NONE";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10101: return "SUBDEVICE_1BB10101";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10103: return "SUBDEVICE_1BB10103";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10105: return "SUBDEVICE_1BB10105";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10106: return "SUBDEVICE_1BB10106";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10107: return "SUBDEVICE_1BB10107";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10108: return "SUBDEVICE_1BB10108";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10121: return "SUBDEVICE_1BB10121";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10123: return "SUBDEVICE_1BB10123";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10125: return "SUBDEVICE_1BB10125";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10126: return "SUBDEVICE_1BB10126";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10127: return "SUBDEVICE_1BB10127";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10128: return "SUBDEVICE_1BB10128";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10131: return "SUBDEVICE_1BB10131";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10132: return "SUBDEVICE_1BB10132";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10141: return "SUBDEVICE_1BB10141";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10142: return "SUBDEVICE_1BB10142";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10151: return "SUBDEVICE_1BB10151";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10152: return "SUBDEVICE_1BB10152";
        case PciSubDevice1BB10100::SUBDEVICE_1BB101A1: return "SUBDEVICE_1BB101A1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1BB10100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1BB10100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1BB10100::SUBDEVICE_1BB10101: return "Nytro XF1440";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10103: return "Nytro 5000";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10105: return "Nytro 5020";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10106: return "Nytro 5020 TCG";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10107: return "Nytro 5320";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10108: return "Nytro 5320 TCG";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10121: return "Nytro XM1440";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10123: return "Nytro 5000";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10125: return "Nytro 5020";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10126: return "Nytro 5020";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10127: return "Nytro 5320 M.2";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10128: return "Nytro 5320 M.2 TCG";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10131: return "Nytro 5320 M.2";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10132: return "Nytro 5320 M.2 TCG";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10141: return "Nytro 5320 E1.S";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10142: return "Nytro 5320 E1.S TCG";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10151: return "Nytro 5520";
        case PciSubDevice1BB10100::SUBDEVICE_1BB10152: return "Nytro 5520 TCG";
        case PciSubDevice1BB10100::SUBDEVICE_1BB101A1: return "Nytro XP7102";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB1_PCISUBDEVICE1BB10100_H
