#ifndef CPUTEST_SRC_BITS64_TESTS_TESTBASE_H
#define CPUTEST_SRC_BITS64_TESTS_TESTBASE_H



#include <uefi/uefimpservicesprotocol.h>
#include <ngos/status.h>

#include "src/bits64/other/testtype.h"



class TestBase
{
public:
    TestBase(TestType type, const char8 *name, uefi_ap_procedure procedure);
    ~TestBase();

    NgosStatus reset();

    const char8* getName() const;

    NgosStatus setScore(u64 score);
    u64 getScore() const;

    uefi_ap_procedure getProcedure() const;

    bool isCompleted() const;

private:
    const char8       *mName;
    u64                mScore;
    uefi_ap_procedure  mProcedure;
    bool               mCompleted;
};



extern TestBase* cpuTests[(u64)TestType::MAXIMUM]; // cpuTests declared in testbase.cpp file



#endif // CPUTEST_SRC_BITS64_TESTS_TESTBASE_H
