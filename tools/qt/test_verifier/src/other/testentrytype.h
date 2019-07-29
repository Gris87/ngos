#ifndef TEST_VERIFIER_SRC_OTHER_TESTENTRYTYPE_H
#define TEST_VERIFIER_SRC_OTHER_TESTENTRYTYPE_H



#include <Qt>
#include <ngos/types.h>



enum class TestEntryType: quint8
{
    NONE              = 0,
    INTERNAL_FUNCTION = 1,
    DEFINE            = 2,
    FUNCTION          = 3
};



inline const char8* testEntryTypeToString(TestEntryType type) // TEST: NO
{
    switch (type)
    {
        case TestEntryType::NONE:              return "NONE";
        case TestEntryType::INTERNAL_FUNCTION: return "INTERNAL_FUNCTION";
        case TestEntryType::DEFINE:            return "DEFINE";
        case TestEntryType::FUNCTION:          return "FUNCTION";

        default: return "UNKNOWN";
    }
}



#endif // TEST_VERIFIER_SRC_OTHER_TESTENTRYTYPE_H
