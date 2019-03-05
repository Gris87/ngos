OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0xFFFFFFFF80000000;

    .kernel_code : AT(0) { *(.kernel_code) }
    .asm_code    :       { *(.asm_code) }
    .text        :       { *(.text*) }
    .rodata      :       { *(.rodata*) }
    .data        :       { *(.data*) }

    . = ALIGN((1 << 12));
    .pagetable   :       { *(.pagetable) }
    . = ALIGN((1 << 12));

    .gdt         :       { *(.gdt) }
    .idt         :       { *(.idt) }

    .assets      :       {
        _assets_begin = .;
        *(.assets)
        _assets_end = .;
    }

    . = ALIGN(64);
    .stack       :       {
        *(.stack)
        _stack_begin = .;
    }

    .bss         :       {
        _bss_begin = .;
        *(.bss)
        _bss_end = .;
    }

    .brk         :       {
        _brk_begin = .;
        . += 64 * 1024;
        _brk_end = .;
    }

    _end = .;



    . = ASSERT(_start == 0xFFFFFFFF80000000, "Invalid entry point!");
}
