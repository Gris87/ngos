#ifndef COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H
#define COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H



#include <com/ngos/shared/common/ngos/status.h>



class Crc
{
public:
    static u32 crc32(u8 *data, u64 length);
    static u64 crc64(u8 *data, u64 length);
};



#endif // COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H
