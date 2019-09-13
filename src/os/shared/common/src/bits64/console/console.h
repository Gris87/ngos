#ifndef OS_SHARED_COMMON_SRC_BITS64_CONSOLE_CONSOLE_H
#define OS_SHARED_COMMON_SRC_BITS64_CONSOLE_CONSOLE_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>
#include <ngos/types.h>
#include <uefi/uefigraphicsoutputprotocol.h>



class Console
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO

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

    static UefiGraphicsOutputProtocol *sScreenGop;
    static u16                         sScreenPosX;
    static u16                        *sGlyphOffsets;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_CONSOLE_CONSOLE_H
