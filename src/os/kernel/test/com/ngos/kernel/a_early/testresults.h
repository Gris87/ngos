#ifndef COM_NGOS_KERNEL_A_EARLY_TESTRESULTS_H
#define COM_NGOS_KERNEL_A_EARLY_TESTRESULTS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/status.h>



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



#endif // COM_NGOS_KERNEL_A_EARLY_TESTRESULTS_H
