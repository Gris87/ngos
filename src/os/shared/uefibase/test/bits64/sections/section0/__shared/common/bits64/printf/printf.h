#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_PRINTF_PRINTF_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_PRINTF_PRINTF_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/string/string.h>
#include <uefibase/test/bits64/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



// Ignore CppAlignmentVerifier [BEGIN]
TEST_CASES(section0, __shared_common_bits64_printf_printf);
{
    char8 buffer[1024];



    TEST_CASE("sprintf(). Simplest format");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "abcdeFGHIJ"), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "abcdeFGHIJ"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for single char");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello%c", '!'), 6);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello!"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello%10c", '!'), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello         !"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello%-10c", '!'), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello!         "), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Field width from the arguments");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "world%*c", 5, '!'), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "world    !"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "world%*c", -5, '!'), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "world!    "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "world%-*c", 6, '!'), 11);
        TEST_ASSERT_EQUALS(strcmp(buffer, "world!     "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "world%-*c", -6, '!'), 11);
        TEST_ASSERT_EQUALS(strcmp(buffer, "world!     "), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for string");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %s!", "world"), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello world!"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %10s!", "world"), 17);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello      world!"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %-10s!", "world"), 17);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello world     !"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %10.3s!", "world"), 17);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello        wor!"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %-10.3s!", "world"), 17);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello wor       !"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %.3s!", "world"), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello wor!"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Precision from the arguments");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %10.*s!", 3, "world"), 17);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello        wor!"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %-10.*s!", 1, "world"), 17);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello w         !"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "Hello %.*s!", -5, "world"), 7);
        TEST_ASSERT_EQUALS(strcmp(buffer, "Hello !"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for pointer");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %p", (void *)1000), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd 00000000000003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %8p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd      3E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %-8p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd 3E8     "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %+8p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd      3E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd % 8p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd      3E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %#8p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd    0X3E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %08p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd 000003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %.5p", (void *)1000), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd 00000000000003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %8.5p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd    003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %-8.5p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd 003E8   "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %+8.5p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd    003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd % 8.5p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd    003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %#8.5p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd  0X003E8"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "asd %08.5p", (void *)1000), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "asd 000003E8"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for percent");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "yovyof %%"), 8);
        TEST_ASSERT_EQUALS(strcmp(buffer, "yovyof %"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "yovyof %"), 8);
        TEST_ASSERT_EQUALS(strcmp(buffer, "yovyof %"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "yovyof %k"), 9);
        TEST_ASSERT_EQUALS(strcmp(buffer, "yovyof %k"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for 8-based number");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %o", 245694), 11);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj 737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %10o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj     737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %-10o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj 737676    "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %+10o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj     737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj % 10o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj     737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %#10o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj    0737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %010o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj 0000737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %.8o", 245694), 13);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj 00737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %10.8o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj   00737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %-10.8o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj 00737676  "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %+10.8o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj   00737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj % 10.8o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj   00737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %#10.8o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj  000737676"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffhj %010.8o", 245694), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffhj 0000737676"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for 16-based number (lowercase)");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %x", 38633838), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 24d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %10x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid    24d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %-10x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 24d816e   "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %+10x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid    24d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid % 10x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid    24d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %#10x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid  0x24d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %010x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 00024d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %.8x", 38633838), 13);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 024d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %10.8x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid   024d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %-10.8x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 024d816e  "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %+10.8x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid   024d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid % 10.8x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid   024d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %#10.8x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 0x024d816e"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %010.8x", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 00024d816e"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for 16-based number (uppercase)");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %X", 38633838), 12);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 24D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %10X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid    24D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %-10X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 24D816E   "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %+10X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid    24D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid % 10X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid    24D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %#10X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid  0X24D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %010X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 00024D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %.8X", 38633838), 13);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 024D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %10.8X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid   024D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %-10.8X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 024D816E  "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %+10.8X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid   024D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid % 10.8X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid   024D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %#10.8X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 0X024D816E"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "dtid %010.8X", 38633838), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "dtid 00024D816E"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for 10-based signed number (d)");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %d", 373945), 11);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %15d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %-15d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 373945         "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %+15d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick         +373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick % 15d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %#15d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %015d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 000000000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %.10d", 373945), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %15.10d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %-15.10d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 0000373945     "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %+15.10d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick     +0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick % 15.10d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %#15.10d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %015.10d", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 000000000373945"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for 10-based signed number (i)");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %i", 373945), 11);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %15i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %-15i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 373945         "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %+15i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick         +373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick % 15i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %#15i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %015i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 000000000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %.10i", 373945), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %15.10i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %-15.10i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 0000373945     "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %+15.10i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick     +0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick % 15.10i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %#15.10i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %015.10i", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 000000000373945"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for 10-based unsigned number");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %u", 373945), 11);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %15u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %-15u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 373945         "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %+15u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick % 15u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %#15u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick          373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %015u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 000000000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %.10u", 373945), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %15.10u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %-15.10u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 0000373945     "), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %+15.10u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick % 15.10u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %#15.10u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick      0000373945"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "gick %015.10u", 373945), 20);
        TEST_ASSERT_EQUALS(strcmp(buffer, "gick 000000000373945"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for flags of signed number");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %d", -35640), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy -35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %+d", -35640), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy -35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy % d", -35640), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy -35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %10d", -35640), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy     -35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %+10d", -35640), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy     -35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy % 10d", -35640), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy     -35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %d", 35640), 9);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %+d", 35640), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy +35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy % d", 35640), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy  35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %10d", 35640), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy      35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %+10d", 35640), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy     +35640"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy % 10d", 35640), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy      35640"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Format for qualifiers");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %d", 423949673010), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy -1252089294"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %Ld", 423949673010), 15);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy -1252089294"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %ld", 423949673010), 16);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 423949673010"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %hd", 423949673010), 10);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy -24014"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %u", 423949673010), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 3042878002"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %Lu", 423949673010), 14);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 3042878002"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %lu", 423949673010), 16);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 423949673010"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy %hu", 423949673010), 9);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 41522"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy 0x%016lX", 0xBD39C17DC3AC79A7), 22);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 0xBD39C17DC3AC79A7"), 0);

        TEST_ASSERT_EQUALS(sprintf(buffer, "ffy 0x%016lX", 0xEE34C2E29C26AE40), 22);
        TEST_ASSERT_EQUALS(strcmp(buffer, "ffy 0xEE34C2E29C26AE40"), 0);
    }
    TEST_CASE_END();



    TEST_CASE("sprintf(). Complex formats");
    {
        TEST_ASSERT_EQUALS(sprintf(buffer, "rfyh %c tugg %s fhtfb %p gjgtyg %% fgff %o fghg %x fhtuh %X yof6 %d gygg %i ftff %u", 'c', "str", (void *)0x00FFFFFFFFFFFFA0, 123, 255, 255, 321, 456, 789), 100);
        TEST_ASSERT_EQUALS(strcmp(buffer, "rfyh c tugg str fhtfb 00FFFFFFFFFFFFA0 gjgtyg % fgff 173 fghg ff fhtuh FF yof6 321 gygg 456 ftff 789"), 0);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif
// Ignore CppAlignmentVerifier [END]



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_SECTIONS_SECTION0___SHARED_COMMON_BITS64_PRINTF_PRINTF_H
