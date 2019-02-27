#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_FLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_FLAGS_H



//
// EFLAGS
//
#define X86_EFLAGS_CF       (1ULL << 0)     // Carry Flag
#define X86_EFLAGS_FIXED    (1ULL << 1)     // Bit 1 - always on
#define X86_EFLAGS_PF       (1ULL << 2)     // Parity Flag
#define X86_EFLAGS_AF       (1ULL << 4)     // Auxiliary carry Flag
#define X86_EFLAGS_ZF       (1ULL << 6)     // Zero Flag
#define X86_EFLAGS_SF       (1ULL << 7)     // Sign Flag
#define X86_EFLAGS_TF       (1ULL << 8)     // Trap Flag
#define X86_EFLAGS_IF       (1ULL << 9)     // Interrupt Flag
#define X86_EFLAGS_DF       (1ULL << 10)    // Direction Flag
#define X86_EFLAGS_OF       (1ULL << 11)    // Overflow Flag
#define X86_EFLAGS_IOPL     (3ULL << 12)    // I/O Privilege Level (2 bits)
#define X86_EFLAGS_NT       (1ULL << 14)    // Nested Task
#define X86_EFLAGS_RF       (1ULL << 16)    // Resume Flag
#define X86_EFLAGS_VM       (1ULL << 17)    // Virtual Mode
#define X86_EFLAGS_AC       (1ULL << 18)    // Alignment Check/Access Control
#define X86_EFLAGS_VIF      (1ULL << 19)    // Virtual Interrupt Flag
#define X86_EFLAGS_VIP      (1ULL << 20)    // Virtual Interrupt Pending
#define X86_EFLAGS_ID       (1ULL << 21)    // CPUID detection



//
// Basic CPU control in CR0
//
#define X86_CR0_PE  (1ULL << 0)     // Protection Enable
#define X86_CR0_MP  (1ULL << 1)     // Monitor Coprocessor
#define X86_CR0_EM  (1ULL << 2)     // Emulation
#define X86_CR0_TS  (1ULL << 3)     // Task Switched
#define X86_CR0_ET  (1ULL << 4)     // Extension Type
#define X86_CR0_NE  (1ULL << 5)     // Numeric Error
#define X86_CR0_WP  (1ULL << 16)    // Write Protect
#define X86_CR0_AM  (1ULL << 18)    // Alignment Mask
#define X86_CR0_NW  (1ULL << 29)    // Not Write-through
#define X86_CR0_CD  (1ULL << 30)    // Cache Disable
#define X86_CR0_PG  (1ULL << 31)    // Paging



//
// Intel CPU features in CR4
//
#define X86_CR4_VME         (1ULL << 0)     // enable vm86 extensions
#define X86_CR4_PVI         (1ULL << 1)     // virtual interrupts flag enable
#define X86_CR4_TSD         (1ULL << 2)     // disable time stamp at ipl 3
#define X86_CR4_DE          (1ULL << 3)     // enable debugging extensions
#define X86_CR4_PSE         (1ULL << 4)     // enable page size extensions
#define X86_CR4_PAE         (1ULL << 5)     // enable physical address extensions
#define X86_CR4_MCE         (1ULL << 6)     // Machine check enable
#define X86_CR4_PGE         (1ULL << 7)     // enable global pages
#define X86_CR4_PCE         (1ULL << 8)     // enable performance counters at ipl 3
#define X86_CR4_OSFXSR      (1ULL << 9)     // enable fast FPU save and restore
#define X86_CR4_OSXMMEXCPT  (1ULL << 10)    // enable unmasked SSE exceptions
#define X86_CR4_LA57        (1ULL << 12)    // enable 5 level page tables
#define X86_CR4_VMXE        (1ULL << 13)    // enable VMX virtualization
#define X86_CR4_SMXE        (1ULL << 14)    // enable safer mode (TXT)
#define X86_CR4_FSGSBASE    (1ULL << 16)    // enable RDWRFSGS support
#define X86_CR4_PCIDE       (1ULL << 17)    // enable PCID support
#define X86_CR4_OSXSAVE     (1ULL << 18)    // enable xsave and xrestore
#define X86_CR4_SMEP        (1ULL << 20)    // enable SMEP support
#define X86_CR4_SMAP        (1ULL << 21)    // enable SMAP support
#define X86_CR4_PKE         (1ULL << 22)    // enable Protection Keys support



//
// x86-64 Task Priority Register, CR8
//
#define X86_CR8_TPR 0x0F // task priority register



//
// FPU (Floating Point Unit) CWR Register
//
#define FPU_CWR_IM  (1ULL << 0)     // Invalid operation error mask
#define FPU_CWR_DM  (1ULL << 1)     // Denormalized operand error mask
#define FPU_CWR_ZM  (1ULL << 2)     // Divide by zero error mask
#define FPU_CWR_OM  (1ULL << 3)     // Overflow error mask
#define FPU_CWR_UM  (1ULL << 4)     // Underflow error mask
#define FPU_CWR_PM  (1ULL << 5)     // Precision error mask

#define FPU_CWR_ERROR_MASK \
    ( \
        FPU_CWR_IM \
        | FPU_CWR_DM \
        | FPU_CWR_ZM \
        | FPU_CWR_OM \
        | FPU_CWR_UM \
        | FPU_CWR_PM \
    )



//
// FPU (Floating Point Unit) SWR Register
//
#define FPU_SWR_IE  (1ULL << 0)     // Invalid operation error
#define FPU_SWR_DE  (1ULL << 1)     // Denormalized operand error
#define FPU_SWR_ZE  (1ULL << 2)     // Divide by zero error
#define FPU_SWR_OE  (1ULL << 3)     // Overflow error
#define FPU_SWR_UE  (1ULL << 4)     // Underflow error
#define FPU_SWR_PE  (1ULL << 5)     // Precision error



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_FLAGS_H
