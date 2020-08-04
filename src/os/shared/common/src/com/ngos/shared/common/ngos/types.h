#ifndef COM_NGOS_SHARED_COMMON_NGOS_TYPES_H
#define COM_NGOS_SHARED_COMMON_NGOS_TYPES_H



typedef signed char      i8;
typedef signed short     i16;
typedef signed int       i32;
typedef signed long long i64;

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef char     char8;
typedef char16_t char16;



#ifdef __GNUC__
typedef long unsigned int size_t;
#else
typedef unsigned long long size_t;
#endif



#endif // COM_NGOS_SHARED_COMMON_NGOS_TYPES_H
