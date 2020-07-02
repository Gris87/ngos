#ifndef OS_SHARED_COMMON_SRC_BITS64_TIME_TIME_H
#define OS_SHARED_COMMON_SRC_BITS64_TIME_TIME_H



#include <buildconfig.h>
#include <ngos/types.h>



class Time
{
public:
    static i64 currentTimestampInMilliseconds(); // TEST: NO
    static i64 timeToTimestampInMilliseconds(i64 year, u8 month, u8 day, u8 hour, u8 minute, u8 second, u32 nanosecond); // TEST: NO
    static u8 daysInMonth(i64 year, u8 month); // TEST: NO
    static bool isLeapYear(i64 year);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static u8  sDaysInMonth[12];
    static u16 sDaysFromStartOfYear[12];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_TIME_TIME_H
