#ifndef OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_MD5_H
#define OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_MD5_H



#include <common/src/bits64/checksum/lib/md5hash.h>
#include <ngos/status.h>



class MD5
{
public:
    MD5();
    ~MD5();

    static Md5Hash md5(u8 *data, u64 length);
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_MD5_H
