#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H



#include <buildconfig.h>
#include <common/src/bits64/dmi/entry/lib/dmiportablebatterymanufacturedate.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_entry_lib_dmiportablebatterymanufacturedate);
{
    TEST_CASE("realYear()");
    {
        DmiPortableBatteryManufactureDate temp;



        temp.year = 0;

        TEST_ASSERT_EQUALS(temp.realYear(), 1980);



        temp.year = 1;

        TEST_ASSERT_EQUALS(temp.realYear(), 1981);



        temp.year = 32;

        TEST_ASSERT_EQUALS(temp.realYear(), 2012);



        temp.year = 40;

        TEST_ASSERT_EQUALS(temp.realYear(), 2020);



        temp.year = 127;

        TEST_ASSERT_EQUALS(temp.realYear(), 2107);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
