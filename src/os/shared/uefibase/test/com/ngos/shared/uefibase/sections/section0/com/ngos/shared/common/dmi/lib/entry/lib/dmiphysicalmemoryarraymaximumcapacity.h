#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmiphysicalmemoryarraymaximumcapacity.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_lib_entry_lib_dmiphysicalmemoryarraymaximumcapacity);
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



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIPHYSICALMEMORYARRAYMAXIMUMCAPACITY_H
