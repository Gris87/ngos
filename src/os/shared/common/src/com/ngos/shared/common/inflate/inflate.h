#ifndef COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H
#define COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus inflate(u8 *compressedAddress, u8 *decompressedAddress, u64 *compressedSize, u64 *uncompressedSize); // TEST: NO



#endif // COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H
