#ifndef GDT_GDTDESCRIPTOR_H
#define GDT_GDTDESCRIPTOR_H



#include <ngos/types.h>



struct GdtDescriptor
{
    union
    {
        struct
        {
            u32 a;
            u32 b;
        };

        struct
        {
            u16 limit0;
            u16 base0;

            u16 base1:  8;
            u16 type:   4; // Segment type
            u16 s:      1; // Descriptor type. 0 = system, 1 = code or data
            u16 dpl:    2; // Descriptor Privilege Level, 2 bits. Contains the ring level, 0 = highest (kernel), 3 = lowest (user applications).
            u16 p:      1; // Present bit. This must be 1 for all valid selectors.

            u16 limit1: 4;
            u16 avl:    1; // Available for use by systen software
            u16 l:      1; // 'L' bit is used to indicate x86-64 descriptor
            u16 d:      1; // Size bit. If 0 the selector defines 16 bit protected mode. If 1 it defines 32 bit protected mode. Should be 0 if 'L' bit is set
            u16 g:      1; // Granularity bit. If 0 the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KiB blocks (page granularity).
            u16 base2:  8;
        };
    };
} __attribute__((packed));



#endif // GDT_GDTDESCRIPTOR_H
