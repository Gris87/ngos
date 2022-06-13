#ifndef COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTSTATUSFLAGS_H
#define COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTSTATUSFLAGS_H



#include <com/ngos/shared/common/bits/flags.h>
#include <com/ngos/shared/common/bits/macros.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 pci_express_slot_status_flags;

enum class PciExpressSlotStatusFlag: pci_express_slot_status_flags
{
    NONE                                = 0,
    ATTENTION_BUTTON_PRESSED            = BIT_0,
    POWER_FAULT_DETECTED                = BIT_1,
    MRL_SENSOR_CHANGED                  = BIT_2,
    PRESENCE_DETECT_CHANGED             = BIT_3,
    COMMAND_COMPLETED                   = BIT_4,
    MRL_SENSOR_OPENNED                  = BIT_5,
    PRESENCE_DETECT                     = BIT_6,
    ELECTROMECHANICAL_INTERLOCK_ENGAGED = BIT_7,
    DATA_LINK_LAYER_STATE_CHANGED       = BIT_8
};

DEFINE_FLAGS(PciExpressSlotStatusFlags, pci_express_slot_status_flags); // TEST: NO



inline const char8* flagToString(PciExpressSlotStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case PciExpressSlotStatusFlag::NONE:                                return "NONE";
        case PciExpressSlotStatusFlag::ATTENTION_BUTTON_PRESSED:            return "ATTENTION_BUTTON_PRESSED";
        case PciExpressSlotStatusFlag::POWER_FAULT_DETECTED:                return "POWER_FAULT_DETECTED";
        case PciExpressSlotStatusFlag::MRL_SENSOR_CHANGED:                  return "MRL_SENSOR_CHANGED";
        case PciExpressSlotStatusFlag::PRESENCE_DETECT_CHANGED:             return "PRESENCE_DETECT_CHANGED";
        case PciExpressSlotStatusFlag::COMMAND_COMPLETED:                   return "COMMAND_COMPLETED";
        case PciExpressSlotStatusFlag::MRL_SENSOR_OPENNED:                  return "MRL_SENSOR_OPENNED";
        case PciExpressSlotStatusFlag::PRESENCE_DETECT:                     return "PRESENCE_DETECT";
        case PciExpressSlotStatusFlag::ELECTROMECHANICAL_INTERLOCK_ENGAGED: return "ELECTROMECHANICAL_INTERLOCK_ENGAGED";
        case PciExpressSlotStatusFlag::DATA_LINK_LAYER_STATE_CHANGED:       return "DATA_LINK_LAYER_STATE_CHANGED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(PciExpressSlotStatusFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[45];

    sprintf(res, "0x%04X (%s)", (pci_express_slot_status_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const PciExpressSlotStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[239];

    FLAGS_TO_STRING(res, flags.flags, PciExpressSlotStatusFlag);

    return res;
}



inline const char8* flagsToFullString(const PciExpressSlotStatusFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[248];

    FLAGS_TO_FULL_STRING(res, flags.flags, PciExpressSlotStatusFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_PCI_LIB_PCIEXPRESSSLOTSTATUSFLAGS_H
