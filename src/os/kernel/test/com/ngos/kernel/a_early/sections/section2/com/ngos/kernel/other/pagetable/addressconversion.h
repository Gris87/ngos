#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_PAGETABLE_ADDRESSCONVERSION_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_PAGETABLE_ADDRESSCONVERSION_H



#include <buildconfig.h>

#include <com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



extern void *_start; // _start declared in main.S file // Ignore CppEqualAlignmentVerifier



TEST_CASES(section2, com_ngos_kernel_other_pagetable_addressconversion);
{
    TEST_CASE("physicalAddress()");
    {
        u64 temp = AddressConversion::sPhysicalDelta;

        TEST_ASSERT_NOT_EQUALS(temp, 0);
        TEST_ASSERT_EQUALS(AddressConversion::physicalAddress(0), temp);
        TEST_ASSERT_EQUALS(AddressConversion::physicalAddress(-temp), 0);

        AddressConversion::sPhysicalDelta = 0;

        TEST_ASSERT_EQUALS(AddressConversion::physicalAddress(0),   0);
        TEST_ASSERT_EQUALS(AddressConversion::physicalAddress(500), 500);

        AddressConversion::sPhysicalDelta = 1000;

        TEST_ASSERT_EQUALS(AddressConversion::physicalAddress(0),   1000);
        TEST_ASSERT_EQUALS(AddressConversion::physicalAddress(500), 1500);

        AddressConversion::sPhysicalDelta = temp;
    }
    TEST_CASE_END();



    TEST_CASE("virtualAddress()");
    {
        u64 temp = AddressConversion::sPhysicalDelta;

        TEST_ASSERT_NOT_EQUALS(temp, 0);
        TEST_ASSERT_EQUALS(AddressConversion::virtualAddress(0), -temp);
        TEST_ASSERT_EQUALS(AddressConversion::virtualAddress(temp), 0);

        AddressConversion::sPhysicalDelta = 0;

        TEST_ASSERT_EQUALS(AddressConversion::virtualAddress(0),   0);
        TEST_ASSERT_EQUALS(AddressConversion::virtualAddress(500), 500);

        AddressConversion::sPhysicalDelta = 1000;

        TEST_ASSERT_EQUALS(AddressConversion::virtualAddress(2000), 1000);
        TEST_ASSERT_EQUALS(AddressConversion::virtualAddress(2500), 1500);

        AddressConversion::sPhysicalDelta = temp;
    }
    TEST_CASE_END();



    TEST_CASE("setPhysicalDeltaBaseOnLocation()");
    {
        u64 temp = AddressConversion::sPhysicalDelta;

        TEST_ASSERT_NOT_EQUALS(temp, 0);
        TEST_ASSERT_EQUALS(AddressConversion::setPhysicalDeltaBaseOnLocation((u64)&_start), NgosStatus::OK);
        TEST_ASSERT_EQUALS(AddressConversion::sPhysicalDelta,                               0);

        AddressConversion::sPhysicalDelta = temp;
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_PAGETABLE_ADDRESSCONVERSION_H
