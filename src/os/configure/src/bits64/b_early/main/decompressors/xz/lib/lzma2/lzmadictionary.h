#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADICTIONARY_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADICTIONARY_H



#include <buildconfig.h>
#include <ngos/types.h>

#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzmode.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



// Dictionary (history buffer)
//
// These are always true:
//
//    start <= position <= full <= end
//    position <= limit <= end
//
// In multi-call mode, also these are true:
//
//    end == size
//    size <= size_max
//    allocated <= size
//
// Most of these variables are u64 to support single-call mode,
// in which the dictionary variables address the actual output
// buffer directly.
struct LzmaDictionary
{
    // Beginning of the history buffer
    u8 *buffer;

    // Old position in buffer (before decoding more data)
    u64 start;

    // Position in buffer
    u64 position;

    // How full dictionary is. This is used to detect corrupt input that
    // would read beyond the beginning of the uncompressed stream.
    u64 full;

    // Write limit; we don't write to buffer[limit] or later bytes.
    u64 limit;

    // End of the dictionary buffer. In multi-call mode, this is
    // the same as the dictionary size. In single-call mode, this
    // indicates the size of the output buffer.
    u64 end;

    // Size of the dictionary as specified in Block Header. This is used
    // together with "full" to detect corrupt input that would make us
    // read beyond the beginning of the uncompressed stream.
    u32 size;

    // Operation mode
    XzMode mode;
};



#endif



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADICTIONARY_H
