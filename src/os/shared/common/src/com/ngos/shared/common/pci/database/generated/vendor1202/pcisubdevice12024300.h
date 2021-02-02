// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCISUBDEVICE12024300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCISUBDEVICE12024300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12024300: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12029841 = 0x12029841,
    SUBDEVICE_12029842 = 0x12029842,
    SUBDEVICE_12029843 = 0x12029843,
    SUBDEVICE_12029844 = 0x12029844
};



inline const char8* enumToString(PciSubDevice12024300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12024300::NONE:               return "NONE";
        case PciSubDevice12024300::SUBDEVICE_12029841: return "SUBDEVICE_12029841";
        case PciSubDevice12024300::SUBDEVICE_12029842: return "SUBDEVICE_12029842";
        case PciSubDevice12024300::SUBDEVICE_12029843: return "SUBDEVICE_12029843";
        case PciSubDevice12024300::SUBDEVICE_12029844: return "SUBDEVICE_12029844";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12024300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12024300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12024300::SUBDEVICE_12029841: return "SK-9841 LX";
        case PciSubDevice12024300::SUBDEVICE_12029842: return "SK-9841 LX dual link";
        case PciSubDevice12024300::SUBDEVICE_12029843: return "SK-9843 SX";
        case PciSubDevice12024300::SUBDEVICE_12029844: return "SK-9843 SX dual link";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCISUBDEVICE12024300_H
