NGOS
====

1.4. UEFI initialization
------------------------

As we already know from the previous [chapter](../2.%20First%20steps%20in%20the%20kernel/README.md) we jump to the C++ code from start up with the instructions below:

```
# ============================================================================= # =============================================================================
# Entry point                                                                   #
#                                                                               #
# RDX - address of systemTable                                                  #
# RCX - address of imageHandle                                                  #
# ============================================================================= # =============================================================================
                                                                                #
    movq    %rcx, %rdi                                                          # Put address of imageHandle to RDI
    movq    %rdx, %rsi                                                          # Put address of systemTable to RSI
    leaq    _start(%rip), %rdx                                                  # Put address of entry point to RDX
                                                                                #
    call    uefiMain                                                            # Call uefiMain function
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
```

Let's go through [uefiMain()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/main.cpp#L106) function and explain what we are doing.

```
    // We can't output at the moment
    // UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // Commented to avoid error because UEFI is uninitialized
```

At the beginning of each function it is required to have such LT logs that provides information about currently executed function and its parameters.<br/>
You have to set [NGOS_BUILD_LOG_LEVEL](../../0.%20Intro/3.%20Configuration/README.md#-----------ngos_build_log_level-----------) configuration parameter to TRACE logging level in order to see such logs.<br/>
But, we can't do any output at the moment unfortunately. We will call it later.

```
    UEFI_ASSERT_EXECUTION(Serial::initConsole(), 0);
```

As we already mention in [Logging principles chapter](../3.%20Logging%20principles/README.md) we have to call Serial::initConsole() method at the very beginning of the kernel in order to enable logging to default serial port.<br/>
We are checking that Serial::initConsole() was successful with UEFI_ASSERT_EXECUTION macro, otherwise we just leave uefiMain() function.

```
    // Check that we are booting via UEFI
    if (systemTable->header.signature != UEFI_SYSTEM_TABLE_SIGNATURE)
    {
        UEFI_LF(("Unexpected UEFI System Table signature"));

        return 0;
    }
```

Here we just double check that we are booting via UEFI and nothing else.

```
    UEFI_ASSERT_EXECUTION(UEFI::init(imageHandle, systemTable), 0);
```

We are finally initialize [UEFI](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/uefi/uefi.cpp#L19) module with the address of Image Handle and address of System Table.<br/>
After that we can do the printing on the screen.

```
    UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p, kernelLocation = 0x%p", imageHandle, systemTable, kernelLocation)); // We can output now

    UEFI_ASSERT(imageHandle,    "imageHandle is null",    0);
    UEFI_ASSERT(systemTable,    "systemTable is null",    0);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", 0);



    UEFI_LI(("NGOS starting up"));
```

Since we can output we are calling the same UEFI_LT macro for trace logging.<br/>
We are also saying that NGOS is started.<br/>
Here you can see some assertions. It is strongly recommended to do attribute checking in each function.<br/>
We are calling it here because in case of issue we need to print the error message on the screen. That's why we can't do it earlier.

### Waiting for GDB debugging

```
#if NGOS_BUILD_RELEASE == OPTION_NO
    UEFI_LD(("Executing code for gdb_debug"));
    UEFI_LD(("Kernel started at address 0x%p", kernelLocation));
    UEFI_LD(("gdb_debug is ready to go"));

    UEFI_ASSERT_EXECUTION(waitForGdbDebug(),            0);
    UEFI_ASSERT_EXECUTION(gdbDebugBreakpointFunction(), 0);
#else
    UEFI_LV(("Kernel started at address 0x%p", kernelLocation));
#endif
```

This code block is mostly interesting for users that want to debug kernel with gdb.<br/>
In case if we build kernel in Debug mode it will provide 5 second delay for establishing GDB connection.<br/>
Please refer to [How to debug chapter](../../0.%20Intro/5.%20How%20to%20debug/README.md) for details.

### Early CPU initialization

```
    UEFI_ASSERT_EXECUTION(CPU::init(), 0);
    UEFI_LI(("CPU information initialized"));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
    UEFI_ASSERT_EXECUTION(printCpuFlags(), 0);
#endif



    const char *wantedCpuFlag = 0;

    if (CPU::check(&wantedCpuFlag) != NgosStatus::OK)
    {
        char buffer[1024];

        UEFI_ASSERT_EXECUTION(UEFI::clearScreen(), UefiStatus, UefiStatus::SUCCESS, 0);



        UEFI_ASSERT_EXECUTION(CPU::toString(buffer, 1024), 0);

        UEFI_LF(("%s\n", buffer));

        UEFI_ASSERT_EXECUTION(CPU::flagsToString(buffer, 1024), 0);



        UEFI_LF(("CPU flags:             %s\n", buffer));

        if (wantedCpuFlag && *wantedCpuFlag)
        {
            UEFI_LF(("CPU flag \"%s\" is not supported\n", wantedCpuFlag));
        }

        UEFI_LF(("Your CPU is already outdated. Please upgrade your hardware."));
        UEFI_LF(("It is expected Intel Skylake CPU or newer or AMD Zen CPU or newer."));



        return 0;
    }
```

Here we are doing initialization of CPU module in order to obtain all CPU flags.<br/>
We also check the CPU flags and inform user when CPU is not supported.

### Assets initialization

Assets are the set of files directly included to kernel image from [src/os/configure/assets](../../../src/os/configure/assets) folder via [src/os/configure/assets/generate_assets.sh](../../../src/os/configure/assets/generate_assets.sh) script.

```
    UEFI_ASSERT_EXECUTION(Assets::init(), 0);
    UEFI_LI(("Assets initialized"));
```

Here we are calling [Assets::init()](https://github.com/Gris87/ngos/blob/master/src/os/shared/common/src/bits64/assets/assets.cpp#L19) function to perform loading addresses of all assets included to kernel image.<br/>
We can get address of some asset with [Assets::getAssetEntry()](https://github.com/Gris87/ngos/blob/master/src/os/shared/common/src/bits64/assets/assets.cpp#L87) function after this.

### Early kernel testing

```
#if NGOS_BUILD_TEST_MODE == OPTION_YES
    if (startTestSection0() != NgosStatus::OK)
    {
        UEFI_LF(("Test failure"));

        return 0;
    }
#endif
```

This code block is only working if kernel was built with the tests.<br/>
It just perform checking for the set of tests located in [src/os/configure/test/bits64/a_uefi/sections/section0](../../../src/os/configure/test/bits64/a_uefi/sections/section0) folder.<br/>
In case of issue we leave uefiMain() function.

### Setup boot parameters

Boot parameters are the set of parameters that can be shared between Configure part, Kernel part and Installer part.

```
    BootParams *params = 0;

    if (setupBootParams(&params, kernelLocation) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup boot parameters"));

        return 0;
    }

    UEFI_LI(("Setup boot parameters completed"));
```

If you check [setupBootParams()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/main/setupbootparams.cpp#L11) function you will know that it is allocating few pages for [BootParams](../../../src/os/include/bootparams/bootparams.h) structure and perform following simple initialization:

```
    memzero(*params, sizeof(BootParams));

    (*params)->header.signature      = BOOT_PARAMS_HEADER_SIGNATURE;
    (*params)->header.kernelLocation = kernelLocation;
```

### Setup graphics

We need to setup graphics in order to have possibility to draw something on the screen.

```
    if (setupGraphics(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup graphics"));

        return 0;
    }

    UEFI_LI(("Setup graphics completed"));
```

[setupGraphics()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/main/setupgraphics.cpp#L355) function loops over Graphics Output Protocols(GOP) and try to find GOP that support mode with the biggest screen resolution.<br/>
After that we are switching to this mode(why not?) and updating screenInfo in boot parameters via [updateScreenInfo()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/main/setupgraphics.cpp#L47) function.

Since we have information about screen we can use our own printing on the screen.

```
    UEFI_ASSERT_EXECUTION(Console::init(params), NgosStatus::ASSERTION);
    UEFI_LVV(("Console initialized"));
```

[Console](../../../src/os/shared/common/src/bits64/console/console.cpp) module is a special module that use predrawn glyphs for printing on the screen.<br/>
It even can print after calling UEFI::exitBootServices().<br/>
These glyphs located in kernel image as an asset. We are using freetype library to prepare the glyphs.<br/>
You may check it in [code_generator](../../../tools/qt/code_generator/src/generators/assets/zzz_generators/consoleglyphgenerator.cpp) tool.

### Setup PCI IO

Several PCI devices may have its own Read-only memory (ROM) that mostly used for initialization of such devices.<br/>
We have to store these ROM images in order to setup these PCI devices.

```
    if (setupPciIo(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup PCI IO"));

        return 0;
    }

    UEFI_LI(("Setup PCI IO completed"));
```

[setupPciIo()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/main/setuppciio.cpp#L298) function loops over PCI IO Protocols and try to find PCI devices with ROM image.<br/>
If we found such device we will allocate enough space for storing its PCI ROM image.

As a result we should have a linked list of [PciRomImageWithInfo](../../../src/os/include/bootparams/pciromimagewithinfo.h) objects in boot parameters that contains information about PCI device and the ROM image itself.

### Setup kernel location

UEFI loads kernel image in any place of the memory.<br/>
Sometimes it may cause issues in case when image is located above 4 GB limit since we may have to perform jump to 32 bit mode.<br/>
For example, switching to 5 level paging requires to jump to 32 bit mode.<br/>
That's why we are relocating kernel to low address space.

```
    if (setupKernelLocation(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup kernel location"));

        return 0;
    }

    UEFI_LI(("Setup kernel location completed"));
```

As you can see [setupKernelLocation()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/main/setupkernellocation.cpp#L20) function is a little bit complex. So, we will explain it more deeply.

First of all, we will get information about loaded image:

```
    UefiGuid                 protocol = UEFI_LOADED_IMAGE_PROTOCOL_GUID;
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
```

The structure of kernel image can be displayed on figure below:

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/4.%20UEFI%20initialization/Image%20structure.png?raw=true" alt="Image structure"/>
</p>

Since Boot part and .reloc section is only required for UEFI we don't need it anymore.<br/>
We need to drop it from the relocated kernel.<br/>
This can be done in the following way:

```
    // image->imageBase - Address of loaded image
    // image->imageSize == Boot part + .reloc section + Configure part + [De]compressed Kernel part
    // params->header.kernelLocation == image->imageBase + Boot part + .reloc section
    // So imageSize will be equal to Configure part + [De]compressed Kernel part
    u64 imageSize = image->imageSize - (params->header.kernelLocation - (u64)image->imageBase); // Remove Boot part and .reloc section
```

As a result imageSize should be equal to total size of .config section and .kernel section.<br/>
But actually we have to allocate more memory for the kernel.

<p align="center">
    <img src="https://github.com/Gris87/ngos/blob/master/docs/1.%20Booting/4.%20UEFI%20initialization/Kernel%20relocation.png?raw=true" alt="Image structure"/>
</p>

As you can see we are also allocating space for page table, stack and for decompressed kernel if the kernel was compressed.<br/>
Page table should be properly aligned to page size. Therefore we are adding few bytes to imageSize variable to make it aligned.<br/>
It is expected that the location of relocated kernel will be also aligned to page size.

```
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
```

Page table grows from bottom to top while stack grows from top to bottom.<br/>
There is may happen that stack overlap the page table area.<br/>
Stack size should be big enough in order to avoid it.

After that we are allocating space for relocated kernel and storing the results to boot parameters:

```
    // Copy whole image except Boot part and .reloc section to address
    memcpy((void *)address, (void *)params->header.kernelLocation, imageSize);

    params->header.kernelLocation      = address;
    params->header.kernelSize          = imageSize;
    params->header.allocatedKernelSize = allocSize;
```

### Exit Boot Services

At the end of UEFI initialization we are calling exitBootServices() function to release unnecessary resources.

```
    if (exitBootServices(params) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to exit boot services"));

        return 0;
    }

    UEFI_LI(("Exit boot services completed"));
```

If you check [exitBootServices()](https://github.com/Gris87/ngos/blob/master/src/os/configure/src/bits64/a_uefi/main/exitbootservices.cpp#L106) function you will know that we are getting memory map and trying to call UEFI::exitBootServices() with it.<br/>
In case if the first attempt failed it means that memory map was changed and we have one more attempt to exit.

If everything is good we will store information about last known memory map to boot parameters.

### Jumping to relocated kernel

We are ready to perform jump to the relocated kernel now.<br/>
As we already mention UEFI may load kernel image in any place of the memory and this can be a problem when we would like to switch to 32 bit mode while image loaded above 4 GB limit.

Let's go back to [src/os/configure/asm/arch/x86_64/main.S](../../../src/os/configure/asm/arch/x86_64/main.S) file.

```
# ============================================================================= # =============================================================================
# Entry point                                                                   #
#                                                                               #
# RDX - address of systemTable                                                  #
# RCX - address of imageHandle                                                  #
# ============================================================================= # =============================================================================
                                                                                #
    movq    %rcx, %rdi                                                          # Put address of imageHandle to RDI
    movq    %rdx, %rsi                                                          # Put address of systemTable to RSI
    leaq    _start(%rip), %rdx                                                  # Put address of entry point to RDX
                                                                                #
    call    uefiMain                                                            # Call uefiMain function
                                                                                #
    cmpq    $0, %rax                                                            # IF result == 0
    je      fail                                                                #   THEN jump to fail
                                                                                #
    movq    %rax, %rsi                                                          # Put address of boot parameters to RSI
```

As a result uefiMain() function should return address of boot parameters and 0 value in error case. In case of error we will jump to fail label and halt PC in forever loop.

But if everything was fine we will store the result to RSI register.

Instructions below allows to get address of next instruction in relocated address space and perform jump to it.

```
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Jump to the relocated address                                                 #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movq    ASM_OFFSET_BOOT_PARAM_KERNEL_LOCATION(%rsi), %rax                   # Get the relocated address of kernel
    leaq    relocated_address(%rax), %rax                                       # Get address of relocated_address label in relocated address space
    jmp     *%rax                                                               # Jump to relocated_address label in relocated address space
                                                                                #
relocated_address:                                                              # Label for relocated address
```
