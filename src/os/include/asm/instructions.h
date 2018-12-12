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
        "outb    %0, %1"        // outb    %al, (%dx)   # %al == value, (%dx) == port
            :                   // Output parameters
            :                   // Input parameters
                "a" (value),    // "a" == AL // Ignore CppSingleCharVerifier
                "dN" (port)     // "d" == DX, "N" - Constant in range 0 to 255
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline u8 inb(u16 port) // TEST: NO
{
    u8 value;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "inb     %1, %0"        // inb     (%dx), %al   # %al == value, (%dx) == port
            :                   // Output parameters
                "=a" (value)    // "a" == AL, "=" - write only
            :                   // Input parameters
                "dN" (port)     // "d" == DX, "N" - Constant in range 0 to 255
    );
    // Ignore CppAlignmentVerifier [END]

    return value;
}

inline NgosStatus rdrand(u64 *value) // TEST: NO
{
    bool ok;
    u8   retry = RDRAND_RETRY_LOOPS;



    while (retry) // retry > 0
    {
        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "rdrand  %0"    "\n\t"  // rdrand  %rax     # Generate random number to RAX. %rax == (*value)
            "setc    %1"            // setb    %dl      # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == ok
                :                   // Output parameters
                    "=r"  (*value), // "r" == any general register, "=" - write only
                    "=qm" (ok)      // "q" == Registers a, b, c or d, or "m" == use memory, "=" - write only
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

inline u64 rdtsc() // TEST: NO
{
    u32 eax;
    u32 edx;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "rdtsc"             // rdtsc        # Get how many CPU ticks took place since the processor was reset to EDX:EAX. %edx == edx. %eax == eax
            :               // Output parameters
                "=a" (eax), // "a" == EAX, "=" - write only
                "=d" (edx)  // "d" == EDX, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]

    return ((u64)edx << 32) | eax;
}

inline u16 randomI8254() // TEST: NO
{
    u16 status;
    u16 timer;



    do
    {
        outb(I8254_PORT_CONTROL, I8254_CMD_READBACK | I8254_SELECT_COUNTER0);

        status =  inb(I8254_PORT_COUNTER0);
        timer  =  inb(I8254_PORT_COUNTER0);
        timer  |= inb(I8254_PORT_COUNTER0) << 8;

        if (!(status & I8254_STATUS_NOTREADY))
        {
            break;
        }
    } while(true);



    return timer;
}

inline NgosStatus writeCr3(u64 value) // TEST: NO
{
    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq    %0, %%cr3"     // movq    %rax, %cr3   # %rax == value
            :                   // Output parameters
            :                   // Input parameters
                "r" (value)     // "r" == any general register // Ignore CppSingleCharVerifier
    );
    // Ignore CppAlignmentVerifier [END]

    return NgosStatus::OK;
}

inline u64 readCr4() // TEST: NO
{
    u64 value;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "movq    %%cr4, %0"     // movq    %cr4, %rax   # %rax == value
            :                   // Output parameters
                "=r" (value)    // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]

    return value;
}

inline u64 rdmsr(u32 msr) // TEST: NO
{
    u32 eax;
    u32 edx;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "rdmsr"             // rdmsr        # Read MSR value specified by ECX to EDX:EAX. %edx == edx. %eax == eax
            :               // Output parameters
                "=a" (eax), // "a" == EAX, "=" - write only
                "=d" (edx)  // "d" == EDX, "=" - write only
            :               // Input parameters
                "c" (msr)   // "c" == ECX // Ignore CppSingleCharVerifier
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
        "wrmsr"             // wrmsr        # Write MSR value specified by ECX from EDX:EAX. %edx == edx. %eax == eax
            :               // Output parameters
            :               // Input parameters
                "c" (msr),  // "c" == ECX // Ignore CppSingleCharVerifier
                "a" (eax),  // "a" == EAX // Ignore CppSingleCharVerifier
                "d" (edx)   // "d" == EDX // Ignore CppSingleCharVerifier
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



#endif // ASM_INSTRUCTIONS_H
