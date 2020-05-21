#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIMEMORYARRAYMAPPEDADDRESSRANGE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIMEMORYARRAYMAPPEDADDRESSRANGE_H



#include <buildconfig.h>
#include <common/src/bits64/dmi/entry/lib/dmimemoryarraymappedaddressrange.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmimemoryarraymappedaddressrange);
{
    TEST_CASE("address()");
    {
        DmiMemoryArrayMappedAddressRange temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.address(),  1 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 2 * KB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.address(),  64 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 65 * KB);



        temp.value = 16383;

        TEST_ASSERT_EQUALS(temp.address(),  16383 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 16384 * KB);



        temp.value = 916383;

        TEST_ASSERT_EQUALS(temp.address(),  916383 * KB);
        TEST_ASSERT_EQUALS(temp.address(1), 916384 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIMEMORYARRAYMAPPEDADDRESSRANGE_H
