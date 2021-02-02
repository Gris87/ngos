#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADICTIONARY_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADICTIONARY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



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
// Most of these variables are bad_uint64 to support single-call mode,
// in which the dictionary variables address the actual output
// buffer directly.
struct LzmaDictionary
{
    // Beginning of the history buffer
    bad_uint8 *buffer;

    // Old position in buffer (before decoding more data)
    bad_uint64 start;

    // Position in buffer
    bad_uint64 position;

    // How full dictionary is. This is used to detect corrupt input that
    // would read beyond the beginning of the uncompressed stream.
    bad_uint64 full;

    // Write limit; we don't write to buffer[limit] or later bytes.
    bad_uint64 limit;

    // End of the dictionary buffer. In multi-call mode, this is
    // the same as the dictionary size. In single-call mode, this
    // indicates the size of the output buffer.
    bad_uint64 end;

    // Size of the dictionary as specified in Block Header. This is used
    // together with "full" to detect corrupt input that would make us
    // read beyond the beginning of the uncompressed stream.
    bad_uint32 size;
};



#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_DECOMPRESSORS_XZ_LIB_LZMA2_LZMADICTIONARY_H
