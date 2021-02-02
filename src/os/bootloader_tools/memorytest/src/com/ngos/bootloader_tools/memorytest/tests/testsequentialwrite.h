#ifndef COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTSEQUENTIALWRITE_H
#define COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTSEQUENTIALWRITE_H



#include <com/ngos/bootloader_tools/memorytest/tests/testbase.h>



class TestSequentialWrite: public TestBase
{
public:
    TestSequentialWrite(); // TEST: NO
    ~TestSequentialWrite(); // TEST: NO

    bad_uint8* getBuffer() const; // TEST: NO

private:
    bad_uint8 *mBuffer;
};



#endif // COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTSEQUENTIALWRITE_H
