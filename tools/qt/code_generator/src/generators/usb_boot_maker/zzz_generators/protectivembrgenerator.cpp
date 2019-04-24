#include "protectivembrgenerator.h"



#define ASM_PATH  "/assets/binaries/protective_mbr.S"
#define FILE_PATH "/assets/binaries/protective_mbr.bin"



ProtectiveMbrGenerator::ProtectiveMbrGenerator()
    : UsbBootMakerGenerator()
{
    // Nothing
}

bool ProtectiveMbrGenerator::generate(const QString &path)
{
    return true;
}



ProtectiveMbrGenerator protectiveMbrGeneratorInstance;
