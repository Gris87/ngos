#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_UEFI_UEFI_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_UEFI_UEFI_H



#include <buildconfig.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, bits64_other_uefi_uefi);
{
    TEST_CASE("isGuidEquals()");
    {
        UefiGuid guid1 = { 0x00112233, 0x4455, 0x6677, {0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF} };
        UefiGuid guid2 = { 0x00112233, 0x4455, 0x6677, {0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF} };
        UefiGuid guid3 = { 0x10112233, 0x4455, 0x6677, {0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF} };

        TEST_ASSERT_EQUALS(UEFI::isGuidEquals(guid1, guid2), true);
        TEST_ASSERT_EQUALS(UEFI::isGuidEquals(guid2, guid3), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_UEFI_UEFI_H
