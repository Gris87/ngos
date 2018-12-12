#ifndef IDT_TYPES_H
#define IDT_TYPES_H



#include <ngos/types.h>



enum class IdtType: u8
{
    GATE_TASK      = 0x5,
    GATE_CALL      = 0xC,
    GATE_INTERRUPT = 0xE,
    GATE_TRAP      = 0xF
};



#endif // IDT_TYPES_H
