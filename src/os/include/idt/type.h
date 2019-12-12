#ifndef IDT_TYPE_H
#define IDT_TYPE_H



#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class IdtType: u8
{
    NONE           = 0,
    GATE_TASK      = 0x05,
    GATE_CALL      = 0x0C,
    GATE_INTERRUPT = 0x0E,
    GATE_TRAP      = 0x0F
};



inline const char8* enumToString(IdtType type) // TEST: NO
{
    switch (type)
    {
        case IdtType::NONE:           return "NONE";
        case IdtType::GATE_TASK:      return "GATE_TASK";
        case IdtType::GATE_CALL:      return "GATE_CALL";
        case IdtType::GATE_INTERRUPT: return "GATE_INTERRUPT";
        case IdtType::GATE_TRAP:      return "GATE_TRAP";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(IdtType type) // TEST: NO
{
    static char8 res[22];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // IDT_TYPE_H
