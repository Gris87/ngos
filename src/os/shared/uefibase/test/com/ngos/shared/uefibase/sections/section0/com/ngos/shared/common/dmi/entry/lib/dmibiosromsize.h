#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmibiosromsize.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmibiosromsize);
{
    TEST_CASE("size()");
    {
        DmiBiosRomSize temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.size(), 128 * KB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.size(), 4160 * KB);



        temp.value = 255;

        TEST_ASSERT_EQUALS(temp.size(), 16384 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSROMSIZE_H
