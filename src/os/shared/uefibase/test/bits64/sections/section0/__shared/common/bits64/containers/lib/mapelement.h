#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIB_MAPELEMENT_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIB_MAPELEMENT_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/containers/lib/mapelement.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __shared_common_bits64_containers_lib_mapelement);
{
    TEST_CASE("MapElement()");
    {
        MapElement<u8, u32> temp(5,   123456);
        MapElement<u8, u32> temp2(10, 654321);

        TEST_ASSERT_EQUALS(temp.mKey,   5);
        TEST_ASSERT_EQUALS(temp.mValue, 123456);

        TEST_ASSERT_EQUALS(temp2.mKey,   10);
        TEST_ASSERT_EQUALS(temp2.mValue, 654321);
    }
    TEST_CASE_END();



    TEST_CASE("getKey()/setKey()");
    {
        MapElement<u8, u32> temp(3, 77777);

        TEST_ASSERT_EQUALS(temp.mKey,     3);
        TEST_ASSERT_EQUALS(temp.getKey(), 3);

        TEST_ASSERT_EQUALS(temp.setKey(100), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mKey,     100);
        TEST_ASSERT_EQUALS(temp.getKey(), 100);
    }
    TEST_CASE_END();



    TEST_CASE("getValue()/setValue()");
    {
        MapElement<u8, u32> temp(3, 77777);

        TEST_ASSERT_EQUALS(temp.mValue,     77777);
        TEST_ASSERT_EQUALS(temp.getValue(), 77777);

        TEST_ASSERT_EQUALS(temp.setValue(100), NgosStatus::OK);

        TEST_ASSERT_EQUALS(temp.mValue,     100);
        TEST_ASSERT_EQUALS(temp.getValue(), 100);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_CONTAINERS_LIB_MAPELEMENT_H
