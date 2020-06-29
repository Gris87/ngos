BOOTSEG = 0x07C0                                                                # Address of boot sector in memory (0x7C00 >> 4)
                                                                                #
.code16                                                                         # Generate code in 16 bits mode
.section ".bootsector_code", "ax"                                               # bootsector_code section (a - allocatable, x - executable)
                                                                                #
.globl  _start                                                                  # Make _start visible for linker
_start:                                                                         # Global pointer to the entry point in order to make linker silent
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    .ascii  "MZ"                                                                # Start boot sector with MZ characters (MS-DOS Header) in order to let UEFI to skip 0x0200 bytes
                                                                                #
    ljmp    $(BOOTSEG), $(start2)                                               # Normalize the start address
start2:                                                                         # Label used for normalization
                                                                                #
# ============================================================================= # =============================================================================
# There is no UEFI                                                              # We will print message and reboot PC
# ============================================================================= # =============================================================================
                                                                                #
    movw    %cs, %ax                                                            # Indirectly assign (via AX)...
    movw    %ax, %ds                                                            # CS to DS
    movw    %ax, %es                                                            # CS to ES
    movw    %ax, %ss                                                            # CS to SS
    xorw    %sp, %sp                                                            # Set SP to 0
    sti                                                                         # Set Interrupt Flag (When the IF flag is set, the processor begins responding to external, maskable interrupts after the next instruction is executed.)
    cld                                                                         # Clear Direction Flag (When the DF flag is set to 0, string operations increment the index registers (ESI and/or EDI))
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
    movw   $(reboot_msg), %si                                                   # Store pointer of reboot message to SI
                                                                                #
msg_loop:                                                                       # Label for printing message
    lodsb                                                                       # Load one byte from SI to AL
    andb    %al, %al                                                            # IF AL == 0
    jz      bs_die                                                              #   THEN jump to bs_die
    movb    $0x0E, %ah                                                          #   ELSE set AH to 0x0E (Printing on the screen)
    movw    $0x07, %bx                                                          #        set BX to 0x07 (BH=0 - first page, BL=7 - Light Gray)
    int     $0x10                                                               #        Call interrupt 0x10 for printing character from AL on the screen
    jmp     msg_loop                                                            #        Print next character
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
bs_die:                                                                         # We will come to this label when reboot message printed
    xorw    %ax, %ax                                                            # Set AX to 0 in order to let interrupt 0x16 to read key press
    int     $0x16                                                               # Wait until user press some keyboard button
    int     $0x19                                                               # Go to the bootstrap loader (It will try to reload from some bootable disk)
                                                                                #
    ljmp    $0xF000, $0xFFF0                                                    # Reboot your PC if something goes wrong
                                                                                #
# ============================================================================= # =============================================================================
# We have UEFI                                                                  # https://en.wikibooks.org/wiki/X86_Disassembly/Windows_Executable_Files
# ============================================================================= # =============================================================================
                                                                                #
    .org    0x3C                                                                # According to MS-DOS Header there is e_lfanew field at 0x3C.
    .long   pe_header                                                           # We will put offset to the PE Header here.
                                                                                #
# ============================================================================= # =============================================================================
# There is no UEFI                                                              # This section has a reboot message only
# ============================================================================= # =============================================================================
                                                                                #
.section ".bootsector_data", "a"                                                # bootsector_data section (a - allocatable)
reboot_msg:                                                                     # Reboot message
    .ascii  "Please use UEFI bootloader.\r\n"                                   # A lot of...
    .ascii  "\n"                                                                # bytes for...
    .ascii  "Remove disk and press any key to reboot...\r\n"                    # reboot message...
    .byte   0                                                                   # Ends with 0
                                                                                #
# ============================================================================= # =============================================================================
# We have UEFI                                                                  # https://en.wikibooks.org/wiki/X86_Disassembly/Windows_Executable_Files
# ============================================================================= # =============================================================================
                                                                                #
pe_header:                                                                      # Label for locating PE Header
    .ascii  "PE\0\0"                                                            # PE Header starts with PE\0\0
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
coff_header:                                                                    # We will put COFF Header right after the PE Header
                                                                                # struct COFFHeader
                                                                                # {
    .word   0x8664  # 0x8664 == x86-64 machine                                  #     short machine;                # This field determines what machine the file was compiled for.
    .word   0x03    # 3 sections                                                #     short numberOfSections;       # The number of sections that are described at the end of the PE headers.
    .long   0       # No timestamp                                              #     long timeDateStamp;           # 32 bit time at which this header was generated.
    .long   0       # No symbols                                                #     long pointerToSymbolTable;    # Pointer to symbol table.
    .long   0       # No symbols                                                #     long numberOfSymbols;         # Number of symbols.
    .word   section_table - optional_header                                     #     short sizeOfOptionalHeader;   # This field shows how long the "PE Optional Header" is that follows the COFF header.
    .word   0x0206  #   IMAGE_FILE_DEBUG_STRIPPED                               #     short characteristics;        # This is a field of bit flags, that show some characteristics of the file.
                    # | IMAGE_FILE_LINE_NUMS_STRIPPED                           # }
                    # | IMAGE_FILE_EXECUTABLE_IMAGE                             #
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
optional_header:                                                                # Label for PE Optional Header
                                                                                # struct PEOptHeader
                                                                                # {
    .word   0x020B  # PE32+ format                                              #     short signature;                                      # Magic number 0x020B for identifing PE format for 64 bit system
    .byte   0x0E    # Some modern                                               #     char majorLinkerVersion;                              # The major version number of the linker.
    .byte   0x0A    # linker version                                            #     char minorLinkerVersion;                              # The minor version number of the linker.
    .long   0       # Ignored                                                   #     long sizeOfCode;                                      # The size of the code section, in bytes, or the sum of all such sections if there are multiple code sections.
    .long   0       # Ignored                                                   #     long sizeOfInitializedData;                           # The size of the initialized data section, in bytes, or the sum of all such sections if there are multiple initialized data sections.
    .long   0       # Ignored                                                   #     long sizeOfUninitializedData;                         # The size of the uninitialized data section, in bytes, or the sum of all such sections if there are multiple uninitialized data sections.
    .long   0       # To be filled by image_builder                             #     long addressOfEntryPoint;                             # A pointer to the entry point function, relative to the image base address. For executable files, this is the starting address. For device drivers, this is the address of the initialization function. The entry point function is optional for DLLs. When no entry point is present, this member is zero.
    .long   0       # Ignored                                                   #     long baseOfCode;                                      # A pointer to the beginning of the code section, relative to the image base.
    .quad   0       # Ignored                                                   #     long long imageBase;                                  # The preferred address of the first byte of the image when it is loaded in memory. This value is a multiple of 64K bytes. The default value for DLLs is 0x10000000. The default value for applications is 0x00400000, except on Windows CE where it is 0x00010000.
    .long   0x40    # 64                                                        #     long sectionAlignment;                                # The alignment of sections loaded in memory, in bytes. This value must be greater than or equal to the fileAlignment member. The default value is the page size for the system.
    .long   0x40    # 64                                                        #     long fileAlignment;                                   # The alignment of the raw data of sections in the image file, in bytes. The value should be a power of 2 between 512 and 64K (inclusive). The default is 512. If the sectionAlignment member is less than the system page size, this member must be the same as sectionAlignment.
    .word   0       # Ignored                                                   #     short majorOSVersion;                                 # The major version number of the required operating system.
    .word   0       # Ignored                                                   #     short minorOSVersion;                                 # The minor version number of the required operating system.
    .word   0       # Ignored                                                   #     short majorImageVersion;                              # The major version number of the image.
    .word   0       # Ignored                                                   #     short minorImageVersion;                              # The minor version number of the image.
    .word   0       # Ignored                                                   #     short majorSubsystemVersion;                          # The major version number of the subsystem.
    .word   0       # Ignored                                                   #     short minorSubsystemVersion;                          # The minor version number of the subsystem.
    .long   0       # Reserved                                                  #     long win32VersionValue;                               # This member is reserved and must be 0.
    .long   0       # To be filled by image_builder                             #     long sizeOfImage;                                     # The size of the image, in bytes, including all headers. Must be a multiple of sectionAlignment.
    .long   0x0200  # Say UEFI to skip 0x0200 bytes                             #     long sizeOfHeaders;                                   # Total size of all headers.
    .long   0       # Ignored                                                   #     long checksum;                                        # The image file checksum.
    .word   0x0A    # UEFI application                                          #     short subsystem;                                      # The subsystem that will be invoked to run the executable      # 0x0A == UEFI application
    .word   0       # Ignored                                                   #     short dllCharacteristics;                             # The DLL characteristics of the image.
    .quad   0       # Ignored                                                   #     long long sizeOfStackReserve;                         # The number of bytes to reserve for the stack. Only the memory specified by the sizeOfStackCommit member is committed at load time; the rest is made available one page at a time until this reserve size is reached.
    .quad   0       # Ignored                                                   #     long long sizeOfStackCommit;                          # The number of bytes to commit for the stack.
    .quad   0       # Ignored                                                   #     long long sizeOfHeapReserve;                          # The number of bytes to reserve for the local heap. Only the memory specified by the sizeOfHeapCommit member is committed at load time; the rest is made available one page at a time until this reserve size is reached.
    .quad   0       # Ignored                                                   #     long long sizeOfHeapCommit;                           # The number of bytes to commit for the local heap.
    .long   0       # Ignored                                                   #     long loaderFlags;                                     # This member is obsolete.
    .long   0x06    # 6 data directories                                        #     long numberOfRvaAndSizes;                             # The number of directory entries in the remainder of the optional header. Each entry describes a location and size.
                                                                                #     data_directory DataDirectory[numberOfRvaAndSizes];    # Provides RVAs and sizes which locate various data structures, which are used for setting up the execution environment of a module.
                                                                                # }
                                                                                #
                                                                                # struct data_directory
                                                                                # {
                                                                                #     long virtualAddress;  # Address of DataDirectory
                                                                                #     long size;            # Size of DataDirectory
                                                                                # }
                                                                                #
    .long   0       # Ignored                                                   # ExportTable virtualAddress
    .long   0       # Ignored                                                   # ExportTable size
                                                                                #
    .long   0       # Ignored                                                   # ImportTable virtualAddress
    .long   0       # Ignored                                                   # ImportTable size
                                                                                #
    .long   0       # Ignored                                                   # ResourceTable virtualAddress
    .long   0       # Ignored                                                   # ResourceTable size
                                                                                #
    .long   0       # Ignored                                                   # ExceptionTable virtualAddress
    .long   0       # Ignored                                                   # ExceptionTable size
                                                                                #
    .long   0       # Ignored                                                   # CertificationTable virtualAddress
    .long   0       # Ignored                                                   # CertificationTable size
                                                                                #
    .long   0       # Ignored                                                   # BaseRelocationTable virtualAddress
    .long   0       # Ignored                                                   # BaseRelocationTable size
                                                                                #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
section_table:                                                                  # Label for section table
                                                                                # struct IMAGE_SECTION_HEADER
                                                                                # {
    .ascii  ".reloc\0\0"    # UEFI application must be                          #     char  name[8];
                            # relocatable                                       #     union
                                                                                #     {
                                                                                #         long physicalAddress;
                                                                                #         long virtualSize;
    .long   0           # To be filled by image_builder                         #     } misc;
    .long   0           # To be filled by image_builder                         #     long  virtualAddress;
    .long   0           # To be filled by image_builder                         #     long  sizeOfRawData;
    .long   0           # To be filled by image_builder                         #     long  pointerToRawData;
    .long   0           # Ignored                                               #     long  pointerToRelocations;
    .long   0           # Ignored                                               #     long  pointerToLinenumbers;
    .word   0           # Ignored                                               #     short numberOfRelocations;
    .word   0           # Ignored                                               #     short numberOfLineNumbers;
    .long   0x42100040  #   IMAGE_SCN_MEM_READ                                  #     long  characteristics;
                        # | IMAGE_SCN_MEM_DISCARDABLE                           # }
                        # | IMAGE_SCN_ALIGN_1BYTES                              #
                        # | IMAGE_SCN_CNT_INITIALIZED_DATA                      #
                                                                                # struct IMAGE_SECTION_HEADER
                                                                                # {
    .ascii  ".config\0"                                                         #     char  name[8];
                                                                                #     union
                                                                                #     {
                                                                                #         long physicalAddress;
                                                                                #         long virtualSize;
    .long   0           # To be filled by image_builder                         #     } misc;
    .long   0           # To be filled by image_builder                         #     long  virtualAddress;
    .long   0           # To be filled by image_builder                         #     long  sizeOfRawData;
    .long   0           # To be filled by image_builder                         #     long  pointerToRawData;
    .long   0           # Ignored                                               #     long  pointerToRelocations;
    .long   0           # Ignored                                               #     long  pointerToLinenumbers;
    .word   0           # Ignored                                               #     short numberOfRelocations;
    .word   0           # Ignored                                               #     short numberOfLineNumbers;
    .long   0x60500020  #   IMAGE_SCN_MEM_READ                                  #     long  characteristics;
                        # | IMAGE_SCN_MEM_EXECUTE                               # }
                        # | IMAGE_SCN_ALIGN_16BYTES                             #
                        # | IMAGE_SCN_CNT_CODE                                  #
                                                                                # struct IMAGE_SECTION_HEADER
                                                                                # {
    .ascii  ".kernel\0"                                                         #     char  name[8];
                                                                                #     union
                                                                                #     {
                                                                                #         long physicalAddress;
                                                                                #         long virtualSize;
    .long   0           # To be filled by image_builder                         #     } misc;
    .long   0           # To be filled by image_builder                         #     long  virtualAddress;
    .long   0           # To be filled by image_builder                         #     long  sizeOfRawData;
    .long   0           # To be filled by image_builder                         #     long  pointerToRawData;
    .long   0           # Ignored                                               #     long  pointerToRelocations;
    .long   0           # Ignored                                               #     long  pointerToLinenumbers;
    .word   0           # Ignored                                               #     short numberOfRelocations;
    .word   0           # Ignored                                               #     short numberOfLineNumbers;
    .long   0x60100020  #   IMAGE_SCN_MEM_READ                                  #     long  characteristics;
                        # | IMAGE_SCN_MEM_EXECUTE                               # }
                        # | IMAGE_SCN_ALIGN_1BYTES                              #
                        # | IMAGE_SCN_CNT_CODE                                  #
                                                                                #
# ============================================================================= # =============================================================================
                                                                                #
.section ".boot_marker", "a"                                                    # boot_marker section (a - allocatable)
                                                                                #
.globl  _boot_magic_number                                                      # Make _boot_magic_number visible for linker
_boot_magic_number:                                                             # Label for magic number
    .word   0xAA55                                                              # Insert magic number 0xAA55 at the end of 0x0200 byte sector to make it bootable
