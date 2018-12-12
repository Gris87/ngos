#ifndef IDT_IDTDESCRIPTOR_H
#define IDT_IDTDESCRIPTOR_H



#include <ngos/types.h>



struct IdtDescriptor
{
    u16 offsetLow;
    u16 segment;

    u16 ist:    3,
        __pad1: 5,
        type:   4,
        __pad2: 1,
        dpl:    2,
        p:      1;

    u16 offsetMiddle;
    u32 offsetHigh;
    u32 __reserved;
} __attribute__((packed));



#endif // IDT_IDTDESCRIPTOR_H
