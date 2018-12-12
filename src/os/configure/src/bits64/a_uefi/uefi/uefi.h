#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_UEFI_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_UEFI_H



#include <ngos/status.h>

#include "src/bits64/a_uefi/other/uefibootmemorymap.h"
#include "src/bits64/a_uefi/uefi/lib/efisimpletextoutputinterface.h"
#include "src/bits64/a_uefi/uefi/lib/efisystemtable.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



class UEFI
{
public:
    static NgosStatus init(EfiHandle imageHandle, EfiSystemTable *systemTable); // TEST: NO

    static EfiStatus clearScreen(); // TEST: NO
    static void print(char ch); // TEST: NO
    static void print(const char *str); // TEST: NO
    static void println(); // TEST: NO
    static void println(char ch); // TEST: NO
    static void println(const char *str); // TEST: NO
    static i64 printf(const char *format, ...); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

    static EfiStatus createEvent(u32 type, efi_tpl notifyTpl, efi_event_notify notifyFunction, void *notifyContext, EfiEvent *event); // TEST: NO
    static EfiStatus setTimer(EfiEvent event, EfiTimerDelay type, u64 triggerTime); // TEST: NO
    static EfiStatus waitForEvent(u64 numberOfEvents, EfiEvent *event, u64 *index); // TEST: NO
    static EfiStatus closeEvent(EfiEvent event); // TEST: NO

    static EfiStatus allocatePool(EfiMemoryType poolType, u64 size, void **buffer); // TEST: NO
    static EfiStatus freePool(void *buffer); // TEST: NO

    static EfiStatus handleProtocol(EfiHandle handle, EfiGuid *protocol, void **interface); // TEST: NO
    static EfiStatus locateHandle(EfiLocateSearchType searchType, EfiGuid *protocol, void *searchKey, u64 *bufferSize, EfiHandle *buffer); // TEST: NO

    static bool memoryMapHasHeadroom(u64 bufferSize, u64 memoryMapSize, u64 descriptorSize);
    static EfiStatus allocatePages(EfiAllocateType type, EfiMemoryType memoryType, u64 noPages, efi_physical_address *memory); // TEST: NO
    static EfiStatus getMemoryMap(u64 *memoryMapSize, EfiMemoryDescriptor *memoryMap, u64 *mapKey, u64 *descriptorSize, u32 *descriptorVersion); // TEST: NO
    static EfiStatus getMemoryMap(UefiBootMemoryMap *map); // TEST: NO
    static EfiStatus lowAlloc(u64 size, u64 align, void **address); // TEST: NO

    static EfiStatus exitBootServices(u64 mapKey); // TEST: NO

    static EfiHandle getImageHandle(); // TEST: NO

private:
    static EfiHandle                     sImageHandle;
    static EfiSystemTable               *sSystemTable;
    static EfiSimpleTextOutputInterface *sTextOutput;
    static EfiBootServices              *sBootServices;

    static void print(efi_char16 *ch); // TEST: NO
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_UEFI_H
