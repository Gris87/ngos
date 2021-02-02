// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002675F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002675F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002675F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_148C6510 = 0x148C6510,
    SUBDEVICE_148C6530 = 0x148C6530,
    SUBDEVICE_148C7510 = 0x148C7510,
    SUBDEVICE_15457570 = 0x15457570,
    SUBDEVICE_174B6510 = 0x174B6510,
    SUBDEVICE_174B7510 = 0x174B7510,
    SUBDEVICE_174B8510 = 0x174B8510,
    SUBDEVICE_17872012 = 0x17872012,
    SUBDEVICE_17872314 = 0x17872314
};



inline const char8* enumToString(PciSubDevice1002675F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002675F::NONE:               return "NONE";
        case PciSubDevice1002675F::SUBDEVICE_148C6510: return "SUBDEVICE_148C6510";
        case PciSubDevice1002675F::SUBDEVICE_148C6530: return "SUBDEVICE_148C6530";
        case PciSubDevice1002675F::SUBDEVICE_148C7510: return "SUBDEVICE_148C7510";
        case PciSubDevice1002675F::SUBDEVICE_15457570: return "SUBDEVICE_15457570";
        case PciSubDevice1002675F::SUBDEVICE_174B6510: return "SUBDEVICE_174B6510";
        case PciSubDevice1002675F::SUBDEVICE_174B7510: return "SUBDEVICE_174B7510";
        case PciSubDevice1002675F::SUBDEVICE_174B8510: return "SUBDEVICE_174B8510";
        case PciSubDevice1002675F::SUBDEVICE_17872012: return "SUBDEVICE_17872012";
        case PciSubDevice1002675F::SUBDEVICE_17872314: return "SUBDEVICE_17872314";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002675F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002675F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002675F::SUBDEVICE_148C6510: return "Radeon HD 6510";
        case PciSubDevice1002675F::SUBDEVICE_148C6530: return "Radeon HD 6530";
        case PciSubDevice1002675F::SUBDEVICE_148C7510: return "Radeon HD 7510";
        case PciSubDevice1002675F::SUBDEVICE_15457570: return "Radeon HD 7570";
        case PciSubDevice1002675F::SUBDEVICE_174B6510: return "Radeon HD 6510";
        case PciSubDevice1002675F::SUBDEVICE_174B7510: return "Radeon HD 7510";
        case PciSubDevice1002675F::SUBDEVICE_174B8510: return "Radeon HD 8510";
        case PciSubDevice1002675F::SUBDEVICE_17872012: return "Radeon HD 5570 2GB GDDR3";
        case PciSubDevice1002675F::SUBDEVICE_17872314: return "Radeon HD 5570 1GB DDR2/GDDR3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002675F_H
