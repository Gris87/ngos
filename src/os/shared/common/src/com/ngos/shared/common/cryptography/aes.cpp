#include "aes.h"

#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/macro/utils.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/utils.h>



// Ignore CppAlignmentVerifier [BEGIN]
#define __AES_KEY_EXPANSION(roundConstant, xmm1, xmm2, order) \
    "aeskeygenassist    $" #roundConstant ", %%" #xmm1 ", %%xmm2"   "\n\t"    /* aeskeygenassist    $0x01, %xmm1, %xmm2     # Assist in AES round key generation using an 8 bits Round Constant */                                                                                                                                                                              \
                                                                    "\n\t"                                                                                                                                                                                                                                                                                                      \
    "pshufd             $" #order ", %%xmm2, %%xmm2"                "\n\t"    /* pshufd             $0xFF, %xmm2, %xmm2     # Shuffle the doublewords in XMM2 based on the encoding in first argument and store the result in XMM2                                                              # XMM2[0] = XMM2[3], XMM2[1] = XMM2[3], XMM2[2] = XMM2[3], XMM2[3] = XMM2[3] */ \
    "shufps             $0x10, %%" #xmm2 ", %%xmm3"                 "\n\t"    /* shufps             $0x10, %xmm1, %xmm3     # Select from quadruplet of single-precision floating-point values in XMM3 and XMM1 using encoding in first argument, interleaved result pairs are stored in XMM3   # XMM3[0] = XMM3[0], XMM3[1] = XMM3[0], XMM3[2] = XMM1[1], XMM3[3] = XMM1[0] */ \
    "pxor               %%xmm3, %%" #xmm2 ""                        "\n\t"    /* pxor               %xmm3, %xmm1            # Perform bitwise XOR of XMM3 and XMM1 and store the result in XMM1 */                                                                                                                                                                              \
    "shufps             $0x8C, %%" #xmm2 ", %%xmm3"                 "\n\t"    /* shufps             $0x8C, %xmm1, %xmm3     # Select from quadruplet of single-precision floating-point values in XMM3 and XMM1 using encoding in first argument, interleaved result pairs are stored in XMM3   # XMM3[0] = XMM3[0], XMM3[1] = XMM3[3], XMM3[2] = XMM1[0], XMM3[3] = XMM1[2] */ \
    "pxor               %%xmm3, %%" #xmm2 ""                        "\n\t"    /* pxor               %xmm3, %xmm1            # Perform bitwise XOR of XMM3 and XMM1 and store the result in XMM1 */                                                                                                                                                                              \
    "pxor               %%xmm2, %%" #xmm2 ""                        "\n\t"    /* pxor               %xmm2, %xmm1            # Perform bitwise XOR of XMM2 and XMM1 and store the result in XMM1 */



#define __AES_KEY_EXPANSION_128(roundConstant) \
    __AES_KEY_EXPANSION(roundConstant, xmm1, xmm1, 0xFF)



#define AES_KEY_EXPANSION_128(roundConstant, round) \
    __AES_KEY_EXPANSION_128(roundConstant)                                                                                                                                                                                  \
                                                                        "\n\t"                                                                                                                                              \
    "aesimc     %%xmm1, %%xmm4"                                         "\n\t"    /* aesimc     %xmm1, %xmm4    # Perform the InvMixColumn transformation on a 128-bit round key from XMM1 and store the result in XMM4 */  \
    "movaps     %%xmm1, " PP_STRINGIZE(round * 16)        "(%%rax)"     "\n\t"    /* movaps     %xmm1, (%rax)   # Put content of XMM1 to 16 bytes of mEncodeKey // Ignore CppShiftVerifier */                               \
    "movaps     %%xmm4, " PP_STRINGIZE((10 - round) * 16) "(%%rbx)"     "\n\t"    /* movaps     %xmm4, (%rbx)   # Put content of XMM4 to 16 bytes of mDecodeKey // Ignore CppShiftVerifier */



#define AES_KEY_EXPANSION_128_LAST(roundConstant) \
    __AES_KEY_EXPANSION_128(roundConstant)                                                                                              \
                                        "\n\t"                                                                                          \
    "movaps     %%xmm1, 0xA0(%%rax)"    "\n\t"    /* movaps     %xmm1, 0xA0(%rax)   # Put content of XMM1 to 16 bytes of mEncodeKey */  \
    "movaps     %%xmm1, (%%rbx)"        "\n\t"    /* movaps     %xmm1, (%rbx)       # Put content of XMM1 to 16 bytes of mDecodeKey */



#define __AES_ENCODE_KEY_EXPANSION_192(roundConstant) \
    __AES_KEY_EXPANSION(roundConstant, xmm4, xmm1, 0xFF)



#define __AES_ENCODE_KEY_EXPANSION_192_COMMON(roundConstant) \
    __AES_ENCODE_KEY_EXPANSION_192(roundConstant)                                                                                                                                                                                                                                                                                               \
                                            "\n\t"                                                                                                                                                                                                                                                                                              \
    "movaps     %%xmm4, %%xmm5"             "\n\t"    /* movaps     %xmm4, %xmm5            # Put content of XMM4 to XMM5 */                                                                                                                                                                                                                    \
    "pslldq     $0x04, %%xmm5"              "\n\t"    /* pslldq     $0x04, %xmm5            # Shift 4 bytes in XMM5 to left */                                                                                                                                                                                                                  \
    "shufps     $0xF0, %%xmm1, %%xmm6"      "\n\t"    /* shufps     $0xF0, %xmm1, %xmm6     # Select from quadruplet of single-precision floating-point values in XMM6 and XMM1 using encoding in first argument, interleaved result pairs are stored in XMM6   # XMM6[0] = XMM6[0], XMM6[1] = XMM6[0], XMM6[2] = XMM1[3], XMM6[3] = XMM1[3] */ \
    "pxor       %%xmm5, %%xmm6"             "\n\t"    /* pxor       %xmm5, %xmm6            # Perform bitwise XOR of XMM5 and XMM6 and store the result in XMM6 */                                                                                                                                                                              \
    "pxor       %%xmm6, %%xmm4"             "\n\t"    /* pxor       %xmm6, %xmm4            # Perform bitwise XOR of XMM6 and XMM4 and store the result in XMM4 */                                                                                                                                                                              \
    "pshufd     $0x0E, %%xmm4, %%xmm7"      "\n\t"    /* pshufd     $0x0E, %xmm4, %xmm7     # Shuffle the doublewords in XMM4 based on the encoding in first argument and store the result in XMM7  # XMM7[0] = XMM4[2], XMM7[1] = XMM4[3], XMM7[2] = XMM4[0], XMM7[3] = XMM4[0] */



#define AES_ENCODE_KEY_EXPANSION_192_ODD(roundConstant, round) \
    __AES_ENCODE_KEY_EXPANSION_192_COMMON(roundConstant)                                                                                                                \
                                                                    "\n\t"                                                                                              \
    "movups     %%xmm1, " PP_STRINGIZE(round * 24) "(%%rax)"        "\n\t"    /* movups     %xmm1, (%rax)           # Put content of XMM1 to 16 bytes of mEncodeKey */  \
    "movups     %%xmm7, " PP_STRINGIZE(round * 24 + 16) "(%%rax)"   "\n\t"    /* movups     %xmm7, 0x10(%rax)       # Put content of XMM7 to 16 bytes of mEncodeKey */



#define AES_ENCODE_KEY_EXPANSION_192_EVEN(roundConstant, round) \
    __AES_ENCODE_KEY_EXPANSION_192_COMMON(roundConstant)                                                                                                                \
                                                                    "\n\t"                                                                                              \
    "movaps     %%xmm1, " PP_STRINGIZE(round * 24) "(%%rax)"        "\n\t"    /* movaps     %xmm1, (%rax)           # Put content of XMM1 to 16 bytes of mEncodeKey */  \
    "movaps     %%xmm7, " PP_STRINGIZE(round * 24 + 16) "(%%rax)"   "\n\t"    /* movaps     %xmm7, 0x10(%rax)       # Put content of XMM7 to 16 bytes of mEncodeKey */



#define AES_ENCODE_KEY_EXPANSION_192_LAST(roundConstant) \
    __AES_ENCODE_KEY_EXPANSION_192(roundConstant)                                                                                       \
                                        "\n\t"                                                                                          \
    "movaps     %%xmm1, 0xC0(%%rax)"    "\n\t"    /* movaps     %xmm1, 0xC0(%rax)   # Put content of XMM1 to 16 bytes of mEncodeKey */



#define AES_DECODE_KEY_EXPANSION_192(round) \
    "movaps     " PP_STRINGIZE((12 - round) * 16) "(%%rax), %%xmm0"     "\n\t"    /* movaps     (%rax), %xmm0   # Put 16 bytes from mEncodeKey to XMM0 // Ignore CppShiftVerifier */                                        \
    "aesimc     %%xmm0, %%xmm1"                                         "\n\t"    /* aesimc     %xmm0, %xmm1    # Perform the InvMixColumn transformation on a 128-bit round key from XMM0 and store the result in XMM1 */  \
    "movaps     %%xmm1, " PP_STRINGIZE(round * 16) "(%%rbx)"            "\n\t"    /* movaps     %xmm1, (%rbx)   # Put content of XMM1 to 16 bytes of mDecodeKey // Ignore CppShiftVerifier */



#define __AES_KEY_EXPANSION_256_FOR_XMM1(roundConstant) \
    __AES_KEY_EXPANSION(roundConstant, xmm4, xmm1, 0xFF)



#define __AES_KEY_EXPANSION_256_FOR_XMM4(roundConstant) \
    __AES_KEY_EXPANSION(roundConstant, xmm1, xmm4, 0xAA)



#define AES_KEY_EXPANSION_256(roundConstant, round) \
    __AES_KEY_EXPANSION_256_FOR_XMM1(roundConstant)                                                                                                                                                                                                     \
                                                                                    "\n\t"                                                                                                                                                              \
    "aesimc             %%xmm1, %%xmm5"                                             "\n\t"    /* aesimc             %xmm1, %xmm5            # Perform the InvMixColumn transformation on a 128-bit round key from XMM1 and store the result in XMM5 */  \
    "movaps             %%xmm1, " PP_STRINGIZE(round * 32)       "(%%rax)"          "\n\t"    /* movaps             %xmm1, (%rax)           # Put content of XMM1 to 16 bytes of mEncodeKey // Ignore CppShiftVerifier */                               \
    "movaps             %%xmm5, " PP_STRINGIZE((7 - round) * 32) "(%%rbx)"          "\n\t"    /* movaps             %xmm5, (%rbx)           # Put content of XMM5 to 16 bytes of mDecodeKey // Ignore CppShiftVerifier */                               \
                                                                                    "\n\t"                                                                                                                                                              \
    __AES_KEY_EXPANSION_256_FOR_XMM4(roundConstant)                                                                                                                                                                                                     \
                                                                                    "\n\t"                                                                                                                                                              \
    "aesimc             %%xmm4, %%xmm0"                                             "\n\t"    /* aesimc             %xmm4, %xmm0            # Perform the InvMixColumn transformation on a 128-bit round key from XMM4 and store the result in XMM0 */  \
    "movaps             %%xmm4, " PP_STRINGIZE(round * 32 + 16)       "(%%rax)"     "\n\t"    /* movaps             %xmm4, 0x10(%rax)       # Put content of XMM4 to 16 bytes of mEncodeKey // Ignore CppShiftVerifier */                               \
    "movaps             %%xmm0, " PP_STRINGIZE((7 - round) * 32 - 16) "(%%rbx)"     "\n\t"    /* movaps             %xmm0, -0x10(%rbx)      # Put content of XMM0 to 16 bytes of mDecodeKey // Ignore CppShiftVerifier */



#define AES_KEY_EXPANSION_256_LAST(roundConstant) \
    __AES_KEY_EXPANSION_256_FOR_XMM1(roundConstant)                                                                                     \
                                        "\n\t"                                                                                          \
    "movaps     %%xmm1, 0xE0(%%rax)"    "\n\t"    /* movaps     %xmm1, 0xE0(%rax)   # Put content of XMM1 to 16 bytes of mEncodeKey */  \
    "movaps     %%xmm1, (%%rbx)"        "\n\t"    /* movaps     %xmm1, (%rbx)       # Put content of XMM1 to 16 bytes of mDecodeKey */



#define __AES_ENCODE_DECODE_ROUND(round) \
    "movaps     " PP_STRINGIZE(round * 16) "(%%rax), %%xmm2"    "\n\t"    /* movaps     (%rax), %xmm2   # Put 16 bytes from mEncodeKey / mDecodeKey to XMM2 // Ignore CppShiftVerifier */



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
// Ignore CppAlignmentVerifier [END]



AES::AES()
    : mEncodeBlockFunction(nullptr)
    , mDecodeBlockFunction(nullptr)
    , mEncodeKeyAllocated(nullptr)
    , mDecodeKeyAllocated(nullptr)
    , mEncodeKey(nullptr)
    , mDecodeKey(nullptr)
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs

    COMMON_TEST_ASSERT(CPU::hasFlag(X86Feature::AES));
}

AES::~AES()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | key = 0x%p, size = %u", key, size)); // Commented to avoid bad looking logs

    COMMON_ASSERT(key,      "key is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(releaseKey(), NgosStatus::ASSERTION);

    switch (size * 8)
    {
        case 128:
        {
            mEncodeBlockFunction = &AES::encodeBlock128;
            mDecodeBlockFunction = &AES::decodeBlock128;

            mEncodeKeyAllocated = (u8 *)malloc(12 * 16); // Key should contains of 11 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned // Ignore CppShiftVerifier
            mDecodeKeyAllocated = (u8 *)malloc(12 * 16); // Key should contains of 11 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned // Ignore CppShiftVerifier

            COMMON_TEST_ASSERT(mEncodeKeyAllocated != nullptr, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(mDecodeKeyAllocated != nullptr, NgosStatus::ASSERTION);

            mEncodeKey = (u8 *)(ROUND_UP((address_t)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((address_t)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster

            COMMON_ASSERT_EXECUTION(expandKey128(key), NgosStatus::ASSERTION);
        }
        break;

        case 192:
        {
            mEncodeBlockFunction = &AES::encodeBlock192;
            mDecodeBlockFunction = &AES::decodeBlock192;

            mEncodeKeyAllocated = (u8 *)malloc(14 * 16); // Key should contains of 13 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned // Ignore CppShiftVerifier
            mDecodeKeyAllocated = (u8 *)malloc(14 * 16); // Key should contains of 13 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned // Ignore CppShiftVerifier

            COMMON_TEST_ASSERT(mEncodeKeyAllocated != nullptr, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(mDecodeKeyAllocated != nullptr, NgosStatus::ASSERTION);

            mEncodeKey = (u8 *)(ROUND_UP((address_t)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((address_t)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster

            COMMON_ASSERT_EXECUTION(expandKey192(key), NgosStatus::ASSERTION);
        }
        break;

        case 256:
        {
            mEncodeBlockFunction = &AES::encodeBlock256;
            mDecodeBlockFunction = &AES::decodeBlock256;

            mEncodeKeyAllocated = (u8 *)malloc(16 * 16); // Key should contains of 15 x 16-byte blocks. But we are allocating one more block to let mEncodeKey be aligned // Ignore CppShiftVerifier
            mDecodeKeyAllocated = (u8 *)malloc(16 * 16); // Key should contains of 15 x 16-byte blocks. But we are allocating one more block to let mDecodeKey be aligned // Ignore CppShiftVerifier

            COMMON_TEST_ASSERT(mEncodeKeyAllocated != nullptr, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(mDecodeKeyAllocated != nullptr, NgosStatus::ASSERTION);

            mEncodeKey = (u8 *)(ROUND_UP((address_t)mEncodeKeyAllocated, 16)); // Align mEncodeKey to make AES work faster
            mDecodeKey = (u8 *)(ROUND_UP((address_t)mDecodeKeyAllocated, 16)); // Align mDecodeKey to make AES work faster

            COMMON_ASSERT_EXECUTION(expandKey256(key), NgosStatus::ASSERTION);
        }
        break;

        default:
        {
            COMMON_LF(("Unexpected key size: %u, %s:%u", size, __FILE__, __LINE__));

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
    // COMMON_LT(("")); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | in = 0x%p, inSize = %u, out = 0x%p, outSize = %u, resultSize = 0x%p", in, inSize, out, outSize, resultSize)); // Commented to avoid bad looking logs

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



    i64 blocksCount = inSize / 16;

    for (good_I64 i = 0; i < blocksCount; ++i)
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
    // COMMON_LT((" | in = 0x%p, inSize = %u, out = 0x%p, outSize = %u, resultSize = 0x%p", in, inSize, out, outSize, resultSize)); // Commented to avoid bad looking logs

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



    i64 blocksCount = inSize / 16;

    for (good_I64 i = 0; i < blocksCount; ++i)
    {
        COMMON_ASSERT_EXECUTION((this->*mDecodeBlockFunction)(in, out), NgosStatus::ASSERTION);

        in  += 16;
        out += 16;
    }



    return NgosStatus::OK;
}

NgosStatus AES::expandKey128(u8 *key)
{
    // COMMON_LT((" | key = 0x%p", key)); // Commented to avoid bad looking logs

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movups     %0, %%xmm1"                     "\n\t"    // movups     (%rsi), %xmm1       # Put 16 bytes from key to XMM1
                                                    "\n\t"    //
        "movaps     %%xmm1, (%%rax)"                "\n\t"    // movaps     %xmm1, (%rax)       # Put content of XMM1 to 16 bytes of mEncodeKey
        "movaps     %%xmm1, 0xA0(%%rbx)"            "\n\t"    // movaps     %xmm1, 0xA0(%rbx)   # Put content of XMM1 to 16 bytes of mDecodeKey
                                                    "\n\t"    //
        "pxor       %%xmm3, %%xmm3"                 "\n\t"    // pxor       %xmm3, %xmm3        # Fill XMM3 with zeros
                                                    "\n\t"    //
                AES_KEY_EXPANSION_128(0x01, 1)                // Round 1
                AES_KEY_EXPANSION_128(0x02, 2)                // Round 2
                AES_KEY_EXPANSION_128(0x04, 3)                // Round 3
                AES_KEY_EXPANSION_128(0x08, 4)                // Round 4
                AES_KEY_EXPANSION_128(0x10, 5)                // Round 5
                AES_KEY_EXPANSION_128(0x20, 6)                // Round 6
                AES_KEY_EXPANSION_128(0x40, 7)                // Round 7
                AES_KEY_EXPANSION_128(0x80, 8)                // Round 8
                AES_KEY_EXPANSION_128(0x1B, 9)                // Round 9
                AES_KEY_EXPANSION_128_LAST(0x36)              // Round 10
            :                                                 // Output parameters
            :                                                 // Input parameters
                "m" (*key),                                   // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mEncodeKey),                             // 'a' - RAX // Ignore CppSingleCharVerifier
                "b" (mDecodeKey)                              // 'b' - RBX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::expandKey192(u8 *key)
{
    // COMMON_LT((" | key = 0x%p", key)); // Commented to avoid bad looking logs

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq       %0, %%xmm7"                     "\n\t"    // movq       0x10(%rsi), %xmm7       # Put 8 bytes from key to XMM7
        "movq       %%xmm7, 0x10(%%rax)"            "\n\t"    // movq       %xmm7, 0x10(%%rax)      # Put 8 bytes of XMM7 to mEncodeKey
                                                    "\n\t"    //
        "pshufd     $0x4F, %%xmm7, %%xmm4"          "\n\t"    // pshufd     $0x4F, %xmm7, %xmm4     # Shuffle the doublewords in XMM7 based on the encoding in first argument and store the result in XMM4  # XMM4[0] = XMM7[3], XMM4[1] = XMM7[3], XMM4[2] = XMM7[0], XMM4[3] = XMM7[1]
        "movups     %1, %%xmm1"                     "\n\t"    // movups     (%rsi), %xmm1           # Put 16 bytes from key to XMM1
                                                    "\n\t"    //
        "movaps     %%xmm1, (%%rax)"                "\n\t"    // movaps     %xmm1, (%rax)           # Put content of XMM1 to 16 bytes of mEncodeKey
        "movaps     %%xmm1, 0xC0(%%rbx)"            "\n\t"    // movaps     %xmm1, 0xC0(%rbx)       # Put content of XMM1 to 16 bytes of mDecodeKey
                                                    "\n\t"    //
        "pxor       %%xmm3, %%xmm3"                 "\n\t"    // pxor       %xmm3, %xmm3            # Fill XMM3 with zeros
        "pxor       %%xmm6, %%xmm6"                 "\n\t"    // pxor       %xmm6, %xmm6            # Fill XMM6 with zeros
                                                    "\n\t"    //
                AES_ENCODE_KEY_EXPANSION_192_ODD(0x01,  1)    // Round 1
                AES_ENCODE_KEY_EXPANSION_192_EVEN(0x02, 2)    // Round 2
                AES_ENCODE_KEY_EXPANSION_192_ODD(0x04,  3)    // Round 3
                AES_ENCODE_KEY_EXPANSION_192_EVEN(0x08, 4)    // Round 4
                AES_ENCODE_KEY_EXPANSION_192_ODD(0x10,  5)    // Round 5
                AES_ENCODE_KEY_EXPANSION_192_EVEN(0x20, 6)    // Round 6
                AES_ENCODE_KEY_EXPANSION_192_ODD(0x40,  7)    // Round 7
                AES_ENCODE_KEY_EXPANSION_192_LAST(0x80)       // Round 8
                                                    "\n\t"    //
        "movaps     %%xmm1, (%%rbx)"                "\n\t"    // movaps     %xmm1, (%rbx)           # Put content of XMM1 to 16 bytes of mDecodeKey
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
            :                                                 // Output parameters
            :                                                 // Input parameters
                "m" (key[16]),                                // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (key[0]),                                 // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mEncodeKey),                             // 'a' - RAX // Ignore CppSingleCharVerifier
                "b" (mDecodeKey)                              // 'b' - RBX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::expandKey256(u8 *key)
{
    // COMMON_LT((" | key = 0x%p", key)); // Commented to avoid bad looking logs

    COMMON_ASSERT(key, "key is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movups     %0, %%xmm1"                     "\n\t"    // movups     (%rsi), %xmm1           # Put 16 bytes from key to XMM1
                                                    "\n\t"    //
        "movaps     %%xmm1, (%%rax)"                "\n\t"    // movaps     %xmm1, (%rax)           # Put content of XMM1 to 16 bytes of mEncodeKey
        "movaps     %%xmm1, 0xE0(%%rbx)"            "\n\t"    // movaps     %xmm1, 0xE0(%rbx)       # Put content of XMM1 to 16 bytes of mDecodeKey

        "movups     %1, %%xmm4"                     "\n\t"    // movups     0x10(%rsi), %xmm4       # Put 16 bytes from key to XMM4
        "aesimc     %%xmm4, %%xmm0"                 "\n\t"    // aesimc     %xmm4, %xmm0            # Perform the InvMixColumn transformation on a 128-bit round key from XMM4 and store the result in XMM0
                                                    "\n\t"    //
        "movaps     %%xmm4, 0x10(%%rax)"            "\n\t"    // movaps     %xmm4, 0x10(%rax)       # Put content of XMM4 to 16 bytes of mEncodeKey
        "movaps     %%xmm0, 0xD0(%%rbx)"            "\n\t"    // movaps     %xmm0, 0xD0(%rbx)       # Put content of XMM0 to 16 bytes of mDecodeKey
                                                    "\n\t"    //
        "pxor       %%xmm3, %%xmm3"                 "\n\t"    // pxor       %xmm3, %xmm3            # Fill XMM3 with zeros
                                                    "\n\t"    //
                AES_KEY_EXPANSION_256(0x01, 1)                // Round 1
                AES_KEY_EXPANSION_256(0x02, 2)                // Round 2
                AES_KEY_EXPANSION_256(0x04, 3)                // Round 3
                AES_KEY_EXPANSION_256(0x08, 4)                // Round 4
                AES_KEY_EXPANSION_256(0x10, 5)                // Round 5
                AES_KEY_EXPANSION_256(0x20, 6)                // Round 6
                AES_KEY_EXPANSION_256_LAST(0x40)              // Round 7
            :                                                 // Output parameters
            :                                                 // Input parameters
                "m" (key[0]),                                 // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (key[16]),                                // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mEncodeKey),                             // 'a' - RAX // Ignore CppSingleCharVerifier
                "b" (mDecodeKey)                              // 'b' - RBX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    // COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress)); // Commented to avoid bad looking logs

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
                "m" (*sourceAddress),             // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (*destinationAddress),        // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mEncodeKey)                  // 'a' - RAX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    // COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress)); // Commented to avoid bad looking logs

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
                "m" (*sourceAddress),             // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (*destinationAddress),        // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mEncodeKey)                  // 'a' - RAX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::encodeBlock256(u8 *sourceAddress, u8 *destinationAddress)
{
    // COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress)); // Commented to avoid bad looking logs

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
                "m" (*sourceAddress),             // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (*destinationAddress),        // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mEncodeKey)                  // 'a' - RAX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock128(u8 *sourceAddress, u8 *destinationAddress)
{
    // COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress)); // Commented to avoid bad looking logs

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
                "m" (*sourceAddress),             // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (*destinationAddress),        // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mDecodeKey)                  // 'a' - RAX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock192(u8 *sourceAddress, u8 *destinationAddress)
{
    // COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress)); // Commented to avoid bad looking logs

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
                "m" (*sourceAddress),             // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (*destinationAddress),        // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mDecodeKey)                  // 'a' - RAX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

NgosStatus AES::decodeBlock256(u8 *sourceAddress, u8 *destinationAddress)
{
    // COMMON_LT((" | sourceAddress = 0x%p, destinationAddress = 0x%p", sourceAddress, destinationAddress)); // Commented to avoid bad looking logs

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
                "m" (*sourceAddress),             // 'm' - use memory // Ignore CppSingleCharVerifier
                "m" (*destinationAddress),        // 'm' - use memory // Ignore CppSingleCharVerifier
                "a" (mDecodeKey)                  // 'a' - RAX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}
