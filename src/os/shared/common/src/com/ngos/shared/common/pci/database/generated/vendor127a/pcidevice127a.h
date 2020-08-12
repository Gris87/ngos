// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCIDEVICE127A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCIDEVICE127A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice127A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1022 = 0x1022,
    DEVICE_1023 = 0x1023,
    DEVICE_1024 = 0x1024,
    DEVICE_1025 = 0x1025,
    DEVICE_1026 = 0x1026,
    DEVICE_1032 = 0x1032,
    DEVICE_1033 = 0x1033,
    DEVICE_1034 = 0x1034,
    DEVICE_1035 = 0x1035,
    DEVICE_1036 = 0x1036,
    DEVICE_1085 = 0x1085,
    DEVICE_2004 = 0x2004,
    DEVICE_2005 = 0x2005,
    DEVICE_2013 = 0x2013,
    DEVICE_2014 = 0x2014,
    DEVICE_2015 = 0x2015,
    DEVICE_2016 = 0x2016,
    DEVICE_4311 = 0x4311,
    DEVICE_4320 = 0x4320,
    DEVICE_4321 = 0x4321,
    DEVICE_4322 = 0x4322,
    DEVICE_8234 = 0x8234
};



inline const char8* enumToString(PciDevice127A device127A) // TEST: NO
{
    // COMMON_LT((" | device127A = %u", device127A)); // Commented to avoid bad looking logs



    switch (device127A)
    {
        case PciDevice127A::NONE:        return "NONE";
        case PciDevice127A::DEVICE_1002: return "DEVICE_1002";
        case PciDevice127A::DEVICE_1003: return "DEVICE_1003";
        case PciDevice127A::DEVICE_1004: return "DEVICE_1004";
        case PciDevice127A::DEVICE_1005: return "DEVICE_1005";
        case PciDevice127A::DEVICE_1022: return "DEVICE_1022";
        case PciDevice127A::DEVICE_1023: return "DEVICE_1023";
        case PciDevice127A::DEVICE_1024: return "DEVICE_1024";
        case PciDevice127A::DEVICE_1025: return "DEVICE_1025";
        case PciDevice127A::DEVICE_1026: return "DEVICE_1026";
        case PciDevice127A::DEVICE_1032: return "DEVICE_1032";
        case PciDevice127A::DEVICE_1033: return "DEVICE_1033";
        case PciDevice127A::DEVICE_1034: return "DEVICE_1034";
        case PciDevice127A::DEVICE_1035: return "DEVICE_1035";
        case PciDevice127A::DEVICE_1036: return "DEVICE_1036";
        case PciDevice127A::DEVICE_1085: return "DEVICE_1085";
        case PciDevice127A::DEVICE_2004: return "DEVICE_2004";
        case PciDevice127A::DEVICE_2005: return "DEVICE_2005";
        case PciDevice127A::DEVICE_2013: return "DEVICE_2013";
        case PciDevice127A::DEVICE_2014: return "DEVICE_2014";
        case PciDevice127A::DEVICE_2015: return "DEVICE_2015";
        case PciDevice127A::DEVICE_2016: return "DEVICE_2016";
        case PciDevice127A::DEVICE_4311: return "DEVICE_4311";
        case PciDevice127A::DEVICE_4320: return "DEVICE_4320";
        case PciDevice127A::DEVICE_4321: return "DEVICE_4321";
        case PciDevice127A::DEVICE_4322: return "DEVICE_4322";
        case PciDevice127A::DEVICE_8234: return "DEVICE_8234";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice127A device127A) // TEST: NO
{
    // COMMON_LT((" | device127A = %u", device127A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device127A, enumToString(device127A));

    return res;
}



inline const char8* enumToHumanString(PciDevice127A device127A) // TEST: NO
{
    // COMMON_LT((" | device127A = %u", device127A)); // Commented to avoid bad looking logs



    switch (device127A)
    {
        case PciDevice127A::DEVICE_1002: return "HCF 56k Data/Fax Modem";
        case PciDevice127A::DEVICE_1003: return "HCF 56k Data/Fax Modem";
        case PciDevice127A::DEVICE_1004: return "HCF 56k Data/Fax/Voice Modem";
        case PciDevice127A::DEVICE_1005: return "HCF 56k Data/Fax/Voice/Spkp (w/Handset) Modem";
        case PciDevice127A::DEVICE_1022: return "HCF 56k Modem";
        case PciDevice127A::DEVICE_1023: return "HCF 56k Data/Fax Modem";
        case PciDevice127A::DEVICE_1024: return "HCF 56k Data/Fax/Voice Modem";
        case PciDevice127A::DEVICE_1025: return "HCF 56k Data/Fax/Voice/Spkp (w/Handset) Modem";
        case PciDevice127A::DEVICE_1026: return "HCF 56k PCI Speakerphone Modem";
        case PciDevice127A::DEVICE_1032: return "HCF 56k Modem";
        case PciDevice127A::DEVICE_1033: return "HCF 56k Modem";
        case PciDevice127A::DEVICE_1034: return "HCF 56k Modem";
        case PciDevice127A::DEVICE_1035: return "HCF 56k PCI Speakerphone Modem";
        case PciDevice127A::DEVICE_1036: return "HCF 56k Modem";
        case PciDevice127A::DEVICE_1085: return "HCF 56k Volcano PCI Modem";
        case PciDevice127A::DEVICE_2004: return "HSF 56k Data/Fax/Voice/Spkp (w/Handset) Modem";
        case PciDevice127A::DEVICE_2005: return "HCF 56k Data/Fax Modem";
        case PciDevice127A::DEVICE_2013: return "HSF 56k Data/Fax Modem";
        case PciDevice127A::DEVICE_2014: return "HSF 56k Data/Fax/Voice Modem";
        case PciDevice127A::DEVICE_2015: return "HSF 56k Data/Fax/Voice/Spkp (w/Handset) Modem";
        case PciDevice127A::DEVICE_2016: return "HSF 56k Data/Fax/Voice/Spkp Modem";
        case PciDevice127A::DEVICE_4311: return "Riptide HSF 56k PCI Modem";
        case PciDevice127A::DEVICE_4320: return "Riptide PCI Audio Controller";
        case PciDevice127A::DEVICE_4321: return "Riptide HCF 56k PCI Modem";
        case PciDevice127A::DEVICE_4322: return "Riptide PCI Game Controller";
        case PciDevice127A::DEVICE_8234: return "RapidFire 616X ATM155 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCIDEVICE127A_H
