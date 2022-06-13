#ifndef COM_NGOS_SHARED_COMMON_PAGETABLE_FLAGS_H
#define COM_NGOS_SHARED_COMMON_PAGETABLE_FLAGS_H



#define PAGE_FLAG_PRESENT             BIT_0
#define PAGE_FLAG_READ_WRITE          BIT_1
#define PAGE_FLAG_USER                BIT_2
#define PAGE_FLAG_WRITE_THROUGH       BIT_3
#define PAGE_FLAG_CACHE_DISABLED      BIT_4
#define PAGE_FLAG_ACCESSED            BIT_5
#define PAGE_FLAG_DIRTY               BIT_6
#define PAGE_FLAG_PAGE_SIZE_EXTENSION BIT_7
#define PAGE_FLAG_GLOBAL              BIT_8
#define PAGE_FLAG_LARGE_EXTENSTION    BIT_12
#define PAGE_FLAG_NX                  BIT_63



#define KERNEL_PAGE_TABLE_FLAGS \
            ( \
                PAGE_FLAG_PRESENT \
                | PAGE_FLAG_READ_WRITE \
                | PAGE_FLAG_ACCESSED \
                | PAGE_FLAG_DIRTY \
            )



#define USER_PAGE_TABLE_FLAGS \
            ( \
                PAGE_FLAG_PRESENT \
                | PAGE_FLAG_READ_WRITE \
                | PAGE_FLAG_ACCESSED \
                | PAGE_FLAG_DIRTY \
                | PAGE_FLAG_USER \
            )



#define KERNEL_PAGE_EXEC_FLAGS \
    ( \
        PAGE_FLAG_PRESENT \
        | PAGE_FLAG_READ_WRITE \
        | PAGE_FLAG_ACCESSED \
        | PAGE_FLAG_DIRTY \
        | PAGE_FLAG_GLOBAL \
    )



#define KERNEL_PAGE_FLAGS \
    ( \
        PAGE_FLAG_PRESENT \
        | PAGE_FLAG_READ_WRITE \
        | PAGE_FLAG_ACCESSED \
        | PAGE_FLAG_DIRTY \
        | PAGE_FLAG_GLOBAL \
        | PAGE_FLAG_NX \
    )



#define KERNEL_PAGE_LARGE_EXEC_FLAGS    (KERNEL_PAGE_EXEC_FLAGS | PAGE_FLAG_PAGE_SIZE_EXTENSION)



#endif // COM_NGOS_SHARED_COMMON_PAGETABLE_FLAGS_H
