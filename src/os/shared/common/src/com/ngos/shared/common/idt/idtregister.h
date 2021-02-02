#ifndef COM_NGOS_SHARED_COMMON_IDT_IDTREGISTER_H
#define COM_NGOS_SHARED_COMMON_IDT_IDTREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct IdtRegister
{
    bad_uint16   size;
    void *address;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_IDT_IDTREGISTER_H
