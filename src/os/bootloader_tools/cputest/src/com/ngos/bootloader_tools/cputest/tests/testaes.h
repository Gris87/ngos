#ifndef CPUTEST_SRC_BITS64_TESTS_TESTAES_H
#define CPUTEST_SRC_BITS64_TESTS_TESTAES_H



#include "src/bits64/tests/testbase.h"

#include <common/src/bits64/cryptography/aes.h>



class TestAes: public TestBase
{
public:
    TestAes(); // TEST: NO
    ~TestAes(); // TEST: NO

    AES& getAES(); // TEST: NO

private:
    AES mAES;
};



#endif // CPUTEST_SRC_BITS64_TESTS_TESTAES_H
