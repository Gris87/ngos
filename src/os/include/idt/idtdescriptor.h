#ifndef IDT_IDTDESCRIPTOR_H
#define IDT_IDTDESCRIPTOR_H



#include <ngos/types.h>



struct IdtDescriptor
{
    u16 offsetLow;
    u16 segment;

    u16 ist:    3;
    u16 __pad1: 5;
    u16 type:   4;
    u16 __pad2: 1;
    u16 dpl:    2;
    u16 p:      1;

    u16 offsetMiddle;
    u32 offsetHigh;
    u32 __reserved;
} __attribute__((packed));



#endif // IDT_IDTDESCRIPTOR_H
