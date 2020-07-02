#ifndef ASM_INSTRUCTIONS_H
#define ASM_INSTRUCTIONS_H



#include <ngos/status.h>
#include <ngos/types.h>



#define RDRAND_RETRY_LOOPS 10

#define I8254_PORT_CONTROL    0x43
#define I8254_PORT_COUNTER0   0x40
#define I8254_CMD_READBACK    0xC0
#define I8254_SELECT_COUNTER0 0x02
#define I8254_STATUS_NOTREADY 0x40



inline NgosStatus cpuIdle() // TEST: NO
{
    asm volatile("rep; nop");

    return NgosStatus::OK;
}

inline NgosStatus outb(u8 value, u16 port) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "outb   %0, %1"       // outb   %al, (%dx)  # Output byte in AL to I/O port in DX. %al == value, (%dx) == port
            :                 // Output parameters
            :                 // Input parameters
                "a" (value),  // 'a' - AL // Ignore CppSingleCharVerifier
                "dN" (port)   // 'd' - DX, 'N' - Constant in range 0 to 255
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline u8 inb(u16 port) // TEST: NO
{
    u8 value;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "inb    %1, %0"       // inb    (%dx), %al  # Input byte from I/O port in DX into AL. %al == value, (%dx) == port
            :                 // Output parameters
                "=a" (value)  // 'a' - AL, '=' - write only
            :                 // Input parameters
                "dN" (port)   // 'd' - DX, 'N' - Constant in range 0 to 255
    );
    // Ignore CppAlignmentVerifier [END]

    return value;
}

inline NgosStatus rdrand(u64 *value)
{
    bool ok;
    u8   retry = RDRAND_RETRY_LOOPS;



    while (retry > 0)
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rdrand     %0"     "\n\t"    // rdrand     %rax    # Generate random number to RAX. %rax == (*value)
            "setc       %1"               // setc       %dl     # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == ok
                :                         // Output parameters
                    "=r"  (*value),       // 'r' - any general register, '=' - write only
                    "=qm" (ok)            // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
        );
        // Ignore CppAlignmentVerifier [END]



        if (ok)
        {
            return NgosStatus::OK;
        }



        --retry;
    }



    return NgosStatus::FAILED;
}

inline u64 rdtsc()
{
    u32 eax;
    u32 edx;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "rdtsc"               // rdtsc      # Get how many CPU ticks took place since the processor was reset to EDX:EAX. %edx == edx. %eax == eax
            :                 // Output parameters
                "=a" (eax),   // 'a' - EAX, '=' - write only
                "=d" (edx)    // 'd' - EDX, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]

    return ((u64)edx << 32) | eax;
}

inline NgosStatus writeCr3(u64 value) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq   %0, %%cr3"    // movq   %rax, %cr3      # Put value to CR3. %rax == value
            :                 // Output parameters
            :                 // Input parameters
                "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline u64 readCr4() // TEST: NO
{
    u64 value;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq   %%cr4, %0"    // movq   %cr4, %rax      # Put CR4 to value. %rax == value
            :                 // Output parameters
                "=r" (value)  // 'r' - any general register, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]

    return value;
}

inline NgosStatus writeCr4(u64 value) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq   %0, %%cr4"    // movq   %rax, %cr4      # Put value to CR4. %rax == value
            :                 // Output parameters
            :                 // Input parameters
                "r" (value)   // 'r' - any general register // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline bool bt(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "bt     %2, %1"     "\n\t"    // bt     %rax, (%rbx)    # Tests bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc   %0"                   // setc   %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                         // Output parameters
                "=qm" (res)           // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                         // Input parameters
                "m" (*address),       // 'm' - use memory // Ignore CppSingleCharVerifier
                "r" (bit)             // 'r' - any general register // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline bool bts(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "bts    %2, %0"     "\n\t"    // bts    %rax, (%rbx)    # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc   %1"                   // setc   %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                         // Output parameters
                "+m" (*address),      // 'm' - use memory, '+' - read and write
                "=qm" (res)           // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                         // Input parameters
                "r" (bit)             // 'r' - any general register // Ignore CppSingleCharVerifier
            :                         // Clobber list
                "memory"              // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline bool btsSafe(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lock bts   %2, %0"     "\n\t"    // lock bts   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc       %1"                   // setc       %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                             // Output parameters
                "+m" (*address),          // 'm' - use memory, '+' - read and write
                "=qm" (res)               // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                             // Input parameters
                "r" (bit)                 // 'r' - any general register // Ignore CppSingleCharVerifier
            :                             // Clobber list
                "memory"                  // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline NgosStatus btsPure(u8 *address, u64 bit)
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "bts    %1, %0"           // bts    %rax, (%rbx)    # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "r" (bit)         // 'r' - any general register // Ignore CppSingleCharVerifier
            :                     // Clobber list
                "memory"          // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus btsPureSafe(u8 *address, u64 bit)
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lock bts   %1, %0"       // lock bts   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "r" (bit)         // 'r' - any general register // Ignore CppSingleCharVerifier
            :                     // Clobber list
                "memory"          // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline bool btr(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "btr    %2, %0"     "\n\t"    // btr    %rax, (%rbx)    # Resets bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc   %1"                   // setc   %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                         // Output parameters
                "+m" (*address),      // 'm' - use memory, '+' - read and write
                "=qm" (res)           // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                         // Input parameters
                "r" (bit)             // 'r' - any general register // Ignore CppSingleCharVerifier
            :                         // Clobber list
                "memory"              // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline bool btrSafe(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lock btr   %2, %0"     "\n\t"    // lock btr   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Resets bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc       %1"                   // setc       %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                             // Output parameters
                "+m" (*address),          // 'm' - use memory, '+' - read and write
                "=qm" (res)               // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                             // Input parameters
                "r" (bit)                 // 'r' - any general register // Ignore CppSingleCharVerifier
            :                             // Clobber list
                "memory"                  // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline NgosStatus btrPure(u8 *address, u64 bit)
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "btr    %1, %0"           // btr    %rax, (%rbx)    # Resets bit RAX starting from address RBX. %rax == bit. %rbx == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "r" (bit)         // 'r' - any general register // Ignore CppSingleCharVerifier
            :                     // Clobber list
                "memory"          // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus btrPureSafe(u8 *address, u64 bit)
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lock btr   %1, %0"       // lock btr   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Resets bit RAX starting from address RBX. %rax == bit. %rbx == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "r" (bit)         // 'r' - any general register // Ignore CppSingleCharVerifier
            :                     // Clobber list
                "memory"          // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline bool btc(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "btc    %2, %0"     "\n\t"    // btc    %rax, (%rbx)    # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc   %1"                   // setc   %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                         // Output parameters
                "+m" (*address),      // 'm' - use memory, '+' - read and write
                "=qm" (res)           // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                         // Input parameters
                "r" (bit)             // 'r' - any general register // Ignore CppSingleCharVerifier
            :                         // Clobber list
                "memory"              // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline bool btcSafe(u8 *address, u64 bit)
{
    bool res;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lock btc   %2, %0"     "\n\t"    // lock btc   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
        "setc       %1"                   // setc       %dl             # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
            :                             // Output parameters
                "+m" (*address),          // 'm' - use memory, '+' - read and write
                "=qm" (res)               // 'q' - Registers a, b, c or d, or 'm' - use memory, '=' - write only
            :                             // Input parameters
                "r" (bit)                 // 'r' - any general register // Ignore CppSingleCharVerifier
            :                             // Clobber list
                "memory"                  // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return res;
}

inline NgosStatus btcPure(u8 *address, u64 bit)
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "btc    %1, %0"           // btc    %rax, (%rbx)    # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "r" (bit)         // 'r' - any general register // Ignore CppSingleCharVerifier
            :                     // Clobber list
                "memory"          // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus btcPureSafe(u8 *address, u64 bit)
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "lock btc   %1, %0"       // lock btc   %rax, (%rbx)    # lock - CPU will lock system Bus until instruction finish # Inverts bit RAX starting from address RBX. %rax == bit. %rbx == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "r" (bit)         // 'r' - any general register // Ignore CppSingleCharVerifier
            :                     // Clobber list
                "memory"          // Inform gcc that memory will be changed
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline u64 rdmsr(u32 msr) // TEST: NO
{
    u32 eax;
    u32 edx;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "rdmsr"               // rdmsr      # Read MSR value specified by ECX to EDX:EAX. %edx == edx. %eax == eax
            :                 // Output parameters
                "=a" (eax),   // 'a' - EAX, '=' - write only
                "=d" (edx)    // 'd' - EDX, '=' - write only
            :                 // Input parameters
                "c" (msr)     // 'c' - ECX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return ((u64)edx << 32) | eax;
}

inline NgosStatus wrmsr(u32 msr, u64 value) // TEST: NO
{
    u32 eax = value & 0xFFFFFFFF;
    u32 edx = value >> 32;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "wrmsr"               // wrmsr      # Write MSR value specified by ECX from EDX:EAX. %edx == edx. %eax == eax
            :                 // Output parameters
            :                 // Input parameters
                "c" (msr),    // 'c' - ECX // Ignore CppSingleCharVerifier
                "a" (eax),    // 'a' - EAX // Ignore CppSingleCharVerifier
                "d" (edx)     // 'd' - EDX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus cli() // TEST: NO
{
    asm volatile("cli");

    return NgosStatus::OK;
}

inline NgosStatus sti() // TEST: NO
{
    asm volatile("sti");

    return NgosStatus::OK;
}

inline NgosStatus fninit() // TEST: NO
{
    asm volatile("fninit");

    return NgosStatus::OK;
}

inline NgosStatus xsetbv(u32 index, u64 value) // TEST: NO
{
    u32 eax = value;
    u32 edx = value >> 32;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "xsetbv"              // xsetbv     # Writes the contents of registers EDX:EAX into the 64-bit extended control register (XCR) specified in the ECX register
            :                 // Output parameters
            :                 // Input parameters
                "c" (index),  // 'c' - ECX // Ignore CppSingleCharVerifier
                "a" (eax),    // 'a' - EAX // Ignore CppSingleCharVerifier
                "d" (edx)     // 'd' - EDX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus fxsave(u8 *address) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "fxsave     %0"           // fxsave     0x0000(%rip)    # Saves the current state of the x87 FPU, MMX technology, XMM, and MXCSR registers to a 512-byte memory location. 0x0000(%rip) == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus xsave64(u8 *address, u64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    u32 eax = mask;
    u32 edx = mask >> 32;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "xsave64    %0"           // xsave64    0x0000(%rip)    # Saves Processor Extended States specified by EDX:EAX to address. 0x0000(%rip) == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "a" (eax),        // 'a' - EAX // Ignore CppSingleCharVerifier
                "d" (edx)         // 'd' - EDX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus xsaves64(u8 *address, u64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    u32 eax = mask;
    u32 edx = mask >> 32;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "xsaves64   %0"           // xsaves64   0x0000(%rip)    # Saves Processor Extended States specified by EDX:EAX to address with compaction, optimizing if possible. 0x0000(%rip) == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "a" (eax),        // 'a' - EAX // Ignore CppSingleCharVerifier
                "d" (edx)         // 'd' - EDX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus xrstor64(u8 *address, u64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    u32 eax = mask;
    u32 edx = mask >> 32;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "xrstor64   %0"           // xrstor64   0x0000(%rip)    # Restores Processor Extended States specified by EDX:EAX to address. 0x0000(%rip) == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "a" (eax),        // 'a' - EAX // Ignore CppSingleCharVerifier
                "d" (edx)         // 'd' - EDX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus xrstors64(u8 *address, u64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    u32 eax = mask;
    u32 edx = mask >> 32;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "xrstors64  %0"           // xrstors64  0x0000(%rip)    # Restores Processor Extended States specified by EDX:EAX to address. 0x0000(%rip) == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
            :                     // Input parameters
                "a" (eax),        // 'a' - EAX // Ignore CppSingleCharVerifier
                "d" (edx)         // 'd' - EDX // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline NgosStatus invlpg(u8 *address) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "invlpg     %0"           // invlpg     0x0000(%rip)    # Invalidate TLB entries for page containing specified address. 0x0000(%rip) == address
            :                     // Output parameters
            :                     // Input parameters
                "m" (*address)    // 'm' - use memory // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}



#endif // ASM_INSTRUCTIONS_H
