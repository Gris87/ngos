#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_IDT_IDTREGISTER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_IDT_IDTREGISTER_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct IdtRegister
{
    u16   size;
    void *address;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_IDT_IDTREGISTER_H
