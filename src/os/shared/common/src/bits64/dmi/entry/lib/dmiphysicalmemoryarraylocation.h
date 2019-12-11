#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYLOCATION_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYLOCATION_H



#include <ngos/types.h>



enum class DmiPhysicalMemoryArrayLocation: u8
{
    NONE                      = 0,
    OTHER                     = 0x01,
    UNKNOWN                   = 0x02,
    SYSTEM_BOARD              = 0x03,
    ISA_ADDON_CARD            = 0x04,
    EISA_ADDON_CARD           = 0x05,
    PCI_ADDON_CARD            = 0x06,
    MCA_ADDON_CARD            = 0x07,
    PCMCIA_ADDON_CARD         = 0x08,
    PROPRIETARY_ADDON_CARD    = 0x09,
    NU_BUS                    = 0x0A,
    PC98_C20_ADDON_CARD       = 0xA0,
    PC98_C24_ADDON_CARD       = 0xA1,
    PC98_E_ADDON_CARD         = 0xA2,
    PC98_LOCAL_BUS_ADDON_CARD = 0xA3
};



inline const char8* enumToString(DmiPhysicalMemoryArrayLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    switch (location)
    {
        case DmiPhysicalMemoryArrayLocation::NONE:                      return "NONE";
        case DmiPhysicalMemoryArrayLocation::OTHER:                     return "OTHER";
        case DmiPhysicalMemoryArrayLocation::UNKNOWN:                   return "UNKNOWN";
        case DmiPhysicalMemoryArrayLocation::SYSTEM_BOARD:              return "SYSTEM_BOARD";
        case DmiPhysicalMemoryArrayLocation::ISA_ADDON_CARD:            return "ISA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::EISA_ADDON_CARD:           return "EISA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PCI_ADDON_CARD:            return "PCI_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::MCA_ADDON_CARD:            return "MCA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PCMCIA_ADDON_CARD:         return "PCMCIA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PROPRIETARY_ADDON_CARD:    return "PROPRIETARY_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::NU_BUS:                    return "NU_BUS";
        case DmiPhysicalMemoryArrayLocation::PC98_C20_ADDON_CARD:       return "PC98_C20_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PC98_C24_ADDON_CARD:       return "PC98_C24_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PC98_E_ADDON_CARD:         return "PC98_E_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PC98_LOCAL_BUS_ADDON_CARD: return "PC98_LOCAL_BUS_ADDON_CARD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiPhysicalMemoryArrayLocation location) // TEST: NO
{
    // COMMON_LT((" | location = %u", location)); // Commented to avoid bad looking logs



    switch (location)
    {
        case DmiPhysicalMemoryArrayLocation::NONE:                      return "NONE";
        case DmiPhysicalMemoryArrayLocation::OTHER:                     return "OTHER";
        case DmiPhysicalMemoryArrayLocation::UNKNOWN:                   return "UNKNOWN";
        case DmiPhysicalMemoryArrayLocation::SYSTEM_BOARD:              return "SYSTEM_BOARD";
        case DmiPhysicalMemoryArrayLocation::ISA_ADDON_CARD:            return "ISA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::EISA_ADDON_CARD:           return "EISA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PCI_ADDON_CARD:            return "PCI_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::MCA_ADDON_CARD:            return "MCA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PCMCIA_ADDON_CARD:         return "PCMCIA_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PROPRIETARY_ADDON_CARD:    return "PROPRIETARY_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::NU_BUS:                    return "NU_BUS";
        case DmiPhysicalMemoryArrayLocation::PC98_C20_ADDON_CARD:       return "PC98_C20_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PC98_C24_ADDON_CARD:       return "PC98_C24_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PC98_E_ADDON_CARD:         return "PC98_E_ADDON_CARD";
        case DmiPhysicalMemoryArrayLocation::PC98_LOCAL_BUS_ADDON_CARD: return "PC98_LOCAL_BUS_ADDON_CARD";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYLOCATION_H
