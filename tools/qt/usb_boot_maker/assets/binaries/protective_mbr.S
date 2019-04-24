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
    ljmp    $(BOOTSEG), $(start2)                                               # Normalize the start address
start2:                                                                         # Label used for normalization
                                                                                #
# ============================================================================= # =============================================================================
# We will print message and reboot PC                                           #
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
    movw    $(separator), %si                                                   # Store pointer of reboot message to SI
    call    print_string
    movw    $(header), %si                                                   # Store pointer of reboot message to SI
    call    print_string
    movw    $(separator), %si                                                   # Store pointer of reboot message to SI
    call    print_string
    movw    $(reboot_msg), %si                                                   # Store pointer of reboot message to SI
    call    print_string

    xorw    %ax, %ax                                                            # Set AX to 0 in order to let interrupt 0x16 to read key press
    int     $0x16                                                               # Wait until user press some keyboard button
    int     $0x19                                                               # Go to the bootstrap loader (It will try to reload from some bootable disk)
                                                                                #
    ljmp    $0xF000, $0xFFF0                                                    # Reboot your PC if something goes wrong

# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
print_string:                                                                   # Label for printing message
    lodsb                                                                       # Load one byte from SI to AL
    andb    %al, %al                                                            # IF AL == 0
    jz      1f                                                                  #   THEN jump to bs_die
    movb    $0x0E, %ah                                                          #   ELSE set AH to 0x0E (Printing on the screen)
    movw    $0x07, %bx                                                          #        set BX to 0x07 (BH=0 - first page, BL=7 - Light Gray)
    int     $0x10                                                               #        Call interrupt 0x10 for printing character from AL on the screen
    jmp     print_string                                                        #        Print next character
1:
    ret
                                                                                #
# ============================================================================= # =============================================================================
# Data used for printing                                                        #
# ============================================================================= # =============================================================================
                                                                                #
.section ".bootsector_data", "a"                                                # bootsector_data section (a - allocatable)
separator:                                                                      # Separator string
    .ascii  "****************************************\r\n"                      # Separator text...
    .byte   0                                                                   # Ends with 0
                                                                                #
header:                                                                         # Header string
    .ascii  "*** ERROR: LEGACY BOOT OF UEFI MEDIA ***\r\n"                      # Header text...
    .byte   0                                                                   # Ends with 0
                                                                                #
reboot_msg:                                                                     # Reboot message
    .ascii  "Please use UEFI bootloader.\r\n"                                   # A lot of...
    .ascii  "\n"                                                                # bytes for...
    .ascii  "Remove disk and press any key to reboot...\r\n"                    # reboot message...
    .byte   0                                                                   # Ends with 0
                                                                                #
# ============================================================================= # =============================================================================
                                                                                #
.section ".boot_marker", "a"                                                    # boot_marker section (a - allocatable)
                                                                                #
.globl  _boot_magic_number                                                      # Make _boot_magic_number visible for linker
_boot_magic_number:                                                             # Label for magic number
    .word   0xAA55                                                              # Insert magic number 0xAA55 at the end of 0x200 byte sector to make it bootable
