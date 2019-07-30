#ifndef UUID_UTILS_H
#define UUID_UTILS_H



#include <uuid/uuid.h>



bool isUuidEquals(const Uuid &uuid1, const Uuid &uuid2)
{
    return ((u64 *)&uuid1)[0] == ((u64 *)&uuid2)[0]
            &&
            ((u64 *)&uuid1)[1] == ((u64 *)&uuid2)[1];
}



#endif // UUID_UTILS_H
