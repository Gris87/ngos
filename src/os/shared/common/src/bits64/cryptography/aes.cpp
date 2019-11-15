#include "aes.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <ngos/utils.h>



AES::AES()
    : mExpandKeyFunction(nullptr)
    , mEncodeBlockFunction(nullptr)
    , mDecodeBlockFunction(nullptr)
    , mEncodeKeyAllocated(nullptr)
    , mDecodeKeyAllocated(nullptr)
    , mEncodeKey(nullptr)
    , mDecodeKey(nullptr)
{
    COMMON_LT((""));
}

AES::~AES()
{
    COMMON_LT((""));



    if (mEncodeKeyAllocated)
    {
        COMMON_ASSERT_EXECUTION(free(mEncodeKeyAllocated));
    }

    if (mDecodeKeyAllocated)
    {
        COMMON_ASSERT_EXECUTION(free(mDecodeKeyAllocated));
    }
}

NgosStatus AES::setKey(u8 *key, u8 size)
{
    COMMON_LT((" | key = 0x%p, size = %u", key, size));

    COMMON_ASSERT(key,      "key is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(releaseKey(), NgosStatus::ASSERTION);

    switch (size * 8)
    {
        case 128:
        {
            mExpandKeyFunction   = &AES::expandKey128;
            mEncodeBlockFunction = &AES::encodeBlock128;
            mDecodeBlockFunction = &AES::decodeBlock128;

            mEncodeKeyAllocated = (u8 *)malloc(11 * 16); // Key should contains of 10 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(11 * 16); // Key should contains of 10 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster
        }
        break;

        case 192:
        {
            mExpandKeyFunction   = &AES::expandKey192;
            mEncodeBlockFunction = &AES::encodeBlock192;
            mDecodeBlockFunction = &AES::decodeBlock192;

            mEncodeKeyAllocated = (u8 *)malloc(13 * 16); // Key should contains of 12 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(13 * 16); // Key should contains of 12 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster
        }
        break;

        default:
        {
            COMMON_LF(("Unexpected key size: %u", size));

            return NgosStatus::INVALID_DATA;
        }
        break;
    }



    COMMON_TEST_ASSERT(mExpandKeyFunction   != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mEncodeBlockFunction != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mDecodeBlockFunction != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mEncodeKeyAllocated  != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mDecodeKeyAllocated  != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mEncodeKey           != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mDecodeKey           != nullptr, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION((this->*mExpandKeyFunction)(key), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus AES::releaseKey()
{
    COMMON_LT((""));



    if (mEncodeKeyAllocated)
    {
        COMMON_ASSERT_EXECUTION(free(mEncodeKeyAllocated), NgosStatus::ASSERTION);

        mEncodeKeyAllocated = nullptr;
        mEncodeKey          = nullptr;
    }

    if (mDecodeKeyAllocated)
    {
        COMMON_ASSERT_EXECUTION(free(mDecodeKeyAllocated), NgosStatus::ASSERTION);

        mDecodeKeyAllocated = nullptr;
        mDecodeKey          = nullptr;
    }



    return NgosStatus::OK;
}

NgosStatus AES::expandKey128(u8 *key)
{
    COMMON_LT((" | key = 0x%p", key));

    COMMON_ASSERT(key, "key is null",  NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus AES::expandKey192(u8 *key)
{
    COMMON_LT((" | key = 0x%p", key));

    COMMON_ASSERT(key, "key is null",  NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
