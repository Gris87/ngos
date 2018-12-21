#ifndef ASM_BITUTILS_H
#define ASM_BITUTILS_H



#include <ngos/linkage.h>
#include <ngos/status.h>
#include <ngos/types.h>



#define CONST_BIT_ADDRESS(address, bit) (u8 *)((u64)(address) + ((bit) >> 3)) // ">> 3" == "/ 8"
#define CONST_BIT_IN_U8(bit)            (1 << ((bit) & 7))



class BitUtils
{
public:
    static inline bool test(u8 *address, u64 bit) // TEST: NO
    {
        bool res;

        // Ignore CppAlignmentVerifier [BEGIN]
        asm volatile(
            "bt      %2, %0"    "\n\t"  // bt      %rax, (%rbx) # Tests bit RAX starting from address RBX. %rax == bit. %rbx == address
            "setc    %1"                // setc    %dl          # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
                :                       // Output parameters
                    "+m" (*address),    // "m" == use memory, "+" - read and write
                    "=qm" (res)         // "q" == Registers a, b, c or d, or "m" == use memory, "=" - write only
                :                       // Input parameters
                    "r" (bit)           // "r" == any general register // Ignore CppSingleCharVerifier
        );
        // Ignore CppAlignmentVerifier [END]

        return res;
    }

    inline bool set(u8 *address, u64 bit) // TEST: NO
    {
        bool res;

        if (IS_CONSTANT(bit))
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "orb     %2, %0"    "\n\t"  // orb     %rax, (%rbx) # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                "setc    %1"                // setc    %dl          # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
                    :                       // Output parameters
                        "+m" (*CONST_BIT_ADDRESS(address, bit)),    // "m" == use memory, "+" - read and write
                        "=qm" (res)         // "q" == Registers a, b, c or d, or "m" == use memory, "=" - write only
                    :                       // Input parameters
                        "i" (CONST_BIT_IN_U8(bit))           // "r" == any general register // Ignore CppSingleCharVerifier
                    :                       // Clobber list
                        "memory"            // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }
        else
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            asm volatile(
                "bts     %2, %0"    "\n\t"  // bts     %rax, (%rbx) # Sets bit RAX starting from address RBX. %rax == bit. %rbx == address
                "setc    %1"                // setc    %dl          # Sets the byte in the operand to 1 if the Carry Flag is set. %dl == res
                    :                       // Output parameters
                        "+m" (*address),    // "m" == use memory, "+" - read and write
                        "=qm" (res)         // "q" == Registers a, b, c or d, or "m" == use memory, "=" - write only
                    :                       // Input parameters
                        "r" (bit)           // "r" == any general register // Ignore CppSingleCharVerifier
                    :                       // Clobber list
                        "memory"            // Inform gcc that memory will be changed
            );
            // Ignore CppAlignmentVerifier [END]
        }

        return res;
    }
};



#endif // ASM_BITUTILS_H
