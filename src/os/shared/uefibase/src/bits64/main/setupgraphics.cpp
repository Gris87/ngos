#include "setupgraphics.h"

#include <guid/guid.h>
#include <ngos/linkage.h>
#include <uefi/uefigraphicsoutputprotocol.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus setupGraphicsOutputProtocol(BootParams *params, Guid *protocol, u64 size, uefi_handle *graphicsHandles)
{
    UEFI_LT((" | params = 0x%p, protocol = 0x%p, size = %u, graphicsHandles = 0x%p", params, protocol, size, graphicsHandles));

    UEFI_ASSERT(params,          "params is null",          NgosStatus::ASSERTION);
    UEFI_ASSERT(protocol,        "protocol is null",        NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0,        "size is zero",            NgosStatus::ASSERTION);
    UEFI_ASSERT(graphicsHandles, "graphicsHandles is null", NgosStatus::ASSERTION);



    i64 count = size / sizeof(uefi_handle);
    UEFI_LVVV(("count = %d", count));



    UefiGraphicsOutputProtocol **screens;
    u64                          screensSize  = count * sizeof(UefiGraphicsOutputProtocol *);
    u64                          screensCount = 0;

    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, screensSize, (void **)&screens) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for screen infos", screensSize));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for screen infos", screens, screensSize));



    for (i64 i = 0; i < count; ++i)
    {
        uefi_handle                 handle = graphicsHandles[i];
        UefiGraphicsOutputProtocol *gop;



        if (UEFI::handleProtocol(handle, protocol, (void **)&gop) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to handle(0x%p) protocol for UEFI_GRAPHICS_OUTPUT_PROTOCOL", handle));

            continue;
        }

        UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_GRAPHICS_OUTPUT_PROTOCOL", handle, gop));



        UEFI_LVVV(("gop->mode->maxMode = %u",           gop->mode->maxMode));
        UEFI_LVVV(("gop->mode->mode = %u",              gop->mode->mode));
        UEFI_LVVV(("gop->mode->info = 0x%p",            gop->mode->info));
        UEFI_LVVV(("gop->mode->sizeOfInfo = %u",        gop->mode->sizeOfInfo));
        UEFI_LVVV(("gop->mode->frameBufferBase = 0x%p", gop->mode->frameBufferBase));
        UEFI_LVVV(("gop->mode->frameBufferSize = %u",   gop->mode->frameBufferSize));

        UEFI_TEST_ASSERT(gop->mode->sizeOfInfo == sizeof(UefiGraphicsOutputModeInformation), NgosStatus::ASSERTION);



        u64 maximumBuffer = 0;
        u32 foundMode     = 0;

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

            UEFI_TEST_ASSERT(sizeOfInfo == sizeof(UefiGraphicsOutputModeInformation), NgosStatus::ASSERTION);



            u64 screenResolution = info->horizontalResolution * info->verticalResolution;

            UEFI_LVVV(("info->pixelFormat          = %u (%s)", info->pixelFormat, uefiGraphicsPixelFormatToString(info->pixelFormat)));
            UEFI_LVVV(("info->horizontalResolution = %u",      info->horizontalResolution));
            UEFI_LVVV(("info->verticalResolution   = %u",      info->verticalResolution));
            UEFI_LVVV(("screenResolution           = %u",      screenResolution));

            if (
                info->pixelFormat != UefiGraphicsPixelFormat::BLT_ONLY
                &&
                screenResolution > maximumBuffer
               )
            {
                maximumBuffer = screenResolution;
                foundMode     = j;
            }
        }



        if (gop->mode->mode != foundMode)
        {
            if (gop->setMode(gop, foundMode) != UefiStatus::SUCCESS)
            {
                UEFI_LF(("Failed to update screen mode"));

                return NgosStatus::FAILED;
            }

            UEFI_LVV(("Updated screen mode"));
        }



        screens[screensCount] = gop;
        ++screensCount;
    }



    // Validation
    {
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            UEFI_LVVV(("screens:"));
            UEFI_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)screensCount; ++i)
            {
                UEFI_LVVV(("screens[%d]->mode->frameBufferBase                     = 0x%p",    i, screens[i]->mode->frameBufferBase));
                UEFI_LVVV(("screens[%d]->mode->frameBufferSize                     = %u",      i, screens[i]->mode->frameBufferSize));
                UEFI_LVVV(("screens[%d]->mode->maxMode                             = %u",      i, screens[i]->mode->maxMode));
                UEFI_LVVV(("screens[%d]->mode->mode                                = %u",      i, screens[i]->mode->mode));
                UEFI_LVVV(("screens[%d]->mode->sizeOfInfo                          = %u",      i, screens[i]->mode->sizeOfInfo));
                UEFI_LVVV(("screens[%d]->mode->info->version                       = %u",      i, screens[i]->mode->info->version));
                UEFI_LVVV(("screens[%d]->mode->info->horizontalResolution          = %u",      i, screens[i]->mode->info->horizontalResolution));
                UEFI_LVVV(("screens[%d]->mode->info->verticalResolution            = %u",      i, screens[i]->mode->info->verticalResolution));
                UEFI_LVVV(("screens[%d]->mode->info->pixelsPerScanLine             = %u",      i, screens[i]->mode->info->pixelsPerScanLine));
                UEFI_LVVV(("screens[%d]->mode->info->pixelFormat                   = %u (%s)", i, screens[i]->mode->info->pixelFormat, uefiGraphicsPixelFormatToString(screens[i]->mode->info->pixelFormat)));
                UEFI_LVVV(("screens[%d]->mode->info->pixelInformation.redMask      = 0x%08X",  i, screens[i]->mode->info->pixelInformation.redMask));
                UEFI_LVVV(("screens[%d]->mode->info->pixelInformation.greenMask    = 0x%08X",  i, screens[i]->mode->info->pixelInformation.greenMask));
                UEFI_LVVV(("screens[%d]->mode->info->pixelInformation.blueMask     = 0x%08X",  i, screens[i]->mode->info->pixelInformation.blueMask));
                UEFI_LVVV(("screens[%d]->mode->info->pixelInformation.reservedMask = 0x%08X",  i, screens[i]->mode->info->pixelInformation.reservedMask));
            }

            UEFI_LVVV(("-------------------------------------"));
        }
#endif
    }



    params->screens      = screens;
    params->screensCount = screensCount;



    UEFI_ASSERT_EXECUTION(Console::init(params), NgosStatus::ASSERTION);
    UEFI_LVV(("Console initialized"));

    UEFI_ASSERT_EXECUTION(UEFI::noMorePrint(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus setupGraphicsOutputProtocol(BootParams *params, Guid *protocol, u64 size)
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



    Guid         graphicsProtocol = UEFI_GRAPHICS_OUTPUT_PROTOCOL_GUID;
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
