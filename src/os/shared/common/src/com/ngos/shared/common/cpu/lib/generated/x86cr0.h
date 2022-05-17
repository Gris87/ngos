// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_X86CR0_H
#define COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_X86CR0_H



#define X86_CR0_PROTECTED_MODE_ENABLE (1ULL << 0)  // If 1, system is in protected mode, else system is in real mode
#define X86_CR0_MONITOR_CO_PROCESSOR  (1ULL << 1)  // Controls interaction of WAIT/FWAIT instructions with TS flag in CR0
#define X86_CR0_EMULATION             (1ULL << 2)  // If set, no x87 floating-point unit present, if clear, x87 FPU present
#define X86_CR0_TASK_SWITCHED         (1ULL << 3)  // Allows saving x87 task context upon a task switch only after x87 instruction used
#define X86_CR0_EXTENSION_TYPE        (1ULL << 4)  // On the 386, it allowed to specify whether the external math coprocessor was an 80287 or 80387
#define X86_CR0_NUMERIC_ERROR         (1ULL << 5)  // Enable internal x87 floating point error reporting when set, else enables PC style x87 error detection
#define X86_CR0_WRITE_PROTECT         (1ULL << 16) // When set, the CPU can't write to read-only pages when privilege level is 0
#define X86_CR0_ALIGNMENT_MASK        (1ULL << 18) // Alignment check enabled if AM set, AC flag (in EFLAGS register) set, and privilege level is 3
#define X86_CR0_NOT_WRITE_THROUGH     (1ULL << 29) // Globally enables/disable write-through caching
#define X86_CR0_CACHE_DISABLE         (1ULL << 30) // Globally enables/disable the memory cache
#define X86_CR0_PAGING                (1ULL << 31) // If 1, enable paging and use the § CR3 register, else disable paging.



#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_X86CR0_H
