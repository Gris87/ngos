#ifndef COM_NGOS_SHARED_COMMON_GDT_GDTREGISTER_H
#define COM_NGOS_SHARED_COMMON_GDT_GDTREGISTER_H



#include <com/ngos/shared/common/ngos/types.h>



struct GdtRegister
{
    u16   size;
    void *address;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_GDT_GDTREGISTER_H
