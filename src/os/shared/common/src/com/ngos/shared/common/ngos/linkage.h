#ifndef COM_NGOS_SHARED_COMMON_NGOS_LINKAGE_H
#define COM_NGOS_SHARED_COMMON_NGOS_LINKAGE_H



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



#define CPP_NO_OPTIMIZATION  __attribute__((optimize("O0")))
#define CPP_MAX_OPTIMIZATION __attribute__((optimize("O3")))



#define AVOID_UNUSED(x) (void)x;



#define IS_CONSTANT(x) __builtin_constant_p(x)



#define ARRAY_COUNT(a) (sizeof(a) / sizeof(a[0]))



#endif // COM_NGOS_SHARED_COMMON_NGOS_LINKAGE_H
