#ifndef OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATE_H
#define OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATE_H



#include <ngos/status.h>
#include <ngos/types.h>



NgosStatus inflate(u8 *compressedAddress, u8 *decompressedAddress, u64 *compressedSize, u64 *uncompressedSize); // TEST: NO



#endif // OS_SHARED_COMMON_SRC_BITS64_INFLATE_INFLATE_H
