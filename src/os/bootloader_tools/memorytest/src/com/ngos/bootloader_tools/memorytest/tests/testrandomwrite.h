#ifndef COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTRANDOMWRITE_H
#define COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTRANDOMWRITE_H



#include <com/ngos/bootloader_tools/memorytest/tests/testbase.h>



class TestRandomWrite: public TestBase
{
public:
    TestRandomWrite(); // TEST: NO
    ~TestRandomWrite(); // TEST: NO

    bad_uint8* getBuffer() const; // TEST: NO

private:
    bad_uint8 *mBuffer;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTRANDOMWRITE_H
