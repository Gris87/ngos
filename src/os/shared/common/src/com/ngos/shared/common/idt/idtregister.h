#ifndef IDT_IDTREGISTER_H
#define IDT_IDTREGISTER_H



#include <ngos/types.h>



struct IdtRegister
{
    u16   size;
    void *address;
} __attribute__((packed));



#endif // IDT_IDTREGISTER_H
