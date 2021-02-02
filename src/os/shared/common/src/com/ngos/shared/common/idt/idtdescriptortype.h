#ifndef COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTORTYPE_H
#define COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTORTYPE_H



#include <com/ngos/shared/common/idt/idtgatetype.h>



struct IdtDescriptorType
{
    union
    {
        struct
        {
            bad_uint8 gateType:   4; // TODO: Use enum IdtGateType
            bad_uint8 __reserved: 1;
            bad_uint8 dpl:        2;
            bad_uint8 p:          1;
        };

        bad_uint8 value8;
    };
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTORTYPE_H
