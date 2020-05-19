#include "hex.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/linkage.h>



NgosStatus Hex::toString(u8 *data, u64 size, char8 *buffer, u64 bufferSize, bool ellipsis)
{
    COMMON_LT((" | data = 0x%p, size = %u, buffer = 0x%p, bufferSize = %u, ellipsis = %u", data, size, buffer, bufferSize, ellipsis));

    COMMON_ASSERT(data,           "data is null",       NgosStatus::ASSERTION);
    COMMON_ASSERT(buffer,         "buffer is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(bufferSize > 0, "bufferSize is zero", NgosStatus::ASSERTION);



    AVOID_UNUSED(size);
    AVOID_UNUSED(ellipsis);



    return NgosStatus::OK;
}

NgosStatus Hex::toString(u8 *data, u64 size, char8 **buffer, u64 maxBufferSize, bool ellipsis)
{
    COMMON_LT((" | data = 0x%p, size = %u, buffer = 0x%p, maxBufferSize = %u, ellipsis = %u", data, size, buffer, maxBufferSize, ellipsis));

    COMMON_ASSERT(data,              "data is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(buffer,            "buffer is null",        NgosStatus::ASSERTION);
    COMMON_ASSERT(maxBufferSize > 0, "maxBufferSize is zero", NgosStatus::ASSERTION);



    AVOID_UNUSED(size);
    AVOID_UNUSED(ellipsis);



    return NgosStatus::OK;
}
