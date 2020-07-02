#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmicacheconfiguration.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmicacheconfiguration);
{
    TEST_CASE("levelReal()");
    {
        DmiCacheConfiguration temp;



        temp.level = 0;

        TEST_ASSERT_EQUALS(temp.levelReal(), 1);



        temp.level = 1;

        TEST_ASSERT_EQUALS(temp.levelReal(), 2);



        temp.level = 2;

        TEST_ASSERT_EQUALS(temp.levelReal(), 3);



        temp.level = 3;

        TEST_ASSERT_EQUALS(temp.levelReal(), 4);



        temp.level = 7;

        TEST_ASSERT_EQUALS(temp.levelReal(), 8);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
