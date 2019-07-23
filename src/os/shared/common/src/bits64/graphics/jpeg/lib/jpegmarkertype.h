#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGMARKERTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGMARKERTYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



#define JPEG_START_OF_IMAGE_SIGNATURE 0xD8FF
#define JPEG_END_OF_IMAGE_SIGNATURE   0xD9FF



enum class JpegMarkerType: u8
{
    NONE                      = 0,
    START_OF_IMAGE            = 0xD8,
    START_OF_FRAME            = 0xC0,
    DEFINE_HUFFMAN_TABLE      = 0xC4,
    DEFINE_QUANTIZATION_TABLE = 0xDB,
    DEFINE_RESTART_INTERVAL   = 0xDD,
    START_OF_SCAN             = 0xDA,
    RESTART_0                 = 0xD0,
    RESTART_1                 = 0xD1,
    RESTART_2                 = 0xD2,
    RESTART_3                 = 0xD3,
    RESTART_4                 = 0xD4,
    RESTART_5                 = 0xD5,
    RESTART_6                 = 0xD6,
    RESTART_7                 = 0xD7,
    APPLICATION_0             = 0xE0,
    APPLICATION_1             = 0xE1,
    APPLICATION_2             = 0xE2,
    APPLICATION_3             = 0xE3,
    APPLICATION_4             = 0xE4,
    APPLICATION_5             = 0xE5,
    APPLICATION_6             = 0xE6,
    APPLICATION_7             = 0xE7,
    APPLICATION_8             = 0xE8,
    APPLICATION_9             = 0xE9,
    APPLICATION_10            = 0xEA,
    APPLICATION_11            = 0xEB,
    APPLICATION_12            = 0xEC,
    APPLICATION_13            = 0xED,
    APPLICATION_14            = 0xEE,
    APPLICATION_15            = 0xEF,
    COMMENT                   = 0xFE,
    END_OF_IMAGE              = 0xD9
};



inline const char* jpegMarkerTypeToString(JpegMarkerType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case JpegMarkerType::NONE:                      return "NONE";
        case JpegMarkerType::START_OF_IMAGE:            return "START_OF_IMAGE";
        case JpegMarkerType::START_OF_FRAME:            return "START_OF_FRAME";
        case JpegMarkerType::DEFINE_HUFFMAN_TABLE:      return "DEFINE_HUFFMAN_TABLE";
        case JpegMarkerType::DEFINE_QUANTIZATION_TABLE: return "DEFINE_QUANTIZATION_TABLE";
        case JpegMarkerType::DEFINE_RESTART_INTERVAL:   return "DEFINE_RESTART_INTERVAL";
        case JpegMarkerType::START_OF_SCAN:             return "START_OF_SCAN";
        case JpegMarkerType::RESTART_0:                 return "RESTART_0";
        case JpegMarkerType::RESTART_1:                 return "RESTART_1";
        case JpegMarkerType::RESTART_2:                 return "RESTART_2";
        case JpegMarkerType::RESTART_3:                 return "RESTART_3";
        case JpegMarkerType::RESTART_4:                 return "RESTART_4";
        case JpegMarkerType::RESTART_5:                 return "RESTART_5";
        case JpegMarkerType::RESTART_6:                 return "RESTART_6";
        case JpegMarkerType::RESTART_7:                 return "RESTART_7";
        case JpegMarkerType::APPLICATION_0:             return "APPLICATION_0";
        case JpegMarkerType::APPLICATION_1:             return "APPLICATION_1";
        case JpegMarkerType::APPLICATION_2:             return "APPLICATION_2";
        case JpegMarkerType::APPLICATION_3:             return "APPLICATION_3";
        case JpegMarkerType::APPLICATION_4:             return "APPLICATION_4";
        case JpegMarkerType::APPLICATION_5:             return "APPLICATION_5";
        case JpegMarkerType::APPLICATION_6:             return "APPLICATION_6";
        case JpegMarkerType::APPLICATION_7:             return "APPLICATION_7";
        case JpegMarkerType::APPLICATION_8:             return "APPLICATION_8";
        case JpegMarkerType::APPLICATION_9:             return "APPLICATION_9";
        case JpegMarkerType::APPLICATION_10:            return "APPLICATION_10";
        case JpegMarkerType::APPLICATION_11:            return "APPLICATION_11";
        case JpegMarkerType::APPLICATION_12:            return "APPLICATION_12";
        case JpegMarkerType::APPLICATION_13:            return "APPLICATION_13";
        case JpegMarkerType::APPLICATION_14:            return "APPLICATION_14";
        case JpegMarkerType::APPLICATION_15:            return "APPLICATION_15";
        case JpegMarkerType::COMMENT:                   return "COMMENT";
        case JpegMarkerType::END_OF_IMAGE:              return "END_OF_IMAGE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGMARKERTYPE_H
