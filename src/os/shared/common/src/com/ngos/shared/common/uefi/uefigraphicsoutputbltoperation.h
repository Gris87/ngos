#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiGraphicsOutputBltOperation operation) // TEST: NO
{
    // COMMON_LT((" | operation = %u", operation)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%08X (%s)", operation, enumToString(operation));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTOPERATION_H
