#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/bootparams/memorymapentry.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_bootparams_memorymapentry);
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



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
