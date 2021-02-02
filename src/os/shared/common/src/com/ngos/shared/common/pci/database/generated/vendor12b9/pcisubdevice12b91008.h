// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91008_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91008_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12B91008: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12B900A2 = 0x12B900A2,
    SUBDEVICE_12B900AA = 0x12B900AA,
    SUBDEVICE_12B900AB = 0x12B900AB,
    SUBDEVICE_12B900AC = 0x12B900AC,
    SUBDEVICE_12B900AD = 0x12B900AD,
    SUBDEVICE_12B900D3 = 0x12B900D3,
    SUBDEVICE_12B9BABA = 0x12B9BABA
};



inline const char8* enumToString(PciSubDevice12B91008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12B91008::NONE:               return "NONE";
        case PciSubDevice12B91008::SUBDEVICE_12B900A2: return "SUBDEVICE_12B900A2";
        case PciSubDevice12B91008::SUBDEVICE_12B900AA: return "SUBDEVICE_12B900AA";
        case PciSubDevice12B91008::SUBDEVICE_12B900AB: return "SUBDEVICE_12B900AB";
        case PciSubDevice12B91008::SUBDEVICE_12B900AC: return "SUBDEVICE_12B900AC";
        case PciSubDevice12B91008::SUBDEVICE_12B900AD: return "SUBDEVICE_12B900AD";
        case PciSubDevice12B91008::SUBDEVICE_12B900D3: return "SUBDEVICE_12B900D3";
        case PciSubDevice12B91008::SUBDEVICE_12B9BABA: return "SUBDEVICE_12B9BABA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12B91008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12B91008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12B91008::SUBDEVICE_12B900A2: return "USR 56k Internal FAX Modem (Model 2977)";
        case PciSubDevice12B91008::SUBDEVICE_12B900AA: return "USR 56k Internal Voice Modem (Model 2976)";
        case PciSubDevice12B91008::SUBDEVICE_12B900AB: return "USR 56k Internal Voice Modem (Model 5609)";
        case PciSubDevice12B91008::SUBDEVICE_12B900AC: return "USR 56k Internal Voice Modem (Model 3298)";
        case PciSubDevice12B91008::SUBDEVICE_12B900AD: return "USR 56k Internal FAX Modem (Model 5610)";
        case PciSubDevice12B91008::SUBDEVICE_12B900D3: return "USR 56K Internal V92 FAX Modem (Model 5610)";
        case PciSubDevice12B91008::SUBDEVICE_12B9BABA: return "USR 56K Internal Voice Modem 3CP3298-DEL (Model 5601) [Hawk]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91008_H
