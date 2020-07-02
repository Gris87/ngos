#ifndef IDT_IDTDESCRIPTOR_H
#define IDT_IDTDESCRIPTOR_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct IdtDescriptor
{
    u16 offsetLow;
    u16 segment;

    u8 ist;

    union
    {
        struct
        {
            u8 gateType:   4; // TODO: Use enum IdtGateType
            u8 __reserved: 1;
            u8 dpl:        2;
            u8 p:          1;
        };

        u8 type;
    };

    u16 offsetMiddle;
    u32 offsetHigh;
    u32 __reserved2;
} __attribute__((packed));



#endif // IDT_IDTDESCRIPTOR_H
