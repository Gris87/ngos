#include "testaes.h"

#include <asm/instructions.h>
#include <common/src/bits64/cpu/cpu.h>
#include <common/src/bits64/cryptography/aes.h>
#include <common/src/bits64/fpu/fpu.h>
#include <ngos/linkage.h>
#include <uefibase/src/bits64/main/setupcr4.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/main/cputest.h"
#include "src/bits64/main/cputestgui.h"



#define NUMBER_OF_ITERATIONS 1000000
#define SCORE_PER_SECOND     800



CPP_NO_OPTIMIZATION
void UEFI_API testAesProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAes *test = (TestAes *)buffer;

    if (CPU::hasFlag(X86Feature::AES))
    {
        u8 in[1024]  __attribute__((aligned(16)));
        u8 out[1024] __attribute__((aligned(16)));

        u64 outSize;



        AES aes;

        const char8 *key = "My dear password";

        UEFI_TEST_ASSERT(strlen(key) == 16);



        u64 startTime = rdtsc();

        UEFI_ASSERT_EXECUTION(aes.setKey((u8 *)key, strlen(key)));

        for (i64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            UEFI_ASSERT_EXECUTION(aes.encode(in, sizeof(in), out, sizeof(out), &outSize));
            UEFI_ASSERT_EXECUTION(aes.decode(out, sizeof(out), in, sizeof(in), &outSize));
        }

        u64 endTime = rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND / ((double)(endTime - startTime) / CpuTest::getCpuSpeed())));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestAes::TestAes()
    : TestBase(TestType::AES, "Testing AES instructions", testAesProcedure)
{
    UEFI_LT((""));
}

TestAes::~TestAes()
{
    UEFI_LT((""));
}



TestAes testAesInstance;
