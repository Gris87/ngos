#ifndef TESTTYPE_H
#define TESTTYPE_H



#include <ngos/types.h>



enum class TestType: u8
{
    SSE,
    AVX,
    MAXIMUM
};



inline const char8* testTypeToString(TestType type) // TEST: NO
{
    switch (type)
    {
        case TestType::SSE:     return "SSE";
        case TestType::AVX:     return "AVX";
        case TestType::MAXIMUM: return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // TESTTYPE_H
