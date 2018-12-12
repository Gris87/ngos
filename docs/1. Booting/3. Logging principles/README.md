NGOS
====

1.3. Logging principles
-----------------------

Logging in NGOS generally implemented via default serial port 0x03F8 (ttyS0).<br/>
So, in order to obtain logs from the machine we just need to connect to ttyS0 serial port.

In most cases UEFI::print() calls printing to this serial port inside, but after calling UEFI::exitBootServices() there is no more such possibility.

That's why we have our own mechanism for printing characters to default serial port. You may check it in [src/os/common/src/bits64/serial/serial.cpp](../../../src/os/common/src/bits64/serial/serial.cpp) file.<br/>
The only thing that we should to do is to call Serial::initConsole() method at the very beginning of the kernel.

You may use Serial::print methods for your own debugging, but it is more preferable to use special macros defined in [src/os/common/src/bits64/log/log.h](../../../src/os/common/src/bits64/log/log.h) file.<br/>
If you check [src/os/common/src/bits64/log/log.h](../../../src/os/common/src/bits64/log/log.h) file you may found that there are several macros like:
* COMMON_LF
* COMMON_LC
* COMMON_LE
* COMMON_LW
* COMMON_LI
* COMMON_LD
* COMMON_LV
* COMMON_LVV
* COMMON_LVVV

These macros just simply printing its log level and the message with attributes.<br/>
It is better to use macros because they can be simply disabled via [NGOS_BUILD_LOG_LEVEL](../../0.%20Intro/3.%20Configuration/README.md#-----------ngos_build_log_level-----------) configuration parameter.

In configuration file you can also see that there are several categories of logging levels.<br/>
You may customize each logging level if you want or just inherit it from the general logging level.

Each category has its own macros for logging.

### Assertions

Another helpful thing that you may found in NGOS source code is an assertions.

Please check [src/os/common/src/bits64/log/assert.h](../../../src/os/common/src/bits64/log/assert.h) file.

There are 3 kind of asserts implemented:
* ASSERT
* TEST_ASSERT
* ASSERT_EXECUTION

ASSERT is mostly used for checking function input parameters and for checking that some stuff working in expected way.<br/>
But TEST_ASSERT is used only for validating values of variables like a inline testing in the source code.

ASSERT is available in Debug mode only.<br/>
TEST_ASSERT is available in Debug mode with the tests only.

Both ASSERT and TEST_ASSERT exits from the current function in case of failure instead of throwing exception because we don't have exception handling yet.

ASSERT_EXECUTION macro equivalent to:

```
    NgosStatus status = command();

    if (status != NgosStatus::OK)
    {
        return NgosStatus::ASSERTION;
    }
```

ASSERT_EXECUTION is available in Debug mode with the tests only. It will simply call command() in another mode.
