#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_UUID_UTILS_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_UUID_UTILS_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>
#include <uuid/utils.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, __include_uuid_utils);
{
    TEST_CASE("isUuidEquals()");
    {
        Uuid uuid1 = { 0x00112233, 0x4455, 0x6677, 0x88, 0x99, {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF} };
        Uuid uuid2 = { 0x00112233, 0x4455, 0x6677, 0x88, 0x99, {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF} };
        Uuid uuid3 = { 0x10112233, 0x4455, 0x6677, 0x88, 0x99, {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF} };

        TEST_ASSERT_EQUALS(isUuidEquals(uuid1, uuid2), true);
        TEST_ASSERT_EQUALS(isUuidEquals(uuid2, uuid3), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___INCLUDE_UUID_UTILS_H
