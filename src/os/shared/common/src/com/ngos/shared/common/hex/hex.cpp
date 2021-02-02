#include "hex.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/common/ngos/linkage.h>



NgosStatus Hex::toString(bad_uint8 *data, bad_int64 size, char8 *buffer, bad_int64 bufferSize, bool ellipsis)
{
    COMMON_LT((" | data = 0x%p, size = %d, buffer = 0x%p, bufferSize = %d, ellipsis = %u", data, size, buffer, bufferSize, ellipsis));

    COMMON_ASSERT(data,                                                       "data is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(size >= 0,                                                  "size is invalid",       NgosStatus::ASSERTION);
    COMMON_ASSERT(buffer,                                                     "buffer is null",        NgosStatus::ASSERTION)
    COMMON_ASSERT(bufferSize > 0,                                             "bufferSize is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(!ellipsis || bufferSize >= size * 2 + 1 || bufferSize >= 6, "bufferSize is invalid", NgosStatus::ASSERTION);



    bool needEllipsis = false;



    bad_int64 neededBufferSize = size * 2 + 1;

    if (neededBufferSize > bufferSize)
    {
        if (ellipsis)
        {
            needEllipsis = true;

            size = (bufferSize - 4) / 2;
        }
        else
        {
            size = (bufferSize - 1) / 2;
        }
    }



    bad_uint16 *cur = (bad_uint16 *)buffer;

    for (bad_int64 i = 0; i < size; ++i)
    {
        bad_uint8 ch = *data;

        *cur = sHexChars[ch];

        ++data;
        ++cur;
    }



    char8 *terminator = (char8 *)cur;

    if (needEllipsis)
    {
        terminator[0] = '.';
        terminator[1] = '.';
        terminator[2] = '.';
        terminator[3] = 0;
    }
    else
    {
        terminator[0] = 0;
    }



    return NgosStatus::OK;
}

NgosStatus Hex::toString(bad_uint8 *data, bad_int64 size, char8 **buffer, bad_int64 maxBufferSize, bool ellipsis)
{
    COMMON_LT((" | data = 0x%p, size = %d, buffer = 0x%p, maxBufferSize = %d, ellipsis = %u", data, size, buffer, maxBufferSize, ellipsis));

    COMMON_ASSERT(data,              "data is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(size >= 0,         "size is invalid",          NgosStatus::ASSERTION);
    COMMON_ASSERT(buffer,            "buffer is null",           NgosStatus::ASSERTION);
    COMMON_ASSERT(maxBufferSize > 0, "maxBufferSize is invalid", NgosStatus::ASSERTION);



    bad_int64 bufferSize = size * 2 + 1;

    if (bufferSize > maxBufferSize)
    {
        if (ellipsis)
        {
            if (maxBufferSize < 6)
            {
                return NgosStatus::INVALID_DATA;
            }

            bufferSize = maxBufferSize & 0xFFFFFFFFFFFFFFFE;
        }
        else
        {
            bufferSize = maxBufferSize;

            if (bufferSize % 2 == 0)
            {
                --bufferSize;
            }
        }
    }



    *buffer = (char8 *)malloc(bufferSize);
    COMMON_TEST_ASSERT(*buffer != nullptr, NgosStatus::ASSERTION);



    return toString(data, size, *buffer, bufferSize, ellipsis);
}
