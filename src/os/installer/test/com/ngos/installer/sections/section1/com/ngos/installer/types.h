#ifndef PARTITIONWIZARD_TEST_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_TYPES_H
#define PARTITIONWIZARD_TEST_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_TYPES_H



#include <buildconfig.h>
#include <uefibase/test/bits64/testengine.h>

#include "src/com/ngos/bootloader_tools/partitionwizard/main/partitionwizard.h"
#include "src/com/ngos/bootloader_tools/partitionwizard/main/partitionwizardgui.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, com_ngos_bootloader_tools_partitionwizard_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(PartitionWizard),    1);
        TEST_ASSERT_EQUALS(sizeof(PartitionWizardGUI), 1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // PARTITIONWIZARD_TEST_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_SECTIONS_SECTION1_COM_NGOS_BOOTLOADER_TOOLS_PARTITIONWIZARD_TYPES_H
