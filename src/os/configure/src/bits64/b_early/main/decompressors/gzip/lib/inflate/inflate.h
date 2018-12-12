#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATE_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATE_H



#include <buildconfig.h>
#include <ngos/status.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



NgosStatus inflate(u8 *compressedAddress, u8 *decompressedAddress, u64 *compressedSize, u64 *uncompressedSize); // TEST: NO



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_GZIP_LIB_INFLATE_INFLATE_H
