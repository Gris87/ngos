#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_DMISTRINGID_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_DMISTRINGID_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_dmi_dmistringid);
{
    TEST_CASE("DmiStringId()");
    {
        DmiStringId temp;



        TEST_ASSERT_EQUALS(temp.id, 0);
    }
    TEST_CASE_END();



    TEST_CASE("operator=()");
    {
        DmiStringId temp;
        DmiStringId temp2;



        TEST_ASSERT_EQUALS(temp.id,  0);
        TEST_ASSERT_EQUALS(temp2.id, 0);



        temp2.id = 5;
        temp     = temp2;



        TEST_ASSERT_EQUALS(temp.id,  5);
        TEST_ASSERT_EQUALS(temp2.id, 5);
    }
    TEST_CASE_END();



    TEST_CASE("operator++()");
    {
        DmiStringId temp;



        TEST_ASSERT_EQUALS(temp.id, 0);



        ++temp;

        TEST_ASSERT_EQUALS(temp.id, 1);



        ++temp;

        TEST_ASSERT_EQUALS(temp.id, 2);



        ++temp;

        TEST_ASSERT_EQUALS(temp.id, 3);
    }
    TEST_CASE_END();



    TEST_CASE("operator==()");
    {
        DmiStringId temp;
        DmiStringId temp2;



        TEST_ASSERT_EQUALS(temp.id,       0);
        TEST_ASSERT_EQUALS(temp2.id,      0);
        TEST_ASSERT_EQUALS(temp == temp2, true);



        temp.id = 5;

        TEST_ASSERT_EQUALS(temp == temp2, false);



        temp2.id = 5;

        TEST_ASSERT_EQUALS(temp == temp2, true);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_DMI_DMISTRINGID_H
