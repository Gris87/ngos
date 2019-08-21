#ifndef OS_SHARED_COMMON_SRC_BITS64_CONSOLE_GRAPHICALCONSOLE_H
#define OS_SHARED_COMMON_SRC_BITS64_CONSOLE_GRAPHICALCONSOLE_H



#include <ngos/status.h>
#include <ngos/types.h>



class GraphicalConsole
{
public:
    static NgosStatus init(); // TEST: NO

    static void print(char8 ch); // TEST: NO
    static void print(const char8 *str); // TEST: NO
    static void println(); // TEST: NO
    static void println(char8 ch); // TEST: NO
    static void println(const char8 *str); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

private:
    static void newLineWithoutCaretReturn(); // TEST: NO
    static void newLine(); // TEST: NO

    static u16  sPositionX;
    static u16 *sGlyphOffsets;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CONSOLE_GRAPHICALCONSOLE_H
