#ifndef MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTSEQUENTIALWRITE_H
#define MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTSEQUENTIALWRITE_H



#include "com/ngos/bootloader_tools/memorytest/tests/testbase.h"



class TestSequentialWrite: public TestBase
{
public:
    TestSequentialWrite(); // TEST: NO
    ~TestSequentialWrite(); // TEST: NO

    u8* getBuffer() const; // TEST: NO

private:
    u8 *mBuffer;
};



#endif // MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTSEQUENTIALWRITE_H
