#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H



#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



struct JpegStartOfScanComponent
{
    JpegComponentId id;

    union
    {
        struct
        {
            u8 huffmanAcTableId: 4;
            u8 huffmanDcTableId: 4;
        };

        u8 huffmanTableIds;
    };
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H
