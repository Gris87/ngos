#include "printf.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/malloc.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/string/string.h>



#define FLAG_NONE    0x00
#define FLAG_LEFT    0x01
#define FLAG_PLUS    0x02
#define FLAG_SPACE   0x04
#define FLAG_SPECIAL 0x08
#define FLAG_ZEROPAD 0x10
#define FLAG_SMALL   0x20
#define FLAG_SIGN    0x40



char8 timestampBuffer[32];
char8 printfBuffer[1024];



i64 parseDigits(const char8 **str)
{
    // COMMON_LT((" | str = 0x%p", str)); // Commented to avoid bad looking logs

    COMMON_ASSERT(str, "str is null", 0);



    i64 res = 0;

    while (**str >= '0' && **str <= '9')
    {
        res = res * 10 + (**str - '0');

        ++(*str);
    }

    return res;
}

char8* number(char8 *str, i64 value, u8 base, i64 size, i64 precision, u8 flags)
{
    // COMMON_LT((" | str = 0x%p, value = %d, base = %u, size = %d, precision = %d, flags = %u", str, value, base, size, precision, flags)); // Commented to avoid infinite loop

    COMMON_ASSERT(str,                     "str is null",        nullptr);
    COMMON_ASSERT(base >= 2 && base <= 16, "Invalid base value", nullptr);



    if (base < 2 || base > 16)
    {
        return nullptr;
    }



    const char8 *digits;

    if (flags & FLAG_SMALL)
    {
        digits = "0123456789abcdef";
    }
    else
    {
        digits = "0123456789ABCDEF";
    }



    char8 pad;

    if (flags & FLAG_LEFT)
    {
        pad = ' ';

        flags &= ~FLAG_ZEROPAD;
    }
    else
    {
        if (flags & FLAG_ZEROPAD)
        {
            pad = '0';
        }
        else
        {
            pad = ' ';
        }
    }



    char8 sign = 0;

    if (flags & FLAG_SIGN)
    {
        if (value < 0)
        {
            sign  = '-';
            value = -value;

            --size;
        }
        else
        if (flags & FLAG_PLUS)
        {
            sign = '+';
            --size;
        }
        else
        if (flags & FLAG_SPACE)
        {
            sign = ' ';
            --size;
        }
    }



    if (flags & FLAG_SPECIAL)
    {
        if (base == 16)
        {
            size -= 2;
        }
        else
        if (base == 8)
        {
            --size;
        }
    }



    char8 temp[66];

    i64 i = 0;

    if (value == 0)
    {
        temp[0] = '0';
        ++i;
    }
    else
    {
        i64 index;

        if (base == 16 && value < 0)
        {
            temp[i] = digits[(u64)value & 0x0F];
            ++i;

            value = (u64)value >> 4;
        }

        while (value != 0)
        {
            index = value % base;
            value = value / base;

            temp[i] = digits[index];
            ++i;
        }
    }

    if (i > precision)
    {
        precision = i;
    }

    size -= precision;



    if (!(flags & (FLAG_ZEROPAD | FLAG_LEFT)))
    {
        while (size > 0)
        {
            *str = ' ';
            ++str;

            --size;
        }
    }



    if (sign)
    {
        *str = sign;
        ++str;
    }



    if (flags & FLAG_SPECIAL)
    {
        if (base == 8)
        {
            *str = '0';
            ++str;
        }
        else
        if (base == 16)
        {
            *str = '0';
            ++str;

            if (flags & FLAG_SMALL)
            {
                *str = 'x';
                ++str;
            }
            else
            {
                *str = 'X';
                ++str;
            }
        }
    }



    if (!(flags & FLAG_LEFT))
    {
        while (size > 0)
        {
            *str = pad;
            ++str;

            --size;
        }
    }



    while (precision > i)
    {
        *str = '0';
        ++str;

        --precision;
    }

    while (i > 0)
    {
        --i;

        *str = temp[i];
        ++str;
    }

    while (size > 0)
    {
        *str = ' ';
        ++str;

        --size;
    }



    return str;
}

i64 vsprintf(char8 *buffer, const char8 *format, va_list args)
{
    // COMMON_LT((" | buffer = 0x%p, format = 0x%p, args = ...", buffer, format)); // Commented to avoid infinite loop

    COMMON_ASSERT(buffer, "buffer is null", 0);
    COMMON_ASSERT(format, "format is null", 0);



    char8 *str;

    for (str = buffer; *format; ++format) // Ignore CppForVerifier
    {
        if (*format != '%')
        {
            *str = *format;
            ++str;

            continue;
        }



        u8 flags = FLAG_NONE;

        do
        {
            ++format;

            switch (*format)
            {
                case '-':
                {
                    flags |= FLAG_LEFT;

                    continue;
                }
                break;

                case '+':
                {
                    flags |= FLAG_PLUS;

                    continue;
                }
                break;

                case ' ':
                {
                    flags |= FLAG_SPACE;

                    continue;
                }
                break;

                case '#':
                {
                    flags |= FLAG_SPECIAL;

                    continue;
                }
                break;

                case '0':
                {
                    flags |= FLAG_ZEROPAD;

                    continue;
                }
                break;

                default:
                {
                    // Nothing
                }
                break;
            }

            break;
        } while(true);



        i64 fieldWidth = -1;

        if (*format >= '0' && *format <= '9')
        {
            fieldWidth = parseDigits(&format);
        }
        else
        if (*format == '*')
        {
            ++format;

            // Take fieldWidth from the arguments
            fieldWidth = va_arg(args, i32);

            if (fieldWidth < 0)
            {
                fieldWidth =  -fieldWidth;
                flags      |= FLAG_LEFT;
            }
        }



        i64 precision = -1;

        if (*format == '.')
        {
            ++format;

            if (*format >= '0' && *format <= '9')
            {
                precision = parseDigits(&format);
            }
            else
            if (*format == '*')
            {
                ++format;

                // Take precision from the arguments
                precision = va_arg(args, i32);

                if (precision < 0)
                {
                    precision = 0;
                }
            }
        }



        char8 qualifier = 0;

        if (*format == 'h' || *format == 'l' || *format == 'L')
        {
            qualifier = *format;
            ++format;

            if (qualifier == 'l' && *format == 'l')
            {
                ++format;
            }
        }



        u8 base = 10;

        switch (*format)
        {
            case 'c':
            {
                --fieldWidth;

                if (!(flags & FLAG_LEFT))
                {
                    while (fieldWidth > 0)
                    {
                        *str = ' ';
                        ++str;

                        --fieldWidth;
                    }
                }

                if (qualifier == 'l')
                {
                    *str = (char16)va_arg(args, i32);
                }
                else
                {
                    *str = (char8)va_arg(args, i32);
                }

                ++str;

                while (fieldWidth > 0)
                {
                    *str = ' ';
                    ++str;

                    --fieldWidth;
                }

                continue;
            }
            break;

            case 's':
            {
                if (qualifier == 'l')
                {
                    const char16 *str2   = va_arg(args, char16 *);
                    i64           length = strnlen(str2, precision);

                    if (!(flags & FLAG_LEFT))
                    {
                        while (fieldWidth > length)
                        {
                            *str = ' ';
                            ++str;

                            --fieldWidth;
                        }
                    }

                    for (i64 i = 0; i < length; ++i)
                    {
                        *str = *str2;
                        ++str;
                        ++str2;
                    }

                    while (fieldWidth > length)
                    {
                        *str = ' ';
                        ++str;

                        --fieldWidth;
                    }
                }
                else
                {
                    const char8 *str2   = va_arg(args, char8 *);
                    i64          length = strnlen(str2, precision);

                    if (!(flags & FLAG_LEFT))
                    {
                        while (fieldWidth > length)
                        {
                            *str = ' ';
                            ++str;

                            --fieldWidth;
                        }
                    }

                    for (i64 i = 0; i < length; ++i)
                    {
                        *str = *str2;
                        ++str;
                        ++str2;
                    }

                    while (fieldWidth > length)
                    {
                        *str = ' ';
                        ++str;

                        --fieldWidth;
                    }
                }

                continue;
            }
            break;

            case 'p':
            {
                if (fieldWidth == -1)
                {
                    fieldWidth =  2 * sizeof(void *);
                    flags      |= FLAG_ZEROPAD;
                }

                str = number(str, (u64)va_arg(args, void *), 16, fieldWidth, precision, flags);

                continue;
            }
            break;

            case '%':
            {
                *str = '%';
                ++str;

                continue;
            }
            break;

            case 'o':
            {
                base = 8;
            }
            break;

            case 'x':
            {
                base = 16;

                flags |= FLAG_SMALL;
            }
            break;

            case 'X':
            {
                base = 16;
            }
            break;

            case 'd':
            case 'i':
            {
                flags |= FLAG_SIGN;
            }
            break;

            case 'u':
            {
                // Nothing
            }
            break;

            default:
            {
                *str = '%';
                ++str;

                if (*format)
                {
                    *str = *format;
                    ++str;
                }
                else
                {
                    --format;
                }

                continue;
            }
            break;
        }



        i64 value;

        if (qualifier == 'l')
        {
            value = va_arg(args, u64);
        }
        else
        if (qualifier == 'h')
        {
            value = (u16)va_arg(args, i32);

            if (flags & FLAG_SIGN)
            {
                value = (i16)value;
            }
        }
        else
        {
            if (flags & FLAG_SIGN)
            {
                value = va_arg(args, i32);
            }
            else
            {
                value = va_arg(args, u32);
            }
        }

        str = number(str, value, base, fieldWidth, precision, flags);
    }

    *str = 0;



    return str - buffer;
}

i64 sprintf(char8 *buffer, const char8 *format, ...)
{
    // COMMON_LT((" | buffer = 0x%p, format = 0x%p", buffer, format)); // Commented to avoid too frequent logs

    COMMON_ASSERT(buffer, "buffer is null", 0);
    COMMON_ASSERT(format, "format is null", 0);



    va_list args;

    va_start(args, format);
    i64 res = vsprintf(buffer, format, args);
    va_end(args);

    return res;
}

char8* vmprintf(const char8 *format, va_list args)
{
    // COMMON_LT((" | format = 0x%p, args = ...", format)); // Commented to avoid infinite loop

    COMMON_ASSERT(format, "format is null", nullptr);



    char8 buffer[1024];



    i64 len = vsprintf(buffer, format, args);

    COMMON_TEST_ASSERT(len < (i64)sizeof(buffer), nullptr);



    u64 size = (len + 1) * sizeof(char8);

    char8 *res = (char8 *)malloc(size);
    COMMON_TEST_ASSERT(res != nullptr, nullptr);

    memcpy(res, buffer, size);



    return res;
}

char8* mprintf(const char8 *format, ...)
{
    // COMMON_LT((" | format = 0x%p", format)); // Commented to avoid too frequent logs

    COMMON_ASSERT(format, "format is null", nullptr);



    va_list args;

    va_start(args, format);
    char8 *res = vmprintf(format, args);
    va_end(args);

    return res;
}
