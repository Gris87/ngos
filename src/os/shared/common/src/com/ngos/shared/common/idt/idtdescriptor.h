#ifndef COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTOR_H



#include <com/ngos/shared/common/idt/idtdescriptortype.h>



struct IdtDescriptor
{
    u16               offsetLow;
    u16               segment;
    u8                ist;
    IdtDescriptorType type;
    u16               offsetMiddle;
    u32               offsetHigh;
    u32               __reserved2;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTOR_H
