#include "md5.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



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
    return (x & y) | ((~x) & z);
}

inline u32 G(u32 x, u32 y, u32 z)
{
    return (x & z) | (y & (~z));
}

inline u32 H(u32 x, u32 y, u32 z)
{
    return x ^ y ^ z;
}

inline u32 I(u32 x, u32 y, u32 z)
{
    return y ^ (x | (~z));
}

inline u32 rotateLeft(u32 x, int n)
{
    return (x << n) | (x >> (32 - n));
}



inline void FF(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    a = rotateLeft(a + F(b, c, d) + x + ac, s) + b;
}

inline void GG(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    a = rotateLeft(a + G(b, c, d) + x + ac, s) + b;
}

inline void HH(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    a = rotateLeft(a + H(b, c, d) + x + ac, s) + b;
}

inline void II(u32 &a, u32 b, u32 c, u32 d, u32 x, u32 s, u32 ac)
{
    a = rotateLeft(a + I(b, c, d) + x + ac, s) + b;
}



MD5::MD5()
    : mFinished(false)
    , mBuffer()
    , mCount()
    , mState()
    , mResult(0, 0)
{
    COMMON_LT((""));



    memzero(mCount, sizeof(mCount));

    mState[0] = 0x67452301;
    mState[1] = 0xEFCDAB89;
    mState[2] = 0x98BADCFE;
    mState[3] = 0x10325476;
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

    COMMON_ASSERT_EXECUTION(temp.update(data, length), Md5Hash(0, 0));
    COMMON_ASSERT_EXECUTION(temp.finish(),             Md5Hash(0, 0));



    return temp.getResult();
}

NgosStatus MD5::update(u8 *data, u64 length)
{
    COMMON_LT((" | data = 0x%p, length = %u", data, length));

    COMMON_ASSERT(data,       "data is null",   NgosStatus::ASSERTION);
    COMMON_ASSERT(length > 0, "length is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(!mFinished, NgosStatus::ASSERTION);



    u8 index     = (mCount[0] >> 3) % MD5_BLOCK_SIZE; // ">> 3" == "/ 8"
    u8 firstPart = MD5_BLOCK_SIZE - index;



    u64 numberOfBits = length << 3;



    mCount[0] += numberOfBits;

    if (mCount[0] < numberOfBits)
    {
        ++mCount[1];
    }

    mCount[1] += (length >> 29);



    i64 i;

    if (length >= firstPart)
    {
        memcpy(&mBuffer[index], data, firstPart);
        COMMON_ASSERT_EXECUTION(transform(mBuffer), NgosStatus::ASSERTION);

        for (i = firstPart; i + MD5_BLOCK_SIZE <= (i64)length; i += MD5_BLOCK_SIZE)
        {
            COMMON_ASSERT_EXECUTION(transform(&data[i]), NgosStatus::ASSERTION);
        }

        index = 0;
    }
    else
    {
        i = 0;
    }

    memcpy(&mBuffer[index], &data[i], length - i);



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

        COMMON_ASSERT_EXECUTION(encode(mCount, sizeof(mCount), bits), NgosStatus::ASSERTION);



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



        u8 index         = (mCount[0] >> 3) % MD5_BLOCK_SIZE; // ">> 3" == "/ 8"
        u8 paddingLength = (index < MD5_BLOCK_SIZE - 8) ? (MD5_BLOCK_SIZE - index - 8) : ((MD5_BLOCK_SIZE << 1) - index - 8); // "<< 1" == "* 2"

        COMMON_TEST_ASSERT(paddingLength < MD5_BLOCK_SIZE, NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(update(padding, paddingLength), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(update(bits,    sizeof(bits)),  NgosStatus::ASSERTION);



        COMMON_TEST_ASSERT(sizeof(mState) == sizeof(mResult), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(encode(mState, sizeof(mState), mResult.bytes), NgosStatus::ASSERTION);



        mFinished = true;
    }



    return NgosStatus::OK;
}

Md5Hash MD5::getResult() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    COMMON_TEST_ASSERT(mFinished, Md5Hash(0, 0));



    return mResult;
}

NgosStatus MD5::transform(u8 block[MD5_BLOCK_SIZE])
{
    // COMMON_LT((" | block = 0x%p", block)); // Commented to avoid too frequent logs

    COMMON_ASSERT(block, "block is null", NgosStatus::ASSERTION);



    u32 a = mState[0];
    u32 b = mState[1];
    u32 c = mState[2];
    u32 d = mState[3];

    u32 x[MD5_BLOCK_SIZE >> 2]; // ">> 2" == "/ 4"
    COMMON_ASSERT_EXECUTION(decode(block, MD5_BLOCK_SIZE, x), NgosStatus::ASSERTION);



    // Round 1
    FF(a, b, c, d, x[0],  S11, 0xd76aa478); // 1
    FF(d, a, b, c, x[1],  S12, 0xe8c7b756); // 2
    FF(c, d, a, b, x[2],  S13, 0x242070db); // 3
    FF(b, c, d, a, x[3],  S14, 0xc1bdceee); // 4
    FF(a, b, c, d, x[4],  S11, 0xf57c0faf); // 5
    FF(d, a, b, c, x[5],  S12, 0x4787c62a); // 6
    FF(c, d, a, b, x[6],  S13, 0xa8304613); // 7
    FF(b, c, d, a, x[7],  S14, 0xfd469501); // 8
    FF(a, b, c, d, x[8],  S11, 0x698098d8); // 9
    FF(d, a, b, c, x[9],  S12, 0x8b44f7af); // 10
    FF(c, d, a, b, x[10], S13, 0xffff5bb1); // 11
    FF(b, c, d, a, x[11], S14, 0x895cd7be); // 12
    FF(a, b, c, d, x[12], S11, 0x6b901122); // 13
    FF(d, a, b, c, x[13], S12, 0xfd987193); // 14
    FF(c, d, a, b, x[14], S13, 0xa679438e); // 15
    FF(b, c, d, a, x[15], S14, 0x49b40821); // 16

    // Round 2
    GG(a, b, c, d, x[1],  S21, 0xf61e2562); // 17
    GG(d, a, b, c, x[6],  S22, 0xc040b340); // 18
    GG(c, d, a, b, x[11], S23, 0x265e5a51); // 19
    GG(b, c, d, a, x[0],  S24, 0xe9b6c7aa); // 20
    GG(a, b, c, d, x[5],  S21, 0xd62f105d); // 21
    GG(d, a, b, c, x[10], S22, 0x02441453); // 22
    GG(c, d, a, b, x[15], S23, 0xd8a1e681); // 23
    GG(b, c, d, a, x[4],  S24, 0xe7d3fbc8); // 24
    GG(a, b, c, d, x[9],  S21, 0x21e1cde6); // 25
    GG(d, a, b, c, x[14], S22, 0xc33707d6); // 26
    GG(c, d, a, b, x[3],  S23, 0xf4d50d87); // 27
    GG(b, c, d, a, x[8],  S24, 0x455a14ed); // 28
    GG(a, b, c, d, x[13], S21, 0xa9e3e905); // 29
    GG(d, a, b, c, x[2],  S22, 0xfcefa3f8); // 30
    GG(c, d, a, b, x[7],  S23, 0x676f02d9); // 31
    GG(b, c, d, a, x[12], S24, 0x8d2a4c8a); // 32

    // Round 3
    HH(a, b, c, d, x[5],  S31, 0xfffa3942); // 33
    HH(d, a, b, c, x[8],  S32, 0x8771f681); // 34
    HH(c, d, a, b, x[11], S33, 0x6d9d6122); // 35
    HH(b, c, d, a, x[14], S34, 0xfde5380c); // 36
    HH(a, b, c, d, x[1],  S31, 0xa4beea44); // 37
    HH(d, a, b, c, x[4],  S32, 0x4bdecfa9); // 38
    HH(c, d, a, b, x[7],  S33, 0xf6bb4b60); // 39
    HH(b, c, d, a, x[10], S34, 0xbebfbc70); // 40
    HH(a, b, c, d, x[13], S31, 0x289b7ec6); // 41
    HH(d, a, b, c, x[0],  S32, 0xeaa127fa); // 42
    HH(c, d, a, b, x[3],  S33, 0xd4ef3085); // 43
    HH(b, c, d, a, x[6],  S34, 0x04881d05); // 44
    HH(a, b, c, d, x[9],  S31, 0xd9d4d039); // 45
    HH(d, a, b, c, x[12], S32, 0xe6db99e5); // 46
    HH(c, d, a, b, x[15], S33, 0x1fa27cf8); // 47
    HH(b, c, d, a, x[2],  S34, 0xc4ac5665); // 48

    // Round 4
    II(a, b, c, d, x[0],  S41, 0xf4292244); // 49
    II(d, a, b, c, x[7],  S42, 0x432aff97); // 50
    II(c, d, a, b, x[14], S43, 0xab9423a7); // 51
    II(b, c, d, a, x[5],  S44, 0xfc93a039); // 52
    II(a, b, c, d, x[12], S41, 0x655b59c3); // 53
    II(d, a, b, c, x[3],  S42, 0x8f0ccc92); // 54
    II(c, d, a, b, x[10], S43, 0xffeff47d); // 55
    II(b, c, d, a, x[1],  S44, 0x85845dd1); // 56
    II(a, b, c, d, x[8],  S41, 0x6fa87e4f); // 57
    II(d, a, b, c, x[15], S42, 0xfe2ce6e0); // 58
    II(c, d, a, b, x[6],  S43, 0xa3014314); // 59
    II(b, c, d, a, x[13], S44, 0x4e0811a1); // 60
    II(a, b, c, d, x[4],  S41, 0xf7537e82); // 61
    II(d, a, b, c, x[11], S42, 0xbd3af235); // 62
    II(c, d, a, b, x[2],  S43, 0x2ad7d2bb); // 63
    II(b, c, d, a, x[9],  S44, 0xeb86d391); // 64



    mState[0] += a;
    mState[1] += b;
    mState[2] += c;
    mState[3] += d;



    return NgosStatus::OK;
}

NgosStatus MD5::decode(u8 *input, u64 length, u32 *output)
{
    // COMMON_LT((" | input = 0x%p, length = %u, output = 0x%p", input, length, output)); // Commented to avoid too frequent logs

    COMMON_ASSERT(input,      "input is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(length > 0, "length is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(output,     "output is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < (i64)length; i += 4)
    {
        *output = ((u32)input[i])
                | ((u32)input[i + 1] << 8)
                | ((u32)input[i + 2] << 16)
                | ((u32)input[i + 3] << 24);

        ++output;
    }



    return NgosStatus::OK;
}

NgosStatus MD5::encode(u32 *input, u64 length, u8 *output)
{
    // COMMON_LT((" | input = 0x%p, length = %u, output = 0x%p", input, length, output)); // Commented to avoid too frequent logs

    COMMON_ASSERT(input,      "input is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(length > 0, "length is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(output,     "output is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < (i64)length; i += 4)
    {
      output[i]     = *input         & 0xFF;
      output[i + 1] = (*input >> 8)  & 0xFF;
      output[i + 2] = (*input >> 16) & 0xFF;
      output[i + 3] = (*input >> 24) & 0xFF;

      ++input;
    }



    return NgosStatus::OK;
}
