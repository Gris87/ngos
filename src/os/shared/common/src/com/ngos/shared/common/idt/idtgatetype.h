#ifndef IDT_IDTGATETYPE_H
#define IDT_IDTGATETYPE_H



#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class IdtGateType: u8
{
    NONE      = 0,
    TASK      = 0x05,
    CALL      = 0x0C,
    INTERRUPT = 0x0E,
    TRAP      = 0x0F
};



inline const char8* enumToString(IdtGateType type) // TEST: NO
{
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
    static char8 res[17];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // IDT_IDTGATETYPE_H
