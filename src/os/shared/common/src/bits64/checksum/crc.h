#ifndef OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_CRC_H
#define OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_CRC_H



#include <ngos/status.h>



class Crc
{
public:
    static u32 crc32(u8 *data, u64 length); // TEST: NO
    static u64 crc64(u8 *data, u64 length); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_CRC_H
