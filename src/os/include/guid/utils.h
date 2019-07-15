#ifndef GUID_UTILS_H
#define GUID_UTILS_H



#include <guid/guid.h>



bool isGuidEquals(const Guid &guid1, const Guid &guid2)
{
    return ((u64 *)&guid1)[0] == ((u64 *)&guid2)[0]
           &&
           ((u64 *)&guid1)[1] == ((u64 *)&guid2)[1];
}



#endif // GUID_UTILS_H
