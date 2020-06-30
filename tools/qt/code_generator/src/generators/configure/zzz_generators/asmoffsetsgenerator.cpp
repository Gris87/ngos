#include "asmoffsetsgenerator.h"

#include <bootparams/bootparams.h>
#include <src/com/ngos/configure/other/kerneldescriptor.h>



#define FILE_PATH "/src/com/ngos/configure/other/asm/generated/asmoffsets.h"



#define ADD_ASM_OFFSET(name, align, type, field) \
        lines.append(QString("#define %1 0x%2").arg(#name, -align, QChar(' ')).arg((quint64)(&((type *)0)->field), 8, 16, QChar('0')));



AsmOffsetsGenerator::AsmOffsetsGenerator()
    : ConfigureGenerator()
{
    // Nothing
}

bool AsmOffsetsGenerator::generate(const QString &path)
{
    QStringList lines;

    ADD_ASM_OFFSET(ASM_OFFSET_BOOT_PARAM_KERNEL_LOCATION, 37, BootParams, header.kernelLocation);
    ADD_ASM_OFFSET(ASM_OFFSET_BOOT_PARAM_KERNEL_SIZE,     37, BootParams, header.kernelSize);

    addOneBlankLine(lines);

    ADD_ASM_OFFSET(ASM_OFFSET_KERNEL_DESCRIPTOR_CONTENT,  37, KernelDescriptor, content);

    return save(path + FILE_PATH, lines);
}



AsmOffsetsGenerator asmOffsetsGeneratorInstance;
