#ifndef COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H
#define COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H



#include <com/ngos/shared/common/ngos/status.h>



class Adler
{
public:
    static bad_uint32 adler32(bad_uint8 *data, bad_uint64 length);
};



#endif // COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H
