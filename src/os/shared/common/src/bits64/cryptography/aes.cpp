#include "aes.h"

#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>



#define __AES_KEY_EXPANSION_128(roundConstant) \
    "aeskeygenassist    $" #roundConstant ", %%xmm1, %%xmm2"    "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
                                                                "\n\t"                                                                              \
    "pshufd             $0xFF, %%xmm2, %%xmm2"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "movaps             %%xmm1, %%xmm3"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pshufd             $0x00, %%xmm2, %%xmm2"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
                                                                "\n\t"                                                                              \
    "pshufd             $0x39, %%xmm3, %%xmm3"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pslldq             $0x04, %%xmm3"                          "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pshufd             $0x14, %%xmm2, %%xmm2"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
                                                                "\n\t"                                                                              \
    "pshufd             $0x38, %%xmm3, %%xmm3"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pslldq             $0x04, %%xmm3"                          "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pshufd             $0xA4, %%xmm2, %%xmm2"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
                                                                "\n\t"                                                                              \
    "pshufd             $0x34, %%xmm3, %%xmm3"                  "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pslldq             $0x04, %%xmm3"                          "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
                                                                "\n\t"                                                                              \
    "movaps             %%xmm2, %%xmm1"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "movaps             %%xmm2, (%%rax)"                        "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */



#define AES_KEY_EXPANSION_128(roundConstant) \
    __AES_KEY_EXPANSION_128(roundConstant) \
                                                                "\n\t"                                                                              \
    "aesimc             %%xmm1, %%xmm3"                         "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "movaps             %%xmm3, (%%rbx)"                        "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
                                                                "\n\t"                                                                              \
    "addq               $0x10, %%rax"                           "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */  \
    "subq               $0x10, %%rbx"                           "\n\t"  /* movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1 */



#define AES_KEY_EXPANSION_128_LAST(roundConstant) \
    __AES_KEY_EXPANSION_128(roundConstant) \



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

    COMMON_TEST_ASSERT(CPU::hasFlag(X86Feature::AES));
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

            mEncodeKeyAllocated = (u8 *)malloc(12 * 16); // Key should contains of 11 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(12 * 16); // Key should contains of 11 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster
        }
        break;

        case 192:
        {
            mExpandKeyFunction   = &AES::expandKey192;
            mEncodeBlockFunction = &AES::encodeBlock192;
            mDecodeBlockFunction = &AES::decodeBlock192;

            mEncodeKeyAllocated = (u8 *)malloc(14 * 16); // Key should contains of 13 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(14 * 16); // Key should contains of 13 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster
        }
        break;

        case 256:
        {
            mExpandKeyFunction   = &AES::expandKey256;
            mEncodeBlockFunction = &AES::encodeBlock256;
            mDecodeBlockFunction = &AES::decodeBlock256;

            mEncodeKeyAllocated = (u8 *)malloc(16 * 16); // Key should contains of 15 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(16 * 16); // Key should contains of 15 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

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

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movups     %0, %%xmm1"             "\n\t"  // movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1
                                            "\n\t"  //
        "movaps     %%xmm1, (%%rax)"        "\n\t"  // movaps     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1
        "movaps     %%xmm1, (%%rbx)"        "\n\t"  // movaps     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1
        "addq       $0x10, %%rax"           "\n\t"  // movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1
        "subq       $0x10, %%rbx"           "\n\t"  // movups     0x20(%rsp), %xmm1    # Put 8 floats located at %0 to YMM1
                                            "\n\t"  //
                AES_KEY_EXPANSION_128(0x01)         // Round 1
                AES_KEY_EXPANSION_128(0x02)         // Round 2
                AES_KEY_EXPANSION_128(0x04)         // Round 3
                AES_KEY_EXPANSION_128(0x08)         // Round 4
                AES_KEY_EXPANSION_128(0x10)         // Round 5
                AES_KEY_EXPANSION_128(0x20)         // Round 6
                AES_KEY_EXPANSION_128(0x40)         // Round 7
                AES_KEY_EXPANSION_128(0x80)         // Round 8
                AES_KEY_EXPANSION_128(0x1b)         // Round 9
                AES_KEY_EXPANSION_128_LAST(0x36)    // Round 10
                                            "\n\t"  //
        "movaps     %%xmm1, (%%rbx)"                // movaps     %xmm1, (%rbx)    # Put 8 floats located at %0 to YMM1
            :                                       // Output parameters
            :                                       // Input parameters
                "m" (*key),                         // 'm' - use memory
                "a" (mEncodeKey),                   // 'a' - RAX
                "b" (&mDecodeKey[160])              // 'b' - RBX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::expandKey192(u8 *key)
{
    COMMON_LT((" | key = 0x%p", key));

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(key);



    return NgosStatus::OK;
}

NgosStatus AES::expandKey256(u8 *key)
{
    COMMON_LT((" | key = 0x%p", key));

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(key);



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(sourceAddress);
    AVOID_UNUSED(destinationAddress);



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(sourceAddress);
    AVOID_UNUSED(destinationAddress);



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock256(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(sourceAddress);
    AVOID_UNUSED(destinationAddress);



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(sourceAddress);
    AVOID_UNUSED(destinationAddress);



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(sourceAddress);
    AVOID_UNUSED(destinationAddress);



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock256(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(sourceAddress);
    AVOID_UNUSED(destinationAddress);



    return NgosStatus::OK;
}
