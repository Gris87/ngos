#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H



#include <common/src/com/ngos/shared/common/ngos/status.h>



class AES
{
public:
    AES();
    ~AES(); // TEST: NO

    NgosStatus setKey(u8 *key, u8 size);
    NgosStatus releaseKey();

    NgosStatus encode(u8 *in, u64 inSize, u8 *out, u64 outSize, u64 *resultSize);
    NgosStatus decode(u8 *in, u64 inSize, u8 *out, u64 outSize, u64 *resultSize);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NgosStatus expandKey128(u8 *key); // TEST: NO
    NgosStatus expandKey192(u8 *key); // TEST: NO
    NgosStatus expandKey256(u8 *key); // TEST: NO
    NgosStatus encodeBlock128(u8 *sourceAddress, u8 *destinationAddress); // TEST: NO
    NgosStatus encodeBlock192(u8 *sourceAddress, u8 *destinationAddress); // TEST: NO
    NgosStatus encodeBlock256(u8 *sourceAddress, u8 *destinationAddress); // TEST: NO
    NgosStatus decodeBlock128(u8 *sourceAddress, u8 *destinationAddress); // TEST: NO
    NgosStatus decodeBlock192(u8 *sourceAddress, u8 *destinationAddress); // TEST: NO
    NgosStatus decodeBlock256(u8 *sourceAddress, u8 *destinationAddress); // TEST: NO



    NgosStatus (AES::*mEncodeBlockFunction)(u8 *sourceAddress, u8 *destinationAddress);
    NgosStatus (AES::*mDecodeBlockFunction)(u8 *sourceAddress, u8 *destinationAddress);

    u8 *mEncodeKeyAllocated;
    u8 *mDecodeKeyAllocated;
    u8 *mEncodeKey;
    u8 *mDecodeKey;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H
