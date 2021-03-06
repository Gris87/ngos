#include "serial.h"

#include <com/ngos/shared/common/asm/instructions.h>
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



    COMMON_ASSERT_EXECUTION(outb(0x03, DEFAULT_SERIAL_PORT + LCR), NgosStatus::ASSERTION); // 8n1
    COMMON_ASSERT_EXECUTION(outb(0,    DEFAULT_SERIAL_PORT + IER), NgosStatus::ASSERTION); // no interrupt
    COMMON_ASSERT_EXECUTION(outb(0,    DEFAULT_SERIAL_PORT + FCR), NgosStatus::ASSERTION); // no fifo
    COMMON_ASSERT_EXECUTION(outb(0x03, DEFAULT_SERIAL_PORT + MCR), NgosStatus::ASSERTION); // DTR + RTS



    u64 divisor = 115200 / DEFAULT_BAUD;

    u8 c = inb(DEFAULT_SERIAL_PORT + LCR);



    COMMON_ASSERT_EXECUTION(outb(c | DLAB,              DEFAULT_SERIAL_PORT + LCR), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(outb(divisor & 0xFF,        DEFAULT_SERIAL_PORT + DLL), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(outb((divisor >> 8) & 0xFF, DEFAULT_SERIAL_PORT + DLH), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(outb(c & ~DLAB,             DEFAULT_SERIAL_PORT + LCR), NgosStatus::ASSERTION);



    COMMON_LT((""));



    return NgosStatus::OK;
}

void Serial::print(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid infinite loop



    u16 timeout = 0xFFFF;

    while (
           !(inb(DEFAULT_SERIAL_PORT + LSR) & XMTRDY)
           &&
           --timeout
          )
    {
        COMMON_ASSERT_EXECUTION(cpuIdle());
    }

    COMMON_ASSERT_EXECUTION(outb(ch, DEFAULT_SERIAL_PORT + TXR));
}

void Serial::print(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    COMMON_ASSERT(str, "str is null");



    while (*str)
    {
        if (*str == '\n')
        {
            print('\r');
        }

        print(*str);

        ++str;
    }
}

void Serial::println()
{
    // COMMON_LT(("")); // Commented to avoid bad looking logs



    char8 nl[2] = { '\n', 0 };
    print(nl);
}

void Serial::println(char8 ch)
{
    // COMMON_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    char8 buffer[3] = { ch, '\n', 0 };
    print(buffer);
}

void Serial::println(const char8 *str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    COMMON_ASSERT(str, "str is null");



    print(str);

    char8 nl[2] = { '\n', 0 };
    print(nl);
}

i64 Serial::printf(const char8 *format, ...)
{
    // COMMON_LT((" | format = 0x%p", format)); // Commented to avoid infinite loop

    COMMON_ASSERT(format, "format is null", 0);



    va_list args;

    va_start(args, format);
    i64 res = vsprintf(printfBuffer, format, args);
    va_end(args);

    COMMON_TEST_ASSERT(res < (i64)sizeof(printfBuffer), 0);



    println(printfBuffer);



    return res;
}
