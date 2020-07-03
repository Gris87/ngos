#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H



#include <com/ngos/shared/common/ngos/status.h>



class Adler
{
public:
    static u32 adler32(u8 *data, u64 length);
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_ADLER_H
