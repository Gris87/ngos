#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERCONTROLLERCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERCONTROLLERCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressPowerControllerControl: bad_uint8
{
    ON  = 0,
    OFF = 1
};



inline const char8* enumToString(PciExpressPowerControllerControl control) // TEST: NO
{
    // COMMON_LT((" | control = %u", control)); // Commented to avoid bad looking logs



    switch (control)
    {
        case PciExpressPowerControllerControl::ON:  return "ON";
        case PciExpressPowerControllerControl::OFF: return "OFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressPowerControllerControl control) // TEST: NO
{
    // COMMON_LT((" | control = %u", control)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (bad_uint8)control, enumToString(control));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSPOWERCONTROLLERCONTROL_H
