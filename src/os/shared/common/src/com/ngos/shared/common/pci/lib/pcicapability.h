#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCICAPABILITY_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCICAPABILITY_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciCapability: u8
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
    PCI_EXPRESS                   = 16,
    MESSAGE_SIGNALED_INTERRUPTS_X = 17
};



inline const char8* enumToString(PciCapability capability) // TEST: NO
{
    // COMMON_LT((" | capability = %u", capability)); // Commented to avoid bad looking logs



    switch (capability)
    {
        case PciCapability::NONE:                          return "NONE";
        case PciCapability::POWER_MANAGEMENT_INTERFACE:    return "POWER_MANAGEMENT_INTERFACE";
        case PciCapability::ACCELERATED_GRAPHICS_PORT:     return "ACCELERATED_GRAPHICS_PORT";
        case PciCapability::VITAL_PRODUCT_DATA:            return "VITAL_PRODUCT_DATA";
        case PciCapability::SLOT_IDENTIFICATION:           return "SLOT_IDENTIFICATION";
        case PciCapability::MESSAGE_SIGNALED_INTERRUPTS:   return "MESSAGE_SIGNALED_INTERRUPTS";
        case PciCapability::HOT_SWAP:                      return "HOT_SWAP";
        case PciCapability::PCI_X:                         return "PCI_X";
        case PciCapability::HYPER_TRANSPORT:               return "HYPER_TRANSPORT";
        case PciCapability::VENDOR:                        return "VENDOR";
        case PciCapability::DEBUG_PORT:                    return "DEBUG_PORT";
        case PciCapability::CENTRAL_RESOURCE_CONTROL:      return "CENTRAL_RESOURCE_CONTROL";
        case PciCapability::HOT_PLUG:                      return "HOT_PLUG";
        case PciCapability::ACCELERATED_GRAPHICS_PORT_8X:  return "ACCELERATED_GRAPHICS_PORT_8X";
        case PciCapability::PCI_EXPRESS:                   return "PCI_EXPRESS";
        case PciCapability::MESSAGE_SIGNALED_INTERRUPTS_X: return "MESSAGE_SIGNALED_INTERRUPTS_X";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciCapability capability) // TEST: NO
{
    // COMMON_LT((" | capability = %u", capability)); // Commented to avoid bad looking logs



    static char8 res[37];

    sprintf(res, "0x%02X (%s)", (u8)capability, enumToString(capability));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCICAPABILITY_H
