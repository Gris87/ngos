#ifndef COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_ASM_SWITCHTOFIVELEVELPAGING_H
#define COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_ASM_SWITCHTOFIVELEVELPAGING_H



#include <buildconfig.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
CPP_EXTERN_C
void switchToFiveLevelPaging(bad_uint8 *topLevelPaging); // TEST: NO
#endif



#endif // COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_ASM_SWITCHTOFIVELEVELPAGING_H
