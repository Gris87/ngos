#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_TESTRESULTS_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_TESTRESULTS_H



#include <buildconfig.h>
#include <ngos/status.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



class TestResults
{
public:
    TestResults();

    void testPassed();
    void testFailed(const char *filename, u64 line, const char *description);

    NgosStatus summary();

private:
    u64 mPassed;
    u64 mFailed;
};



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_TESTRESULTS_H
