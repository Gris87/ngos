#ifndef OS_SHARED_COMMON_SRC_BITS64_CONSOLE_GRAPHICALCONSOLE_H
#define OS_SHARED_COMMON_SRC_BITS64_CONSOLE_GRAPHICALCONSOLE_H



#include <ngos/status.h>
#include <ngos/types.h>



class ConsoleWidget;
class Image;



class GraphicalConsole
{
public:
    static NgosStatus init(); // TEST: NO
    static NgosStatus readyToPrint(); // TEST: NO

    static NgosStatus print(char8 ch); // TEST: NO
    static NgosStatus print(const char8 *str); // TEST: NO
    static NgosStatus println(); // TEST: NO
    static NgosStatus println(char8 ch); // TEST: NO
    static NgosStatus println(const char8 *str); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

private:
    static NgosStatus newLineWithoutCaretReturn(); // TEST: NO
    static NgosStatus newLine(); // TEST: NO

    static ConsoleWidget *sConsoleWidget;
    static Image         *sTextImage;
    static u16            sPositionX;
    static u16            sPaddingLeft;
    static u16            sPaddingTop;
    static u16           *sGlyphOffsets;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CONSOLE_GRAPHICALCONSOLE_H
