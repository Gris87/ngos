#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_DMISTRINGID_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_DMISTRINGID_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_dmistringid);
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



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_DMISTRINGID_H
