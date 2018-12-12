#ifndef GDT_SEGMENTS_H
#define GDT_SEGMENTS_H



#define GDT_ENTRY_KERNEL32_CS       1
#define GDT_ENTRY_KERNEL_CS         2
#define GDT_ENTRY_KERNEL_DS         3
#define GDT_ENTRY_DEFAULT_USER32_CS 4
#define GDT_ENTRY_DEFAULT_USER_DS   5
#define GDT_ENTRY_DEFAULT_USER_CS   6
#define GDT_ENTRY_TSS               8
#define GDT_ENTRY_LDT               10
#define GDT_ENTRY_TLS_MIN           12
#define GDT_ENTRY_TLS_MAX           14
#define GDT_ENTRY_PER_CPU           15

#define GDT_ENTRIES                 16



// Segment selector values corresponding to the above entries:
//
// Note, selectors also need to have a correct RPL,
// expressed with the +3 value for user-space selectors:
//
#define GDT_KERNEL32_CS   ((GDT_ENTRY_KERNEL32_CS       << 3))
#define GDT_KERNEL_CS     ((GDT_ENTRY_KERNEL_CS         << 3))
#define GDT_KERNEL_DS     ((GDT_ENTRY_KERNEL_DS         << 3))
#define GDT_USER32_CS     ((GDT_ENTRY_DEFAULT_USER32_CS << 3) + 3)
#define GDT_USER_DS       ((GDT_ENTRY_DEFAULT_USER_DS   << 3) + 3)
#define GDT_USER32_DS     GDT_USER_DS
#define GDT_USER_CS       ((GDT_ENTRY_DEFAULT_USER_CS   << 3) + 3)
#define GDT_PER_CPU_SEG   ((GDT_ENTRY_PER_CPU           << 3) + 3)



#endif // GDT_SEGMENTS_H
