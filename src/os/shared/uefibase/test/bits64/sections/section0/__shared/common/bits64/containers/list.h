#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIST_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIST_H



#include <buildconfig.h>
#include <common/src/bits64/containers/list.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_containers_list);
{
    TEST_CASE("List()");
    {
        List<u8> temp;

        TEST_ASSERT_EQUALS(temp.mHead, 0);
        TEST_ASSERT_EQUALS(temp.mTail, 0);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIST_H
