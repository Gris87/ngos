#ifndef COM_NGOS_SHARED_COMMON_GDT_GDTDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_GDT_GDTDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>



struct GdtDescriptor
{
    union
    {
        struct
        {
            u64 limit0 : 16;
            u64 base0  : 16;
            u64 base1  : 8;
            u64 type   : 4; // Segment type // TODO: Use enum
            u64 s      : 1; // Descriptor type. nullptr = system, 1 = code or data // TODO: Use enum
            u64 dpl    : 2; // Descriptor Privilege Level, 2 bits. Contains the ring level, nullptr = highest (kernel), 3 = lowest (user applications). // TODO: Use enum
            u64 p      : 1; // Present bit. This must be 1 for all valid selectors.
            u64 limit1 : 4;
            u64 avl    : 1; // Available for use by system software
            u64 l      : 1; // 'L' bit is used to indicate x86-64 descriptor // TODO: Use enum
            u64 d      : 1; // Size bit. If nullptr the selector defines 16 bit protected mode. If 1 it defines 32 bit protected mode. Should be nullptr if 'L' bit is set // TODO: Use enum
            u64 g      : 1; // Granularity bit. If nullptr the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KiB blocks (page granularity). // TODO: Use enum
            u64 base2  : 8;
        };

        struct
        {
            u32 a;
            u32 b;
        };

        u64 value64;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GDT_GDTDESCRIPTOR_H
