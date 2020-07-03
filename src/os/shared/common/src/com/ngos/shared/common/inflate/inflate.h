#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus inflate(u8 *compressedAddress, u8 *decompressedAddress, u64 *compressedSize, u64 *uncompressedSize); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H
