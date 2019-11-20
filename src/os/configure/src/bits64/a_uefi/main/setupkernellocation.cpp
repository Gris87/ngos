#include "setupkernellocation.h"

#include <buildconfig.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/utils.h>
#include <uefi/uefiloadedimageprotocol.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/bits64/other/configuredefines.h"
#include "src/bits64/other/kerneldescriptor.h"



extern void *_end; // _end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



NgosStatus setupKernelLocation(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    Guid                     protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
    uefi_handle              handle   = UEFI::getImageHandle();
    UefiLoadedImageProtocol *image    = 0;



    if (UEFI::handleProtocol(handle, &protocol, (void **)&image) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_LOADED_IMAGE_PROTOCOL", handle));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_LOADED_IMAGE_PROTOCOL", handle, image));



    UEFI_LVVV(("Loaded image:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("image->imageBase = 0x%p", image->imageBase));
    UEFI_LVVV(("image->imageSize = %u",   image->imageSize));

    UEFI_LVVV(("-------------------------------------"));



    // _end variable is pointing to KernelDescriptor structure included right after Configure part
    // HACK: Temporary fix for PIE. Try to find another solution
    KernelDescriptor *kernelDescriptor;
    AVOID_UNUSED(kernelDescriptor);

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq   _end(%%rip), %0"          // leaq   _end(%rip), %rdx    # Get address of _end variable to RDX. %RDX == kernelDescriptor
            :                             // Output parameters
                "=r" (kernelDescriptor)   // 'r' - any general register, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]



    // image->imageBase - Address of loaded image
    // image->imageSize == Boot part + .reloc section + Configure part + [De]compressed Kernel part
    // params->header.kernelLocation == image->imageBase + Boot part + .reloc section
    // So imageSize will be equal to Configure part + [De]compressed Kernel part
    u64 imageSize = image->imageSize - (params->header.kernelLocation - (u64)image->imageBase); // Remove Boot part and .reloc section



    // We are going to allocate space for imageSize + page table + stack ( + decompressed Kernel part if it compressed)
    //
    u64 allocSize =
            ROUND_UP(imageSize, PAGE_SIZE)  // Use ROUND_UP in order to make space for page table to be aligned
            + BOOT_PAGE_TABLE_SIZE
            + BOOT_STACK_SIZE
#if NGOS_BUILD_KERNEL_COMPRESSION != OPTION_KERNEL_COMPRESSION_NONE
            + kernelDescriptor->imageSize // Space for decompressed Kernel part
#endif
            ;



    UEFI_LVVV(("imageSize = %u", imageSize));
    UEFI_LVVV(("allocSize = %u", allocSize));



    u64 address = 0;

    if (UEFI::lowAlloc(allocSize, NGOS_BUILD_KERNEL_ALIGN, (void **)&address) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate space(%u) for kernel", allocSize));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Kernel allocated in space(0x%p, %u)", address, allocSize));



    // Copy whole image except Boot part and .reloc section to address
    memcpy((void *)address, (void *)params->header.kernelLocation, imageSize);

    params->header.kernelLocation      = address;
    params->header.kernelSize          = imageSize;
    params->header.allocatedKernelSize = allocSize;



    UEFI_LV(("Kernel relocated to address 0x%p", address));



    return NgosStatus::OK;
}
