#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_TESTRESULTS_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_TESTRESULTS_H



#include <buildconfig.h>
#include <ngos/status.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



class TestResults
{
public:
    TestResults();

    void testPassed();
    void testFailed(const char8 *fileName, u64 line, const char8 *description);

    NgosStatus summary();

private:
    u64 mPassed;
    u64 mFailed;
};



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_TESTRESULTS_H
