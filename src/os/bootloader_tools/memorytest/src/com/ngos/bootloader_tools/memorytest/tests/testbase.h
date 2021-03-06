#ifndef COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTBASE_H
#define COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTBASE_H



#include <com/ngos/bootloader_tools/memorytest/other/testtype.h>
#include <com/ngos/shared/common/macro/constants.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefimpservicesprotocol.h>



#define TEST_BLOCK_SIZE (1 * MB)



class TestBase
{
public:
    TestBase(TestType type, uefi_ap_procedure procedure); // TEST: NO
    ~TestBase(); // TEST: NO

    NgosStatus reset(address_t start, address_t end, i64 testSize); // TEST: NO

    uefi_ap_procedure getProcedure() const; // TEST: NO

    NgosStatus setScore(i64 score); // TEST: NO
    i64 getScore() const; // TEST: NO

    NgosStatus setAverageSpeed(i64 speed); // TEST: NO
    i64 getAverageSpeed() const; // TEST: NO

    bool isCompleted() const; // TEST: NO

    address_t getRegionStart() const; // TEST: NO

    address_t getRegionEnd() const; // TEST: NO

    i64 getTestSize() const; // TEST: NO

    inline NgosStatus setProgress(i64 progress) // TEST: NO
    {
        // UEFI_LT((" | progress = %d", progress)); // Commented to avoid bad looking logs



        mProgress = progress;



        return NgosStatus::OK;
    }

    i64 getProgress() const; // TEST: NO

    NgosStatus setHandledProgress(i64 progress); // TEST: NO
    i64 getHandledProgress() const; // TEST: NO

    NgosStatus setMaximumSpeed(i64 speed); // TEST: NO
    i64 getMaximumSpeed() const; // TEST: NO

    NgosStatus setStartTsc(u64 tsc); // TEST: NO
    u64 getStartTsc() const; // TEST: NO

    NgosStatus setIntermediateTsc(u64 tsc); // TEST: NO
    u64 getIntermediateTsc() const; // TEST: NO

private:
    uefi_ap_procedure mProcedure;
    i64               mScore;
    i64               mAverageSpeed;
    address_t         mRegionStart;
    address_t         mRegionEnd;
    i64               mTestSize;
    i64               mProgress;
    i64               mHandledProgress;
    i64               mMaximumSpeed;
    u64               mStartTsc;
    u64               mIntermediateTsc;
};



extern TestBase* memoryTests[(u64)TestType::MAXIMUM]; // memoryTests declared in testbase.cpp file



#endif // COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTBASE_H
