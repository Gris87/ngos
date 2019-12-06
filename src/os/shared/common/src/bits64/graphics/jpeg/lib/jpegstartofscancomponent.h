#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H



#include <common/src/bits64/graphics/jpeg/lib/jpegcomponentid.h>
#include <ngos/types.h>



struct JpegStartOfScanComponent
{
    JpegComponentId id;
    u8              huffmanAcTableId: 4;
    u8              huffmanDcTableId: 4;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGSTARTOFSCANCOMPONENT_H
