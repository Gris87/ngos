#ifndef GDT_GDTDESCRIPTOR_H
#define GDT_GDTDESCRIPTOR_H



#include <ngos/types.h>



struct GdtDescriptor
{
    union
    {
        struct
        {
            u16 limit0;
            u16 base0;

            u8 base1;

            u8 type: 4; // Segment type // TODO: Use enum
            u8 s:    1; // Descriptor type. 0 = system, 1 = code or data // TODO: Use enum
            u8 dpl:  2; // Descriptor Privilege Level, 2 bits. Contains the ring level, 0 = highest (kernel), 3 = lowest (user applications). // TODO: Use enum
            u8 p:    1; // Present bit. This must be 1 for all valid selectors.

            u8 limit1: 4;
            u8 avl:    1; // Available for use by system software
            u8 l:      1; // 'L' bit is used to indicate x86-64 descriptor // TODO: Use enum
            u8 d:      1; // Size bit. If 0 the selector defines 16 bit protected mode. If 1 it defines 32 bit protected mode. Should be 0 if 'L' bit is set // TODO: Use enum
            u8 g:      1; // Granularity bit. If 0 the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KiB blocks (page granularity). // TODO: Use enum

            u8 base2;
        };

        struct
        {
            u32 a;
            u32 b;
        };
    };
} __attribute__((packed));



#endif // GDT_GDTDESCRIPTOR_H
