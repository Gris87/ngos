#ifndef PAGETABLE_FLAGS_H
#define PAGETABLE_FLAGS_H



#define PAGE_FLAG_PRESENT             (1ULL << 0)
#define PAGE_FLAG_READ_WRITE          (1ULL << 1)
#define PAGE_FLAG_USER                (1ULL << 2)
#define PAGE_FLAG_ACCESSED            (1ULL << 5)
#define PAGE_FLAG_DIRTY               (1ULL << 6)
#define PAGE_FLAG_PAGE_SIZE_EXTENSION (1ULL << 7)
#define PAGE_FLAG_GLOBAL              (1ULL << 8)



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



#define KERNEL_PAGE_LARGE_EXEC_FLAGS    (KERNEL_PAGE_EXEC_FLAGS | PAGE_FLAG_PAGE_SIZE_EXTENSION)



#endif // PAGETABLE_FLAGS_H
