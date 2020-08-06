#ifndef COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTENTRYTYPE_H
#define COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTENTRYTYPE_H



#include <Qt>
#include <stdio.h>

#include <com/ngos/shared/common/ngos/types.h>



enum class TestEntryType: quint8
{
    NONE              = 0,
    INTERNAL_FUNCTION = 1,
    DEFINE            = 2,
    FUNCTION          = 3
};



inline const char8* enumToString(TestEntryType type) // TEST: NO
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



inline const char8* enumToFullString(TestEntryType type) // TEST: NO
{
    static char8 res[25];

    sprintf(res, "0x%02X (%s)", (quint8)type, enumToString(type));

    return res;
}



inline const char8* enumToHumanString(TestEntryType type) // TEST: NO
{
    switch (type)
    {
        case TestEntryType::NONE:              return "NONE";
        case TestEntryType::INTERNAL_FUNCTION: return "INTERNAL FUNCTION";
        case TestEntryType::DEFINE:            return "DEFINE";
        case TestEntryType::FUNCTION:          return "FUNCTION";

        default: return "UNKNOWN";
    }
}



#endif // COM_NGOS_DEVTOOLS_TEST_VERIFIER_OTHER_TESTENTRYTYPE_H
