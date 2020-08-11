// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCISUBCLASS06_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCISUBCLASS06_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pciinterface0604.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pciinterface0608.h>
#include <com/ngos/shared/common/pci/database/generated/baseclass06/pciinterface0609.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubClass06: u8
{
    SUB_CLASS_00 = 0x00,
    SUB_CLASS_01 = 0x01,
    SUB_CLASS_02 = 0x02,
    SUB_CLASS_03 = 0x03,
    SUB_CLASS_04 = 0x04,
    SUB_CLASS_05 = 0x05,
    SUB_CLASS_06 = 0x06,
    SUB_CLASS_07 = 0x07,
    SUB_CLASS_08 = 0x08,
    SUB_CLASS_09 = 0x09,
    SUB_CLASS_0A = 0x0A,
    SUB_CLASS_80 = 0x80,
};



inline const char8* enumToString(PciSubClass06 class06) // TEST: NO
{
    // COMMON_LT((" | class06 = %u", class06)); // Commented to avoid bad looking logs



    switch (class06)
    {
        case PciSubClass06::SUB_CLASS_00: return "SUB_CLASS_00";
        case PciSubClass06::SUB_CLASS_01: return "SUB_CLASS_01";
        case PciSubClass06::SUB_CLASS_02: return "SUB_CLASS_02";
        case PciSubClass06::SUB_CLASS_03: return "SUB_CLASS_03";
        case PciSubClass06::SUB_CLASS_04: return "SUB_CLASS_04";
        case PciSubClass06::SUB_CLASS_05: return "SUB_CLASS_05";
        case PciSubClass06::SUB_CLASS_06: return "SUB_CLASS_06";
        case PciSubClass06::SUB_CLASS_07: return "SUB_CLASS_07";
        case PciSubClass06::SUB_CLASS_08: return "SUB_CLASS_08";
        case PciSubClass06::SUB_CLASS_09: return "SUB_CLASS_09";
        case PciSubClass06::SUB_CLASS_0A: return "SUB_CLASS_0A";
        case PciSubClass06::SUB_CLASS_80: return "SUB_CLASS_80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubClass06 class06) // TEST: NO
{
    // COMMON_LT((" | class06 = %u", class06)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)class06, enumToString(class06));

    return res;
}



inline const char8* enumToHumanString(PciSubClass06 class06, u8 interfaceId) // TEST: NO
{
    // COMMON_LT((" | class06 = %u, interfaceId = %u", class06, interfaceId)); // Commented to avoid bad looking logs



    switch (class06)
    {
        case PciSubClass06::SUB_CLASS_00: return "Host bridge";
        case PciSubClass06::SUB_CLASS_01: return "ISA bridge";
        case PciSubClass06::SUB_CLASS_02: return "EISA bridge";
        case PciSubClass06::SUB_CLASS_03: return "MicroChannel bridge";
        case PciSubClass06::SUB_CLASS_04: return enumToHumanString((PciInterface0604)interfaceId);
        case PciSubClass06::SUB_CLASS_05: return "PCMCIA bridge";
        case PciSubClass06::SUB_CLASS_06: return "NuBus bridge";
        case PciSubClass06::SUB_CLASS_07: return "CardBus bridge";
        case PciSubClass06::SUB_CLASS_08: return enumToHumanString((PciInterface0608)interfaceId);
        case PciSubClass06::SUB_CLASS_09: return enumToHumanString((PciInterface0609)interfaceId);
        case PciSubClass06::SUB_CLASS_0A: return "InfiniBand to PCI host bridge";
        case PciSubClass06::SUB_CLASS_80: return "Bridge";

        default: return "Bridge";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_BASECLASS06_PCISUBCLASS06_H
