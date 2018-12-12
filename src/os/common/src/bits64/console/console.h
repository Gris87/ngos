#ifndef OS_COMMON_SRC_BITS64_CONSOLE_CONSOLE_H
#define OS_COMMON_SRC_BITS64_CONSOLE_CONSOLE_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>
#include <ngos/types.h>



class Console
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO

    static void print(char ch); // TEST: NO
    static void print(const char *str); // TEST: NO
    static void println(); // TEST: NO
    static void println(char ch); // TEST: NO
    static void println(const char *str); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

private:
    static void newLineWithoutCaretReturn(); // TEST: NO
    static void newLine(); // TEST: NO

    static ScreenInfo *sScreenInfo;
    static u16         sScreenPosX;
    static u16        *sGlyphOffsets;
};



#endif // OS_COMMON_SRC_BITS64_CONSOLE_CONSOLE_H
