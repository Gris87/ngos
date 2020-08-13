// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0107_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0107_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciInterface0107: u8 // Ignore CppEnumVerifier
{
    NONE         = 0,
    INTERFACE_01 = 0x01
};



inline const char8* enumToString(PciInterface0107 interface0107) // TEST: NO
{
    // COMMON_LT((" | interface0107 = %u", interface0107)); // Commented to avoid bad looking logs



    switch (interface0107)
    {
        case PciInterface0107::NONE:         return "NONE";
        case PciInterface0107::INTERFACE_01: return "INTERFACE_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciInterface0107 interface0107) // TEST: NO
{
    // COMMON_LT((" | interface0107 = %u", interface0107)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)interface0107, enumToString(interface0107));

    return res;
}



inline const char8* enumToHumanString(PciInterface0107 interface0107) // TEST: NO
{
    // COMMON_LT((" | interface0107 = %u", interface0107)); // Commented to avoid bad looking logs



    switch (interface0107)
    {
        case PciInterface0107::INTERFACE_01: return "Mass storage controller - Serial Attached SCSI controller - Serial Storage Bus";

        default: return "Mass storage controller - Serial Attached SCSI controller";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS01_PCIINTERFACE0107_H
