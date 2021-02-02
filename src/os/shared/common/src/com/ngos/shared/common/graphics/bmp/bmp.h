#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_BMP_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_BMP_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/ngos/status.h>



class Bmp
{
public:
    static NgosStatus loadImage(bad_uint8 *data, bad_uint64 size, Image **image); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_BMP_H
