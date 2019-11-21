#include "aes.h"

#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>
#include <macro/utils.h>



#define __AES_KEY_EXPANSION_128(roundConstant) \
    "aeskeygenassist    $" #roundConstant ", %%xmm1, %%xmm2"    "\n\t"    /* aeskeygenassist    $0x01, %xmm1, %xmm2     # Assist in AES round key generation using an 8 bits Round Constant */                                                                                                                  \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0xFF, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0xFF, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[3], XMM2[1] = XMM2[3], XMM2[2] = XMM2[3], XMM2[3] = XMM2[3] */ \
    "movaps             %%xmm1, %%xmm3"                         "\n\t"    /* movaps             %xmm1, %xmm3            # Put content of XMM1 to XMM3 */                                                                                                                                                        \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
    "pshufd             $0x00, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0x00, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[0], XMM2[1] = XMM2[0], XMM2[2] = XMM2[0], XMM2[3] = XMM2[0] */ \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0x39, %%xmm3, %%xmm3"                  "\n\t"    /* pshufd             $0x39, %xmm3, %xmm3     # Shuffle the doublewords in XMM3 based on the encoding in first argument and store the result in XMM3  # XMM3[0] = XMM3[1], XMM3[1] = XMM3[2], XMM3[2] = XMM3[3], XMM3[3] = XMM3[0] */ \
    "pslldq             $0x04, %%xmm3"                          "\n\t"    /* pslldq             $0x04, %xmm3            # Shift 4 bytes in XMM3 to left */                                                                                                                                                      \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
    "pshufd             $0x14, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0x14, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[0], XMM2[1] = XMM2[1], XMM2[2] = XMM2[1], XMM2[3] = XMM2[0] */ \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0x38, %%xmm3, %%xmm3"                  "\n\t"    /* pshufd             $0x38, %xmm3, %xmm3     # Shuffle the doublewords in XMM3 based on the encoding in first argument and store the result in XMM3  # XMM3[0] = XMM3[0], XMM3[1] = XMM3[2], XMM3[2] = XMM3[3], XMM3[3] = XMM3[0] */ \
    "pslldq             $0x04, %%xmm3"                          "\n\t"    /* pslldq             $0x04, %xmm3            # Shift 4 bytes in XMM3 to left */                                                                                                                                                      \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
    "pshufd             $0xA4, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0xA4, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[0], XMM2[1] = XMM2[1], XMM2[2] = XMM2[3], XMM2[3] = XMM2[3] */ \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0x34, %%xmm3, %%xmm3"                  "\n\t"    /* pshufd             $0x34, %xmm3, %xmm3     # Shuffle the doublewords in XMM3 based on the encoding in first argument and store the result in XMM3  # XMM3[0] = XMM3[0], XMM3[1] = XMM3[1], XMM3[2] = XMM3[3], XMM3[3] = XMM3[0] */ \
    "pslldq             $0x04, %%xmm3"                          "\n\t"    /* pslldq             $0x04, %xmm3            # Shift 4 bytes in XMM3 to left */                                                                                                                                                      \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "movaps             %%xmm2, %%xmm1"                         "\n\t"    /* movaps             %xmm2, %xmm1            # Put content of XMM2 to XMM1 */



#define AES_KEY_EXPANSION_128(roundConstant, round) \
    __AES_KEY_EXPANSION_128(roundConstant)                                                                                                                                                                                  \
                                                                        "\n\t"                                                                                                                                              \
    "aesimc     %%xmm1, %%xmm3"                                         "\n\t"    /* aesimc     %xmm1, %xmm3    # Perform the InvMixColumn transformation on a 128-bit round key from XMM1 and store the result in XMM3 */  \
    "movaps     %%xmm2, " PP_STRINGIZE(round * 16)        "(%%rax)"     "\n\t"    /* movaps     %xmm2, (%rax)   # Put content of XMM2 to 16 bytes of mEncodeKey */                                                          \
    "movaps     %%xmm3, " PP_STRINGIZE((10 - round) * 16) "(%%rbx)"     "\n\t"    /* movaps     %xmm3, (%rbx)   # Put content of XMM3 to 16 bytes of mDecodeKey */                                                          \



#define AES_KEY_EXPANSION_128_LAST(roundConstant) \
    __AES_KEY_EXPANSION_128(roundConstant)                                                                                              \
                                        "\n\t"                                                                                          \
    "movaps     %%xmm2, 0xA0(%%rax)"    "\n\t"    /* movaps     %xmm2, 0xA0(%rax)   # Put content of XMM2 to 16 bytes of mEncodeKey */



// TODO: Update asm comments
#define __AES_ENCODE_KEY_EXPANSION_192(roundConstant, round) \
    "aeskeygenassist    $" #roundConstant ", %%xmm1, %%xmm2"    "\n\t"    /* aeskeygenassist    $0x01, %xmm1, %xmm2     # Assist in AES round key generation using an 8 bits Round Constant */                                                                                                                  \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0xFF, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0xFF, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[3], XMM2[1] = XMM2[3], XMM2[2] = XMM2[3], XMM2[3] = XMM2[3] */ \
    "movaps             %%xmm4, %%xmm3"                         "\n\t"    /* movaps             %xmm4, %xmm3            # Put content of XMM4 to XMM3 */                                                                                                                                                        \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
    "pshufd             $0x00, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0x00, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[0], XMM2[1] = XMM2[0], XMM2[2] = XMM2[0], XMM2[3] = XMM2[0] */ \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0x39, %%xmm3, %%xmm3"                  "\n\t"    /* pshufd             $0x39, %xmm3, %xmm3     # Shuffle the doublewords in XMM3 based on the encoding in first argument and store the result in XMM3  # XMM3[0] = XMM3[1], XMM3[1] = XMM3[2], XMM3[2] = XMM3[3], XMM3[3] = XMM3[0] */ \
    "pslldq             $0x04, %%xmm3"                          "\n\t"    /* pslldq             $0x04, %xmm3            # Shift 4 bytes in XMM3 to left */                                                                                                                                                      \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
    "pshufd             $0x14, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0x14, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[0], XMM2[1] = XMM2[1], XMM2[2] = XMM2[1], XMM2[3] = XMM2[0] */ \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0x38, %%xmm3, %%xmm3"                  "\n\t"    /* pshufd             $0x38, %xmm3, %xmm3     # Shuffle the doublewords in XMM3 based on the encoding in first argument and store the result in XMM3  # XMM3[0] = XMM3[0], XMM3[1] = XMM3[2], XMM3[2] = XMM3[3], XMM3[3] = XMM3[0] */ \
    "pslldq             $0x04, %%xmm3"                          "\n\t"    /* pslldq             $0x04, %xmm3            # Shift 4 bytes in XMM3 to left */                                                                                                                                                      \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
    "pshufd             $0xA4, %%xmm2, %%xmm2"                  "\n\t"    /* pshufd             $0xA4, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2  # XMM2[0] = XMM2[0], XMM2[1] = XMM2[1], XMM2[2] = XMM2[3], XMM2[3] = XMM2[3] */ \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "pshufd             $0x34, %%xmm3, %%xmm3"                  "\n\t"    /* pshufd             $0x34, %xmm3, %xmm3     # Shuffle the doublewords in XMM3 based on the encoding in first argument and store the result in XMM3  # XMM3[0] = XMM3[0], XMM3[1] = XMM3[1], XMM3[2] = XMM3[3], XMM3[3] = XMM3[0] */ \
    "pslldq             $0x04, %%xmm3"                          "\n\t"    /* pslldq             $0x04, %xmm3            # Shift 4 bytes in XMM3 to left */                                                                                                                                                      \
    "pxor               %%xmm3, %%xmm2"                         "\n\t"    /* pxor               %xmm3, %xmm2            # Perform bitwise XOR of XMM3 and XMM2 and store the result in XMM2 */                                                                                                                  \
                                                                "\n\t"                                                                                                                                                                                                                                          \
    "movups             %%xmm2, " PP_STRINGIZE(round * 24) "(%%rax)"                        "\n\t"    /* movaps             %xmm2, (%rax)           # Put content of XMM2 to 16 bytes of mEncodeKey */



// TODO: Update asm comments
#define AES_ENCODE_KEY_EXPANSION_192(roundConstant, round) \
    __AES_ENCODE_KEY_EXPANSION_192(roundConstant, round)    \
                                        "\n\t"              \
    "pshufd     $0xFF, %%xmm2, %%xmm2"  "\n\t"    /*  */    \
    "pshufd     $0xFE, %%xmm1, %%xmm1"  "\n\t"    /*  */    \
    "pxor       %%xmm1, %%xmm2"         "\n\t"    /*  */    \
                                        "\n\t"              \
    "pshufd     $0x00, %%xmm2, %%xmm2"  "\n\t"    /*  */    \
    "pslldq     $0x04, %%xmm1"          "\n\t"    /*  */    \
    "pshufd     $0x08, %%xmm1, %%xmm1"  "\n\t"    /*  */    \
    "pxor       %%xmm1, %%xmm2"         "\n\t"    /*  */    \
                                        "\n\t"              \
    "movups     %%xmm2, " PP_STRINGIZE(round * 24 + 16) "(%%rax)"    "\n\t"    /*  */    \
    "movups     " PP_STRINGIZE(round * 24 + 8) "(%%rax), %%xmm1"    "\n\t"    /*  */    \
    "movups     " PP_STRINGIZE(round * 24)     "(%%rax), %%xmm4"        "\n\t"    /*  */    \



#define AES_ENCODE_KEY_EXPANSION_192_LAST(roundConstant) \
    __AES_ENCODE_KEY_EXPANSION_192(roundConstant, 8)



// TODO: Update asm comments
#define AES_DECODE_KEY_EXPANSION_192(round) \
    "movaps     " PP_STRINGIZE(round * 16) "(%%rax), %%xmm1"            "\n\t"    /*  */    \
    "aesimc     %%xmm1, %%xmm1"                                         "\n\t"    /*  */    \
    "movaps     %%xmm1, " PP_STRINGIZE((12 - round) * 16) "(%%rbx)"     "\n\t"    /*  */



#define __AES_ENCODE_DECODE_ROUND(round) \
    "movaps     " PP_STRINGIZE(round * 16) "(%%rax), %%xmm2"    "\n\t"    /* movaps     (%rax), %xmm2   # Put 16 bytes from mEncodeKey/mDecodeKey to XMM2 */



#define AES_ENCODE_ROUND(round) \
    __AES_ENCODE_DECODE_ROUND(round)                                                                                                                                                                            \
                                    "\n\t"                                                                                                                                                                      \
    "aesenc     %%xmm2, %%xmm1"     "\n\t"    /* aesenc     %xmm2, %xmm1    # Perform one round of an AES encryption flow, operating on a 128-bit data (state) from XMM1 with a 128-bit round key from XMM2 */



#define AES_ENCODE_ROUND_LAST(round) \
    __AES_ENCODE_DECODE_ROUND(round)                                                                                                                                                                                        \
                                        "\n\t"                                                                                                                                                                              \
    "aesenclast     %%xmm2, %%xmm1"     "\n\t"    /* aesenclast     %xmm2, %xmm1    # Perform the last round of an AES encryption flow, operating on a 128-bit data (state) from XMM1 with a 128-bit round key from XMM2 */



#define AES_DECODE_ROUND(round) \
    __AES_ENCODE_DECODE_ROUND(round)                                                                                                                                                                                                                \
                                    "\n\t"                                                                                                                                                                                                          \
    "aesdec     %%xmm2, %%xmm1"     "\n\t"    /* aesdec     %xmm2, %xmm1    # Perform one round of an AES decryption flow, using the Equivalent Inverse Cipher, operating on a 128-bit data (state) from XMM1 with a 128-bit round key from XMM2 */



#define AES_DECODE_ROUND_LAST(round) \
    __AES_ENCODE_DECODE_ROUND(round)                                                                                                                                                                                                                                \
                                        "\n\t"                                                                                                                                                                                                                      \
    "aesdeclast     %%xmm2, %%xmm1"     "\n\t"    /* aesdeclast     %xmm2, %xmm1    # Perform the last round of an AES decryption flow, using the Equivalent Inverse Cipher, operating on a 128-bit data (state) from XMM1 with a 128-bit round key from XMM2 */



AES::AES()
    : mEncodeBlockFunction(nullptr)
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
            mEncodeBlockFunction = &AES::encodeBlock128;
            mDecodeBlockFunction = &AES::decodeBlock128;

            mEncodeKeyAllocated = (u8 *)malloc(12 * 16); // Key should contains of 11 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(12 * 16); // Key should contains of 11 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster

            COMMON_ASSERT_EXECUTION(expandKey128(key), NgosStatus::ASSERTION);
        }
        break;

        case 192:
        {
            mEncodeBlockFunction = &AES::encodeBlock192;
            mDecodeBlockFunction = &AES::decodeBlock192;

            mEncodeKeyAllocated = (u8 *)malloc(14 * 16); // Key should contains of 13 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(14 * 16); // Key should contains of 13 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster

            COMMON_ASSERT_EXECUTION(expandKey192(key), NgosStatus::ASSERTION);
        }
        break;

        case 256:
        {
            mEncodeBlockFunction = &AES::encodeBlock256;
            mDecodeBlockFunction = &AES::decodeBlock256;

            mEncodeKeyAllocated = (u8 *)malloc(16 * 16); // Key should contains of 15 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned
            mDecodeKeyAllocated = (u8 *)malloc(16 * 16); // Key should contains of 15 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned

            mEncodeKey = (u8 *)(ROUND_UP((u64)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((u64)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster

            COMMON_ASSERT_EXECUTION(expandKey256(key), NgosStatus::ASSERTION);
        }
        break;

        default:
        {
            COMMON_LF(("Unexpected key size: %u", size));

            return NgosStatus::INVALID_DATA;
        }
        break;
    }



    COMMON_TEST_ASSERT(mEncodeBlockFunction != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mDecodeBlockFunction != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mEncodeKeyAllocated  != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mDecodeKeyAllocated  != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mEncodeKey           != nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mDecodeKey           != nullptr, NgosStatus::ASSERTION);



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

NgosStatus AES::encode(u8 *in, u64 inSize, u8 *out, u64 outSize, u64 *resultSize)
{
    COMMON_LT((" | in = 0x%p, inSize = %u, out = 0x%p, outSize = %u, resultSize = 0x%p", in, inSize, out, outSize, resultSize));

    COMMON_ASSERT(in,                  "in is null",         NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_ALIGNED(in, 16),  "in is invalid",      NgosStatus::ASSERTION);
    COMMON_ASSERT(inSize > 0,          "inSize is zero",     NgosStatus::ASSERTION);
    COMMON_ASSERT(out,                 "out is null",        NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_ALIGNED(out, 16), "out is invalid",     NgosStatus::ASSERTION);
    COMMON_ASSERT(outSize > 0,         "outSize is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(resultSize,          "resultSize is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mEncodeKey, NgosStatus::ASSERTION);



    u8  padding = inSize & 0x0F;
    u64 size;

    if (padding)
    {
        padding = 16 - padding;
        size    = inSize + padding;
    }
    else
    {
        size = inSize;
    }



    if (outSize < size)
    {
        return NgosStatus::BUFFER_TOO_SMALL;
    }

    *resultSize = size;



    i64 blocksCount = inSize >> 4; // ">> 4" == "/ 16"

    for (i64 i = 0; i < blocksCount; ++i)
    {
        COMMON_ASSERT_EXECUTION((this->*mEncodeBlockFunction)(in, out), NgosStatus::ASSERTION);

        in  += 16;
        out += 16;
    }



    if (padding)
    {
        u8 paddingBlock[16] __attribute__((aligned(16)));

        memcpy(paddingBlock, in, 16 - padding);
        memzero(&paddingBlock[16 - padding], padding);

        COMMON_ASSERT_EXECUTION((this->*mEncodeBlockFunction)(paddingBlock, out), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus AES::decode(u8 *in, u64 inSize, u8 *out, u64 outSize, u64 *resultSize)
{
    COMMON_LT((" | in = 0x%p, inSize = %u, out = 0x%p, outSize = %u, resultSize = 0x%p", in, inSize, out, outSize, resultSize));

    COMMON_ASSERT(in,                     "in is null",         NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_ALIGNED(in, 16),     "in is invalid",      NgosStatus::ASSERTION);
    COMMON_ASSERT(inSize > 0,             "inSize is zero",     NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_ALIGNED(inSize, 16), "inSize is invalid",  NgosStatus::ASSERTION);
    COMMON_ASSERT(out,                    "out is null",        NgosStatus::ASSERTION);
    COMMON_ASSERT(IS_ALIGNED(out, 16),    "out is invalid",     NgosStatus::ASSERTION);
    COMMON_ASSERT(outSize > 0,            "outSize is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(resultSize,             "resultSize is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mDecodeKey, NgosStatus::ASSERTION);



    u64 size = inSize;

    if (outSize < size)
    {
        return NgosStatus::BUFFER_TOO_SMALL;
    }

    *resultSize = size;



    i64 blocksCount = inSize >> 4; // ">> 4" == "/ 16"

    for (i64 i = 0; i < blocksCount; ++i)
    {
        COMMON_ASSERT_EXECUTION((this->*mDecodeBlockFunction)(in, out), NgosStatus::ASSERTION);

        in  += 16;
        out += 16;
    }



    return NgosStatus::OK;
}

NgosStatus AES::expandKey128(u8 *key)
{
    COMMON_LT((" | key = 0x%p", key));

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movups     %0, %%xmm1"                     "\n\t"    // movups     (%rsi), %xmm1       # Put 16 bytes from key to XMM1
                                                    "\n\t"    //
        "movaps     %%xmm1, (%%rax)"                "\n\t"    // movaps     %xmm1, (%rax)       # Put content of XMM1 to 16 bytes of mEncodeKey
        "movaps     %%xmm1, 0xA0(%%rbx)"            "\n\t"    // movaps     %xmm1, 0xA0(%rbx)   # Put content of XMM1 to 16 bytes of mDecodeKey
                                                    "\n\t"    //
                AES_KEY_EXPANSION_128(0x01, 1)                // Round 1
                AES_KEY_EXPANSION_128(0x02, 2)                // Round 2
                AES_KEY_EXPANSION_128(0x04, 3)                // Round 3
                AES_KEY_EXPANSION_128(0x08, 4)                // Round 4
                AES_KEY_EXPANSION_128(0x10, 5)                // Round 5
                AES_KEY_EXPANSION_128(0x20, 6)                // Round 6
                AES_KEY_EXPANSION_128(0x40, 7)                // Round 7
                AES_KEY_EXPANSION_128(0x80, 8)                // Round 8
                AES_KEY_EXPANSION_128(0x1b, 9)                // Round 9
                AES_KEY_EXPANSION_128_LAST(0x36)              // Round 10
                                                    "\n\t"    //
        "movaps     %%xmm1, (%%rbx)"                          // movaps     %xmm1, (%rbx)       # Put content of XMM1 to 16 bytes of mDecodeKey
            :                                                 // Output parameters
            :                                                 // Input parameters
                "m" (*key),                                   // 'm' - use memory
                "a" (mEncodeKey),                             // 'a' - RAX
                "b" (mDecodeKey)                              // 'b' - RBX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::expandKey192(u8 *key)
{
    COMMON_LT((" | key = 0x%p", key));

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    // TODO: Update asm comments
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movups     %0, %%xmm2"                     "\n\t"    // movups     (%rsi), %xmm1   # Put 16 bytes from key to XMM1
        "movups     %1, %%xmm1"                     "\n\t"    // movups     (%rsi), %xmm1   # Put 16 bytes from key to XMM1
                                                    "\n\t"    //
        "movaps     %%xmm2, (%%rax)"                "\n\t"    // movaps     %xmm1, (%rax)   # Put content of XMM1 to 16 bytes of mEncodeKey
        "movups     %%xmm1, 0x08(%%rax)"            "\n\t"    // movaps     %xmm1, (%rax)   # Put content of XMM1 to 16 bytes of mEncodeKey
        "movaps     %%xmm2, %%xmm4"                 "\n\t"    // movaps     %xmm1, %xmm4    # Put content of XMM1 to XMM4
                                                    "\n\t"    //
                AES_ENCODE_KEY_EXPANSION_192(0x01, 1)         // Round 1
                AES_ENCODE_KEY_EXPANSION_192(0x02, 2)         // Round 2
                AES_ENCODE_KEY_EXPANSION_192(0x04, 3)         // Round 3
                AES_ENCODE_KEY_EXPANSION_192(0x08, 4)         // Round 4
                AES_ENCODE_KEY_EXPANSION_192(0x10, 5)         // Round 5
                AES_ENCODE_KEY_EXPANSION_192(0x20, 6)         // Round 6
                AES_ENCODE_KEY_EXPANSION_192(0x40, 7)         // Round 7
                AES_ENCODE_KEY_EXPANSION_192_LAST(0x80)       // Round 8
                                                    "\n\t"    //
        "movaps     (%%rax), %%xmm1"                "\n\t"    //
        "movaps     %%xmm1, 0xC0(%%rbx)"            "\n\t"    //
                                                    "\n\t"    //
                AES_DECODE_KEY_EXPANSION_192(1)               // Round 1
                AES_DECODE_KEY_EXPANSION_192(2)               // Round 2
                AES_DECODE_KEY_EXPANSION_192(3)               // Round 3
                AES_DECODE_KEY_EXPANSION_192(4)               // Round 4
                AES_DECODE_KEY_EXPANSION_192(5)               // Round 5
                AES_DECODE_KEY_EXPANSION_192(6)               // Round 6
                AES_DECODE_KEY_EXPANSION_192(7)               // Round 7
                AES_DECODE_KEY_EXPANSION_192(8)               // Round 8
                AES_DECODE_KEY_EXPANSION_192(9)               // Round 9
                AES_DECODE_KEY_EXPANSION_192(10)              // Round 10
                AES_DECODE_KEY_EXPANSION_192(11)              // Round 11
                                                    "\n\t"    //
        "movaps     0xC0(%%rax), %%xmm1"            "\n\t"    //
        "movaps     %%xmm1, (%%rbx)"                "\n\t"    //
            :                                                 // Output parameters
            :                                                 // Input parameters
                "m" (key[0]),                                 // 'm' - use memory
                "m" (key[8]),                                 // 'm' - use memory
                "a" (mEncodeKey),                             // 'a' - RAX
                "b" (mDecodeKey)                              // 'b' - RBX
    );
    // Ignore CppAlignmentVerifier [END]



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



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movaps     %0, %%xmm1"         "\n\t"    // movaps     (%rsi), %xmm1   # Put 16 bytes of source block to XMM1
        "movaps     (%%rax), %%xmm2"    "\n\t"    // movaps     (%rax), %xmm2   # Put 16 bytes of mEncodeKey to XMM2
                                        "\n\t"    //
        "pxor       %%xmm2, %%xmm1"     "\n\t"    // pxor       %xmm2, %xmm1    # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1
                                        "\n\t"    //
                AES_ENCODE_ROUND(1)               // Round 1
                AES_ENCODE_ROUND(2)               // Round 2
                AES_ENCODE_ROUND(3)               // Round 3
                AES_ENCODE_ROUND(4)               // Round 4
                AES_ENCODE_ROUND(5)               // Round 5
                AES_ENCODE_ROUND(6)               // Round 6
                AES_ENCODE_ROUND(7)               // Round 7
                AES_ENCODE_ROUND(8)               // Round 8
                AES_ENCODE_ROUND(9)               // Round 9
                AES_ENCODE_ROUND_LAST(10)         // Round 10
                                        "\n\t"    //
        "movaps     %%xmm1, %1"         "\n\t"    // movaps     %xmm1, (%rdx)   # Put content of XMM1 to 16 bytes of destination block
            :                                     // Output parameters
            :                                     // Input parameters
                "m" (*sourceAddress),             // 'm' - use memory
                "m" (*destinationAddress),        // 'm' - use memory
                "a" (mEncodeKey)                  // 'a' - RAX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movaps     %0, %%xmm1"         "\n\t"    // movaps     (%rsi), %xmm1   # Put 16 bytes of source block to XMM1
        "movaps     (%%rax), %%xmm2"    "\n\t"    // movaps     (%rax), %xmm2   # Put 16 bytes of mEncodeKey to XMM2
                                        "\n\t"    //
        "pxor       %%xmm2, %%xmm1"     "\n\t"    // pxor       %xmm2, %xmm1    # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1
                                        "\n\t"    //
                AES_ENCODE_ROUND(1)               // Round 1
                AES_ENCODE_ROUND(2)               // Round 2
                AES_ENCODE_ROUND(3)               // Round 3
                AES_ENCODE_ROUND(4)               // Round 4
                AES_ENCODE_ROUND(5)               // Round 5
                AES_ENCODE_ROUND(6)               // Round 6
                AES_ENCODE_ROUND(7)               // Round 7
                AES_ENCODE_ROUND(8)               // Round 8
                AES_ENCODE_ROUND(9)               // Round 9
                AES_ENCODE_ROUND(10)              // Round 10
                AES_ENCODE_ROUND(11)              // Round 11
                AES_ENCODE_ROUND_LAST(12)         // Round 12
                                        "\n\t"    //
        "movaps     %%xmm1, %1"         "\n\t"    // movaps     %xmm1, (%rdx)   # Put content of XMM1 to 16 bytes of destination block
            :                                     // Output parameters
            :                                     // Input parameters
                "m" (*sourceAddress),             // 'm' - use memory
                "m" (*destinationAddress),        // 'm' - use memory
                "a" (mEncodeKey)                  // 'a' - RAX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock256(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movaps     %0, %%xmm1"         "\n\t"    // movaps     (%rsi), %xmm1   # Put 16 bytes of source block to XMM1
        "movaps     (%%rax), %%xmm2"    "\n\t"    // movaps     (%rax), %xmm2   # Put 16 bytes of mEncodeKey to XMM2
                                        "\n\t"    //
        "pxor       %%xmm2, %%xmm1"     "\n\t"    // pxor       %xmm2, %xmm1    # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1
                                        "\n\t"    //
                AES_ENCODE_ROUND(1)               // Round 1
                AES_ENCODE_ROUND(2)               // Round 2
                AES_ENCODE_ROUND(3)               // Round 3
                AES_ENCODE_ROUND(4)               // Round 4
                AES_ENCODE_ROUND(5)               // Round 5
                AES_ENCODE_ROUND(6)               // Round 6
                AES_ENCODE_ROUND(7)               // Round 7
                AES_ENCODE_ROUND(8)               // Round 8
                AES_ENCODE_ROUND(9)               // Round 9
                AES_ENCODE_ROUND(10)              // Round 10
                AES_ENCODE_ROUND(11)              // Round 11
                AES_ENCODE_ROUND(12)              // Round 12
                AES_ENCODE_ROUND(13)              // Round 13
                AES_ENCODE_ROUND_LAST(14)         // Round 14
                                        "\n\t"    //
        "movaps     %%xmm1, %1"         "\n\t"    // movaps     %xmm1, (%rdx)   # Put content of XMM1 to 16 bytes of destination block
            :                                     // Output parameters
            :                                     // Input parameters
                "m" (*sourceAddress),             // 'm' - use memory
                "m" (*destinationAddress),        // 'm' - use memory
                "a" (mEncodeKey)                  // 'a' - RAX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movaps     %0, %%xmm1"         "\n\t"    // movaps     (%rsi), %xmm1   # Put 16 bytes of source block to XMM1
        "movaps     (%%rax), %%xmm2"    "\n\t"    // movaps     (%rax), %xmm2   # Put 16 bytes of mDecodeKey to XMM2
                                        "\n\t"    //
        "pxor       %%xmm2, %%xmm1"     "\n\t"    // pxor       %xmm2, %xmm1    # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1
                                        "\n\t"    //
                AES_DECODE_ROUND(1)               // Round 1
                AES_DECODE_ROUND(2)               // Round 2
                AES_DECODE_ROUND(3)               // Round 3
                AES_DECODE_ROUND(4)               // Round 4
                AES_DECODE_ROUND(5)               // Round 5
                AES_DECODE_ROUND(6)               // Round 6
                AES_DECODE_ROUND(7)               // Round 7
                AES_DECODE_ROUND(8)               // Round 8
                AES_DECODE_ROUND(9)               // Round 9
                AES_DECODE_ROUND_LAST(10)         // Round 10
                                        "\n\t"    //
        "movaps     %%xmm1, %1"         "\n\t"    // movaps     %xmm1, (%rdx)   # Put content of XMM1 to 16 bytes of destination block
            :                                     // Output parameters
            :                                     // Input parameters
                "m" (*sourceAddress),             // 'm' - use memory
                "m" (*destinationAddress),        // 'm' - use memory
                "a" (mDecodeKey)                  // 'a' - RAX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movaps     %0, %%xmm1"         "\n\t"    // movaps     (%rsi), %xmm1   # Put 16 bytes of source block to XMM1
        "movaps     (%%rax), %%xmm2"    "\n\t"    // movaps     (%rax), %xmm2   # Put 16 bytes of mDecodeKey to XMM2
                                        "\n\t"    //
        "pxor       %%xmm2, %%xmm1"     "\n\t"    // pxor       %xmm2, %xmm1    # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1
                                        "\n\t"    //
                AES_DECODE_ROUND(1)               // Round 1
                AES_DECODE_ROUND(2)               // Round 2
                AES_DECODE_ROUND(3)               // Round 3
                AES_DECODE_ROUND(4)               // Round 4
                AES_DECODE_ROUND(5)               // Round 5
                AES_DECODE_ROUND(6)               // Round 6
                AES_DECODE_ROUND(7)               // Round 7
                AES_DECODE_ROUND(8)               // Round 8
                AES_DECODE_ROUND(9)               // Round 9
                AES_DECODE_ROUND(10)              // Round 10
                AES_DECODE_ROUND(11)              // Round 11
                AES_DECODE_ROUND_LAST(12)         // Round 12
                                        "\n\t"    //
        "movaps     %%xmm1, %1"         "\n\t"    // movaps     %xmm1, (%rdx)   # Put content of XMM1 to 16 bytes of destination block
            :                                     // Output parameters
            :                                     // Input parameters
                "m" (*sourceAddress),             // 'm' - use memory
                "m" (*destinationAddress),        // 'm' - use memory
                "a" (mDecodeKey)                  // 'a' - RAX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock256(u8 *sourceAddress, u8 *destinationAddress)
{
    COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress));

    COMMON_ASSERT(sourceAddress,      "sourceAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(destinationAddress, "destinationAddress is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movaps     %0, %%xmm1"         "\n\t"    // movaps     (%rsi), %xmm1   # Put 16 bytes of source block to XMM1
        "movaps     (%%rax), %%xmm2"    "\n\t"    // movaps     (%rax), %xmm2   # Put 16 bytes of mDecodeKey to XMM2
                                        "\n\t"    //
        "pxor       %%xmm2, %%xmm1"     "\n\t"    // pxor       %xmm2, %xmm1    # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1
                                        "\n\t"    //
                AES_DECODE_ROUND(1)               // Round 1
                AES_DECODE_ROUND(2)               // Round 2
                AES_DECODE_ROUND(3)               // Round 3
                AES_DECODE_ROUND(4)               // Round 4
                AES_DECODE_ROUND(5)               // Round 5
                AES_DECODE_ROUND(6)               // Round 6
                AES_DECODE_ROUND(7)               // Round 7
                AES_DECODE_ROUND(8)               // Round 8
                AES_DECODE_ROUND(9)               // Round 9
                AES_DECODE_ROUND(10)              // Round 10
                AES_DECODE_ROUND(11)              // Round 11
                AES_DECODE_ROUND(12)              // Round 12
                AES_DECODE_ROUND(13)              // Round 13
                AES_DECODE_ROUND_LAST(14)         // Round 14
                                        "\n\t"    //
        "movaps     %%xmm1, %1"         "\n\t"    // movaps     %xmm1, (%rdx)   # Put content of XMM1 to 16 bytes of destination block
            :                                     // Output parameters
            :                                     // Input parameters
                "m" (*sourceAddress),             // 'm' - use memory
                "m" (*destinationAddress),        // 'm' - use memory
                "a" (mDecodeKey)                  // 'a' - RAX
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}
