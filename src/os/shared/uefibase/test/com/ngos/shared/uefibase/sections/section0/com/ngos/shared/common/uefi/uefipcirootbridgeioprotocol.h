#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H



#include <buildconfig.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocol.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_uefi_uefipcirootbridgeioprotocol);
{
    TEST_CASE("UEFI_PCI_ADDRESS()");
    {
        TEST_ASSERT_EQUALS(UEFI_PCI_ADDRESS(0, 0, 0, 0),               0x0000000000000000);
        TEST_ASSERT_EQUALS(UEFI_PCI_ADDRESS(0x01, 0x02, 0x03, 0x04),   0x0000000001020304);
        TEST_ASSERT_EQUALS(UEFI_PCI_ADDRESS(0x10, 0x20, 0x30, 0x40),   0x0000000010203040);
        TEST_ASSERT_EQUALS(UEFI_PCI_ADDRESS(0x10, 0x20, 0x30, 0x9940), 0x0000994010203000);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H
