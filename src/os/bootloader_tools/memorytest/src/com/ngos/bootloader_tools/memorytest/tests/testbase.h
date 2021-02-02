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

    NgosStatus reset(bad_uint64 start, bad_uint64 end, bad_int64 testSize); // TEST: NO

    uefi_ap_procedure getProcedure() const; // TEST: NO

    NgosStatus setScore(bad_uint64 score); // TEST: NO
    bad_uint64 getScore() const; // TEST: NO

    NgosStatus setAverageSpeed(bad_uint64 speed); // TEST: NO
    bad_uint64 getAverageSpeed() const; // TEST: NO

    bool isCompleted() const; // TEST: NO

    bad_uint64 getRegionStart() const; // TEST: NO

    bad_uint64 getRegionEnd() const; // TEST: NO

    bad_int64 getTestSize() const; // TEST: NO

    inline NgosStatus setProgress(bad_int64 progress) // TEST: NO
    {
        // UEFI_LT((" | progress = %d", progress)); // Commented to avoid bad looking logs



        mProgress = progress;



        return NgosStatus::OK;
    }

    bad_int64 getProgress() const; // TEST: NO

    NgosStatus setHandledProgress(bad_int64 progress); // TEST: NO
    bad_int64 getHandledProgress() const; // TEST: NO

    NgosStatus setMaximumSpeed(bad_uint64 speed); // TEST: NO
    bad_uint64 getMaximumSpeed() const; // TEST: NO

    NgosStatus setStartTsc(bad_uint64 tsc); // TEST: NO
    bad_uint64 getStartTsc() const; // TEST: NO

    NgosStatus setIntermediateTsc(bad_uint64 tsc); // TEST: NO
    bad_uint64 getIntermediateTsc() const; // TEST: NO

private:
    uefi_ap_procedure mProcedure;
    bad_uint64               mScore;
    bad_uint64               mAverageSpeed;
    bad_uint64               mRegionStart;
    bad_uint64               mRegionEnd;
    bad_int64               mTestSize;
    bad_int64               mProgress;
    bad_int64               mHandledProgress;
    bad_uint64               mMaximumSpeed;
    bad_uint64               mStartTsc;
    bad_uint64               mIntermediateTsc;
};



extern TestBase* memoryTests[(bad_uint64)TestType::MAXIMUM]; // memoryTests declared in testbase.cpp file



#endif // COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_TESTS_TESTBASE_H
