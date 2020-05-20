#include "hex.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <ngos/linkage.h>



NgosStatus Hex::toString(u8 *data, i64 size, char8 *buffer, i64 bufferSize, bool ellipsis)
{
    COMMON_LT((" | data = 0x%p, size = %d, buffer = 0x%p, bufferSize = %d, ellipsis = %u", data, size, buffer, bufferSize, ellipsis));

    COMMON_ASSERT(data,                                                       "data is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(size >= 0,                                                  "size is invalid",       NgosStatus::ASSERTION);
    COMMON_ASSERT(buffer,                                                     "buffer is null",        NgosStatus::ASSERTION)
    COMMON_ASSERT(bufferSize > 0,                                             "bufferSize is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(!ellipsis || bufferSize >= size * 2 + 1 || bufferSize >= 6, "bufferSize is invalid", NgosStatus::ASSERTION);



    bool needEllipsis = false;



    i64 neededBufferSize = size * 2 + 1;

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



    char8 *cur = buffer;

    for (i64 i = 0; i < size; ++i)
    {
        *((u16 *)cur) = sHexChars[*data];

        ++data;
        cur += 2;
    }



    if (needEllipsis)
    {
        cur[0] = '.';
        cur[1] = '.';
        cur[2] = '.';
        cur[3] = 0;
    }
    else
    {
        cur[0] = 0;
    }





    return NgosStatus::OK;
}

NgosStatus Hex::toString(u8 *data, i64 size, char8 **buffer, i64 maxBufferSize, bool ellipsis)
{
    COMMON_LT((" | data = 0x%p, size = %d, buffer = 0x%p, maxBufferSize = %d, ellipsis = %u", data, size, buffer, maxBufferSize, ellipsis));

    COMMON_ASSERT(data,              "data is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(size >= 0,         "size is invalid",          NgosStatus::ASSERTION);
    COMMON_ASSERT(buffer,            "buffer is null",           NgosStatus::ASSERTION);
    COMMON_ASSERT(maxBufferSize > 0, "maxBufferSize is invalid", NgosStatus::ASSERTION);



    i64 bufferSize = size * 2 + 1;

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

            if ((bufferSize & 0x01) == 0)
            {
                --bufferSize;
            }
        }
    }



    *buffer = (char8 *)malloc(bufferSize);
    COMMON_TEST_ASSERT(*buffer, NgosStatus::ASSERTION);



    return toString(data, size, *buffer, bufferSize, ellipsis);
}
