#ifndef CPUTEST_SRC_BITS64_OTHER_TESTTYPE_H
#define CPUTEST_SRC_BITS64_OTHER_TESTTYPE_H



#include <ngos/types.h>



enum class TestType: u8
{
    INTEGER,
    BITWISE,
    LOGICAL,
    FLOAT,
    SSE,
    SSE2,
    SSE3,
    SSE41,
    SSE42,
    AVX,
    AVX2,
    AVX512BW,
    AVX512CD,
    AVX512DQ,
    AVX512F,
    AVX512VL,
    FMA3,
    AES,
    MAXIMUM
};



inline const char8* testTypeToString(TestType type) // TEST: NO
{
    switch (type)
    {
        case TestType::INTEGER:  return "INTEGER";
        case TestType::BITWISE:  return "BITWISE";
        case TestType::LOGICAL:  return "LOGICAL";
        case TestType::FLOAT:    return "FLOAT";
        case TestType::SSE:      return "SSE";
        case TestType::SSE2:     return "SSE2";
        case TestType::SSE3:     return "SSE3";
        case TestType::SSE41:    return "SSE41";
        case TestType::SSE42:    return "SSE42";
        case TestType::AVX:      return "AVX";
        case TestType::AVX2:     return "AVX2";
        case TestType::AVX512BW: return "AVX512BW";
        case TestType::AVX512CD: return "AVX512CD";
        case TestType::AVX512DQ: return "AVX512DQ";
        case TestType::AVX512F:  return "AVX512F";
        case TestType::AVX512VL: return "AVX512VL";
        case TestType::FMA3:     return "FMA3";
        case TestType::AES:      return "AES";
        case TestType::MAXIMUM:  return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // CPUTEST_SRC_BITS64_OTHER_TESTTYPE_H
