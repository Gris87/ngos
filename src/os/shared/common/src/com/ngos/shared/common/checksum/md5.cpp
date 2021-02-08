#include "md5.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21



inline u32 F(u32 x, u32 y, u32 z)
{
    // COMMON_LT((" | x = %u, y = %u, z = %u", x, y, z)); // Commented to avoid too frequent logs



    return (x & y) | ((~x) & z);
}

inline u32 G(u32 x, u32 y, u32 z)
{
    // COMMON_LT((" | x = %u, y = %u, z = %u", x, y, z)); // Commented to avoid too frequent logs



    return (x & z) | (y & (~z));
}

inline u32 H(u32 x, u32 y, u32 z)
{
    // COMMON_LT((" | x = %u, y = %u, z = %u", x, y, z)); // Commented to avoid too frequent logs



    return x ^ y ^ z;
}

inline u32 I(u32 x, u32 y, u32 z)
{
    // COMMON_LT((" | x = %u, y = %u, z = %u", x, y, z)); // Commented to avoid too frequent logs



    return y ^ (x | (~z));
}

inline u32 rotateLeft(u32 x, u8 n)
{
    // COMMON_LT((" | x = %u, n = %d", x, n)); // Commented to avoid too frequent logs

    COMMON_ASSERT(n > 0 && n < 32, "n is invalid", 0);



    return (x << n) | (x >> (32 - n));
}

inline void FF(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    // COMMON_LT((" | a = %u, b = %u, c = %u, d = %u, x = %u, s = %u, ac = %u", a, b, c, d, x, s, ac)); // Commented to avoid too frequent logs



    a = rotateLeft(a + F(b, c, d) + x + ac, s) + b;
}

inline void GG(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    // COMMON_LT((" | a = %u, b = %u, c = %u, d = %u, x = %u, s = %u, ac = %u", a, b, c, d, x, s, ac)); // Commented to avoid too frequent logs



    a = rotateLeft(a + G(b, c, d) + x + ac, s) + b;
}

inline void HH(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    // COMMON_LT((" | a = %u, b = %u, c = %u, d = %u, x = %u, s = %u, ac = %u", a, b, c, d, x, s, ac)); // Commented to avoid too frequent logs



    a = rotateLeft(a + H(b, c, d) + x + ac, s) + b;
}

inline void II(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    // COMMON_LT((" | a = %u, b = %u, c = %u, d = %u, x = %u, s = %u, ac = %u", a, b, c, d, x, s, ac)); // Commented to avoid too frequent logs



    a = rotateLeft(a + I(b, c, d) + x + ac, s) + b;
}



MD5::MD5()
    : mFinished(false)
    , mBuffer()
    , mCount(0)
    , mResult(0xEFCDAB8967452301, 0x1032547698BADCFE)
{
    COMMON_LT((""));
}

MD5::~MD5()
{
    COMMON_LT((""));
}

Md5Hash MD5::md5(u8 *data, u64 length)
{
    COMMON_LT((" | data = 0x%p, length = %u", data, length));

    COMMON_ASSERT(data,       "data is null",   0);
    COMMON_ASSERT(length > 0, "length is zero", 0);



    MD5 temp;

    COMMON_ASSERT_EXECUTION(temp.update(data, length), Md5Hash());
    COMMON_ASSERT_EXECUTION(temp.finish(),             Md5Hash());



    return temp.getResult();
}

NgosStatus MD5::update(u8 *data, u64 length)
{
    COMMON_LT((" | data = 0x%p, length = %u", data, length));

    COMMON_ASSERT(data,       "data is null",   NgosStatus::ASSERTION);
    COMMON_ASSERT(length > 0, "length is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(!mFinished, NgosStatus::ASSERTION);



    u8 index     = (mCount / 8) % MD5_BLOCK_SIZE;
    u8 firstPart = MD5_BLOCK_SIZE - index;



    u64 numberOfBits =  length << 3;
    mCount           += numberOfBits;



    if (length >= firstPart)
    {
        memcpy(&mBuffer[index], data, firstPart);
        COMMON_ASSERT_EXECUTION(transform(mBuffer), NgosStatus::ASSERTION);



        i64 blockIndex = firstPart;

        while (blockIndex <= (i64)length - MD5_BLOCK_SIZE)
        {
            COMMON_ASSERT_EXECUTION(transform(&data[blockIndex]), NgosStatus::ASSERTION);

            blockIndex += MD5_BLOCK_SIZE;
        }

        memcpy(mBuffer, &data[blockIndex], length - blockIndex);
    }
    else
    {
        memcpy(&mBuffer[index], data, length);
    }



    return NgosStatus::OK;
}

NgosStatus MD5::finish()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(!mFinished, NgosStatus::ASSERTION);

    if (!mFinished)
    {
        u8 bits[8];

        COMMON_TEST_ASSERT(sizeof(bits) == sizeof(mCount), NgosStatus::ASSERTION);

        *(u64 *)bits = mCount;



        static u8 padding[MD5_BLOCK_SIZE] =
        {
            0x80, 0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0,
            0,    0, 0, 0, 0, 0, 0, 0
        };



        u8 index         = (mCount / 8) % MD5_BLOCK_SIZE;
        u8 paddingLength = (index < MD5_BLOCK_SIZE - 8) ? (MD5_BLOCK_SIZE - index - 8) : ((MD5_BLOCK_SIZE * 2) - index - 8);

        COMMON_TEST_ASSERT(paddingLength < MD5_BLOCK_SIZE, NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(update(padding, paddingLength), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(update(bits,    sizeof(bits)),  NgosStatus::ASSERTION);



        mFinished = true;
    }



    return NgosStatus::OK;
}

Md5Hash MD5::getResult() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    COMMON_TEST_ASSERT(mFinished, Md5Hash());



    return mResult;
}

NgosStatus MD5::transform(u8 *block)
{
    // COMMON_LT((" | block = 0x%p", block)); // Commented to avoid too frequent logs

    COMMON_ASSERT(block, "block is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(!mFinished, NgosStatus::ASSERTION);



    u32 a = mResult.dwords[0];
    u32 b = mResult.dwords[1];
    u32 c = mResult.dwords[2];
    u32 d = mResult.dwords[3];

    u32 *x = (u32 *)block;



    // Round 1
    FF(a, b, c, d, x[0],  S11, 0xD76AA478); // 1
    FF(d, a, b, c, x[1],  S12, 0xE8C7B756); // 2
    FF(c, d, a, b, x[2],  S13, 0x242070DB); // 3
    FF(b, c, d, a, x[3],  S14, 0xC1BDCEEE); // 4
    FF(a, b, c, d, x[4],  S11, 0xF57C0FAF); // 5
    FF(d, a, b, c, x[5],  S12, 0x4787C62A); // 6
    FF(c, d, a, b, x[6],  S13, 0xA8304613); // 7
    FF(b, c, d, a, x[7],  S14, 0xFD469501); // 8
    FF(a, b, c, d, x[8],  S11, 0x698098D8); // 9
    FF(d, a, b, c, x[9],  S12, 0x8B44F7AF); // 10
    FF(c, d, a, b, x[10], S13, 0xFFFF5BB1); // 11
    FF(b, c, d, a, x[11], S14, 0x895CD7BE); // 12
    FF(a, b, c, d, x[12], S11, 0x6B901122); // 13
    FF(d, a, b, c, x[13], S12, 0xFD987193); // 14
    FF(c, d, a, b, x[14], S13, 0xA679438E); // 15
    FF(b, c, d, a, x[15], S14, 0x49B40821); // 16

    // Round 2
    GG(a, b, c, d, x[1],  S21, 0xF61E2562); // 17
    GG(d, a, b, c, x[6],  S22, 0xC040B340); // 18
    GG(c, d, a, b, x[11], S23, 0x265E5A51); // 19
    GG(b, c, d, a, x[0],  S24, 0xE9B6C7AA); // 20
    GG(a, b, c, d, x[5],  S21, 0xD62F105D); // 21
    GG(d, a, b, c, x[10], S22, 0x02441453); // 22
    GG(c, d, a, b, x[15], S23, 0xD8A1E681); // 23
    GG(b, c, d, a, x[4],  S24, 0xE7D3FBC8); // 24
    GG(a, b, c, d, x[9],  S21, 0x21E1CDE6); // 25
    GG(d, a, b, c, x[14], S22, 0xC33707D6); // 26
    GG(c, d, a, b, x[3],  S23, 0xF4D50D87); // 27
    GG(b, c, d, a, x[8],  S24, 0x455A14ED); // 28
    GG(a, b, c, d, x[13], S21, 0xA9E3E905); // 29
    GG(d, a, b, c, x[2],  S22, 0xFCEFA3F8); // 30
    GG(c, d, a, b, x[7],  S23, 0x676F02D9); // 31
    GG(b, c, d, a, x[12], S24, 0x8D2A4C8A); // 32

    // Round 3
    HH(a, b, c, d, x[5],  S31, 0xFFFA3942); // 33
    HH(d, a, b, c, x[8],  S32, 0x8771F681); // 34
    HH(c, d, a, b, x[11], S33, 0x6D9D6122); // 35
    HH(b, c, d, a, x[14], S34, 0xFDE5380C); // 36
    HH(a, b, c, d, x[1],  S31, 0xA4BEEA44); // 37
    HH(d, a, b, c, x[4],  S32, 0x4BDECFA9); // 38
    HH(c, d, a, b, x[7],  S33, 0xF6BB4B60); // 39
    HH(b, c, d, a, x[10], S34, 0xBEBFBC70); // 40
    HH(a, b, c, d, x[13], S31, 0x289B7EC6); // 41
    HH(d, a, b, c, x[0],  S32, 0xEAA127FA); // 42
    HH(c, d, a, b, x[3],  S33, 0xD4EF3085); // 43
    HH(b, c, d, a, x[6],  S34, 0x04881D05); // 44
    HH(a, b, c, d, x[9],  S31, 0xD9D4D039); // 45
    HH(d, a, b, c, x[12], S32, 0xE6DB99E5); // 46
    HH(c, d, a, b, x[15], S33, 0x1FA27CF8); // 47
    HH(b, c, d, a, x[2],  S34, 0xC4AC5665); // 48

    // Round 4
    II(a, b, c, d, x[0],  S41, 0xF4292244); // 49
    II(d, a, b, c, x[7],  S42, 0x432AFF97); // 50
    II(c, d, a, b, x[14], S43, 0xAB9423A7); // 51
    II(b, c, d, a, x[5],  S44, 0xFC93A039); // 52
    II(a, b, c, d, x[12], S41, 0x655B59C3); // 53
    II(d, a, b, c, x[3],  S42, 0x8F0CCC92); // 54
    II(c, d, a, b, x[10], S43, 0xFFEFF47D); // 55
    II(b, c, d, a, x[1],  S44, 0x85845DD1); // 56
    II(a, b, c, d, x[8],  S41, 0x6FA87E4F); // 57
    II(d, a, b, c, x[15], S42, 0xFE2CE6E0); // 58
    II(c, d, a, b, x[6],  S43, 0xA3014314); // 59
    II(b, c, d, a, x[13], S44, 0x4E0811A1); // 60
    II(a, b, c, d, x[4],  S41, 0xF7537E82); // 61
    II(d, a, b, c, x[11], S42, 0xBD3AF235); // 62
    II(c, d, a, b, x[2],  S43, 0x2AD7D2BB); // 63
    II(b, c, d, a, x[9],  S44, 0xEB86D391); // 64



    mResult.dwords[0] += a;
    mResult.dwords[1] += b;
    mResult.dwords[2] += c;
    mResult.dwords[3] += d;



    return NgosStatus::OK;
}
