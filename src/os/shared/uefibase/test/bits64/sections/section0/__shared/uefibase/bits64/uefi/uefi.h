#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_UEFI_UEFI_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_UEFI_UEFI_H



#include <buildconfig.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_uefibase_bits64_uefi_uefi);
{
    TEST_CASE("memoryMapHasHeadroom()");
    {
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(3000, 1000, 48), true);
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(1000, 3000, 48), false);
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(3000, 2616, 48), true);
        TEST_ASSERT_EQUALS(UEFI::memoryMapHasHeadroom(3000, 2617, 48), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_UEFI_UEFI_H
