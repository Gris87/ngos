#ifndef COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExtendedCapabilityType: u16
{
    NONE = 0
};



inline const char8* enumToString(PciExtendedCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExtendedCapabilityType::NONE: return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExtendedCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_PCIEXTENDEDCAPABILITYTYPE_H
