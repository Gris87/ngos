#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_DMISTRINGID_H                                                                                                              // Colorize: green
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_DMISTRINGID_H                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <buildconfig.h>                                                                                                                                                                                 // Colorize: green
#include <com/ngos/shared/common/dmi/lib/dmistringid.h>                                                                                                                                                  // Colorize: green
#include <com/ngos/shared/uefibase/testengine.h>                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#if NGOS_BUILD_TEST_MODE == OPTION_YES                                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
TEST_CASES(section0, com_ngos_shared_common_dmi_lib_dmistringid);                                                                                                                                        // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    TEST_CASE("DmiStringId()");                                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId temp;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id, 0);                                                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    TEST_CASE("operator=()");                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId temp;                                                                                                                                                                                // Colorize: green
        DmiStringId temp2;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id,  0);                                                                                                                                                                 // Colorize: green
        TEST_ASSERT_EQUALS(temp2.id, 0);                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp2.id = 5;                                                                                                                                                                                    // Colorize: green
        temp     = temp2;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id,  5);                                                                                                                                                                 // Colorize: green
        TEST_ASSERT_EQUALS(temp2.id, 5);                                                                                                                                                                 // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    TEST_CASE("operator++()");                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId temp;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id, 0);                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        ++temp;                                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id, 1);                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        ++temp;                                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id, 2);                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        ++temp;                                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id, 3);                                                                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
    TEST_CASE_END();                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    TEST_CASE("operator==()");                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        DmiStringId temp;                                                                                                                                                                                // Colorize: green
        DmiStringId temp2;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp.id,       0);                                                                                                                                                            // Colorize: green
        TEST_ASSERT_EQUALS(temp2.id,      0);                                                                                                                                                            // Colorize: green
        TEST_ASSERT_EQUALS(temp == temp2, true);                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp.id = 5;                                                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp == temp2, false);                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        temp2.id = 5;                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        TEST_ASSERT_EQUALS(temp == temp2, true);                                                                                                                                                         // Colorize: green
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
#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_DMISTRINGID_H                                                                                                            // Colorize: green