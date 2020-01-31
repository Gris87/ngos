#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMICACHESIZE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMICACHESIZE_H



#include <buildconfig.h>
#include <common/src/bits64/dmi/entry/lib/dmicachesize.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmicachesize);
{
    TEST_CASE("size()");
    {
        DmiCacheSize temp;



        temp.granularity = 0;
        temp.value       = 1;

        TEST_ASSERT_EQUALS(temp.size(), 1024);



        temp.granularity = 0;
        temp.value       = 64;

        TEST_ASSERT_EQUALS(temp.size(), 65536);



        temp.granularity = 0;
        temp.value       = 32767;

        TEST_ASSERT_EQUALS(temp.size(), 33553408);



        temp.granularity = 1;
        temp.value       = 1;

        TEST_ASSERT_EQUALS(temp.size(), 65536);



        temp.granularity = 1;
        temp.value       = 64;

        TEST_ASSERT_EQUALS(temp.size(), 4194304);



        temp.granularity = 1;
        temp.value       = 32767;

        TEST_ASSERT_EQUALS(temp.size(), 2147418112);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMICACHESIZE_H
