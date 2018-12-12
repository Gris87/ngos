OUTPUT_FORMAT("elf64-x86-64", "elf64-x86-64", "elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(_start)

SECTIONS
{
    . = 0;
    .bootsector_code : { *(.bootsector_code) }
    .bootsector_data : { *(.bootsector_data) }

    . = 0x01FE;
    .boot_marker : { *(.boot_marker) }

    _end = .;



    . = ASSERT(_end               == 0x0200, "Bootsector is broken!");
    . = ASSERT(_boot_magic_number == 0x01FE, "Boot magic number 0xAA55 located at the wrong place!");
}
