#ifndef UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
#define UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#endif



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(UefiGraphicsOutputBltOperation operation) // TEST: NO
{
    static char8 res[33];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif



#endif // UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
