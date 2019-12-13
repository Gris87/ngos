#include "uefilogfile.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES



NgosStatus UefiLogFile::init()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::print(char8 ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(write((u8 *)&ch, sizeof(ch)), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::print(const char8 *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    UEFI_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(write((u8 *)str, strlen(str)), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::println()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::println(char8 ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    UEFI_ASSERT_EXECUTION(print(ch),   NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::println(const char8 *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    UEFI_ASSERT(str, "str is null", NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(print(str),  NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UefiLogFile::noMorePrint()
{

    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return NgosStatus::OK;
}

bool UefiLogFile::canPrint()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    return true;
}

NgosStatus UefiLogFile::write(u8 *data, u64 size)
{
    // UEFI_LT((" | data = 0x%p, size = %u", data, size)); // Commented to avoid bad looking logs

    UEFI_ASSERT(data,     "data is null", NgosStatus::ASSERTION);
    UEFI_ASSERT(size > 0, "size is zero", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}



#endif
