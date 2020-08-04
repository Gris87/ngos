#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H



#include <com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H
