#ifndef OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_MD5_H
#define OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_MD5_H



#include <common/src/bits64/checksum/lib/md5hash.h>
#include <ngos/status.h>



#define MD5_BLOCK_SIZE 64



class MD5
{
public:
    MD5();
    ~MD5(); // TEST: NO

    static Md5Hash md5(u8 *data, u64 length);

    NgosStatus update(u8 *data, u64 length);
    NgosStatus finish();

    Md5Hash getResult() const;

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NgosStatus transform(u8 *block);
    static NgosStatus decode(u8 *input, u64 length, u32 *output);
    static NgosStatus encode(u32 *input, u64 length, u8 *output);

    bool    mFinished;
    u8      mBuffer[MD5_BLOCK_SIZE];
    u32     mCount[2];
    u32     mState[4];
    Md5Hash mResult;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CHECKSUM_MD5_H
