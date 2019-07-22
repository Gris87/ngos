#ifndef IDT_TYPE_H
#define IDT_TYPE_H



#include <ngos/types.h>



enum class IdtType: u8
{
    GATE_TASK      = 0x5,
    GATE_CALL      = 0xC,
    GATE_INTERRUPT = 0xE,
    GATE_TRAP      = 0xF
};



inline const char* idtTypeToString(IdtType type) // TEST: NO
{
    switch (type)
    {
        case IdtType::GATE_TASK:      return "GATE_TASK";
        case IdtType::GATE_CALL:      return "GATE_CALL";
        case IdtType::GATE_INTERRUPT: return "GATE_INTERRUPT";
        case IdtType::GATE_TRAP:      return "GATE_TRAP";

        default: return "UNKNOWN";
    }
}



#endif // IDT_TYPE_H
