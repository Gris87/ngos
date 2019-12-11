#ifndef UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
#define UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H



#include <ngos/types.h>



enum class UefiGraphicsOutputBltOperation: u32
{
    VIDEO_FILL,
    VIDEO_TO_BLT_BUFFER,
    BLT_BUFFER_TO_VIDEO,
    VIDEO_TO_VIDEO,
    MAXIMUM
};



inline const char8* enumToString(UefiGraphicsOutputBltOperation operation) // TEST: NO
{
    switch (operation)
    {
        case UefiGraphicsOutputBltOperation::VIDEO_FILL:          return "VIDEO_FILL";
        case UefiGraphicsOutputBltOperation::VIDEO_TO_BLT_BUFFER: return "VIDEO_TO_BLT_BUFFER";
        case UefiGraphicsOutputBltOperation::BLT_BUFFER_TO_VIDEO: return "BLT_BUFFER_TO_VIDEO";
        case UefiGraphicsOutputBltOperation::VIDEO_TO_VIDEO:      return "VIDEO_TO_VIDEO";
        case UefiGraphicsOutputBltOperation::MAXIMUM:             return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiGraphicsOutputBltOperation operation) // TEST: NO
{
    switch (operation)
    {
        case UefiGraphicsOutputBltOperation::VIDEO_FILL:          return "VIDEO_FILL";
        case UefiGraphicsOutputBltOperation::VIDEO_TO_BLT_BUFFER: return "VIDEO_TO_BLT_BUFFER";
        case UefiGraphicsOutputBltOperation::BLT_BUFFER_TO_VIDEO: return "BLT_BUFFER_TO_VIDEO";
        case UefiGraphicsOutputBltOperation::VIDEO_TO_VIDEO:      return "VIDEO_TO_VIDEO";
        case UefiGraphicsOutputBltOperation::MAXIMUM:             return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
