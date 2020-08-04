#ifndef COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTAES_H
#define COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTAES_H



#include <com/ngos/bootloader_tools/cputest/tests/testbase.h>

#include <com/ngos/shared/common/cryptography/aes.h>



class TestAes: public TestBase
{
public:
    TestAes(); // TEST: NO
    ~TestAes(); // TEST: NO

    AES& getAES(); // TEST: NO

private:
    AES mAES;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTAES_H
