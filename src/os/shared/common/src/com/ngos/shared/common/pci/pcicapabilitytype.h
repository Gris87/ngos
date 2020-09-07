#ifndef COM_NGOS_SHARED_COMMON_PCI_PCICAPABILITYTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_PCICAPABILITYTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciCapabilityType: u8
{
    NONE                          = 0,
    POWER_MANAGEMENT_INTERFACE    = 1,
    ACCELERATED_GRAPHICS_PORT     = 2,
    VITAL_PRODUCT_DATA            = 3,
    SLOT_IDENTIFICATION           = 4,
    MESSAGE_SIGNALED_INTERRUPTS   = 5,
    HOT_SWAP                      = 6,
    PCI_X                         = 7,
    HYPER_TRANSPORT               = 8,
    VENDOR                        = 9,
    DEBUG_PORT                    = 10,
    CENTRAL_RESOURCE_CONTROL      = 11,
    HOT_PLUG                      = 12,
    ACCELERATED_GRAPHICS_PORT_8X  = 14,
    SECURE_DEVICE                 = 15,
    PCI_EXPRESS                   = 16,
    MESSAGE_SIGNALED_INTERRUPTS_X = 17
};



inline const char8* enumToString(PciCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciCapabilityType::NONE:                          return "NONE";
        case PciCapabilityType::POWER_MANAGEMENT_INTERFACE:    return "POWER_MANAGEMENT_INTERFACE";
        case PciCapabilityType::ACCELERATED_GRAPHICS_PORT:     return "ACCELERATED_GRAPHICS_PORT";
        case PciCapabilityType::VITAL_PRODUCT_DATA:            return "VITAL_PRODUCT_DATA";
        case PciCapabilityType::SLOT_IDENTIFICATION:           return "SLOT_IDENTIFICATION";
        case PciCapabilityType::MESSAGE_SIGNALED_INTERRUPTS:   return "MESSAGE_SIGNALED_INTERRUPTS";
        case PciCapabilityType::HOT_SWAP:                      return "HOT_SWAP";
        case PciCapabilityType::PCI_X:                         return "PCI_X";
        case PciCapabilityType::HYPER_TRANSPORT:               return "HYPER_TRANSPORT";
        case PciCapabilityType::VENDOR:                        return "VENDOR";
        case PciCapabilityType::DEBUG_PORT:                    return "DEBUG_PORT";
        case PciCapabilityType::CENTRAL_RESOURCE_CONTROL:      return "CENTRAL_RESOURCE_CONTROL";
        case PciCapabilityType::HOT_PLUG:                      return "HOT_PLUG";
        case PciCapabilityType::ACCELERATED_GRAPHICS_PORT_8X:  return "ACCELERATED_GRAPHICS_PORT_8X";
        case PciCapabilityType::SECURE_DEVICE:                 return "SECURE_DEVICE";
        case PciCapabilityType::PCI_EXPRESS:                   return "PCI_EXPRESS";
        case PciCapabilityType::MESSAGE_SIGNALED_INTERRUPTS_X: return "MESSAGE_SIGNALED_INTERRUPTS_X";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[37];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_PCICAPABILITYTYPE_H
