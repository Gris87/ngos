#ifndef COM_NGOS_SHARED_COMMON_GDT_GDTDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_GDT_GDTDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>



struct GdtDescriptor
{
    union
    {
        struct
        {
            bad_uint64 limit0 : 16;
            bad_uint64 base0  : 16;
            bad_uint64 base1  : 8;
            bad_uint64 type   : 4; // Segment type // TODO: Use enum
            bad_uint64 s      : 1; // Descriptor type. 0 = system, 1 = code or data // TODO: Use enum
            bad_uint64 dpl    : 2; // Descriptor Privilege Level, 2 bits. Contains the ring level, 0 = highest (kernel), 3 = lowest (user applications). // TODO: Use enum
            bad_uint64 p      : 1; // Present bit. This must be 1 for all valid selectors.
            bad_uint64 limit1 : 4;
            bad_uint64 avl    : 1; // Available for use by system software
            bad_uint64 l      : 1; // 'L' bit is used to indicate x86-64 descriptor // TODO: Use enum
            bad_uint64 d      : 1; // Size bit. If 0 the selector defines 16 bit protected mode. If 1 it defines 32 bit protected mode. Should be 0 if 'L' bit is set // TODO: Use enum
            bad_uint64 g      : 1; // Granularity bit. If 0 the limit is in 1 B blocks (byte granularity), if 1 the limit is in 4 KiB blocks (page granularity). // TODO: Use enum
            bad_uint64 base2  : 8;
        };

        struct
        {
            bad_uint32 a;
            bad_uint32 b;
        };

        bad_uint64 value64;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GDT_GDTDESCRIPTOR_H
