#ifndef UUID_UTILS_H
#define UUID_UTILS_H



#include <common/src/bits64/printf/printf.h>
#include <uuid/uuid.h>



inline bool isUuidEquals(const Uuid &uuid1, const Uuid &uuid2)
{
    return ((u64 *)&uuid1)[0] == ((u64 *)&uuid2)[0]
            &&
            ((u64 *)&uuid1)[1] == ((u64 *)&uuid2)[1];
}

inline const char8* uuidToString(const Uuid &uuid) // TEST: NO
{
    static char8 res[39];

    sprintf(res, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", uuid.data1, uuid.data2, uuid.data3, uuid.data4, uuid.data5, uuid.data6[0], uuid.data6[1], uuid.data6[2], uuid.data6[3], uuid.data6[4], uuid.data6[5]);

    return res;
}

inline const char8* uuidToString(Uuid *uuid) // TEST: NO
{
    if (!uuid)
    {
        return "null";
    }



    static char8 res[50];

    sprintf(res, "0x%p {%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", uuid, uuid->data1, uuid->data2, uuid->data3, uuid->data4, uuid->data5, uuid->data6[0], uuid->data6[1], uuid->data6[2], uuid->data6[3], uuid->data6[4], uuid->data6[5]);

    return res;
}



#endif // UUID_UTILS_H
