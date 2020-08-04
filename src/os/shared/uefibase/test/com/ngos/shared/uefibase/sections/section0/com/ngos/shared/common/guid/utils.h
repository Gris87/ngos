#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GUID_UTILS_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GUID_UTILS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/guid/utils.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_guid_utils);
{
    TEST_CASE("isGuidEquals()");
    {
        Guid guid1 = { 0x00112233, 0x4455, 0x6677, { 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };
        Guid guid2 = { 0x00112233, 0x4455, 0x6677, { 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };
        Guid guid3 = { 0x10112233, 0x4455, 0x6677, { 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF } };

        TEST_ASSERT_EQUALS(isGuidEquals(guid1, guid2), true);
        TEST_ASSERT_EQUALS(isGuidEquals(guid2, guid3), false);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_GUID_UTILS_H
