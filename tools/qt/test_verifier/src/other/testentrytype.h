#ifndef TEST_VERIFIER_SRC_OTHER_TESTENTRYTYPE_H
#define TEST_VERIFIER_SRC_OTHER_TESTENTRYTYPE_H



#include <Qt>



enum class TestEntryType: quint8
{
    INTERNAL_FUNCTION,
    DEFINE,
    FUNCTION
};



inline const char* testEntryTypeToString(TestEntryType type) // TEST: NO
{
    switch (type)
    {
        case TestEntryType::INTERNAL_FUNCTION: return "INTERNAL_FUNCTION";
        case TestEntryType::DEFINE:            return "DEFINE";
        case TestEntryType::FUNCTION:          return "FUNCTION";

        default: return "UNKNOWN";
    }
}



#endif // TEST_VERIFIER_SRC_OTHER_TESTENTRYTYPE_H
