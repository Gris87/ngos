#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H



#include <ngos/status.h>



class FPU
{
public:
    static NgosStatus init(); // TEST: NO

private:
    static NgosStatus initCpu(); // TEST: NO
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPU_H
