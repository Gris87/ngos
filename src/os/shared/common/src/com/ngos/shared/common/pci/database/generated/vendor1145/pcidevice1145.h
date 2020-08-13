// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1145_PCIDEVICE1145_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1145_PCIDEVICE1145_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1145: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8007 = 0x8007,
    DEVICE_F007 = 0xF007,
    DEVICE_F010 = 0xF010,
    DEVICE_F012 = 0xF012,
    DEVICE_F013 = 0xF013,
    DEVICE_F015 = 0xF015,
    DEVICE_F020 = 0xF020,
    DEVICE_F021 = 0xF021,
    DEVICE_F024 = 0xF024,
    DEVICE_F103 = 0xF103
};



inline const char8* enumToString(PciDevice1145 device1145) // TEST: NO
{
    // COMMON_LT((" | device1145 = %u", device1145)); // Commented to avoid bad looking logs



    switch (device1145)
    {
        case PciDevice1145::NONE:        return "NONE";
        case PciDevice1145::DEVICE_8007: return "DEVICE_8007";
        case PciDevice1145::DEVICE_F007: return "DEVICE_F007";
        case PciDevice1145::DEVICE_F010: return "DEVICE_F010";
        case PciDevice1145::DEVICE_F012: return "DEVICE_F012";
        case PciDevice1145::DEVICE_F013: return "DEVICE_F013";
        case PciDevice1145::DEVICE_F015: return "DEVICE_F015";
        case PciDevice1145::DEVICE_F020: return "DEVICE_F020";
        case PciDevice1145::DEVICE_F021: return "DEVICE_F021";
        case PciDevice1145::DEVICE_F024: return "DEVICE_F024";
        case PciDevice1145::DEVICE_F103: return "DEVICE_F103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1145 device1145) // TEST: NO
{
    // COMMON_LT((" | device1145 = %u", device1145)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1145, enumToString(device1145));

    return res;
}



inline const char8* enumToHumanString(PciDevice1145 device1145) // TEST: NO
{
    // COMMON_LT((" | device1145 = %u", device1145)); // Commented to avoid bad looking logs



    switch (device1145)
    {
        case PciDevice1145::DEVICE_8007: return "NinjaSCSI-32 Workbit";
        case PciDevice1145::DEVICE_F007: return "NinjaSCSI-32 KME";
        case PciDevice1145::DEVICE_F010: return "NinjaSCSI-32 Workbit";
        case PciDevice1145::DEVICE_F012: return "NinjaSCSI-32 Logitec";
        case PciDevice1145::DEVICE_F013: return "NinjaSCSI-32 Logitec";
        case PciDevice1145::DEVICE_F015: return "NinjaSCSI-32 Melco";
        case PciDevice1145::DEVICE_F020: return "NinjaSCSI-32 Sony PCGA-DVD51";
        case PciDevice1145::DEVICE_F021: return "NinjaPATA-32 Delkin Cardbus UDMA";
        case PciDevice1145::DEVICE_F024: return "NinjaPATA-32 Delkin Cardbus UDMA";
        case PciDevice1145::DEVICE_F103: return "NinjaPATA-32 Delkin Cardbus UDMA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1145_PCIDEVICE1145_H
