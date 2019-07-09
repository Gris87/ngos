#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_BOOTPARAMS_MEMORYMAPENTRY_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_BOOTPARAMS_MEMORYMAPENTRY_H



#include <bootparams/memorymapentry.h>
#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_bootparams_memorymapentry);
{
    TEST_CASE("end()");
    {
        MemoryMapEntry temp;

        temp.start = 1000;
        temp.size  = 2000;

        TEST_ASSERT_EQUALS(temp.end(), 3000);

        temp.size = 3000;

        TEST_ASSERT_EQUALS(temp.end(), 4000);

        temp.start = 4000;

        TEST_ASSERT_EQUALS(temp.end(), 7000);

        temp.size = 1000;

        TEST_ASSERT_EQUALS(temp.end(), 5000);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_BOOTPARAMS_MEMORYMAPENTRY_H