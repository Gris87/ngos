#include "partitionwizard.h"

#include <common/src/bits64/assets/assets.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/string.h>
#include <gpt/utils.h>
#include <guid/utils.h>
#include <uefi/uefiblockioprotocol.h>
#include <uefi/uefiharddrivedevicepath.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus PartitionWizard::init()
{
    UEFI_LT((""));



    return NgosStatus::OK;
}

NgosStatus PartitionWizard::loadImageFromAssets(const char8 *path, Image **image)
{
    UEFI_LT((" | path = %s, image = 0x%p", path, image));

    UEFI_ASSERT(path,  "path is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(image, "image is null", NgosStatus::ASSERTION);



    AssetEntry *asset = Assets::getAssetEntry(path);
    UEFI_TEST_ASSERT(asset, NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(Graphics::loadImage(asset->content, asset->contentSize, strend(path, ".9.png"), image), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
