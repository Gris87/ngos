// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_X86CR4_H
#define COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_X86CR4_H



#define X86_CR4_VIRTUAL_8086_MODE_EXTENSIONS                     (1ULL << 0)  // If set, enables support for the virtual interrupt flag (VIF) in virtual-8086 mode.
#define X86_CR4_PROTECTED_MODE_VIRTUAL_INTERRUPTS                (1ULL << 1)  // If set, enables support for the virtual interrupt flag (VIF) in protected mode.
#define X86_CR4_TIME_STAMP_DISABLE                               (1ULL << 2)  // If set, RDTSC instruction can only be executed when in ring 0, otherwise RDTSC can be used at any privilege level.
#define X86_CR4_DEBUGGING_EXTENSIONS                             (1ULL << 3)  // If set, enables debug register based breaks on I/O space access.
#define X86_CR4_PAGE_SIZE_EXTENSION                              (1ULL << 4)  // If unset, page size is 4 KiB, else page size is increased to 4 MiB. If PAE is enabled or the processor is in x86-64 long mode this bit is ignored.
#define X86_CR4_PHYSICAL_ADDRESS_EXTENSION                       (1ULL << 5)  // If set, changes page table layout to translate 32-bit virtual addresses into extended 36-bit physical addresses.
#define X86_CR4_MACHINE_CHECK_EXCEPTION                          (1ULL << 6)  // If set, enables machine check interrupts to occur.
#define X86_CR4_PAGE_GLOBAL_ENABLED                              (1ULL << 7)  // If set, address translations (PDE or PTE records) may be shared between address spaces.
#define X86_CR4_PERFORMANCE_MONITORING_COUNTER_ENABLE            (1ULL << 8)  // If set, RDPMC can be executed at any privilege level, else RDPMC can only be used in ring 0.
#define X86_CR4_SUPPORT_FXSAVE                                   (1ULL << 9)  // If set, enables Streaming SIMD Extensions (SSE) instructions and fast FPU save & restore.
#define X86_CR4_SUPPORT_UNMASKED_SSE_EXCEPTIONS                  (1ULL << 10) // If set, enables unmasked SSE exceptions.
#define X86_CR4_USER_MODE_INSTRUCTION_PREVENTION                 (1ULL << 11) // If set, the SGDT, SIDT, SLDT, SMSW and STR instructions cannot be executed if CPL > 0.
#define X86_CR4_57_BIT_LINEAR_ADDRESSES                          (1ULL << 12) // If set, enables 5-Level Paging.
#define X86_CR4_VIRTUAL_MACHINE_EXTENSIONS_ENABLE                (1ULL << 13) // see Intel VT-x x86 virtualization.
#define X86_CR4_SAFER_MODE_EXTENSIONS_ENABLE                     (1ULL << 14) // see Trusted Execution Technology (TXT)
#define X86_CR4_FSGSBASE                                         (1ULL << 16) // Enables the instructions RDFSBASE, RDGSBASE, WRFSBASE, and WRGSBASE.
#define X86_CR4_PROCESS_CONTEXT_ID_ENABLE                        (1ULL << 17) // If set, enables process-context identifiers (PCIDs).
#define X86_CR4_SUPPORT_XSAVE                                    (1ULL << 18) // XSAVE and Processor Extended States Enable
#define X86_CR4_SUPERVISOR_MODE_EXECUTION_PROTECTION_ENABLE      (1ULL << 20) // If set, execution of code in a higher ring generates a fault.
#define X86_CR4_SUPERVISOR_MODE_ACCESS_PROTECTION_ENABLE         (1ULL << 21) // If set, access of data in a higher ring generates a fault.
#define X86_CR4_PROTECTION_KEY_ENABLE                            (1ULL << 22) // See Intel 64 and IA-32 Architectures Software Developer’s Manual.
#define X86_CR4_CONTROL_FLOW_ENFORCEMENT_TECHNOLOGY              (1ULL << 23) // If set, enables control-flow enforcement technology.
#define X86_CR4_ENABLE_PROTECTION_KEYS_FOR_SUPERVISOR_MODE_PAGES (1ULL << 24) // If set, each supervisor-mode linear address is associated with a protection key when 4-level or 5-level paging is in use.



#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_X86CR4_H
