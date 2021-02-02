#ifndef COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTOR_H



#include <com/ngos/shared/common/idt/idtdescriptortype.h>



struct IdtDescriptor
{
    bad_uint16               offsetLow;
    bad_uint16               segment;
    bad_uint8                ist;
    IdtDescriptorType type;
    bad_uint16               offsetMiddle;
    bad_uint32               offsetHigh;
    bad_uint32               __reserved2;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_IDT_IDTDESCRIPTOR_H
