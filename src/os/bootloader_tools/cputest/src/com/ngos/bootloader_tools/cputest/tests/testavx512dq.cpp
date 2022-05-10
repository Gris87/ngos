#include "testavx512dq.h"

#include <com/ngos/bootloader_tools/cputest/main/cputest.h>
#include <com/ngos/bootloader_tools/cputest/main/cputestgui.h>
#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/cpu/cpu.h>
#include <com/ngos/shared/common/fpu/fpu.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/uefibase/main/setupcr4.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



#define NUMBER_OF_ITERATIONS 100000000
#define SCORE_PER_SECOND     1000



CPP_NO_OPTIMIZATION
void UEFI_API testAvx512DqProcedure(void *buffer)
{
    // UEFI_LT((" | buffer = 0x%p", buffer)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(setupCr4());
    UEFI_ASSERT_EXECUTION(FPU::initForApplicationProcessor());



    TestAvx512Dq *test = (TestAvx512Dq *)buffer;

    if (CPU::hasFeature(X86Feature::AVX512DQ))
    {
        double a[8]  __attribute__((aligned(64))) = { 0.1, 0.9, 12378.4, 12389.6, 1234879.15, 1232134513216.9, 832198789.0, 321983217.98 };
        float  b[16] __attribute__((aligned(64))) = { 0.1, 0.9, 12378.4, 12389.6, 24879.15, 21216.9, 18789.0, 23217.98, 0, 0, 0, 0, 0, 0, 0, 0 };



        u64 startTime = AsmUtils::rdtsc();

        for (good_I64 i = 0; i < NUMBER_OF_ITERATIONS && !CpuTestGUI::isTerminated(); ++i)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovapd    %0, %%zmm1"         "\n\t"    // vmovapd    0x40(%rsp), %zmm1   # Put 8 doubles located at %0 to ZMM1
                "vcvtpd2qq  %%zmm1, %%zmm0"               // vcvtpd2qq  %zmm1, %zmm0        # Convert 8 doubles in ZMM1 to 8 quadwords in ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovaps    %0, %%ymm1"         "\n\t"    // vmovaps    0x80(%rsp), %ymm1   # Put 8 floats located at %0 to YMM1
                "vcvtps2qq  %%ymm1, %%zmm0"               // vcvtps2qq  %ymm1, %zmm0        # Convert 8 floats in YMM1 to 8 quadwords in ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa64  %0, %%zmm1"         "\n\t"    // vmovdqa64  0x40(%rsp), %zmm1   # Put 8 quadwords located at %0 to ZMM1
                "vcvtqq2pd  %%zmm1, %%zmm0"               // vcvtqq2pd  %zmm1, %zmm0        # Convert 8 quadwords in ZMM1 to 8 doubles in ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa64  %0, %%zmm1"         "\n\t"    // vmovdqa64  0x40(%rsp), %zmm1   # Put 8 quadwords located at %0 to ZMM1
                "vcvtqq2ps  %%zmm1, %%ymm0"               // vcvtqq2ps  %zmm1, %ymm0        # Convert 8 quadwords in ZMM1 to 8 floats in YMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]



            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "vmovdqa64  %0, %%zmm1"         "\n\t"    // vmovdqa64  0x40(%rsp), %zmm1       # Put 8 quadwords located at %0 to ZMM1
                "vmovdqa64  %1, %%zmm2"         "\n\t"    // vmovdqa64  0x80(%rsp), %zmm2       # Put 8 quadwords located at %0 to ZMM2
                "vpmullq    %%zmm2, %%zmm1, %%zmm0"       // vpmullq    %zmm2, %zmm1, %zmm0     # Multiply 8 quadwords in ZMM1 with 8 quadwords in ZMM2 and store results in ZMM0
                    :                                     // Output parameters
                    :                                     // Input parameters
                        "m" (a),                          // 'm' - use memory // Ignore CppSingleCharVerifier
                        "m" (b)                           // 'm' - use memory // Ignore CppSingleCharVerifier
            );
            // Ignore CppAlignmentVerifier [END]
        }

        u64 endTime = AsmUtils::rdtsc();



        UEFI_ASSERT_EXECUTION(test->setScore(SCORE_PER_SECOND * CpuTest::getCpuSpeed() / (endTime - startTime)));
    }
    else
    {
        UEFI_ASSERT_EXECUTION(test->setScore(0));
    }
}



TestAvx512Dq::TestAvx512Dq()
    : TestBase(TestType::AVX512DQ, "Testing AVX512DQ instructions", testAvx512DqProcedure)
{
    UEFI_LT((""));
}

TestAvx512Dq::~TestAvx512Dq()
{
    UEFI_LT((""));
}



TestAvx512Dq testAvx512DqInstance;
