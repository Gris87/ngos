#ifndef CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTAES_H
#define CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTAES_H



#include "src/com/ngos/bootloader_tools/cputest/tests/testbase.h"

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



#endif // CPUTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTAES_H
