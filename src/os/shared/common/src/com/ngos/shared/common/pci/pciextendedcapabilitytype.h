#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExtendedCapabilityType: u16
{
    NONE                                 = 0,
    ADVANCED_ERROR_REPORTING             = 1,
    LINK_CONTROL                         = 2,
    LINK_DECLARATION                     = 3,
    SERIAL_NUMBER                        = 4,
    POWER_BUDGETING                      = 5,
    ACS_EXTENDED                         = 6,
    LATENCE_TOLERANCE_REPORTING          = 7,
    ARI_CAPABILITY                       = 8,
    RCRB_HEADER                          = 9,
    VENDOR_SPECIFIC                      = 10,
    DYNAMIC_POWER_ALLOCATION             = 11,
    EVENT_COLLECTOR_ENDPOINT_ASSOCIATION = 12,
    VIRTUAL_CHANNEL                      = 13,
    MULTI_FUNCTION_VIRTUAL_CHANNEL       = 14,
    MULTICAST                            = 15,
    RESIZABLE_BAR                        = 16,
    TPH                                  = 17,
    SECONDARY_PCIE                       = 18
};



inline const char8* enumToString(PciExtendedCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExtendedCapabilityType::NONE:                                 return "NONE";
        case PciExtendedCapabilityType::ADVANCED_ERROR_REPORTING:             return "ADVANCED_ERROR_REPORTING";
        case PciExtendedCapabilityType::LINK_CONTROL:                         return "LINK_CONTROL";
        case PciExtendedCapabilityType::LINK_DECLARATION:                     return "LINK_DECLARATION";
        case PciExtendedCapabilityType::SERIAL_NUMBER:                        return "SERIAL_NUMBER";
        case PciExtendedCapabilityType::POWER_BUDGETING:                      return "POWER_BUDGETING";
        case PciExtendedCapabilityType::ACS_EXTENDED:                         return "ACS_EXTENDED";
        case PciExtendedCapabilityType::LATENCE_TOLERANCE_REPORTING:          return "LATENCE_TOLERANCE_REPORTING";
        case PciExtendedCapabilityType::ARI_CAPABILITY:                       return "ARI_CAPABILITY";
        case PciExtendedCapabilityType::RCRB_HEADER:                          return "RCRB_HEADER";
        case PciExtendedCapabilityType::VENDOR_SPECIFIC:                      return "VENDOR_SPECIFIC";
        case PciExtendedCapabilityType::DYNAMIC_POWER_ALLOCATION:             return "DYNAMIC_POWER_ALLOCATION";
        case PciExtendedCapabilityType::EVENT_COLLECTOR_ENDPOINT_ASSOCIATION: return "EVENT_COLLECTOR_ENDPOINT_ASSOCIATION";
        case PciExtendedCapabilityType::VIRTUAL_CHANNEL:                      return "VIRTUAL_CHANNEL";
        case PciExtendedCapabilityType::MULTI_FUNCTION_VIRTUAL_CHANNEL:       return "MULTI_FUNCTION_VIRTUAL_CHANNEL";
        case PciExtendedCapabilityType::MULTICAST:                            return "MULTICAST";
        case PciExtendedCapabilityType::RESIZABLE_BAR:                        return "RESIZABLE_BAR";
        case PciExtendedCapabilityType::TPH:                                  return "TPH";
        case PciExtendedCapabilityType::SECONDARY_PCIE:                       return "SECONDARY_PCIE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExtendedCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[46];

    sprintf(res, "0x%04X (%s)", (u16)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H
