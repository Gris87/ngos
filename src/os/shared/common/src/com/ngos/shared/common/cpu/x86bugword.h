#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_X86BUGWORD_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_X86BUGWORD_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class x86BugWord: u8
{
    NGOS_COMMON_FLAGS,
    MAXIMUM
};



inline const char8* enumToString(x86BugWord word) // TEST: NO
{
    // COMMON_LT((" | word = %u", word)); // Commented to avoid bad looking logs



    switch (word)
    {
        case x86BugWord::NGOS_COMMON_FLAGS: return "NGOS_COMMON_FLAGS";
        case x86BugWord::MAXIMUM:           return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(x86BugWord word) // TEST: NO
{
    // COMMON_LT((" | word = %u", word)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", word, enumToString(word));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CPU_X86BUGWORD_H
