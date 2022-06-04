#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H                                                                                                   // Colorize: green
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <buildconfig.h>                                                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicachesize.h>                                                                                                                                       // Colorize: green
#include <com/ngos/shared/uefibase/testengine.h>                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TEST_CASES(section0, com_ngos_shared_common_dmi_lib_entry_lib_dmicachesize);                                                                                                                             // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    TEST_CASE("size()");                                                                                                                                                                                 // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiCacheSize temp;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.value       = 1;                                                                                                                                                                            // Colorize: green
        temp.granularity = DmiCacheSizeGranularity::_1_KILOBYTE;                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.size(), KB);                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.value       = 64;                                                                                                                                                                           // Colorize: green
        temp.granularity = DmiCacheSizeGranularity::_1_KILOBYTE;                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.size(), 64 * KB);                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.value       = 32767;                                                                                                                                                                        // Colorize: green
        temp.granularity = DmiCacheSizeGranularity::_1_KILOBYTE;                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.size(), 32767 * KB);                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.value       = 1;                                                                                                                                                                            // Colorize: green
        temp.granularity = DmiCacheSizeGranularity::_64_KILOBYTES;                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.size(), 64 * KB);                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.value       = 64;                                                                                                                                                                           // Colorize: green
        temp.granularity = DmiCacheSizeGranularity::_64_KILOBYTES;                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.size(), 64 * 64 * KB);                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.value       = 32767;                                                                                                                                                                        // Colorize: green
        temp.granularity = DmiCacheSizeGranularity::_64_KILOBYTES;                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.size(), 32767 * 64 * KB);                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
TEST_CASES_END();                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif                                                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHESIZE_H                                                                                                 // Colorize: green
