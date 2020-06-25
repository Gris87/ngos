#ifndef MEMORYTEST_SRC_BITS64_TESTS_TESTRANDOMWRITE_H
#define MEMORYTEST_SRC_BITS64_TESTS_TESTRANDOMWRITE_H



#include "src/bits64/tests/testbase.h"



class TestRandomWrite: public TestBase
{
public:
    TestRandomWrite(); // TEST: NO
    ~TestRandomWrite(); // TEST: NO

    u8* getBuffer() const; // TEST: NO

private:
    u8 *mBuffer;
};



#endif // MEMORYTEST_SRC_BITS64_TESTS_TESTRANDOMWRITE_H
