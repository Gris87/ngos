#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmiphysicalmemoryarraymaximumcapacity);
{
    TEST_CASE("size()");
    {
        DmiPhysicalMemoryArrayMaximumCapacity temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.size(), KB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.size(), 64 * KB);



        temp.value = 16383;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * KB);



        temp.value = 916383;

        TEST_ASSERT_EQUALS(temp.size(), 916383 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
