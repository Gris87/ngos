#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_FILTERBCJ_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_FILTERBCJ_H



#include <buildconfig.h>
#include <ngos/status.h>
#include <ngos/types.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#if NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
#define XZ_FILTER_BCJ 0x04
#endif



NgosStatus filterBCJ(u8 *compressedAddress, u8 *decompressedAddress, u64 sizeOfProperties, u8 *filterProperties, u64 uncompressedSize); // TEST: NO



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_FILTERBCJ_H
