#ifndef COM_NGOS_SHARED_COMMON_UUID_UTILS_H
#define COM_NGOS_SHARED_COMMON_UUID_UTILS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/uuid/uuid.h>



inline bool isUuidEquals(const Uuid &uuid1, const Uuid &uuid2)
{
    COMMON_LT((" | uuid1 = ..., uuid2 = ..."));



    return ((bad_uint64 *)&uuid1)[0] == ((bad_uint64 *)&uuid2)[0]
            &&
            ((bad_uint64 *)&uuid1)[1] == ((bad_uint64 *)&uuid2)[1];
}

inline const char8* uuidToString(const Uuid &uuid) // TEST: NO
{
    COMMON_LT((" | uuid = ..."));



    static char8 res[39];

    sprintf(res, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", uuid.data1, uuid.data2, uuid.data3, uuid.data4, uuid.data5, uuid.data6[0], uuid.data6[1], uuid.data6[2], uuid.data6[3], uuid.data6[4], uuid.data6[5]);

    return res;
}

inline const char8* uuidToString(Uuid *uuid) // TEST: NO
{
    COMMON_LT((" | uuid = 0x%p", uuid));



    if (!uuid)
    {
        return "null";
    }



    static char8 res[39];

    sprintf(res, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", uuid->data1, uuid->data2, uuid->data3, uuid->data4, uuid->data5, uuid->data6[0], uuid->data6[1], uuid->data6[2], uuid->data6[3], uuid->data6[4], uuid->data6[5]);

    return res;
}

// TODO: uuidToFullString



#endif // COM_NGOS_SHARED_COMMON_UUID_UTILS_H
