#ifndef OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PAGETABLE_UTILS_H
#define OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PAGETABLE_UTILS_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/pagetable/utils.h>
#include <uefibase/test/com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_pagetable_utils);
{
    TEST_CASE("pgdIndex()");
    {
#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pgdIndex(0xFAFAFAFAFAFAFAFA), 250);
        TEST_ASSERT_EQUALS(pgdIndex(0xFBFBFBFBFBFBFBFB), 507);
        TEST_ASSERT_EQUALS(pgdIndex(0xFCFCFCFCFCFCFCFC), 252);
        TEST_ASSERT_EQUALS(pgdIndex(0xFDFDFDFDFDFDFDFD), 509);
        TEST_ASSERT_EQUALS(pgdIndex(0xFEFEFEFEFEFEFEFE), 254);
        TEST_ASSERT_EQUALS(pgdIndex(0xFFFFFFFFFFFFFFFF), 511);
#else
        TEST_ASSERT_EQUALS(pgdIndex(0xFAFAFAFAFAFAFAFA), 501);
        TEST_ASSERT_EQUALS(pgdIndex(0xFBFBFBFBFBFBFBFB), 503);
        TEST_ASSERT_EQUALS(pgdIndex(0xFCFCFCFCFCFCFCFC), 505);
        TEST_ASSERT_EQUALS(pgdIndex(0xFDFDFDFDFDFDFDFD), 507);
        TEST_ASSERT_EQUALS(pgdIndex(0xFEFEFEFEFEFEFEFE), 509);
        TEST_ASSERT_EQUALS(pgdIndex(0xFFFFFFFFFFFFFFFF), 511);
#endif
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dIndex()");
    {
        TEST_ASSERT_EQUALS(p4dIndex(0xFAFAFAFAFAFAFAFA), 501);
        TEST_ASSERT_EQUALS(p4dIndex(0xFBFBFBFBFBFBFBFB), 503);
        TEST_ASSERT_EQUALS(p4dIndex(0xFCFCFCFCFCFCFCFC), 505);
        TEST_ASSERT_EQUALS(p4dIndex(0xFDFDFDFDFDFDFDFD), 507);
        TEST_ASSERT_EQUALS(p4dIndex(0xFEFEFEFEFEFEFEFE), 509);
        TEST_ASSERT_EQUALS(p4dIndex(0xFFFFFFFFFFFFFFFF), 511);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudIndex()");
    {
        TEST_ASSERT_EQUALS(pudIndex(0xFAFAFAFAFAFAFAFA), 491);
        TEST_ASSERT_EQUALS(pudIndex(0xFBFBFBFBFBFBFBFB), 495);
        TEST_ASSERT_EQUALS(pudIndex(0xFCFCFCFCFCFCFCFC), 499);
        TEST_ASSERT_EQUALS(pudIndex(0xFDFDFDFDFDFDFDFD), 503);
        TEST_ASSERT_EQUALS(pudIndex(0xFEFEFEFEFEFEFEFE), 507);
        TEST_ASSERT_EQUALS(pudIndex(0xFFFFFFFFFFFFFFFF), 511);
    }
    TEST_CASE_END();



    TEST_CASE("pmdIndex()");
    {
        TEST_ASSERT_EQUALS(pmdIndex(0xFAFAFAFAFAFAFAFA), 471);
        TEST_ASSERT_EQUALS(pmdIndex(0xFBFBFBFBFBFBFBFB), 479);
        TEST_ASSERT_EQUALS(pmdIndex(0xFCFCFCFCFCFCFCFC), 487);
        TEST_ASSERT_EQUALS(pmdIndex(0xFDFDFDFDFDFDFDFD), 495);
        TEST_ASSERT_EQUALS(pmdIndex(0xFEFEFEFEFEFEFEFE), 503);
        TEST_ASSERT_EQUALS(pmdIndex(0xFFFFFFFFFFFFFFFF), 511);
    }
    TEST_CASE_END();



    TEST_CASE("pteIndex()");
    {
        TEST_ASSERT_EQUALS(pteIndex(0xFAFAFAFAFAFAFAFA), 431);
        TEST_ASSERT_EQUALS(pteIndex(0xFBFBFBFBFBFBFBFB), 447);
        TEST_ASSERT_EQUALS(pteIndex(0xFCFCFCFCFCFCFCFC), 463);
        TEST_ASSERT_EQUALS(pteIndex(0xFDFDFDFDFDFDFDFD), 479);
        TEST_ASSERT_EQUALS(pteIndex(0xFEFEFEFEFEFEFEFE), 495);
        TEST_ASSERT_EQUALS(pteIndex(0xFFFFFFFFFFFFFFFF), 511);
    }
    TEST_CASE_END();



    TEST_CASE("setPgd()");
    {
        PGD pgd;

        setPgd(&pgd, 1000);
        TEST_ASSERT_EQUALS(pgd.pgd, 1000);

        setPgd(&pgd, 12345);
        TEST_ASSERT_EQUALS(pgd.pgd, 12345);

        setPgd(&pgd, 987654321);
        TEST_ASSERT_EQUALS(pgd.pgd, 987654321);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("setP4d()");
    {
        P4D p4d;

        setP4d(&p4d, 1000);
        TEST_ASSERT_EQUALS(p4d.p4d, 1000);

        setP4d(&p4d, 12345);
        TEST_ASSERT_EQUALS(p4d.p4d, 12345);

        setP4d(&p4d, 987654321);
        TEST_ASSERT_EQUALS(p4d.p4d, 987654321);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("setPud()");
    {
        PUD pud;

        setPud(&pud, 1000);
        TEST_ASSERT_EQUALS(pud.pud, 1000);

        setPud(&pud, 12345);
        TEST_ASSERT_EQUALS(pud.pud, 12345);

        setPud(&pud, 987654321);
        TEST_ASSERT_EQUALS(pud.pud, 987654321);
    }
    TEST_CASE_END();



    TEST_CASE("setPmd()");
    {
        PMD pmd;

        setPmd(&pmd, 1000);
        TEST_ASSERT_EQUALS(pmd.pmd, 1000);

        setPmd(&pmd, 12345);
        TEST_ASSERT_EQUALS(pmd.pmd, 12345);

        setPmd(&pmd, 987654321);
        TEST_ASSERT_EQUALS(pmd.pmd, 987654321);
    }
    TEST_CASE_END();



    TEST_CASE("setPte()");
    {
        PTE pte;

        setPte(&pte, 1000);
        TEST_ASSERT_EQUALS(pte.pte, 1000);

        setPte(&pte, 12345);
        TEST_ASSERT_EQUALS(pte.pte, 12345);

        setPte(&pte, 987654321);
        TEST_ASSERT_EQUALS(pte.pte, 987654321);
    }
    TEST_CASE_END();



    TEST_CASE("pgdValue()");
    {
        PGD pgd;

        pgd.pgd = 1000;
        TEST_ASSERT_EQUALS(pgdValue(pgd), 1000);

        pgd.pgd = 12345;
        TEST_ASSERT_EQUALS(pgdValue(pgd), 12345);

        pgd.pgd = 987654321;
        TEST_ASSERT_EQUALS(pgdValue(pgd), 987654321);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dValue()");
    {
        P4D p4d;

        p4d.p4d = 1000;
        TEST_ASSERT_EQUALS(p4dValue(p4d), 1000);

        p4d.p4d = 12345;
        TEST_ASSERT_EQUALS(p4dValue(p4d), 12345);

        p4d.p4d = 987654321;
        TEST_ASSERT_EQUALS(p4dValue(p4d), 987654321);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudValue()");
    {
        PUD pud;

        pud.pud = 1000;
        TEST_ASSERT_EQUALS(pudValue(pud), 1000);

        pud.pud = 12345;
        TEST_ASSERT_EQUALS(pudValue(pud), 12345);

        pud.pud = 987654321;
        TEST_ASSERT_EQUALS(pudValue(pud), 987654321);
    }
    TEST_CASE_END();



    TEST_CASE("pmdValue()");
    {
        PMD pmd;

        pmd.pmd = 1000;
        TEST_ASSERT_EQUALS(pmdValue(pmd), 1000);

        pmd.pmd = 12345;
        TEST_ASSERT_EQUALS(pmdValue(pmd), 12345);

        pmd.pmd = 987654321;
        TEST_ASSERT_EQUALS(pmdValue(pmd), 987654321);
    }
    TEST_CASE_END();



    TEST_CASE("pteValue()");
    {
        PTE pte;

        pte.pte = 1000;
        TEST_ASSERT_EQUALS(pteValue(pte), 1000);

        pte.pte = 12345;
        TEST_ASSERT_EQUALS(pteValue(pte), 12345);

        pte.pte = 987654321;
        TEST_ASSERT_EQUALS(pteValue(pte), 987654321);
    }
    TEST_CASE_END();



    TEST_CASE("pgdPresent()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0x00000F0000000001;
        pgd2.pgd = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pgdPresent(pgd),  true);
        TEST_ASSERT_EQUALS(pgdPresent(pgd2), false);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dPresent()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0x00000F0000000001;
        p4d2.p4d = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(p4dPresent(p4d),  true);
        TEST_ASSERT_EQUALS(p4dPresent(p4d2), false);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudPresent()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0x00000F0000000001;
        pud2.pud = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pudPresent(pud),  true);
        TEST_ASSERT_EQUALS(pudPresent(pud2), false);
    }
    TEST_CASE_END();



    TEST_CASE("pmdPresent()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0x00000F0000000001;
        pmd2.pmd = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pmdPresent(pmd),  true);
        TEST_ASSERT_EQUALS(pmdPresent(pmd2), false);
    }
    TEST_CASE_END();



    TEST_CASE("ptePresent()");
    {
        PTE pte;
        PTE pte2;

        pte.pte  = 0x00000F0000000001;
        pte2.pte = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(ptePresent(pte),  true);
        TEST_ASSERT_EQUALS(ptePresent(pte2), false);
    }
    TEST_CASE_END();



    TEST_CASE("pgdExtended()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0x00000F0000000001;
        pgd2.pgd = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pgdExtended(pgd),  false);
        TEST_ASSERT_EQUALS(pgdExtended(pgd2), true);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dExtended()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0x00000F0000000001;
        p4d2.p4d = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(p4dExtended(p4d),  false);
        TEST_ASSERT_EQUALS(p4dExtended(p4d2), true);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudExtended()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0x00000F0000000001;
        pud2.pud = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pudExtended(pud),  false);
        TEST_ASSERT_EQUALS(pudExtended(pud2), true);
    }
    TEST_CASE_END();



    TEST_CASE("pmdExtended()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0x00000F0000000001;
        pmd2.pmd = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pmdExtended(pmd),  false);
        TEST_ASSERT_EQUALS(pmdExtended(pmd2), true);
    }
    TEST_CASE_END();



    TEST_CASE("pteExtended()");
    {
        PTE pte;
        PTE pte2;

        pte.pte  = 0x00000F0000000001;
        pte2.pte = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pteExtended(pte),  false);
        TEST_ASSERT_EQUALS(pteExtended(pte2), true);
    }
    TEST_CASE_END();



    TEST_CASE("pgdPfnMask()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0xABCD0000;
        pgd2.pgd = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pgdPfnMask(pgd),  0x000FFFFFFFFFF000);
        TEST_ASSERT_EQUALS(pgdPfnMask(pgd2), 0x000FFFFFFFFFF000);
#else
        TEST_ASSERT_EQUALS(pgdPfnMask(pgd),  0x00003FFFFFFFF000);
        TEST_ASSERT_EQUALS(pgdPfnMask(pgd2), 0x00003FFFFFFFF000);
#endif
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dPfnMask()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0xABCD0000;
        p4d2.p4d = 0xABCD0080;

        TEST_ASSERT_EQUALS(p4dPfnMask(p4d),  0x000FFFFFFFFFF000);
        TEST_ASSERT_EQUALS(p4dPfnMask(p4d2), 0x000FFFFFFFFFF000);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudPfnMask()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0xABCD0000;
        pud2.pud = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pudPfnMask(pud),  0x000FFFFFFFFFF000);
        TEST_ASSERT_EQUALS(pudPfnMask(pud2), 0x000FFFFFC0000000);
#else
        TEST_ASSERT_EQUALS(pudPfnMask(pud),  0x00003FFFFFFFF000);
        TEST_ASSERT_EQUALS(pudPfnMask(pud2), 0x00003FFFC0000000);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("pmdPfnMask()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0xABCD0000;
        pmd2.pmd = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pmdPfnMask(pmd),  0x000FFFFFFFFFF000);
        TEST_ASSERT_EQUALS(pmdPfnMask(pmd2), 0x000FFFFFFFE00000);
#else
        TEST_ASSERT_EQUALS(pmdPfnMask(pmd),  0x00003FFFFFFFF000);
        TEST_ASSERT_EQUALS(pmdPfnMask(pmd2), 0x00003FFFFFE00000);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("ptePfnMask()");
    {
        PTE pte;
        PTE pte2;

        pte.pte  = 0xABCD0000;
        pte2.pte = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(ptePfnMask(pte),  0x000FFFFFFFFFF000);
        TEST_ASSERT_EQUALS(ptePfnMask(pte2), 0x000FFFFFFFFFF000);
#else
        TEST_ASSERT_EQUALS(ptePfnMask(pte),  0x00003FFFFFFFF000);
        TEST_ASSERT_EQUALS(ptePfnMask(pte2), 0x00003FFFFFFFF000);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("pgdFlagsMask()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0xABCD0000;
        pgd2.pgd = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pgdFlagsMask(pgd),  0xFFF0000000000FFF);
        TEST_ASSERT_EQUALS(pgdFlagsMask(pgd2), 0xFFF0000000000FFF);
#else
        TEST_ASSERT_EQUALS(pgdFlagsMask(pgd),  0xFFFFC00000000FFF);
        TEST_ASSERT_EQUALS(pgdFlagsMask(pgd2), 0xFFFFC00000000FFF);
#endif
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dFlagsMask()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0xABCD0000;
        p4d2.p4d = 0xABCD0080;

        TEST_ASSERT_EQUALS(p4dFlagsMask(p4d),  0xFFF0000000000FFF);
        TEST_ASSERT_EQUALS(p4dFlagsMask(p4d2), 0xFFF0000000000FFF);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudFlagsMask()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0xABCD0000;
        pud2.pud = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pudFlagsMask(pud),  0xFFF0000000000FFF);
        TEST_ASSERT_EQUALS(pudFlagsMask(pud2), 0xFFF000003FFFFFFF);
#else
        TEST_ASSERT_EQUALS(pudFlagsMask(pud),  0xFFFFC00000000FFF);
        TEST_ASSERT_EQUALS(pudFlagsMask(pud2), 0xFFFFC0003FFFFFFF);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("pmdFlagsMask()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0xABCD0000;
        pmd2.pmd = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pmdFlagsMask(pmd),  0xFFF0000000000FFF);
        TEST_ASSERT_EQUALS(pmdFlagsMask(pmd2), 0xFFF00000001FFFFF);
#else
        TEST_ASSERT_EQUALS(pmdFlagsMask(pmd),  0xFFFFC00000000FFF);
        TEST_ASSERT_EQUALS(pmdFlagsMask(pmd2), 0xFFFFC000001FFFFF);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("pteFlagsMask()");
    {
        PTE pte;
        PTE pte2;

        pte.pte  = 0xABCD0000;
        pte2.pte = 0xABCD0080;

#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
        TEST_ASSERT_EQUALS(pteFlagsMask(pte),  0xFFF0000000000FFF);
        TEST_ASSERT_EQUALS(pteFlagsMask(pte2), 0xFFF0000000000FFF);
#else
        TEST_ASSERT_EQUALS(pteFlagsMask(pte),  0xFFFFC00000000FFF);
        TEST_ASSERT_EQUALS(pteFlagsMask(pte2), 0xFFFFC00000000FFF);
#endif
    }
    TEST_CASE_END();



    TEST_CASE("pgdFlags()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0x00000F0000000075;
        pgd2.pgd = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pgdFlags(pgd),  0x75);
        TEST_ASSERT_EQUALS(pgdFlags(pgd2), 0x80);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dFlags()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0x00000F0000000075;
        p4d2.p4d = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(p4dFlags(p4d),  0x75);
        TEST_ASSERT_EQUALS(p4dFlags(p4d2), 0x80);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudFlags()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0x00000F0000000075;
        pud2.pud = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pudFlags(pud),  0x75);
        TEST_ASSERT_EQUALS(pudFlags(pud2), 0x80);
    }
    TEST_CASE_END();



    TEST_CASE("pmdFlags()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0x00000F0000000075;
        pmd2.pmd = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pmdFlags(pmd),  0x75);
        TEST_ASSERT_EQUALS(pmdFlags(pmd2), 0x80);
    }
    TEST_CASE_END();



    TEST_CASE("pteFlags()");
    {
        PTE pte;
        PTE pte2;

        pte.pte  = 0x00000F0000000075;
        pte2.pte = 0x00000F0000000080;

        TEST_ASSERT_EQUALS(pteFlags(pte),  0x75);
        TEST_ASSERT_EQUALS(pteFlags(pte2), 0x80);
    }
    TEST_CASE_END();



    TEST_CASE("pgdPageVirtualAddress()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0x00000FEDCBA98075;
        pgd2.pgd = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS(pgdPageVirtualAddress(pgd),  0x00000FEDCBA98000);
        TEST_ASSERT_EQUALS(pgdPageVirtualAddress(pgd2), 0x00000FEDCBA98000);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dPageVirtualAddress()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0x00000FEDCBA98075;
        p4d2.p4d = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS(p4dPageVirtualAddress(p4d),  0x00000FEDCBA98000);
        TEST_ASSERT_EQUALS(p4dPageVirtualAddress(p4d2), 0x00000FEDCBA98000);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pudPageVirtualAddress()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0x00000FEDCBA98075;
        pud2.pud = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS(pudPageVirtualAddress(pud),  0x00000FEDCBA98000);
        TEST_ASSERT_EQUALS(pudPageVirtualAddress(pud2), 0x00000FEDC0000000);
    }
    TEST_CASE_END();



    TEST_CASE("pmdPageVirtualAddress()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0x00000FEDCBA98075;
        pmd2.pmd = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS(pmdPageVirtualAddress(pmd),  0x00000FEDCBA98000);
        TEST_ASSERT_EQUALS(pmdPageVirtualAddress(pmd2), 0x00000FEDCBA00000);
    }
    TEST_CASE_END();



    TEST_CASE("ptePageVirtualAddress()");
    {
        PTE pte;
        PTE pte2;

        pte.pte  = 0x00000FEDCBA98075;
        pte2.pte = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS(ptePageVirtualAddress(pte),  0x00000FEDCBA98000);
        TEST_ASSERT_EQUALS(ptePageVirtualAddress(pte2), 0x00000FEDCBA98000);
    }
    TEST_CASE_END();



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
    TEST_CASE("p4dOffset()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0x00000FEDCBA98075;
        pgd2.pgd = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS((u64)p4dOffset(&pgd,  0xFAFAFAFAFAFAFAFA), 0x00000FEDCBA98FA8);
        TEST_ASSERT_EQUALS((u64)p4dOffset(&pgd2, 0xFBFBFBFBFBFBFBFB), 0x00000FEDCBA98FB8);
    }
    TEST_CASE_END();



    TEST_CASE("pudOffset()");
    {
        P4D p4d;
        P4D p4d2;

        p4d.p4d  = 0x00000FEDCBA98075;
        p4d2.p4d = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS((u64)pudOffset(&p4d,  0xFAFAFAFAFAFAFAFA), 0x00000FEDCBA98F58);
        TEST_ASSERT_EQUALS((u64)pudOffset(&p4d2, 0xFBFBFBFBFBFBFBFB), 0x00000FEDCBA98F78);
    }
    TEST_CASE_END();
#else
    TEST_CASE("pudOffset()");
    {
        PGD pgd;
        PGD pgd2;

        pgd.pgd  = 0x00000FEDCBA98075;
        pgd2.pgd = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS((u64)pudOffset(&pgd,  0xFAFAFAFAFAFAFAFA), 0x00000FEDCBA98F58);
        TEST_ASSERT_EQUALS((u64)pudOffset(&pgd2, 0xFBFBFBFBFBFBFBFB), 0x00000FEDCBA98F78);
    }
    TEST_CASE_END();
#endif



    TEST_CASE("pmdOffset()");
    {
        PUD pud;
        PUD pud2;

        pud.pud  = 0x00000FEDCBA98075;
        pud2.pud = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS((u64)pmdOffset(&pud,  0xFAFAFAFAFAFAFAFA), 0x00000FEDCBA98EB8);
        TEST_ASSERT_EQUALS((u64)pmdOffset(&pud2, 0xFBFBFBFBFBFBFBFB), 0x00000FEDC0000EF8);
    }
    TEST_CASE_END();



    TEST_CASE("pteOffset()");
    {
        PMD pmd;
        PMD pmd2;

        pmd.pmd  = 0x00000FEDCBA98075;
        pmd2.pmd = 0x00000FEDCBA98080;

        TEST_ASSERT_EQUALS((u64)pteOffset(&pmd,  0xFAFAFAFAFAFAFAFA), 0x00000FEDCBA98D78);
        TEST_ASSERT_EQUALS((u64)pteOffset(&pmd2, 0xFBFBFBFBFBFBFBFB), 0x00000FEDCBA00DF8);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_UEFIBASE_TEST_COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_PAGETABLE_UTILS_H
