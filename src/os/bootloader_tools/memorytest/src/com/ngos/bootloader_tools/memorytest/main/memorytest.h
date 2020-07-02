#ifndef MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_MAIN_MEMORYTEST_H
#define MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_MAIN_MEMORYTEST_H



#include <common/src/com/ngos/shared/common/ngos/status.h>



class MemoryTest
{
public:
    static NgosStatus init(); // TEST: NO

    static u64 getCpuSpeed(); // TEST: NO

private:
    static NgosStatus initCpuSpeed(); // TEST: NO

    static u64 sCpuSpeed;
};



#endif // MEMORYTEST_SRC_COM_NGOS_BOOTLOADER_TOOLS_MEMORYTEST_MAIN_MEMORYTEST_H
