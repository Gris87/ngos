#include <common/src/com/ngos/shared/common/ngos/linkage.h>
                                                                                #
                                                                                #
                                                                                #
.code64                                                                         # Generate code in 64 bits mode
.section ".idt", "ax"                                                           # idt section (a - allocatable, x - executable)
                                                                                #
# ============================================================================= # =============================================================================
# earlyIdtDebugTrap declaration:                                                #
#     void earlyIdtDebugTrap();                                                 #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(earlyIdtDebugTrap)                                              # earlyIdtDebugTrap function
    retq                                                                        # Return from the function
END_FUNCTION(earlyIdtDebugTrap)                                                 # End of earlyIdtDebugTrap function
                                                                                #
# ============================================================================= # =============================================================================
# earlyIdtBreakpointTrap declaration:                                           #
#     void earlyIdtBreakpointTrap();                                            #
# ============================================================================= # =============================================================================
                                                                                #
GLOBAL_FUNCTION(earlyIdtBreakpointTrap)                                         # earlyIdtBreakpointTrap function
    retq                                                                        # Return from the function
END_FUNCTION(earlyIdtBreakpointTrap)                                            # End of earlyIdtBreakpointTrap function
