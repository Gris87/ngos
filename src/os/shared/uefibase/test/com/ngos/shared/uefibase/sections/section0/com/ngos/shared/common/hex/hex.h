#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_HEX_HEX_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_HEX_HEX_H



#include <buildconfig.h>
#include <com/ngos/shared/common/hex/hex.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_hex_hex);
{
    TEST_CASE("toString()");
    {
        u8 bytes1[10];
        u8 bytes2[10];

        for (good_i64 i = 0; i < 10; ++i)
        {
            bytes1[i] = i * 93;
            bytes2[i] = i * 87 + 25;
        }



        char8 *temp1;
        char8 *temp2;
        char8 *temp3;
        char8 *temp4;
        char8 *temp5;
        char8 *temp6;
        char8 *temp7;



        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp1, 21, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp2, 12, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp3, 11, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp4, 10, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp5, 12, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp6, 11, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, &temp7, 10, false), NgosStatus::OK);

        TEST_ASSERT_EQUALS(strcmp(temp1, "005DBA1774D12E8BE845"), 0);
        TEST_ASSERT_EQUALS(strcmp(temp2, "005DBA17..."),          0);
        TEST_ASSERT_EQUALS(strcmp(temp3, "005DBA..."),            0);
        TEST_ASSERT_EQUALS(strcmp(temp4, "005DBA..."),            0);
        TEST_ASSERT_EQUALS(strcmp(temp5, "005DBA1774"),           0);
        TEST_ASSERT_EQUALS(strcmp(temp6, "005DBA1774"),           0);
        TEST_ASSERT_EQUALS(strcmp(temp7, "005DBA17"),             0);

        TEST_ASSERT_EQUALS(free(temp1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp4), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp6), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp7), NgosStatus::OK);



        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp1, 21, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp2, 12, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp3, 11, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp4, 10, true),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp5, 12, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp6, 11, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, &temp7, 10, false), NgosStatus::OK);

        TEST_ASSERT_EQUALS(strcmp(temp1, "1970C71E75CC237AD128"), 0);
        TEST_ASSERT_EQUALS(strcmp(temp2, "1970C71E..."),          0);
        TEST_ASSERT_EQUALS(strcmp(temp3, "1970C7..."),            0);
        TEST_ASSERT_EQUALS(strcmp(temp4, "1970C7..."),            0);
        TEST_ASSERT_EQUALS(strcmp(temp5, "1970C71E75"),           0);
        TEST_ASSERT_EQUALS(strcmp(temp6, "1970C71E75"),           0);
        TEST_ASSERT_EQUALS(strcmp(temp7, "1970C71E"),             0);

        TEST_ASSERT_EQUALS(free(temp1), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp3), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp4), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp5), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp6), NgosStatus::OK);
        TEST_ASSERT_EQUALS(free(temp7), NgosStatus::OK);



        char8 temp[21];

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 21, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA1774D12E8BE845"),      0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 12, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA17..."),               0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 11, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA..."),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 10, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA..."),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 12, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA1774"),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 11, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA1774"),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes1, 10, temp, 10, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "005DBA17"),                   0);



        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 21, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C71E75CC237AD128"),      0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 12, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C71E..."),               0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 11, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C7..."),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 10, true), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C7..."),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 12, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C71E75"),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 11, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C71E75"),                 0);

        TEST_ASSERT_EQUALS(Hex::toString(bytes2, 10, temp, 10, false), NgosStatus::OK);
        TEST_ASSERT_EQUALS(strcmp(temp, "1970C71E"),                   0);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_HEX_HEX_H
