#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONSOLE_GRAPHICALCONSOLE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONSOLE_GRAPHICALCONSOLE_H



#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#define GRAPHICAL_CONSOLE_POSITION_X_PERCENT 10
#define GRAPHICAL_CONSOLE_POSITION_Y_PERCENT 70
#define GRAPHICAL_CONSOLE_WIDTH_PERCENT      80
#define GRAPHICAL_CONSOLE_HEIGHT_PERCENT     30



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_CONSOLE_GRAPHICALCONSOLE_H
