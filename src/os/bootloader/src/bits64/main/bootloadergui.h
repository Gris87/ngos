#ifndef BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H
#define BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>



class BootloaderGUI
{
public:
    static NgosStatus init(BootParams *params); // TEST: NO
    static NgosStatus exec(); // TEST: NO
};



#endif // BOOTLOADER_SRC_BITS64_MAIN_BOOTLOADERGUI_H
