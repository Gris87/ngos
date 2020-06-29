#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_DECOMPRESS_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_DECOMPRESS_H



#include <buildconfig.h>
#include <ngos/status.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize); // TEST: NO



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_DECOMPRESS_H
