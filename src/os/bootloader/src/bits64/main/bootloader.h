#ifndef BOOTLOADER_H
#define BOOTLOADER_H



#include <ngos/status.h>



class Bootloader
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initApplicationPath(); // TEST: NO

    static char *sApplicationPath;
};



#endif // BOOTLOADER_H
