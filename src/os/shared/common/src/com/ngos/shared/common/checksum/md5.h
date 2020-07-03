#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_MD5_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_MD5_H



#include <com/ngos/shared/common/checksum/lib/md5hash.h>
#include <com/ngos/shared/common/ngos/status.h>



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

    bool    mFinished;
    u8      mBuffer[MD5_BLOCK_SIZE];
    u64     mCount;
    Md5Hash mResult;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CHECKSUM_MD5_H
