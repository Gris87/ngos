#ifndef GDT_GDTREGISTER_H
#define GDT_GDTREGISTER_H



#include <ngos/types.h>



struct GdtRegister
{
    u16   size;
    void *address;
} __attribute__((packed));



#endif // GDT_GDTREGISTER_H
