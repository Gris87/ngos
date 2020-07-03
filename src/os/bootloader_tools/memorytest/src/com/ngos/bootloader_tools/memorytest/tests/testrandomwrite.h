#ifndef MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTRANDOMWRITE_H
#define MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTRANDOMWRITE_H



#include "com/ngos/bootloader_tools/memorytest/tests/testbase.h"



class TestRandomWrite: public TestBase
{
public:
    TestRandomWrite(); // TEST: NO
    ~TestRandomWrite(); // TEST: NO

    u8* getBuffer() const; // TEST: NO

private:
    u8 *mBuffer;
};



#endif // MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTRANDOMWRITE_H
