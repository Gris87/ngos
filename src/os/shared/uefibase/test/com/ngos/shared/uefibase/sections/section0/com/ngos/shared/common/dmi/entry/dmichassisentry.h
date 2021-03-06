#ifndef COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICHASSISENTRY_H
#define COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICHASSISENTRY_H



#include <buildconfig.h>
#include <com/ngos/shared/common/dmi/entry/dmichassisentry.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section0, com_ngos_shared_common_dmi_entry_dmichassisentry);
{
    TEST_CASE("DMI_CHASSIS_CONTAINED_ELEMENT()");
    {
        DmiChassisEntryV23 entry;

        u8 *buf = (u8 *)&entry;



        entry.containedElementRecordLength = 2;

        TEST_ASSERT_EQUALS(DMI_CHASSIS_CONTAINED_ELEMENT(&entry, 0), (DmiChassisContainedElement *)&buf[21]);
        TEST_ASSERT_EQUALS(DMI_CHASSIS_CONTAINED_ELEMENT(&entry, 2), (DmiChassisContainedElement *)&buf[25]);
        TEST_ASSERT_EQUALS(DMI_CHASSIS_CONTAINED_ELEMENT(&entry, 7), (DmiChassisContainedElement *)&buf[35]);



        entry.containedElementRecordLength = 5;

        TEST_ASSERT_EQUALS(DMI_CHASSIS_CONTAINED_ELEMENT(&entry, 0), (DmiChassisContainedElement *)&buf[21]);
        TEST_ASSERT_EQUALS(DMI_CHASSIS_CONTAINED_ELEMENT(&entry, 2), (DmiChassisContainedElement *)&buf[31]);
        TEST_ASSERT_EQUALS(DMI_CHASSIS_CONTAINED_ELEMENT(&entry, 7), (DmiChassisContainedElement *)&buf[56]);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_SHARED_UEFIBASE_SECTIONS_SECTION0_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMICHASSISENTRY_H
