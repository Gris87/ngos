#ifndef COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H
#define COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H



#include <com/ngos/shared/common/ngos/status.h>



class Crc
{
public:
    static bad_uint32 crc32(bad_uint8 *data, bad_uint64 length);
    static bad_uint64 crc64(bad_uint8 *data, bad_uint64 length);
};



#endif // COM_NGOS_SHARED_COMMON_CHECKSUM_CRC_H
