#ifndef STDINC_STDARG_H
#define STDINC_STDARG_H



#define va_start(args, format)  __builtin_va_start(args, format)    // TEST: NO
#define va_end(args)            __builtin_va_end(args)              // TEST: NO
#define va_arg(args, type)      __builtin_va_arg(args, type)        // TEST: NO
#define va_copy(dest, src)      __builtin_va_copy(dest, src)        // TEST: NO



typedef __builtin_va_list va_list;



#endif // STDINC_STDARG_H
