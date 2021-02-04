#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



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
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



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
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%08X (%s)", (u32)operation, enumToString(operation));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
