#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TIME_TIME_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TIME_TIME_H



#include <buildconfig.h>
#include <com/ngos/shared/common/time/time.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_time_time);
{
    TEST_CASE("timeToTimestampInMilliseconds()");
    {
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1987, 7,  26, 0,  0,  0,  0),         554256000000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1995, 7,  20, 0,  0,  0,  0),         806198400000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(2020, 1,  4,  0,  0,  0,  0),         1578096000000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(2020, 3,  24, 9,  56, 28, 327123584), 1585043788327);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(2012, 12, 20, 20, 12, 20, 201220122), 1356034340201);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(3269, 9,  11, 1,  2,  4,  816326412), 41014429324816);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1980, 1,  1,  0,  0,  0,  0),         315532800000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1976, 1,  1,  0,  0,  0,  0),         189302400000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1972, 1,  1,  0,  0,  0,  0),         63072000000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1968, 1,  2,  0,  0,  0,  0),         -63072000000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1964, 1,  2,  0,  0,  0,  0),         -189302400000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1960, 1,  2,  0,  0,  0,  0),         -315532800000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1969, 12, 31, 23, 59, 59, 999999999), -1);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(1,    1,  1,  0,  0,  0,  0),         -62135596800000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(0,    1,  1,  0,  0,  0,  0),         -62167219200000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(-1,   1,  1,  0,  0,  0,  0),         -62198755200000);
        TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(-999, 1,  1,  0,  0,  0,  0),         -93692592000000);



        i64 res = 16725225600000;

        for (good_i64 i = 2500; i >= -1000; --i)
        {
            TEST_ASSERT_EQUALS(Time::timeToTimestampInMilliseconds(i, 1,  1,  0,  0,  0,  0), res);

            if (Time::isLeapYear(i - 1))
            {
                res -= 31622400000; // 366 * 24 * 60 * 60 * 1000
            }
            else
            {
                res -= 31536000000; // 365 * 24 * 60 * 60 * 1000
            }
        }
    }
    TEST_CASE_END();



    TEST_CASE("daysInMonth()");
    {
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 1),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 2),  28);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 3),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 4),  30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 5),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 6),  30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 7),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 8),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 9),  30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 10), 31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 11), 30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2019, 12), 31);

        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 1),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 2),  29);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 3),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 4),  30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 5),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 6),  30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 7),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 8),  31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 9),  30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 10), 31);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 11), 30);
        TEST_ASSERT_EQUALS(Time::daysInMonth(2020, 12), 31);



        u16 total = 0;

        for (good_i64 i = 1; i <= 12; ++i)
        {
            TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[i - 1], total);

            total += Time::sDaysInMonth[i - 1];
        }

        TEST_ASSERT_EQUALS(total, 365);



        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[0],  0);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[1],  31);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[2],  59);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[3],  90);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[4],  120);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[5],  151);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[6],  181);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[7],  212);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[8],  243);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[9],  273);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[10], 304);
        TEST_ASSERT_EQUALS(Time::sDaysFromStartOfYear[11], 334);
    }
    TEST_CASE_END();



    TEST_CASE("isLeapYear()");
    {
        TEST_ASSERT_EQUALS(Time::isLeapYear(-400), true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-300), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-200), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-100), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-9),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-8),   true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-7),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-6),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-5),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-4),   true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-3),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-2),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(-1),   false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(0),    true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(1995), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(1996), true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(1997), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(1998), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(1999), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2000), true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2001), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2002), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2003), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2004), true);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2100), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2200), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2300), false);
        TEST_ASSERT_EQUALS(Time::isLeapYear(2400), true);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_TIME_TIME_H
