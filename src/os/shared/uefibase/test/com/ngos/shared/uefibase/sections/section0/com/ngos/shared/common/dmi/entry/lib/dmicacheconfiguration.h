#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmicacheconfiguration.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmicacheconfiguration);
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



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H
