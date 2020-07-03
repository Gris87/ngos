#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiportablebatterymanufacturedate.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmiportablebatterymanufacturedate);
{
    TEST_CASE("yearReal()");
    {
        DmiPortableBatteryManufactureDate temp;



        temp.year = 0;

        TEST_ASSERT_EQUALS(temp.yearReal(), 1980);



        temp.year = 1;

        TEST_ASSERT_EQUALS(temp.yearReal(), 1981);



        temp.year = 32;

        TEST_ASSERT_EQUALS(temp.yearReal(), 2012);



        temp.year = 40;

        TEST_ASSERT_EQUALS(temp.yearReal(), 2020);



        temp.year = 127;

        TEST_ASSERT_EQUALS(temp.yearReal(), 2107);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPORTABLEBATTERYMANUFACTUREDATE_H
