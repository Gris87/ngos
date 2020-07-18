#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIREGISTER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIREGISTER_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciRegister: u8
{
    VENDOR_ID           = 0x00,
    DEVICE_ID           = 0x02,
    COMMAND             = 0x04,
    PRIMARY_STATUS      = 0x06,
    REVISION_ID         = 0x08,
    CLASS_CODE          = 0x09,
    CACHE_LINE_SIZE     = 0x0C,
    LATENCY_TIMER       = 0x0D,
    HEADER_TYPE         = 0x0E,
    BUILT_IN_SELF_TEST  = 0x0F,
    BASE_ADDRESS        = 0x10,
    CARDBUS_CIS         = 0x28,
    SUBSYSTEM_VENDOR_ID = 0x2C,
    SUBSYSTEM_ID        = 0x2E,
    EXPANSION_ROM_BASE  = 0x30,
    CAPABILITY_POINTER  = 0x34,
    INTERRUPT_LINE      = 0x3C,
    INTERRUPT_PIN       = 0x3D,
    MAX_GRANT           = 0x3E,
    MAX_LATENCY         = 0x3F
};



inline const char8* enumToString(PciRegister reg) // TEST: NO
{
    // COMMON_LT((" | reg = %u", reg)); // Commented to avoid bad looking logs



    switch (reg)
    {
        case PciRegister::VENDOR_ID:           return "VENDOR_ID";
        case PciRegister::DEVICE_ID:           return "DEVICE_ID";
        case PciRegister::COMMAND:             return "COMMAND";
        case PciRegister::PRIMARY_STATUS:      return "PRIMARY_STATUS";
        case PciRegister::REVISION_ID:         return "REVISION_ID";
        case PciRegister::CLASS_CODE:          return "CLASS_CODE";
        case PciRegister::CACHE_LINE_SIZE:     return "CACHE_LINE_SIZE";
        case PciRegister::LATENCY_TIMER:       return "LATENCY_TIMER";
        case PciRegister::HEADER_TYPE:         return "HEADER_TYPE";
        case PciRegister::BUILT_IN_SELF_TEST:  return "BUILT_IN_SELF_TEST";
        case PciRegister::BASE_ADDRESS:        return "BASE_ADDRESS";
        case PciRegister::CARDBUS_CIS:         return "CARDBUS_CIS";
        case PciRegister::SUBSYSTEM_VENDOR_ID: return "SUBSYSTEM_VENDOR_ID";
        case PciRegister::SUBSYSTEM_ID:        return "SUBSYSTEM_ID";
        case PciRegister::EXPANSION_ROM_BASE:  return "EXPANSION_ROM_BASE";
        case PciRegister::CAPABILITY_POINTER:  return "CAPABILITY_POINTER";
        case PciRegister::INTERRUPT_LINE:      return "INTERRUPT_LINE";
        case PciRegister::INTERRUPT_PIN:       return "INTERRUPT_PIN";
        case PciRegister::MAX_GRANT:           return "MAX_GRANT";
        case PciRegister::MAX_LATENCY:         return "MAX_LATENCY";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciRegister reg) // TEST: NO
{
    // COMMON_LT((" | reg = %u", reg)); // Commented to avoid bad looking logs



    static char8 res[27];

    sprintf(res, "0x%02X (%s)", reg, enumToString(reg));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIREGISTER_H
