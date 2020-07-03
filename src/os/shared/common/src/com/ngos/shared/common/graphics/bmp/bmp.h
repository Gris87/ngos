#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_BMP_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_BMP_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/ngos/status.h>



class Bmp
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GRAPHICS_BMP_BMP_H
