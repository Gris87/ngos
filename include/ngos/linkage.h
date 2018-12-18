#ifndef NGOS_LINKAGE_H
#define NGOS_LINKAGE_H



// Ignore CppAlignmentVerifier [BEGIN]
#define __ASM_NEWLINE ;

// TEST: NO
#define ENTRY(name) \
    .globl  name    __ASM_NEWLINE \
    name:

// TEST: NO
#define END_ENTRY(name) \
    .size   name, .-name

// TEST: NO
#define GLOBAL_FUNCTION(name) \
    .globl  name            __ASM_NEWLINE \
    .type   name, @function __ASM_NEWLINE \
    name:

// TEST: NO
#define END_FUNCTION(name) \
    END_ENTRY(name)
// Ignore CppAlignmentVerifier [END]



#ifdef __cplusplus
#define CPP_EXTERN_C extern "C" // Ignore CppExternDeclaredVerifier
#else
#define CPP_EXTERN_C
#endif



#define CPP_NO_OPTIMIZATION __attribute__((optimize("O0")))



#define AVOID_UNUSED(x) (void)x;



#endif // NGOS_LINKAGE_H
