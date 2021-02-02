#ifndef COM_NGOS_SHARED_COMMON_IDT_IDTGATETYPE_H
#define COM_NGOS_SHARED_COMMON_IDT_IDTGATETYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class IdtGateType: bad_uint8
{
    NONE      = 0,
    TASK      = 0x05,
    CALL      = 0x0C,
    INTERRUPT = 0x0E,
    TRAP      = 0x0F
};



inline const char8* enumToString(IdtGateType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case IdtGateType::NONE:      return "NONE";
        case IdtGateType::TASK:      return "TASK";
        case IdtGateType::CALL:      return "CALL";
        case IdtGateType::INTERRUPT: return "INTERRUPT";
        case IdtGateType::TRAP:      return "TRAP";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(IdtGateType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_IDT_IDTGATETYPE_H
