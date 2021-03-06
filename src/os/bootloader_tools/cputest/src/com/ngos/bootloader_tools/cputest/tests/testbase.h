#ifndef COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTBASE_H
#define COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTBASE_H



#include <com/ngos/bootloader_tools/cputest/other/testtype.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/uefimpservicesprotocol.h>



class TestBase
{
public:
    TestBase(TestType type, const char8 *name, uefi_ap_procedure procedure); // TEST: NO
    ~TestBase(); // TEST: NO

    NgosStatus reset(); // TEST: NO

    const char8* getName() const; // TEST: NO

    uefi_ap_procedure getProcedure() const; // TEST: NO

    NgosStatus setScore(u64 score); // TEST: NO
    u64 getScore() const; // TEST: NO

    bool isCompleted() const; // TEST: NO

private:
    const char8       *mName;
    uefi_ap_procedure  mProcedure;
    u64                mScore;
    bool               mCompleted;
};



extern TestBase* cpuTests[(u64)TestType::MAXIMUM]; // cpuTests declared in testbase.cpp file



#endif // COM_NGOS_BOOTLOADER_TOOLS_CPUTEST_TESTS_TESTBASE_H
