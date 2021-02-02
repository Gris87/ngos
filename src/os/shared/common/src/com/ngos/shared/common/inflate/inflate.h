#ifndef COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H
#define COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus inflate(bad_uint8 *compressedAddress, bad_uint8 *decompressedAddress, bad_uint64 *compressedSize, bad_uint64 *uncompressedSize); // TEST: NO



#endif // COM_NGOS_SHARED_COMMON_INFLATE_INFLATE_H
