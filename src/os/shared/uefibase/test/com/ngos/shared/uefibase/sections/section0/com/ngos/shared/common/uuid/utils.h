#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_UUID_UTILS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_UUID_UTILS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/uuid/utils.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_uuid_utils);
{
    TEST_CASE("isUuidEquals()");
    {
        Uuid uuid1 = { 0x00112233, 0x4455, 0x6677, 0x88, 0x99, { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };
        Uuid uuid2 = { 0x00112233, 0x4455, 0x6677, 0x88, 0x99, { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };
        Uuid uuid3 = { 0x10112233, 0x4455, 0x6677, 0x88, 0x99, { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };

        TEST_ASSERT_EQUALS(isUuidEquals(uuid1, uuid2), true);
        TEST_ASSERT_EQUALS(isUuidEquals(uuid2, uuid3), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_UUID_UTILS_H
