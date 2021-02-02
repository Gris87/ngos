#ifndef COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H
#define COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H



#include <com/ngos/shared/common/ngos/status.h>



class AES
{
public:
    AES();
    ~AES(); // TEST: NO

    NgosStatus setKey(bad_uint8 *key, bad_uint8 size);
    NgosStatus releaseKey();

    NgosStatus encode(bad_uint8 *in, bad_uint64 inSize, bad_uint8 *out, bad_uint64 outSize, bad_uint64 *resultSize);
    NgosStatus decode(bad_uint8 *in, bad_uint64 inSize, bad_uint8 *out, bad_uint64 outSize, bad_uint64 *resultSize);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    NgosStatus expandKey128(bad_uint8 *key); // TEST: NO
    NgosStatus expandKey192(bad_uint8 *key); // TEST: NO
    NgosStatus expandKey256(bad_uint8 *key); // TEST: NO
    NgosStatus encodeBlock128(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress); // TEST: NO
    NgosStatus encodeBlock192(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress); // TEST: NO
    NgosStatus encodeBlock256(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress); // TEST: NO
    NgosStatus decodeBlock128(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress); // TEST: NO
    NgosStatus decodeBlock192(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress); // TEST: NO
    NgosStatus decodeBlock256(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress); // TEST: NO



    NgosStatus (AES::*mEncodeBlockFunction)(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress);
    NgosStatus (AES::*mDecodeBlockFunction)(bad_uint8 *sourceAddress, bad_uint8 *destinationAddress);

    bad_uint8 *mEncodeKeyAllocated;
    bad_uint8 *mDecodeKeyAllocated;
    bad_uint8 *mEncodeKey;
    bad_uint8 *mDecodeKey;
};



#endif // COM_NGOS_SHARED_COMMON_CRYPTOGRAPHY_AES_H
