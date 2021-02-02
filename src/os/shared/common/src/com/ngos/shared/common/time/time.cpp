#include "time.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>

#ifdef UEFI_APPLICATION                         // Defined in pro file
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#endif



#define DAYS_IN_JANUARY   31
#define DAYS_IN_FEBRUARY  28
#define DAYS_IN_MARCH     31
#define DAYS_IN_APRIL     30
#define DAYS_IN_MAY       31
#define DAYS_IN_JUNE      30
#define DAYS_IN_JULY      31
#define DAYS_IN_AUGUST    31
#define DAYS_IN_SEPTEMBER 30
#define DAYS_IN_OCTOBER   31
#define DAYS_IN_NOVEMBER  30
#define DAYS_IN_DECEMBER  31

#define TOTAL_DAYS 365

#define NUMBER_OF_LEAP_YEARS_FROM_0_TO_1970 477



#if TOTAL_DAYS != DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE + DAYS_IN_JULY + DAYS_IN_AUGUST + DAYS_IN_SEPTEMBER + DAYS_IN_OCTOBER + DAYS_IN_NOVEMBER + DAYS_IN_DECEMBER
#error TOTAL_DAYS invalid
#endif



bad_uint8 Time::sDaysInMonth[12] =
{
    DAYS_IN_JANUARY,
    DAYS_IN_FEBRUARY,
    DAYS_IN_MARCH,
    DAYS_IN_APRIL,
    DAYS_IN_MAY,
    DAYS_IN_JUNE,
    DAYS_IN_JULY,
    DAYS_IN_AUGUST,
    DAYS_IN_SEPTEMBER,
    DAYS_IN_OCTOBER,
    DAYS_IN_NOVEMBER,
    DAYS_IN_DECEMBER
};

bad_uint16 Time::sDaysFromStartOfYear[12] =
{
    0,
    DAYS_IN_JANUARY,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE + DAYS_IN_JULY,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE + DAYS_IN_JULY + DAYS_IN_AUGUST,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE + DAYS_IN_JULY + DAYS_IN_AUGUST + DAYS_IN_SEPTEMBER,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE + DAYS_IN_JULY + DAYS_IN_AUGUST + DAYS_IN_SEPTEMBER + DAYS_IN_OCTOBER,
    DAYS_IN_JANUARY + DAYS_IN_FEBRUARY + DAYS_IN_MARCH + DAYS_IN_APRIL + DAYS_IN_MAY + DAYS_IN_JUNE + DAYS_IN_JULY + DAYS_IN_AUGUST + DAYS_IN_SEPTEMBER + DAYS_IN_OCTOBER + DAYS_IN_NOVEMBER
};



bad_int64 Time::currentTimestampInMilliseconds()
{
    COMMON_LT((""));



#ifdef UEFI_APPLICATION // Defined in pro file
    UefiTime             time;
    UefiTimeCapabilities capabilities;

    if (UEFI::getTime(&time, &capabilities) != UefiStatus::SUCCESS)
    {
        COMMON_LF(("Failed to get current time"));

        return 0;
    }

    return timeToTimestampInMilliseconds(time.year, time.month, time.day, time.hour, time.minute, time.second, time.nanosecond);
#else
    // TODO: Should be updated when implemented

    return 0;
#endif
}

bad_int64 Time::timeToTimestampInMilliseconds(bad_int64 year, bad_uint8 month, bad_uint8 day, bad_uint8 hour, bad_uint8 minute, bad_uint8 second, bad_uint32 nanosecond)
{
    COMMON_LT((" | year = %d, month = %u, day = %u, hour = %u, minute = %u, second = %u, nanosecond = %u", year, month, day, hour, minute, second, nanosecond));

    // Ignore CppAlignmentVerifier [BEGIN]
    COMMON_ASSERT(month >= 1 && month      <= 12,                       "month is invalid",      0);
    COMMON_ASSERT(day   >= 1 && day        <= daysInMonth(year, month), "day is invalid",        0);
    COMMON_ASSERT(              hour       <= 23,                       "hour is invalid",       0);
    COMMON_ASSERT(              minute     <= 59,                       "minute is invalid",     0);
    COMMON_ASSERT(              second     <= 59,                       "second is invalid",     0);
    COMMON_ASSERT(              nanosecond <= 999999999,                "nanosecond is invalid", 0);
    // Ignore CppAlignmentVerifier [END]



    bad_int64 yearsFrom1970 = year - 1970;
    bad_int64 amountOfLeapYears;

    if (year > 0)
    {
        bad_int64 yearBefore = year - 1;

        bad_int64 amountOfYearsDiv4   = yearBefore / 4;
        bad_int64 amountOfYearsDiv100 = yearBefore / 100;
        bad_int64 amountOfYearsDiv400 = yearBefore / 400;

        amountOfLeapYears = amountOfYearsDiv4 - amountOfYearsDiv100 + amountOfYearsDiv400 - NUMBER_OF_LEAP_YEARS_FROM_0_TO_1970;
    }
    else
    {
        bad_int64 amountOfYearsDiv4   = year / 4;
        bad_int64 amountOfYearsDiv100 = year / 100;
        bad_int64 amountOfYearsDiv400 = year / 400;

        amountOfLeapYears = amountOfYearsDiv4 - amountOfYearsDiv100 + amountOfYearsDiv400 - NUMBER_OF_LEAP_YEARS_FROM_0_TO_1970 - 1; // 1 = special case for year 0
    }



    bad_int64 days = yearsFrom1970 * TOTAL_DAYS + amountOfLeapYears;

    days += sDaysFromStartOfYear[month - 1];

    if (
        month > 2
        &&
        isLeapYear(year)
       )
    {
        ++days;
    }

    days += day - 1;



    bad_int64 res;

    res =  days * 24;
    res =  (res + hour) * 60;
    res =  (res + minute) * 60;
    res =  (res + second) * 1000;
    res += nanosecond / 1000000;

    return res;
}

bad_uint8 Time::daysInMonth(bad_int64 year, bad_uint8 month)
{
    COMMON_LT((" | year = %d, month = %u", year, month));

    COMMON_ASSERT(month >= 1 && month <= 12, "month is invalid", 0);



    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }

    return sDaysInMonth[month - 1];
}

bool Time::isLeapYear(bad_int64 year)
{
    COMMON_LT((" | year = %d", year));



    if (year & 3)
    {
        return false;
    }

    return (
        (year % 100 != 0)
        ||
        (year % 400 == 0)
    );
}
