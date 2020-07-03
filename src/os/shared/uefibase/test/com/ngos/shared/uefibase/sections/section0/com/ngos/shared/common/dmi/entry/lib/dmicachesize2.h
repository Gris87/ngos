#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE2_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE2_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmicachesize2.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_lib_dmicachesize2);
{
    TEST_CASE("size()");
    {
        DmiCacheSize2 temp;



        temp.value       = 1;
        temp.granularity = (u32)DmiCacheSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), KB);



        temp.value       = 64;
        temp.granularity = (u32)DmiCacheSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), 64 * KB);



        temp.value       = 32767;
        temp.granularity = (u32)DmiCacheSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), 32767 * KB);



        temp.value       = 2147483647;
        temp.granularity = (u32)DmiCacheSizeGranularity::_1_KILOBYTE;

        TEST_ASSERT_EQUALS(temp.size(), 2147483647 * KB);



        temp.value       = 1;
        temp.granularity = (u32)DmiCacheSizeGranularity::_64_KILOBYTES;

        TEST_ASSERT_EQUALS(temp.size(), 64 * KB);



        temp.value       = 64;
        temp.granularity = (u32)DmiCacheSizeGranularity::_64_KILOBYTES;

        TEST_ASSERT_EQUALS(temp.size(), 64 * 64 * KB);



        temp.value       = 32767;
        temp.granularity = (u32)DmiCacheSizeGranularity::_64_KILOBYTES;

        TEST_ASSERT_EQUALS(temp.size(), 32767 * 64 * KB);



        temp.value       = 2147483647;
        temp.granularity = (u32)DmiCacheSizeGranularity::_64_KILOBYTES;

        TEST_ASSERT_EQUALS(temp.size(), 2147483647ULL * 64 * KB);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE2_H
