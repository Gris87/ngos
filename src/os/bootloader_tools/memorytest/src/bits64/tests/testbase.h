#ifndef MEMORYTEST_SRC_BITS64_TESTS_TESTBASE_H
#define MEMORYTEST_SRC_BITS64_TESTS_TESTBASE_H



#include <ngos/status.h>
#include <macro/constants.h>
#include <uefi/uefimpservicesprotocol.h>

#include "src/bits64/other/memorytesttype.h"



#define TEST_BLOCK_SIZE (1 * MB)



class TestBase
{
public:
    TestBase(MemoryTestType type, uefi_ap_procedure procedure); // TEST: NO
    ~TestBase(); // TEST: NO

    NgosStatus reset(u64 start, u64 end, i64 testSize); // TEST: NO

    uefi_ap_procedure getProcedure() const; // TEST: NO

    NgosStatus setScore(u64 score); // TEST: NO
    u64 getScore() const; // TEST: NO

    bool isCompleted() const; // TEST: NO

    u64 getRegionStart() const; // TEST: NO

    u64 getRegionEnd() const; // TEST: NO

    i64 getTestSize() const; // TEST: NO

    NgosStatus setProgress(i64 progress); // TEST: NO
    i64 getProgress() const; // TEST: NO

    NgosStatus setHandledProgress(i64 progress); // TEST: NO
    i64 getHandledProgress() const; // TEST: NO

    NgosStatus setMaximumSpeed(u64 speed); // TEST: NO
    u64 getMaximumSpeed() const; // TEST: NO

    NgosStatus setStartTsc(u64 tsc); // TEST: NO
    u64 getStartTsc() const; // TEST: NO

    NgosStatus setIntermediateTsc(u64 tsc); // TEST: NO
    u64 getIntermediateTsc() const; // TEST: NO

private:
    uefi_ap_procedure mProcedure;
    u64               mScore;
    u64               mRegionStart;
    u64               mRegionEnd;
    i64               mTestSize;
    i64               mProgress;
    i64               mHandledProgress;
    u64               mMaximumSpeed;
    u64               mStartTsc;
    u64               mIntermediateTsc;
};



extern TestBase* memoryTests[(u64)MemoryTestType::MAXIMUM]; // memoryTests declared in testbase.cpp file



#endif // MEMORYTEST_SRC_BITS64_TESTS_TESTBASE_H
