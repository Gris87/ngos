#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_BOOTPARAMS_LIB_MEMORYMAPENTRY_H                                                                                                    // Colorize: green
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_BOOTPARAMS_LIB_MEMORYMAPENTRY_H                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <buildconfig.h>                                                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/bootparams/lib/memorymapentry.h>                                                                                                                                        // Colorize: green
#include <com/ngos/shared/uefibase/testengine.h>                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TEST_CASES(section0, com_ngos_shared_common_bootparams_lib_memorymapentry);                                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    TEST_CASE("end()");                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        MemoryMapEntry temp;                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.start = 1000;                                                                                                                                                                               // Colorize: green
        temp.size  = 2000;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.end(), 3000);                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.size = 3000;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.end(), 4000);                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.start = 4000;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.end(), 7000);                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.size = 1000;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.end(), 5000);                                                                                                                                                            // Colorize: green
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
#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_BOOTPARAMS_LIB_MEMORYMAPENTRY_H                                                                                                  // Colorize: green