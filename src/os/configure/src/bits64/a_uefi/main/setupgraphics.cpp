#include "setupgraphics.h"

#include <ngos/linkage.h>
#include <uefi/uefigraphicsoutputprotocol.h>
#include <uefi/uefiguid.h>

#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



NgosStatus pixelBitMaskToOffsetAndSize(u32 mask, u8 *offset, u8 *size)
{
    UEFI_LT((" | mask = %u, offset = 0x%p, size = 0x%p", mask, offset, size));

    UEFI_ASSERT(offset, "offset is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size,   "size is null",   NgosStatus::ASSERTION);



    u8 position = 0;
    u8 length   = 0;

    if (mask)
    {
        while (!(mask & 0x01))
        {
            mask >>= 1;
            ++position;
        }

        while (mask & 0x01)
        {
            mask >>= 1;
            ++length;
        }
    }

    *offset = position;
    *size   = length;



    return NgosStatus::OK;
}

NgosStatus updateScreenInfo(BootParams *params, UefiGraphicsOutputProtocol *gop, UefiGraphicsOutputModeInformation *info)
{
    UEFI_LT((" | params = 0x%p, gop = 0x%p, info = 0x%p", params, gop, info));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(gop,    "gop is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(info,   "info is null",   NgosStatus::ASSERTION);



    switch (info->pixelFormat)
    {
        case UefiGraphicsPixelFormat::RGB_8_BIT_PER_COLOR:
        {
            params->screenInfo.depth          = 32;
            params->screenInfo.lineLength     = info->pixelsPerScanLine << 2; // "<< 2" == "* 4"
            params->screenInfo.redOffset      = 0;
            params->screenInfo.greenOffset    = 8;
            params->screenInfo.blueOffset     = 16;
            params->screenInfo.reservedOffset = 24;
            params->screenInfo.redSize        = 8;
            params->screenInfo.greenSize      = 8;
            params->screenInfo.blueSize       = 8;
            params->screenInfo.reservedSize   = 8;
        }
        break;

        case UefiGraphicsPixelFormat::BGR_8_BIT_PER_COLOR:
        {
            params->screenInfo.depth          = 32;
            params->screenInfo.lineLength     = info->pixelsPerScanLine << 2; // "<< 2" == "* 4"
            params->screenInfo.redOffset      = 16;
            params->screenInfo.greenOffset    = 8;
            params->screenInfo.blueOffset     = 0;
            params->screenInfo.reservedOffset = 24;
            params->screenInfo.redSize        = 8;
            params->screenInfo.greenSize      = 8;
            params->screenInfo.blueSize       = 8;
            params->screenInfo.reservedSize   = 8;
        }
        break;

        case UefiGraphicsPixelFormat::BIT_MASK:
        {
            UEFI_ASSERT_EXECUTION(pixelBitMaskToOffsetAndSize(info->pixelInformation.redMask,      &params->screenInfo.redOffset,      &params->screenInfo.redSize),      NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(pixelBitMaskToOffsetAndSize(info->pixelInformation.greenMask,    &params->screenInfo.greenOffset,    &params->screenInfo.greenSize),    NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(pixelBitMaskToOffsetAndSize(info->pixelInformation.blueMask,     &params->screenInfo.blueOffset,     &params->screenInfo.blueSize),     NgosStatus::ASSERTION);
            UEFI_ASSERT_EXECUTION(pixelBitMaskToOffsetAndSize(info->pixelInformation.reservedMask, &params->screenInfo.reservedOffset, &params->screenInfo.reservedSize), NgosStatus::ASSERTION);

            params->screenInfo.depth =
                    params->screenInfo.redSize +
                    params->screenInfo.greenSize +
                    params->screenInfo.blueSize +
                    params->screenInfo.reservedSize;

            params->screenInfo.lineLength = (info->pixelsPerScanLine * params->screenInfo.depth) >> 3; // ">> 3" == "/ 8"
        }
        break;

        case UefiGraphicsPixelFormat::BLT_ONLY:
        case UefiGraphicsPixelFormat::MAXIMUM:
        {
            UEFI_LF(("Invalid pixel format %d", info->pixelFormat));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;

        default:
        {
            UEFI_LF(("Unknown pixel format %d", info->pixelFormat));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    params->screenInfo.width           = info->horizontalResolution;
    params->screenInfo.height          = info->verticalResolution;
    params->screenInfo.frameBufferBase = gop->mode->frameBufferBase;
    params->screenInfo.frameBufferSize = params->screenInfo.lineLength * params->screenInfo.height;



    return NgosStatus::OK;
}

NgosStatus setupGraphicsOutputProtocol(BootParams *params, UefiGuid *protocol, u64 size, uefi_handle *graphicsHandles)
{
    UEFI_LT((" | params = 0x%p, protocol = 0x%p, size = %u, graphicsHandles = 0x%p", params, protocol, size, graphicsHandles));

    UEFI_ASSERT(params,          "params is null",          NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol,        "protocol is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,        "size is zero",            NgosStatus::ASSERTION);
    UEFI_ASSERT(graphicsHandles, "graphicsHandles is null", NgosStatus::ASSERTION);



    u64                                maximumBuffer = 0;
    UefiGraphicsOutputProtocol        *foundGop      = 0;
    u32                                foundMode     = 0;
    UefiGraphicsOutputModeInformation *foundInfo     = 0;



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));

    for (i64 i = 0; i < count; ++i)
    {
        uefi_handle                 handle = graphicsHandles[i];
        UefiGraphicsOutputProtocol *gop    = 0;



        if (UEFI::handleProtocol(handle, protocol, (void **)&gop) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_GRAPHICS_OUTPUT_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", handle, gop));



        for (i64 j = 0; j < gop->mode->maxMode; ++j)
        {
            u64                                sizeOfInfo = 0;
            UefiGraphicsOutputModeInformation *info       = 0;



            if (gop->queryMode(gop, j, &sizeOfInfo, &info) != UefiStatus::SUCCESS)
            {
                UEFI_LE(("Failed to query mode(%d) for protocol(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", j, gop));

                continue;
            }

            UEFI_LVV(("Queried mode(%d) with info(0x%p, %u) for protocol(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", j, info, sizeOfInfo, gop));



            u64 screenResolution = info->horizontalResolution * info->verticalResolution;

            UEFI_LVVV(("info->pixelFormat          = %d", info->pixelFormat));
            UEFI_LVVV(("info->horizontalResolution = %u", info->horizontalResolution));
            UEFI_LVVV(("info->verticalResolution   = %u", info->verticalResolution));
            UEFI_LVVV(("screenResolution           = %u", screenResolution));

            if (
                info->pixelFormat != UefiGraphicsPixelFormat::BLT_ONLY
                &&
                screenResolution > maximumBuffer
               )
            {
                maximumBuffer = screenResolution;
                foundGop      = gop;
                foundMode     = j;
                foundInfo     = info;
            }
        }
    }



    if (!foundGop)
    {
        UEFI_LF(("Failed to find valid protocol for UEFI_GRAPHICS_OUTPUT_PROTOCOL"));

        return NgosStatus::NOT_FOUND;
    }

    UEFI_LVV(("Found valid protocol(0x%p) with info(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", foundGop, foundInfo));



    if (foundGop->mode->mode != foundMode)
    {
        if (foundGop->setMode(foundGop, foundMode) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to update screen mode"));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Updated screen mode"));
    }



    if (updateScreenInfo(params, foundGop, foundInfo) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to update screen info"));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Updated screen info"));



    UEFI_LVVV(("Screen info:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("frameBufferBase = 0x%p", params->screenInfo.frameBufferBase));
    UEFI_LVVV(("frameBufferSize = %u",   params->screenInfo.frameBufferSize));
    UEFI_LVVV(("lineLength      = %u",   params->screenInfo.lineLength));
    UEFI_LVVV(("width           = %u",   params->screenInfo.width));
    UEFI_LVVV(("height          = %u",   params->screenInfo.height));
    UEFI_LVVV(("depth           = %u",   params->screenInfo.depth));
    UEFI_LVVV(("redOffset       = %u",   params->screenInfo.redOffset));
    UEFI_LVVV(("greenOffset     = %u",   params->screenInfo.greenOffset));
    UEFI_LVVV(("blueOffset      = %u",   params->screenInfo.blueOffset));
    UEFI_LVVV(("reservedOffset  = %u",   params->screenInfo.reservedOffset));
    UEFI_LVVV(("redSize         = %u",   params->screenInfo.redSize));
    UEFI_LVVV(("greenSize       = %u",   params->screenInfo.greenSize));
    UEFI_LVVV(("blueSize        = %u",   params->screenInfo.blueSize));
    UEFI_LVVV(("reservedSize    = %u",   params->screenInfo.reservedSize));

    UEFI_LVVV(("-------------------------------------"));



    // UEFI_TEST_ASSERT(params->screenInfo.frameBufferBase == 0x0000000080000000, NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->screenInfo.frameBufferSize == 1920000,            NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->screenInfo.lineLength      == 3200,               NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->screenInfo.width           == 800,                NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->screenInfo.height          == 600,                NgosStatus::ASSERTION); // Commented due to value variation
    UEFI_TEST_ASSERT((params->screenInfo.depth             == 32)
                    ||
                    (params->screenInfo.depth              == 24),                NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(params->screenInfo.redOffset          == 16,                 NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(params->screenInfo.greenOffset        == 8,                  NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(params->screenInfo.blueOffset         == 0,                  NgosStatus::ASSERTION);
    // UEFI_TEST_ASSERT(params->screenInfo.reservedOffset  == 24,                 NgosStatus::ASSERTION); // Commented due to value variation
    UEFI_TEST_ASSERT(params->screenInfo.redSize            == 8,                  NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(params->screenInfo.greenSize          == 8,                  NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(params->screenInfo.blueSize           == 8,                  NgosStatus::ASSERTION);
    // UEFI_TEST_ASSERT(params->screenInfo.reservedSize    == 8,                  NgosStatus::ASSERTION); // Commented due to value variation



    UEFI_ASSERT_EXECUTION(Console::init(params), NgosStatus::ASSERTION);
    UEFI_LVV(("Console initialized"));



    return NgosStatus::OK;
}

NgosStatus setupGraphicsOutputProtocol(BootParams *params, UefiGuid *protocol, u64 size)
{
    UEFI_LT((" | params = 0x%p, protocol = 0x%p, size = %u", params, protocol, size));

    UEFI_ASSERT(params,   "params is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol, "protocol is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero",     NgosStatus::ASSERTION);



    uefi_handle *graphicsHandles = 0;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&graphicsHandles) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for handles for UEFI_GRAPHICS_OUTPUT_PROTOCOL", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for handles for UEFI_GRAPHICS_OUTPUT_PROTOCOL", graphicsHandles, size));



    NgosStatus status = NgosStatus::FAILED;

    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, protocol, 0, &size, graphicsHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located handles(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", graphicsHandles));

        status = setupGraphicsOutputProtocol(params, protocol, size, graphicsHandles);
    }
    else
    {
        UEFI_LF(("Failed to locate handles(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", graphicsHandles));
    }



    if (UEFI::freePool(graphicsHandles) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for handles for UEFI_GRAPHICS_OUTPUT_PROTOCOL", graphicsHandles));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for handles for UEFI_GRAPHICS_OUTPUT_PROTOCOL", graphicsHandles));
    }



    return status;
}

NgosStatus setupGraphics(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UefiGuid     graphicsProtocol = UEFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
    u64          graphicsSize     = 0;
    uefi_handle *graphicsHandles  = 0;



    if (UEFI::locateHandle(UefiLocateSearchType::BY_PROTOCOL, &graphicsProtocol, 0, &graphicsSize, graphicsHandles) == UefiStatus::BUFFER_TOO_SMALL)
    {
        UEFI_LVV(("Found size(%u) of buffer for handles for UEFI_GRAPHICS_OUTPUT_PROTOCOL", graphicsSize));

        if (setupGraphicsOutputProtocol(params, &graphicsProtocol, graphicsSize) != NgosStatus::OK)
        {
            UEFI_LF(("Failed to setup UEFI_GRAPHICS_OUTPUT_PROTOCOL"));

            return NgosStatus::FAILED;
        }

        UEFI_LV(("Setup UEFI_GRAPHICS_OUTPUT_PROTOCOL completed"));
    }
    else
    {
        UEFI_LW(("Handle for UEFI_GRAPHICS_OUTPUT_PROTOCOL not found"));
    }



    return NgosStatus::OK;
}
