#ifndef COM_NGOS_SHARED_COMMON_CONSOLE_CONSOLE_H
#define COM_NGOS_SHARED_COMMON_CONSOLE_CONSOLE_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/graphics/rgbapixel.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputprotocol.h>



class Console
{
public:
    static NgosStatus init(BootParams *params, RgbaPixel *doubleBuffer, u64 doubleBufferSize); // TEST: NO
    static NgosStatus init(); // TEST: NO

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

    static UefiGraphicsOutputProtocol *sScreenGop;
    static RgbaPixel                  *sDoubleBuffer;
    static RgbaPixel                  *sLastLineBuffer;
    static u64                         sLastLineBufferSize;
    static u16                         sScreenPosX;
    static u16                        *sGlyphOffsets;
};



#endif // COM_NGOS_SHARED_COMMON_CONSOLE_CONSOLE_H
