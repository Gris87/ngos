#ifndef OS_SHARED_COMMON_SRC_BITS64_CRYPTOGRAPHY_AES_H
#define OS_SHARED_COMMON_SRC_BITS64_CRYPTOGRAPHY_AES_H



#include <ngos/status.h>



class AES
{
public:
    AES();
    ~AES(); // TEST: NO

    NgosStatus setKey(u8 *key, u8 size);
    NgosStatus releaseKey();

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NgosStatus expandKey128(u8 *key);
    NgosStatus expandKey192(u8 *key);
    NgosStatus encodeBlock128(u8 *sourceAddress, u8 *destinationAddress);
    NgosStatus encodeBlock192(u8 *sourceAddress, u8 *destinationAddress);
    NgosStatus decodeBlock128(u8 *sourceAddress, u8 *destinationAddress);
    NgosStatus decodeBlock192(u8 *sourceAddress, u8 *destinationAddress);



    NgosStatus (AES::*mExpandKeyFunction)(u8 *key);
    NgosStatus (AES::*mEncodeBlockFunction)(u8 *sourceAddress, u8 *destinationAddress);
    NgosStatus (AES::*mDecodeBlockFunction)(u8 *sourceAddress, u8 *destinationAddress);

    u8 *mEncodeKeyAllocated;
    u8 *mDecodeKeyAllocated;
    u8 *mEncodeKey;
    u8 *mDecodeKey;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CRYPTOGRAPHY_AES_H
