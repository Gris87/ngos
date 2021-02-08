#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTCAPABILITYTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTCAPABILITYTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciHyperTransportCapabilityType: u8
{
    SLAVE_OR_PRIMARY_INTERFACE  = 0,
    HOST_OR_SECONDARY_INTERFACE = 1
};



inline const char8* enumToString(PciHyperTransportCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciHyperTransportCapabilityType::SLAVE_OR_PRIMARY_INTERFACE:  return "SLAVE_OR_PRIMARY_INTERFACE";
        case PciHyperTransportCapabilityType::HOST_OR_SECONDARY_INTERFACE: return "HOST_OR_SECONDARY_INTERFACE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciHyperTransportCapabilityType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[35];

    sprintf(res, "0x%02X (%s)", (u8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIHYPERTRANSPORTCAPABILITYTYPE_H
