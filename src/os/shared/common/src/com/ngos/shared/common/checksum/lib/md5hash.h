#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_LIB_MD5HASH_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_LIB_MD5HASH_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/memory/memory.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct Md5Hash
{
    Md5Hash()
    {
        quads[0] = 0;
        quads[1] = 0;
    }

    Md5Hash(u64 quad1, u64 quad2)
    {
        quads[0] = quad1;
        quads[1] = quad2;
    }

    Md5Hash(u8 data[16])
    {
        memcpy(bytes, data, sizeof(bytes));
    }

    bool operator==(const Md5Hash &another) const
    {
        return quads[0] == another.quads[0]
                &&
                quads[1] == another.quads[1];
    }



    union
    {
        u8  bytes[16];
        u32 dwords[4];
        u64 quads[2];
    };
};



inline const char8* md5HashToString(const Md5Hash &hash) // TEST: NO
{
    // COMMON_LT((" | hash = ...")); // Commented to avoid bad looking logs



    static char8 res[33];

    i64 length = sprintf(res, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X"
                            , hash.bytes[0]
                            , hash.bytes[1]
                            , hash.bytes[2]
                            , hash.bytes[3]
                            , hash.bytes[4]
                            , hash.bytes[5]
                            , hash.bytes[6]
                            , hash.bytes[7]
                            , hash.bytes[8]
                            , hash.bytes[9]
                            , hash.bytes[10]
                            , hash.bytes[11]
                            , hash.bytes[12]
                            , hash.bytes[13]
                            , hash.bytes[14]
                            , hash.bytes[15]
            );

    AVOID_UNUSED(length);

    COMMON_TEST_ASSERT(length == 32,              nullptr);
    COMMON_TEST_ASSERT(length == sizeof(res) - 1, nullptr);



    return res;
}



inline const char8* md5HashToStringAsConstructor(const Md5Hash &hash) // TEST: NO
{
    // COMMON_LT((" | hash = ...")); // Commented to avoid bad looking logs



    static char8 res[48];

    i64 length = sprintf(res, "Md5Hash(0x%016lX, 0x%016lX)", hash.quads[0], hash.quads[1]);

    AVOID_UNUSED(length);

    COMMON_TEST_ASSERT(length == 47,              nullptr);
    COMMON_TEST_ASSERT(length == sizeof(res) - 1, nullptr);



    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_LIB_MD5HASH_H
