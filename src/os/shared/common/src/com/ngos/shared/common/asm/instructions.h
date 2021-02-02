#ifndef COM_NGOS_SHARED_COMMON_ASM_INSTRUCTIONS_H
#define COM_NGOS_SHARED_COMMON_ASM_INSTRUCTIONS_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



#define RDRAND_RETRY_LOOPS 10

#define bad_int8254_PORT_CONTROL    0x43
#define bad_int8254_PORT_COUNTER0   0x40
#define bad_int8254_CMD_READBACK    0xC0
#define bad_int8254_SELECT_COUNTER0 0x02
#define bad_int8254_STATUS_NOTREADY 0x40



inline NgosStatus cpuIdle() // TEST: NO
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    asm volatile("rep; nop");



    return NgosStatus::OK;
}

inline NgosStatus outb(bad_uint8 value, bad_uint16 port) // TEST: NO
{
    COMMON_LT((" | value = 0x%02X, port = 0x%04X", value, port));



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

inline bad_uint8 inb(bad_uint16 port) // TEST: NO
{
    COMMON_LT((" | port = 0x%04X", port));



    bad_uint8 value;

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

inline NgosStatus rdrand(bad_uint64 *value)
{
    COMMON_LT((" | value = 0x%p", value));



    bool ok;
    bad_uint8   retry = RDRAND_RETRY_LOOPS;



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

inline bad_uint64 rdtsc()
{
    COMMON_LT((""));



    bad_uint32 eax;
    bad_uint32 edx;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "rdtsc"               // rdtsc      # Get how many CPU ticks took place since the processor was reset to EDX:EAX. %edx == edx. %eax == eax
            :                 // Output parameters
                "=a" (eax),   // 'a' - EAX, '=' - write only
                "=d" (edx)    // 'd' - EDX, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]



    return ((bad_uint64)edx << 32) | eax;
}

inline NgosStatus writeCr3(bad_uint64 value) // TEST: NO
{
    COMMON_LT((" | value = 0x%016llX", value));



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

inline bad_uint64 readCr4() // TEST: NO
{
    COMMON_LT((""));



    bad_uint64 value;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq   %%cr4, %0"    // movq   %cr4, %rax      # Put CR4 to value. %rax == value
            :                 // Output parameters
                "=r" (value)  // 'r' - any general register, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]



    return value;
}

inline NgosStatus writeCr4(bad_uint64 value) // TEST: NO
{
    COMMON_LT((" | value = 0x%016llX", value));



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

inline bool bt(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline bool bts(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline bool btsSafe(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline NgosStatus btsPure(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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

inline NgosStatus btsPureSafe(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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

inline bool btr(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline bool btrSafe(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline NgosStatus btrPure(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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

inline NgosStatus btrPureSafe(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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

inline bool btc(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline bool btcSafe(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", false);



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

inline NgosStatus btcPure(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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

inline NgosStatus btcPureSafe(bad_uint8 *address, bad_uint64 bit)
{
    COMMON_LT((" | address = 0x%p, bit = 0x%016llX", address, bit));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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

inline bad_uint64 rdmsr(bad_uint32 msr) // TEST: NO
{
    COMMON_LT((" | msr = 0x%08X", msr));



    bad_uint32 eax;
    bad_uint32 edx;

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



    return ((bad_uint64)edx << 32) | eax;
}

inline NgosStatus wrmsr(bad_uint32 msr, bad_uint64 value) // TEST: NO
{
    COMMON_LT((" | msr = 0x%08X, value = 0x%016llX", msr, value));



    bad_uint32 eax = value & 0xFFFFFFFF;
    bad_uint32 edx = value >> 32;

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
    COMMON_LT((""));



    asm volatile("cli");



    return NgosStatus::OK;
}

inline NgosStatus sti() // TEST: NO
{
    COMMON_LT((""));



    asm volatile("sti");



    return NgosStatus::OK;
}

inline NgosStatus fninit() // TEST: NO
{
    COMMON_LT((""));



    asm volatile("fninit");



    return NgosStatus::OK;
}

inline NgosStatus xsetbv(bad_uint32 index, bad_uint64 value) // TEST: NO
{
    COMMON_LT((" | index = 0x%08X, value = 0x%016llX", index, value));



    bad_uint32 eax = value;
    bad_uint32 edx = value >> 32;

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

inline NgosStatus fxsave(bad_uint8 *address) // TEST: NO
{
    COMMON_LT((" | address = 0x%p", address));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "fxsave     %0"           // fxsave     0x0000(%rip)    # Saves the current state of the x87 FPU, MMX technology, XMM, and MXCSR registers to a 512-byte memory location. 0x0000(%rip) == address
            :                     // Output parameters
                "+m" (*address)   // 'm' - use memory, '+' - read and write
    );
    // Ignore CppAlignmentVerifier [END]



    return NgosStatus::OK;
}

inline NgosStatus xsave64(bad_uint8 *address, bad_uint64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    COMMON_LT((" | address = 0x%p, mask = 0x%016llX", address, mask));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(mask    != 0,       "mask is zero",    NgosStatus::ASSERTION);



    bad_uint32 eax = mask;
    bad_uint32 edx = mask >> 32;

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

inline NgosStatus xsaves64(bad_uint8 *address, bad_uint64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    COMMON_LT((" | address = 0x%p, mask = 0x%016llX", address, mask));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(mask    != 0,       "mask is zero",    NgosStatus::ASSERTION);



    bad_uint32 eax = mask;
    bad_uint32 edx = mask >> 32;

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

inline NgosStatus xrstor64(bad_uint8 *address, bad_uint64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    COMMON_LT((" | address = 0x%p, mask = 0x%016llX", address, mask));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(mask    != 0,       "mask is zero",    NgosStatus::ASSERTION);



    bad_uint32 eax = mask;
    bad_uint32 edx = mask >> 32;

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

inline NgosStatus xrstors64(bad_uint8 *address, bad_uint64 mask = 0xFFFFFFFFFFFFFFFF) // TEST: NO
{
    COMMON_LT((" | address = 0x%p, mask = 0x%016llX", address, mask));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(mask    != 0,       "mask is zero",    NgosStatus::ASSERTION);



    bad_uint32 eax = mask;
    bad_uint32 edx = mask >> 32;

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

inline NgosStatus invlpg(bad_uint8 *address) // TEST: NO
{
    COMMON_LT((" | address = 0x%p", address));

    COMMON_ASSERT(address != nullptr, "address is null", NgosStatus::ASSERTION);



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



#endif // COM_NGOS_SHARED_COMMON_ASM_INSTRUCTIONS_H
