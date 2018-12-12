OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0;

    .configure_code : { *(.configure_code) }
    .asm_code       : { *(.asm_code) }
    .text           : { *(.text*) }
    .rodata         : { *(.rodata*) }
    .data           : { *(.data*) }

    .gdt            : { *(.gdt) }

    .assets         : {
        _assets_begin = .;
        *(.assets)
        _assets_end = .;
    }

    .noinit         : {
        *(.noinit)
        *(.bss)
    }

    _end = .;



    . = ASSERT(_start == 0, "Invalid entry point!");
}
