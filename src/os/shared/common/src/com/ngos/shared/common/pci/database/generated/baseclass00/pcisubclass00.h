// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCISUBCLASS00_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCISUBCLASS00_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass00/pciinterface0000.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass00/pciinterface0001.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass00: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01
};



inline const char8* enumToString(PciSubClass00 class00) // TEST: NO
{
    // COMMON_LT((" | class00 = %u", class00)); // Commented to avoid bad looking logs



    switch (class00)
    {
        case PciSubClass00::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass00::SUB_CLASS_01: return "SUB_CLASS_01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass00 class00) // TEST: NO
{
    // COMMON_LT((" | class00 = %u", class00)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class00, enumToString(class00));

    return res;
}



inline const char8* enumToHumanString(PciSubClass00 class00, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class00 = %u, interfaceId = %u", class00, interfaceId)); // Commented to avoid bad looking logs



    switch (class00)
    {
        case PciSubClass00::SUB_CLASS_00: return enumToHumanString((PciInterface0000)interfaceId);
        case PciSubClass00::SUB_CLASS_01: return enumToHumanString((PciInterface0001)interfaceId);

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS00_PCISUBCLASS00_H
