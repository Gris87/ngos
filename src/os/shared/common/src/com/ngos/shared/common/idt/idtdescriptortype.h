#ifndef COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTORTYPE_H
#define COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTORTYPE_H



#include <com/ngos/shared/common/idt/idtgatetype.h>



struct IdtDescriptorType
{
    union
    {
        struct
        {
            u8 gateType:   4; // TODO: Use enum IdtGateType
            u8 __reserved: 1;
            u8 dpl:        2;
            u8 p:          1;
        };

        u8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTORTYPE_H
