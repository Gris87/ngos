#include "testaes.h"

#include <com/ngos/bootloader_tools/cputest/main/cputest.h>
#include <com/ngos/bootloader_tools/cputest/main/cputestgui.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define NUMBER_OF_ITERATIONS 1000000
#define SCORE_PER_SECOND     800



CPP_NO_OPTIMIZATION
void UEFI_API testAesProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAes *test = (TestAes *)buffer;

    if (CPU::hasFeature(X86Feature::AESNI))
    {
        good_U8 in[1024]  __attribute__((aligned(16)));
        good_U8 out[1024] __attribute__((aligned(16)));

        good_I64 outSize;



        AES& aes = test->getAES();



        u64 startTime = AsmUtils::rdtsc();

        for (good_I64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            UEFI_ASSERT_EXECUTION(aes.encode(in, sizeof(in), out, sizeof(out), &outSize));
            UEFI_ASSERT_EXECUTION(aes.decode(out, sizeof(out), in, sizeof(in)));
        }

        u64 endTime = AsmUtils::rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestAes::TestAes()
    : TestBase(TestType::AES, "Testing AES instructions", testAesProcedure)
    , mAES()
{
    UEFI_LT((""));



    const char8 *key = "My dear password";

    UEFI_TEST_ASSERT(strlen(key) == 16);



    UEFI_ASSERT_EXECUTION(mAES.setKey((u8 *)key, strlen(key)));
}

TestAes::~TestAes()
{
    UEFI_LT((""));
}

AES& TestAes::getAES()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return mAES;
}



TestAes testAesInstance;
