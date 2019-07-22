#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_X86BUGWORD_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_X86BUGWORD_H



#include <ngos/types.h>



enum class x86BugWord: u8
{
    NGOS_COMMON_FLAGS,
    MAXIMUM
};



inline const char* x86BugWordToString(x86BugWord word) // TEST: NO
{
    // COMMON_LT((" | word = %u", word)); // Commented to avoid bad looking logs



    switch (word)
    {
        case x86BugWord::NGOS_COMMON_FLAGS: return "NGOS_COMMON_FLAGS";
        case x86BugWord::MAXIMUM:           return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_X86BUGWORD_H
