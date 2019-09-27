#ifndef MEMORYTEST_SRC_BITS64_MAIN_MEMORYTEST_H
#define MEMORYTEST_SRC_BITS64_MAIN_MEMORYTEST_H



#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefifileinfo.h>
#include <uefi/uefiloadedimageprotocol.h>



class MemoryTest
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus loadImageFromAssets(const char8 *path, Image **image); // TEST: NO
};



#endif // MEMORYTEST_SRC_BITS64_MAIN_MEMORYTEST_H
