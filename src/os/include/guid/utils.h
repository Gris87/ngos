#ifndef GUID_UTILS_H
#define GUID_UTILS_H



#include <common/src/bits64/printf/printf.h>
#include <guid/guid.h>



inline bool isGuidEquals(const Guid &guid1, const Guid &guid2)
{
    return ((u64 *)&guid1)[0] == ((u64 *)&guid2)[0]
            &&
            ((u64 *)&guid1)[1] == ((u64 *)&guid2)[1];
}

inline const char8* guidToString(const Guid &guid) // TEST: NO
{
    static char8 res[38];

    sprintf(res, "{%08X-%04X-%04X-%02X%02X%02X%02X%02X%02X%02X%02X}", guid.data1, guid.data2, guid.data3, guid.data4[0], guid.data4[1], guid.data4[2], guid.data4[3], guid.data4[4], guid.data4[5], guid.data4[6], guid.data4[7]);

    return res;
}

inline const char8* guidToString(Guid *guid) // TEST: NO
{
    if (!guid)
    {
        return "null";
    }



    static char8 res[49];

    sprintf(res, "0x%p {%08X-%04X-%04X-%02X%02X%02X%02X%02X%02X%02X%02X}", guid, guid->data1, guid->data2, guid->data3, guid->data4[0], guid->data4[1], guid->data4[2], guid->data4[3], guid->data4[4], guid->data4[5], guid->data4[6], guid->data4[7]);

    return res;
}



#endif // GUID_UTILS_H
