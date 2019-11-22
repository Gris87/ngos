#ifndef OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_LIB_MD5HASH_H
#define OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_LIB_MD5HASH_H



#include <common/src/bits64/memory/memory.h>
#include <ngos/types.h>



struct Md5Hash
{
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
        u64 quads[2];
    };
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_LIB_MD5HASH_H
