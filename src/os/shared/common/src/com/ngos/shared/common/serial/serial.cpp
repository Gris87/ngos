#include "serial.h"

#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>



#define DEFAULT_SERIAL_PORT 0x03F8 // ttyS0

#define XMTRDY 0x20
#define DLAB   0x80

#define TXR 0 // Transmit register (WRITE)
#define RXR 0 // Receive register  (READ)
#define IER 1 // Interrupt Enable
#define IIR 2 // Interrupt ID
#define FCR 2 // FIFO control
#define LCR 3 // Line control
#define MCR 4 // Modem control
#define LSR 5 // Line Status
#define MSR 6 // Modem Status
#define DLL 0 // Divisor Latch Low
#define DLH 1 // Divisor latch High

#define DEFAULT_BAUD 9600



NgosStatus Serial::initConsole()
{
    // COMMON_LT(("")); // Commented to avoid error because serial console is uninitialized



    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + LCR, 0x03), NgosStatus::ASSERTION); // 8n1
    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + IER, 0x00), NgosStatus::ASSERTION); // no interrupt
    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + FCR, 0x00), NgosStatus::ASSERTION); // no fifo
    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + MCR, 0x03), NgosStatus::ASSERTION); // DTR + RTS



    u64 divisor = 115200 / DEFAULT_BAUD;

    u8 c = AsmUtils::inb(DEFAULT_SERIAL_PORT + LCR);



    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + LCR, c | DLAB),              NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + DLL, divisor & 0xFF),        NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + DLH, (divisor >> 8) & 0xFF), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + LCR, c & ~DLAB),             NgosStatus::ASSERTION);



    COMMON_LT((""));



    return NgosStatus::OK;
}

NgosStatus Serial::print(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid infinite loop



    u16 timeout = 0xFFFF;

    while (
           (AsmUtils::inb(DEFAULT_SERIAL_PORT + LSR) & XMTRDY) == 0
           &&
           timeout > 0
          )
    {
        COMMON_ASSERT_EXECUTION(AsmUtils::cpuIdle(), NgosStatus::ASSERTION);

        --timeout;
    }

    COMMON_ASSERT_EXECUTION(AsmUtils::outb(DEFAULT_SERIAL_PORT + TXR, ch), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Serial::print(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    COMMON_ASSERT(str != nullptr, "str is null", NgosStatus::ASSERTION);



    while (*str != 0)
    {
        if (*str == '\n')
        {
            COMMON_ASSERT_EXECUTION(print('\r'), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(print(*str), NgosStatus::ASSERTION);

        ++str;
    }



    return NgosStatus::OK;
}

NgosStatus Serial::println()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(print('\r'), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Serial::println(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    COMMON_ASSERT_EXECUTION(print(ch),   NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(print('\r'), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Serial::println(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    COMMON_ASSERT(str != nullptr, "str is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(print(str),  NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(print('\r'), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(print('\n'), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

i64 Serial::printf(const char8 *format, ...)
{
    // COMMON_LT((" | format = 0x%p", format)); // Commented to avoid infinite loop

    COMMON_ASSERT(format != nullptr, "format is null", 0);



    va_list args;

    va_start(args, format);
    i64 res = vsprintf(printfBuffer, format, args);
    va_end(args);

    COMMON_TEST_ASSERT(res < (i64)sizeof(printfBuffer), 0);



    COMMON_ASSERT_EXECUTION(println(printfBuffer), 0);



    return res;
}
