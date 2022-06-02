#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmimemorydevicesize.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmimemorydevicesize);
{
    TEST_CASE("size()");
    {
        DmiMemoryDeviceSize temp;



        temp.value       = 1;
        temp.granularity = (u16)DmiMemoryDeviceSizeGranularity::_1_MEGABYTE;

        TEST_ASSERT_EQUALS(temp.size(), MB);



        temp.value       = 64;
        temp.granularity = (u16)DmiMemoryDeviceSizeGranularity::_1_MEGABYTE;

        TEST_ASSERT_EQUALS(temp.size(), 64 * MB);



        temp.value       = 32767;
        temp.granularity = (u16)DmiMemoryDeviceSizeGranularity::_1_MEGABYTE;

        TEST_ASSERT_EQUALS(temp.size(), 32767 * MB);



        temp.value       = 1;
        temp.granularity = (u16)DmiMemoryDeviceSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), KB);



        temp.value       = 64;
        temp.granularity = (u16)DmiMemoryDeviceSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), 64 *  KB);



        temp.value       = 32767;
        temp.granularity = (u16)DmiMemoryDeviceSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), 32767 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIMEMORYDEVICESIZE_H
