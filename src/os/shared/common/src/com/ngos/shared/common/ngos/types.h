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

typedef u64 address_t;
typedef u64 enum_t;



// TODO: Delete it
typedef signed char      good_I8;
typedef signed short     good_I16;
typedef signed int       good_I32;
typedef signed long long good_I64;

typedef unsigned char      good_U8;
typedef unsigned short     good_U16;
typedef unsigned int       good_U32;
typedef unsigned long long good_U64;

typedef char     good_char8;
typedef char16_t good_char16;

typedef u64 good_address_t;
typedef u64 good_enum_t;



#ifndef NGOS_DEVTOOLS_APPLICATION // Defined in pro file
typedef long unsigned int size_t;
typedef long unsigned int good_size_t; // TODO: Delete it
#endif



#endif // COM_NGOS_SHARED_COMMON_NGOS_TYPES_H
