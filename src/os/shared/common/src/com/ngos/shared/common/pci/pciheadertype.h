#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIHEADERTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIHEADERTYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciHeaderType: u8
{
    DEVICE            = 0,
    PCI_TO_PCI_BRIDGE = 1,
    CARDBUS_BRIDGE    = 2
};



inline const char8* enumToString(PciHeaderType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciHeaderType::DEVICE:            return "DEVICE";
        case PciHeaderType::PCI_TO_PCI_BRIDGE: return "PCI_TO_PCI_BRIDGE";
        case PciHeaderType::CARDBUS_BRIDGE:    return "CARDBUS_BRIDGE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciHeaderType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_PCI_PCIHEADERTYPE_H
