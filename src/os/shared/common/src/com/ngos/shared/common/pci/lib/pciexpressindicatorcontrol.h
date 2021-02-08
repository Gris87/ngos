#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSINDICATORCONTROL_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSINDICATORCONTROL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciExpressIndicatorControl: u8
{
    NONE  = 0,
    ON    = 1,
    BLINK = 2,
    OFF   = 3
};



inline const char8* enumToString(PciExpressIndicatorControl control) // TEST: NO
{
    // COMMON_LT((" | control = %u", control)); // Commented to avoid bad looking logs



    switch (control)
    {
        case PciExpressIndicatorControl::NONE:  return "NONE";
        case PciExpressIndicatorControl::ON:    return "ON";
        case PciExpressIndicatorControl::BLINK: return "BLINK";
        case PciExpressIndicatorControl::OFF:   return "OFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciExpressIndicatorControl control) // TEST: NO
{
    // COMMON_LT((" | control = %u", control)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)control, enumToString(control));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSINDICATORCONTROL_H
