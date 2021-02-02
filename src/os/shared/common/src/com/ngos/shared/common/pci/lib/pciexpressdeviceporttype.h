#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICEPORTTYPE_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICEPORTTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressDevicePortType: bad_uint8
{
    PCI_EXPRESS_ENDPOINT                  = 0,
    LEGACY_PCI_EXPRESS_ENDPOINT           = 1,
    ROOT_PORT_OF_PCI_EXPRESS_ROOT_COMPLEX = 4,
    UPSTREAM_PORT_OF_PCI_EXPRESS_SWITCH   = 5,
    DOWNSTREAM_PORT_OF_PCI_EXPRESS_SWITCH = 6,
    PCI_EXPRESS_TO_PCI_BRIDGE             = 7,
    PCI_TO_PCI_EXPRESS_BRIDGE             = 8,
    ROOT_COMPLEX_INTEGRATED_ENDPOINT      = 9,
    ROOT_COMPLEX_EVENT_COLLECTOR          = 10
};



inline const char8* enumToString(PciExpressDevicePortType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case PciExpressDevicePortType::PCI_EXPRESS_ENDPOINT:                  return "PCI_EXPRESS_ENDPOINT";
        case PciExpressDevicePortType::LEGACY_PCI_EXPRESS_ENDPOINT:           return "LEGACY_PCI_EXPRESS_ENDPOINT";
        case PciExpressDevicePortType::ROOT_PORT_OF_PCI_EXPRESS_ROOT_COMPLEX: return "ROOT_PORT_OF_PCI_EXPRESS_ROOT_COMPLEX";
        case PciExpressDevicePortType::UPSTREAM_PORT_OF_PCI_EXPRESS_SWITCH:   return "UPSTREAM_PORT_OF_PCI_EXPRESS_SWITCH";
        case PciExpressDevicePortType::DOWNSTREAM_PORT_OF_PCI_EXPRESS_SWITCH: return "DOWNSTREAM_PORT_OF_PCI_EXPRESS_SWITCH";
        case PciExpressDevicePortType::PCI_EXPRESS_TO_PCI_BRIDGE:             return "PCI_EXPRESS_TO_PCI_BRIDGE";
        case PciExpressDevicePortType::PCI_TO_PCI_EXPRESS_BRIDGE:             return "PCI_TO_PCI_EXPRESS_BRIDGE";
        case PciExpressDevicePortType::ROOT_COMPLEX_INTEGRATED_ENDPOINT:      return "ROOT_COMPLEX_INTEGRATED_ENDPOINT";
        case PciExpressDevicePortType::ROOT_COMPLEX_EVENT_COLLECTOR:          return "ROOT_COMPLEX_EVENT_COLLECTOR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressDevicePortType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[45];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSDEVICEPORTTYPE_H
