// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS12_PCISUBCLASS12_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS12_PCISUBCLASS12_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass12: u8 // Ignore CppEnumVerifier
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01
};



inline const char8* enumToString(PciSubClass12 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass12::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass12::SUB_CLASS_01: return "SUB_CLASS_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass12 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)subClass, enumToString(subClass));

    return res;
}



inline const char8* enumToHumanString(PciSubClass12 subClass) // TEST: NO
{
    // COMMON_LT((" | subClass = %u", subClass)); // Commented to avoid bad looking logs



    switch (subClass)
    {
        case PciSubClass12::SUB_CLASS_00: return "Processing accelerators - Processing accelerators";
        case PciSubClass12::SUB_CLASS_01: return "Processing accelerators - SNIA Smart Data Accelerator Interface (SDXI) controller";

        default: return "Processing accelerators";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS12_PCISUBCLASS12_H
