#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_TYPES_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_TYPES_H



#include <buildconfig.h>
#include <uefibase/src/bits64/other/uefibootmemorymap.h>
#include <uefibase/src/bits64/uefi/uefi.h>
#include <uefibase/src/bits64/uefi/uefilogfile.h>
#include <uefibase/src/bits64/uefi/uefipointerdevices.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_uefibase_bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(UEFI),               1);
        TEST_ASSERT_EQUALS(sizeof(UefiBootMemoryMap),  48);
        TEST_ASSERT_EQUALS(sizeof(UefiLogFile),        1);
        TEST_ASSERT_EQUALS(sizeof(UefiPointerDevices), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_UEFIBASE_BITS64_TYPES_H
