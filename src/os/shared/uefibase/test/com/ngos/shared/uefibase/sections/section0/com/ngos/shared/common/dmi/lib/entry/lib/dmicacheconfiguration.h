#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H                                                                                          // Colorize: green
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <buildconfig.h>                                                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/dmi/lib/entry/lib/dmicacheconfiguration.h>                                                                                                                              // Colorize: green
#include <com/ngos/shared/uefibase/testengine.h>                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TEST_CASES(section0, com_ngos_shared_common_dmi_lib_entry_lib_dmicacheconfiguration);                                                                                                                    // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    TEST_CASE("levelReal()");                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiCacheConfiguration temp;                                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.level = 0;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.levelReal(), 1);                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.level = 1;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.levelReal(), 2);                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.level = 2;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.levelReal(), 3);                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.level = 3;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.levelReal(), 4);                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.level = 7;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.levelReal(), 8);                                                                                                                                                         // Colorize: green
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
#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICACHECONFIGURATION_H                                                                                        // Colorize: green