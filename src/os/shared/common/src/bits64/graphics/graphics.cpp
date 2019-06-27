#include "graphics.h"

#include <common/src/bits64/graphics/bmp/bmp.h>
#include <common/src/bits64/graphics/bmp/bmpheader.h>
#include <common/src/bits64/graphics/jpeg/jpeg.h>
#include <common/src/bits64/graphics/jpeg/jpegmarkertype.h>
#include <common/src/bits64/graphics/png/png.h>
#include <common/src/bits64/graphics/png/pngheader.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



NgosStatus Graphics::loadImage(u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, image = 0x%p", data, size, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);



    if (size >= 8)
    {
        if (*((u64 *)&data[0]) == PNG_HEADER_SIGNATURE)
        {
            return Png::loadImage(data, size, image);
        }



        if (
            *((u16 *)&data[0])        == JPEG_START_OF_IMAGE_SIGNATURE
            &&
            *((u16 *)&data[size - 2]) == JPEG_END_OF_IMAGE_SIGNATURE
           )
        {
            return Jpeg::loadImage(data, size, image);
        }



        if (*((u16 *)&data[0]) == BMP_HEADER_SIGNATURE)
        {
            return Bmp::loadImage(data, size, image);
        }
    }



    COMMON_LF(("Failed to load image from not supported image format"));

    *image = 0;



    return NgosStatus::NOT_SUPPORTED;
}
