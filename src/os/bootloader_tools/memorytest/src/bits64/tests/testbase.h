#ifndef MEMORYTEST_SRC_BITS64_TESTS_TESTBASE_H
#define MEMORYTEST_SRC_BITS64_TESTS_TESTBASE_H



#include <ngos/status.h>
#include <uefi/uefimpservicesprotocol.h>

#include "src/bits64/other/memorytesttype.h"



class TestBase
{
public:
    TestBase(MemoryTestType type, uefi_ap_procedure procedure); // TEST: NO
    ~TestBase(); // TEST: NO

    uefi_ap_procedure getProcedure() const; // TEST: NO

    NgosStatus setScore(u64 score); // TEST: NO
    u64 getScore() const; // TEST: NO

    bool isCompleted() const; // TEST: NO

private:
    uefi_ap_procedure mProcedure;
    u64               mScore;
};



extern TestBase* memoryTests[(u64)MemoryTestType::MAXIMUM]; // memoryTests declared in testbase.cpp file



#endif // MEMORYTEST_SRC_BITS64_TESTS_TESTBASE_H
