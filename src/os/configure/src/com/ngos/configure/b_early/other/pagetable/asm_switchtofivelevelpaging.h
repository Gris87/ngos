#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_ASM_SWITCHTOFIVELEVELPAGING_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_ASM_SWITCHTOFIVELEVELPAGING_H



#include <buildconfig.h>
#include <common/src/com/ngos/shared/common/ngos/linkage.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#if NGOS_BUILD_5_LEVEL_PAGING == OPTION_YES
CPP_EXTERN_C
void switchToFiveLevelPaging(u8 *topLevelPaging); // TEST: NO
#endif



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_ASM_SWITCHTOFIVELEVELPAGING_H
