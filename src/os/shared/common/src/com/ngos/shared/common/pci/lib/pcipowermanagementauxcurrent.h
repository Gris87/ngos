#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTAUXCURRENT_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTAUXCURRENT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciPowerManagementAuxCurrent: u8
{
    SELF_POWERED = 0,
    _55_MA       = 1,
    _100_MA      = 2,
    _160_MA      = 3,
    _220_MA      = 4,
    _270_MA      = 5,
    _320_MA      = 6,
    _375_MA      = 7
};



inline const char8* enumToString(PciPowerManagementAuxCurrent current) // TEST: NO
{
    // COMMON_LT((" | current = %u", current)); // Commented to avoid bad looking logs



    switch (current)
    {
        case PciPowerManagementAuxCurrent::SELF_POWERED: return "SELF_POWERED";
        case PciPowerManagementAuxCurrent::_55_MA:       return "_55_MA";
        case PciPowerManagementAuxCurrent::_100_MA:      return "_100_MA";
        case PciPowerManagementAuxCurrent::_160_MA:      return "_160_MA";
        case PciPowerManagementAuxCurrent::_220_MA:      return "_220_MA";
        case PciPowerManagementAuxCurrent::_270_MA:      return "_270_MA";
        case PciPowerManagementAuxCurrent::_320_MA:      return "_320_MA";
        case PciPowerManagementAuxCurrent::_375_MA:      return "_375_MA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciPowerManagementAuxCurrent current) // TEST: NO
{
    // COMMON_LT((" | current = %u", current)); // Commented to avoid bad looking logs



    static char8 res[20];

    sprintf(res, "0x%02X (%s)", (u8)current, enumToString(current));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIPOWERMANAGEMENTAUXCURRENT_H
