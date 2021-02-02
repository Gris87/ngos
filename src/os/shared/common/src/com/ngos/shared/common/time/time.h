#ifndef COM_NGOS_SHARED_COMMON_TIME_TIME_H
#define COM_NGOS_SHARED_COMMON_TIME_TIME_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/types.h>



class Time
{
public:
    static bad_int64 currentTimestampInMilliseconds(); // TEST: NO
    static bad_int64 timeToTimestampInMilliseconds(bad_int64 year, bad_uint8 month, bad_uint8 day, bad_uint8 hour, bad_uint8 minute, bad_uint8 second, bad_uint32 nanosecond); // TEST: NO
    static bad_uint8 daysInMonth(bad_int64 year, bad_uint8 month); // TEST: NO
    static bool isLeapYear(bad_int64 year);

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static bad_uint8  sDaysInMonth[12];
    static bad_uint16 sDaysFromStartOfYear[12];
};



#endif // COM_NGOS_SHARED_COMMON_TIME_TIME_H
