#ifndef COM_NGOS_INSTALLER_SECTIONS_SECTION1_COM_NGOS_INSTALLER_TYPES_H
#define COM_NGOS_INSTALLER_SECTIONS_SECTION1_COM_NGOS_INSTALLER_TYPES_H



#include <buildconfig.h>
#include <com/ngos/installer/main/installer.h>
#include <com/ngos/installer/main/installergui.h>
#include <com/ngos/shared/uefibase/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_installer_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(Installer),    1);
        TEST_ASSERT_EQUALS(sizeof(InstallerGUI), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_INSTALLER_SECTIONS_SECTION1_COM_NGOS_INSTALLER_TYPES_H
