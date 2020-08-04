#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimemorydeviceextendedsize.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemorydeviceextendedsize);
{
    TEST_CASE("size()");
    {
        DmiMemoryDeviceExtendedSize temp;



        temp.value = 1;

        TEST_ASSERT_EQUALS(temp.size(), MB);



        temp.value = 64;

        TEST_ASSERT_EQUALS(temp.size(), 64 * MB);



        temp.value = 16383;

        TEST_ASSERT_EQUALS(temp.size(), 16383 * MB);



        temp.value = 916383;

        TEST_ASSERT_EQUALS(temp.size(), 916383 * MB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICEEXTENDEDSIZE_H
