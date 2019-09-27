.code64                                                                         # Generate code in 64 bits mode
.section ".partitionwizard_code", "ax"                                                  # partitionwizard_code section (a - allocatable, x - executable)
                                                                                #
.globl  _start                                                                  # Make _start visible for linker
_start:                                                                         # Global pointer to the entry point in order to make linker silent
                                                                                #
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
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
# Failure                                                                       #
# ----------------------------------------------------------------------------- # -----------------------------------------------------------------------------
                                                                                #
fail:                                                                           # Label for failure
    hlt                                                                         # Wait for interrupt
    jmp    fail                                                                 # Loop in fail forever
