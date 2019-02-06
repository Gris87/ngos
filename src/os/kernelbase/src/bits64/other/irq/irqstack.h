#ifndef OS_COMMON_SRC_BITS64_IRQ_IRQSTACK_H
#define OS_COMMON_SRC_BITS64_IRQ_IRQSTACK_H



#include <ngos/types.h>
#include <page/macros.h>



#define IRQ_STACK_SIZE (4 * PAGE_SIZE)



union IrqStack
{
    u8 stack[IRQ_STACK_SIZE];

    struct
    {
        u8  gsBase[40];
        u64 stackCanary;
    };
};



extern IrqStack irqStack; // irqStack declared in irqstack.cpp file



#endif // OS_COMMON_SRC_BITS64_IRQ_IRQSTACK_H
