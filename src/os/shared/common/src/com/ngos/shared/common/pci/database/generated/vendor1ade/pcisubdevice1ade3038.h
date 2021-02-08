// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ADE_PCISUBDEVICE1ADE3038_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ADE_PCISUBDEVICE1ADE3038_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1ADE3038: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13C23016 = 0x13C23016,
    SUBDEVICE_42540552 = 0x42540552
};



inline const char8* enumToString(PciSubDevice1ADE3038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1ADE3038::NONE:               return "NONE";
        case PciSubDevice1ADE3038::SUBDEVICE_13C23016: return "SUBDEVICE_13C23016";
        case PciSubDevice1ADE3038::SUBDEVICE_42540552: return "SUBDEVICE_42540552";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1ADE3038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1ADE3038 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1ADE3038::SUBDEVICE_13C23016: return "TT-budget S2-4200 Twin";
        case PciSubDevice1ADE3038::SUBDEVICE_42540552: return "S952 v3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1ADE_PCISUBDEVICE1ADE3038_H
