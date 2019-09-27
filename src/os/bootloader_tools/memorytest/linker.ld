OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0;



    .cputest_code : { *(.cputest_code) }
    .asm_code     : { *(.asm_code) }
    .text         : { *(.text*) }
    .rodata       : { *(.rodata*) }
    .data         : { *(.data*) }

    .gdt          : { *(.gdt) }



    .ctors        : {
        _ctors_begin = .;
        *(.ctors)
        _ctors_end = .;
    }



    _rela_begin = .;
    .rela.dyn        : { *(.rela.dyn) }
    _rela_end = .;



    .assets       : {
        _assets_begin = .;
        *(.assets)
        _assets_end = .;
    }

    .noinit       : {
        *(.noinit)
        *(.bss*)
    }



    _end = .;



    /DISCARD/     : { *(.dynamic) }
    /DISCARD/     : { *(.dynsym) }
    /DISCARD/     : { *(.dynstr) }
    /DISCARD/     : { *(.hash) }



    . = ASSERT(_start == 0, "Invalid entry point!");
}
