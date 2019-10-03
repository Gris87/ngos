#ifndef HDDTEST_SRC_BITS64_MAIN_HDDTEST_H
#define HDDTEST_SRC_BITS64_MAIN_HDDTEST_H



#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefifileinfo.h>
#include <uefi/uefiloadedimageprotocol.h>



class HddTest
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus loadImageFromAssets(const char8 *path, Image **image); // TEST: NO
};



#endif // HDDTEST_SRC_BITS64_MAIN_HDDTEST_H