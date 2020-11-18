#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExtendedCapabilityType: u16
{
    NONE                                 = 0,
    ADVANCED_ERROR_REPORTING             = 1,
    VIRTUAL_CHANNEL                      = 2,
    DEVICE_SERIAL_NUMBER                 = 3,
    POWER_BUDGETING                      = 4,
    ROOT_COMPLEX_LINK_DECLARATION        = 5,
    ROOT_COMPLEX_INTERNAL_LINK_CONTROL   = 6,
    EVENT_COLLECTOR_ENDPOINT_ASSOCIATION = 7,
    MULTI_FUNCTION_VIRTUAL_CHANNEL       = 8,
    VIRTUAL_CHANNEL_MFVC                 = 9,
    RCRB_HEADER                          = 10,
    VENDOR_SPECIFIC                      = 11,
    ACCESS_CONTROL_SERVICES              = 13,
    ARI_CAPABILITY                       = 14,
    MULTICAST                            = 18,
    RESIZABLE_BAR                        = 21,
    DYNAMIC_POWER_ALLOCATION             = 22,
    TPH                                  = 23,
    LATENCE_TOLERANCE_REPORTING          = 24,
    SECONDARY_PCIE                       = 25,
    L1_PM_SUBSTATES                      = 30,
    PHYSICAL_LAYER_16_0                  = 38,
    PHYSICAL_LAYER_32_0                  = 42
};



inline const char8* enumToString(PciExtendedCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExtendedCapabilityType::NONE:                                 return "NONE";
        case PciExtendedCapabilityType::ADVANCED_ERROR_REPORTING:             return "ADVANCED_ERROR_REPORTING";
        case PciExtendedCapabilityType::VIRTUAL_CHANNEL:                      return "VIRTUAL_CHANNEL";
        case PciExtendedCapabilityType::DEVICE_SERIAL_NUMBER:                 return "DEVICE_SERIAL_NUMBER";
        case PciExtendedCapabilityType::POWER_BUDGETING:                      return "POWER_BUDGETING";
        case PciExtendedCapabilityType::ROOT_COMPLEX_LINK_DECLARATION:        return "ROOT_COMPLEX_LINK_DECLARATION";
        case PciExtendedCapabilityType::ROOT_COMPLEX_INTERNAL_LINK_CONTROL:   return "ROOT_COMPLEX_INTERNAL_LINK_CONTROL";
        case PciExtendedCapabilityType::EVENT_COLLECTOR_ENDPOINT_ASSOCIATION: return "EVENT_COLLECTOR_ENDPOINT_ASSOCIATION";
        case PciExtendedCapabilityType::MULTI_FUNCTION_VIRTUAL_CHANNEL:       return "MULTI_FUNCTION_VIRTUAL_CHANNEL";
        case PciExtendedCapabilityType::VIRTUAL_CHANNEL_MFVC:                 return "VIRTUAL_CHANNEL_MFVC";
        case PciExtendedCapabilityType::RCRB_HEADER:                          return "RCRB_HEADER";
        case PciExtendedCapabilityType::VENDOR_SPECIFIC:                      return "VENDOR_SPECIFIC";
        case PciExtendedCapabilityType::ACCESS_CONTROL_SERVICES:              return "ACCESS_CONTROL_SERVICES";
        case PciExtendedCapabilityType::ARI_CAPABILITY:                       return "ARI_CAPABILITY";
        case PciExtendedCapabilityType::MULTICAST:                            return "MULTICAST";
        case PciExtendedCapabilityType::RESIZABLE_BAR:                        return "RESIZABLE_BAR";
        case PciExtendedCapabilityType::DYNAMIC_POWER_ALLOCATION:             return "DYNAMIC_POWER_ALLOCATION";
        case PciExtendedCapabilityType::TPH:                                  return "TPH";
        case PciExtendedCapabilityType::LATENCE_TOLERANCE_REPORTING:          return "LATENCE_TOLERANCE_REPORTING";
        case PciExtendedCapabilityType::SECONDARY_PCIE:                       return "SECONDARY_PCIE";
        case PciExtendedCapabilityType::L1_PM_SUBSTATES:                      return "L1_PM_SUBSTATES";
        case PciExtendedCapabilityType::PHYSICAL_LAYER_16_0:                  return "PHYSICAL_LAYER_16_0";
        case PciExtendedCapabilityType::PHYSICAL_LAYER_32_0:                  return "PHYSICAL_LAYER_32_0";

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
