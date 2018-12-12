#ifndef IDT_MACROS_H
#define IDT_MACROS_H



#define EARLY_IDT_HANDLER_SIZE 9



// ---------------------------------------------------------------------------------------------------------
// | Vector | Mnemonic | Description          | Type  | Error Code | Source                                |
// ---------------------------------------------------------------------------------------------------------
// | 0      | #DE      | Divide Error         | Fault | NO         | DIV and IDIV                          |
// |--------------------------------------------------------------------------------------------------------
// | 1      | #DB      | Debug                | F/T   | NO         | Debug interrupt                       |
// |--------------------------------------------------------------------------------------------------------
// | 2      | ---      | NMI                  | INT   | NO         | external NMI                          |
// |--------------------------------------------------------------------------------------------------------
// | 3      | #BP      | Breakpoint           | Trap  | NO         | INT 3                                 |
// |--------------------------------------------------------------------------------------------------------
// | 4      | #OF      | Overflow             | Trap  | NO         | INTO  instruction                     |
// |--------------------------------------------------------------------------------------------------------
// | 5      | #BR      | Bound Range Exceeded | Fault | NO         | BOUND instruction                     |
// |--------------------------------------------------------------------------------------------------------
// | 6      | #UD      | Invalid Opcode       | Fault | NO         | UD2 instruction                       |
// |--------------------------------------------------------------------------------------------------------
// | 7      | #NM      | Device Not Available | Fault | NO         | Floating point or [F]WAIT             |
// |--------------------------------------------------------------------------------------------------------
// | 8      | #DF      | Double Fault         | Abort | YES        | An instruction which can generate NMI |
// |--------------------------------------------------------------------------------------------------------
// | 9      | ---      | Reserved             | Fault | NO         |                                       |
// |--------------------------------------------------------------------------------------------------------
// | 10     | #TS      | Invalid TSS          | Fault | YES        | Task switch or TSS access             |
// |--------------------------------------------------------------------------------------------------------
// | 11     | #NP      | Segment Not Present  | Fault | YES        | Accessing segment register            |
// |--------------------------------------------------------------------------------------------------------
// | 12     | #SS      | Stack-Segment Fault  | Fault | YES        | Stack operations                      |
// |--------------------------------------------------------------------------------------------------------
// | 13     | #GP      | General Protection   | Fault | YES        | Memory reference                      |
// |--------------------------------------------------------------------------------------------------------
// | 14     | #PF      | Page fault           | Fault | YES        | Memory reference                      |
// |--------------------------------------------------------------------------------------------------------
// | 15     | ---      | Reserved             |       | NO         |                                       |
// |--------------------------------------------------------------------------------------------------------
// | 16     | #MF      | x87 FPU fp error     | Fault | NO         | Floating point or [F]Wait             |
// |--------------------------------------------------------------------------------------------------------
// | 17     | #AC      | Alignment Check      | Fault | YES        | Data reference                        |
// |--------------------------------------------------------------------------------------------------------
// | 18     | #MC      | Machine Check        | Abort | NO         |                                       |
// |--------------------------------------------------------------------------------------------------------
// | 19     | #XM      | SIMD fp exception    | Fault | NO         | SSE[2,3] instructions                 |
// |--------------------------------------------------------------------------------------------------------
// | 20     | #VE      | Virtualization exc.  | Fault | NO         | EPT violations                        |
// |--------------------------------------------------------------------------------------------------------
// | 21-31  | ---      | Reserved             | INT   | NO         | External interrupts                   |
// ---------------------------------------------------------------------------------------------------------

#define IDT_EXCEPTIONS_COUNT                    32

#define IDT_EXCEPTION_DIVIDE_ERROR              0
#define IDT_EXCEPTION_DEBUG                     1
#define IDT_EXCEPTION_NMI                       2
#define IDT_EXCEPTION_BREAKPOINT                3
#define IDT_EXCEPTION_OVERFLOW                  4
#define IDT_EXCEPTION_BOUND_RANGE_EXCEEDED      5
#define IDT_EXCEPTION_INVALID_OPCODE            6
#define IDT_EXCEPTION_DEVICE_NOT_AVAILABLE      7
#define IDT_EXCEPTION_DOUBLE_FAULT              8
// #define IDT_EXCEPTION_RESERVED               9
#define IDT_EXCEPTION_INVALID_TSS               10
#define IDT_EXCEPTION_SEGMENT_NOT_PRESENT       11
#define IDT_EXCEPTION_STACK_SEGMENT_FAULT       12
#define IDT_EXCEPTION_GENERAL_PROTECTION        13
#define IDT_EXCEPTION_PAGE_FAULT                14
// #define IDT_EXCEPTION_RESERVED               15
#define IDT_EXCEPTION_X87_FPU_FP_ERROR          16
#define IDT_EXCEPTION_ALIGNMENT_CHECK           17
#define IDT_EXCEPTION_MACHINE_CHECK             18
#define IDT_EXCEPTION_SIMD_FP_EXCEPTION         19
#define IDT_EXCEPTION_VIRTUALIZATION_EXC        20

#define IDT_EXCEPTION_DIVIDE_ERROR_MASK         (1ULL << IDT_EXCEPTION_DIVIDE_ERROR)
#define IDT_EXCEPTION_DEBUG_MASK                (1ULL << IDT_EXCEPTION_DEBUG)
#define IDT_EXCEPTION_NMI_MASK                  (1ULL << IDT_EXCEPTION_NMI)
#define IDT_EXCEPTION_BREAKPOINT_MASK           (1ULL << IDT_EXCEPTION_BREAKPOINT)
#define IDT_EXCEPTION_OVERFLOW_MASK             (1ULL << IDT_EXCEPTION_OVERFLOW)
#define IDT_EXCEPTION_BOUND_RANGE_EXCEEDED_MASK (1ULL << IDT_EXCEPTION_BOUND_RANGE_EXCEEDED)
#define IDT_EXCEPTION_INVALID_OPCODE_MASK       (1ULL << IDT_EXCEPTION_INVALID_OPCODE)
#define IDT_EXCEPTION_DEVICE_NOT_AVAILABLE_MASK (1ULL << IDT_EXCEPTION_DEVICE_NOT_AVAILABLE)
#define IDT_EXCEPTION_DOUBLE_FAULT_MASK         (1ULL << IDT_EXCEPTION_DOUBLE_FAULT)
// #define IDT_EXCEPTION_RESERVED_MASK          (1ULL << IDT_EXCEPTION_RESERVED)
#define IDT_EXCEPTION_INVALID_TSS_MASK          (1ULL << IDT_EXCEPTION_INVALID_TSS)
#define IDT_EXCEPTION_SEGMENT_NOT_PRESENT_MASK  (1ULL << IDT_EXCEPTION_SEGMENT_NOT_PRESENT)
#define IDT_EXCEPTION_STACK_SEGMENT_FAULT_MASK  (1ULL << IDT_EXCEPTION_STACK_SEGMENT_FAULT)
#define IDT_EXCEPTION_GENERAL_PROTECTION_MASK   (1ULL << IDT_EXCEPTION_GENERAL_PROTECTION)
#define IDT_EXCEPTION_PAGE_FAULT_MASK           (1ULL << IDT_EXCEPTION_PAGE_FAULT)
// #define IDT_EXCEPTION_RESERVED_MASK          (1ULL << IDT_EXCEPTION_RESERVED)
#define IDT_EXCEPTION_X87_FPU_FP_ERROR_MASK     (1ULL << IDT_EXCEPTION_X87_FPU_FP_ERROR)
#define IDT_EXCEPTION_ALIGNMENT_CHECK_MASK      (1ULL << IDT_EXCEPTION_ALIGNMENT_CHECK)
#define IDT_EXCEPTION_MACHINE_CHECK_MASK        (1ULL << IDT_EXCEPTION_MACHINE_CHECK)
#define IDT_EXCEPTION_SIMD_FP_EXCEPTION_MASK    (1ULL << IDT_EXCEPTION_SIMD_FP_EXCEPTION)
#define IDT_EXCEPTION_VIRTUALIZATION_EXC_MASK   (1ULL << IDT_EXCEPTION_VIRTUALIZATION_EXC)



// Bitmask of exception vectors which push an error code on the stack
#define IDT_EXCEPTIONS_WITH_ERRCODES_MASK \
    ( \
        IDT_EXCEPTION_DOUBLE_FAULT_MASK \
        | IDT_EXCEPTION_INVALID_TSS_MASK \
        | IDT_EXCEPTION_SEGMENT_NOT_PRESENT_MASK \
        | IDT_EXCEPTION_STACK_SEGMENT_FAULT_MASK \
        | IDT_EXCEPTION_GENERAL_PROTECTION_MASK \
        | IDT_EXCEPTION_PAGE_FAULT_MASK \
        | IDT_EXCEPTION_ALIGNMENT_CHECK_MASK \
    )



#endif // IDT_MACROS_H
