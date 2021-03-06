#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_memory_memory);
{
    TEST_CASE("memcpy()");
    {
        u8 buffer[34] = { 5, 7, 3, 2, 8, 9, 1, 3, 4, 6, 7, 5, 4, 3, 9, 1, 7, 5, 7, 3, 2, 8, 9, 1, 3, 4, 6, 7, 5, 4, 3, 9, 1, 7 };
        u8 temp[34];



        TEST_ASSERT_EQUALS(memzero(temp,        34), temp);
        TEST_ASSERT_EQUALS(memcpy(temp, buffer, 34), temp);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 0);

        temp[9] = 9;

        TEST_ASSERT_EQUALS(memcpy(temp, buffer, 9),  temp);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 1);

        TEST_ASSERT_EQUALS(memcpy(temp, buffer, 10), temp);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 0);
    }
    TEST_CASE_END();



    TEST_CASE("memset()");
    {
        u8 buffer[197];
        u8 temp[197];



        for (i64 i = 0; i < 197; ++i)
        {
            buffer[i] = 5;
            temp[i]   = 0;
        }



        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 197), 1);
        TEST_ASSERT_EQUALS(memset(buffer, 0, 197), buffer);
        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 197), 0);



        for (i64 i = 0; i < 135; ++i)
        {
            temp[i] = 8;
        }



        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 197), -1);
        TEST_ASSERT_EQUALS(memset(buffer, 8, 135), buffer);
        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 197), 0);
    }
    TEST_CASE_END();



    TEST_CASE("memzero()");
    {
        u8 buffer[197];
        u8 temp[197];



        for (i64 i = 0; i < 197; ++i)
        {
            buffer[i] = 5;
            temp[i]   = 0;
        }



        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 197), 1);
        TEST_ASSERT_EQUALS(memzero(buffer,      197), buffer);
        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 197), 0);
    }
    TEST_CASE_END();



    TEST_CASE("memcmp()");
    {
        u8 buffer[5] = { 5, 7, 3, 2, 8 };
        u8 temp[5]   = { 5, 7, 3, 2, 8 };

        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 5), 0);

        temp[4] = 1;

        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 5), 1);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 5), -1);
        TEST_ASSERT_EQUALS(memcmp(buffer, temp, 4), 0);
    }
    TEST_CASE_END();



    TEST_CASE("memempty()");
    {
        u8 buffer[197];



        TEST_ASSERT_EQUALS(memzero(buffer,  197), buffer);
        TEST_ASSERT_EQUALS(memempty(buffer, 197), true);

        buffer[163] = 1;

        TEST_ASSERT_EQUALS(memempty(buffer, 197), false);
    }
    TEST_CASE_END();



    TEST_CASE("memmove()");
    {
        u8 buffer[34] = { 5, 7, 3, 2, 8, 9, 1, 3, 4, 6, 7, 5, 4, 3, 9, 1, 7, 5, 7, 3, 2, 8, 9, 1, 3, 4, 6, 7, 5, 4, 3, 9, 1, 7 };
        u8 temp[34];



        TEST_ASSERT_EQUALS(memzero(temp,         34), temp);
        TEST_ASSERT_EQUALS(memmove(temp, buffer, 34), temp);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer,  34), 0);



        for (i64 i = 0; i < 33; ++i)
        {
            temp[i] = temp[i + 1];
        }



        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 1);
        TEST_ASSERT_EQUALS(memmove(buffer, buffer + 1, 33), buffer);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 0);



        for (i64 i = 31; i >= 0; --i)
        {
            temp[i + 2] = temp[i];
        }



        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 1);
        TEST_ASSERT_EQUALS(memmove(buffer + 2, buffer, 32), buffer + 2);
        TEST_ASSERT_EQUALS(memcmp(temp, buffer, 34), 0);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_MEMORY_MEMORY_H
