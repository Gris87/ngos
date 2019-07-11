#ifndef OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_ADLER_H
#define OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_ADLER_H



#include <ngos/status.h>



class Adler
{
public:
    static u32 adler32(u8 *data, u64 length); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_ADLER_H
