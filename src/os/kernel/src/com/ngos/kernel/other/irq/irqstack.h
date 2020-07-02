#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IRQ_IRQSTACK_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IRQ_IRQSTACK_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/page/macros.h>



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



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IRQ_IRQSTACK_H
