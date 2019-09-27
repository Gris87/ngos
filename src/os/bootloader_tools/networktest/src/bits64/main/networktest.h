#ifndef NETWORKTEST_SRC_BITS64_MAIN_NETWORKTEST_H
#define NETWORKTEST_SRC_BITS64_MAIN_NETWORKTEST_H



#include <common/src/bits64/containers/arraylist.h>
#include <common/src/bits64/containers/list.h>
#include <common/src/bits64/graphics/image.h>
#include <ngos/status.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefifileinfo.h>
#include <uefi/uefiloadedimageprotocol.h>



class NetworkTest
{
public:
    static NgosStatus init(); // TEST: NO

    static NgosStatus loadImageFromAssets(const char8 *path, Image **image); // TEST: NO
};



#endif // NETWORKTEST_SRC_BITS64_MAIN_NETWORKTEST_H
