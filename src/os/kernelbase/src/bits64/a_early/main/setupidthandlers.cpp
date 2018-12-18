#include "setupidthandlers.h"

#include <gdt/segments.h>
#include <idt/flags.h>
#include <idt/idtdescriptor.h>
#include <idt/idtregister.h>
#include <idt/macros.h>
#include <idt/types.h>
#include <ngos/linkage.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/a_early/main/asm_setupidthandlers.h>



extern u8            earlyIdtHandlerArray[IDT_EXCEPTIONS_COUNT][EARLY_IDT_HANDLER_SIZE]; // earlyIdtHandlerArray declared in main.S file
extern IdtRegister   earlyIdtRegister;                                                   // earlyIdtRegister declared in main.S file
extern IdtDescriptor idt[IDT_EXCEPTIONS_COUNT];                                          // idt declared in main.S file



NgosStatus setupIdtInterruptGate(u8 vectorNumber, void *address)
{
    EARLY_LT((" | vectorNumber = %u, address = 0x%p", vectorNumber, address));

    EARLY_ASSERT(address,                             "address is null",         NgosStatus::ASSERTION);
    EARLY_ASSERT(vectorNumber < IDT_EXCEPTIONS_COUNT, "vectorNumber is invalid", NgosStatus::ASSERTION);



    IdtDescriptor &idtEntry = idt[vectorNumber];

    idtEntry.segment      = GDT_KERNEL_CS;
    idtEntry.offsetLow    = (u64)address & 0xFFFF;
    idtEntry.offsetMiddle = ((u64)address >> 16) & 0xFFFF;
    idtEntry.offsetHigh   = (u64)address >> 32;
    idtEntry.ist          = IDT_INTERRUPT_STACK_TABLE_NOT_USED;
    idtEntry.type         = (u8)IdtType::GATE_INTERRUPT;
    idtEntry.dpl          = IDT_DESCRIPTOR_PRIVELEGE_LEVEL_0_HIGHEST;
    idtEntry.p            = IDT_ENTRY_PRESENT_YES;
    idtEntry.__pad1       = 0;
    idtEntry.__pad2       = 0;
    idtEntry.__reserved   = 0;



    return NgosStatus::OK;
}

NgosStatus setupIdtDebugTrap()
{
    EARLY_LT((""));



    u64 address = (u64)&earlyIdtDebugTrap;



    IdtDescriptor &idtEntry = idt[IDT_EXCEPTION_DEBUG];

    idtEntry.offsetLow    = address & 0xFFFF;
    idtEntry.offsetMiddle = (address >> 16) & 0xFFFF;
    idtEntry.offsetHigh   = address >> 32;



    return NgosStatus::OK;
}

NgosStatus setupIdtBreakpointTrap()
{
    EARLY_LT((""));



    u64 address = (u64)&earlyIdtBreakpointTrap;



    IdtDescriptor &idtEntry = idt[IDT_EXCEPTION_BREAKPOINT];

    idtEntry.offsetLow    = address & 0xFFFF;
    idtEntry.offsetMiddle = (address >> 16) & 0xFFFF;
    idtEntry.offsetHigh   = address >> 32;
    idtEntry.dpl          = IDT_DESCRIPTOR_PRIVELEGE_LEVEL_3_LOWEST;



    return NgosStatus::OK;
}

inline NgosStatus setupIdtRegister()
{
    EARLY_LT((""));



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lidt    %0"                    // lidt    (%rax)   # Loads the values in the source operand into the interrupt descriptor table register. (%rax) == (*earlyIdtRegister)
            :                           // Output parameters
            :                           // Input parameters
                "m" (earlyIdtRegister)  // "m" == use memory // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus setupIdtHandlers()
{
    EARLY_LT((""));



    for (i64 i = 0; i < IDT_EXCEPTIONS_COUNT; ++i)
    {
        EARLY_ASSERT_EXECUTION(setupIdtInterruptGate(i, earlyIdtHandlerArray[i]), NgosStatus::ASSERTION);
    }



    EARLY_ASSERT_EXECUTION(setupIdtDebugTrap(),      NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(setupIdtBreakpointTrap(), NgosStatus::ASSERTION);



    EARLY_ASSERT_EXECUTION(setupIdtRegister(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
