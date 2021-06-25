#include "elfspecverifier.h"                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDebug>                                                                                                                                                                                        // Colorize: green
#include <QEventLoop>                                                                                                                                                                                    // Colorize: green
#include <QFile>                                                                                                                                                                                         // Colorize: green
#include <QNetworkAccessManager>                                                                                                                                                                         // Colorize: green
#include <QNetworkReply>                                                                                                                                                                                 // Colorize: green
#include <QNetworkRequest>                                                                                                                                                                               // Colorize: green
#include <QProcess>                                                                                                                                                                                      // Colorize: green
#include <QTemporaryDir>                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define ELF_SPECIFICATION_URL "https://www.uclibc.org/docs/elf-64-gen.pdf" // Version 1.5                                                                                                                // Colorize: green
#define ELF_PDF               "elf.pdf"                                                                                                                                                                  // Colorize: green
#define ELF_TXT               "elf.txt"                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#define ELF_HEADER_H                "src/os/shared/common/src/com/ngos/shared/common/elf/header.h"                                                                                                                      // Colorize: green
#define ELF_HEADER_IDENTIFICATION_H "src/os/shared/common/src/com/ngos/shared/common/elf/headeridentification.h"                                                                                                                      // Colorize: green
#define ELF_CLASS_H                 "src/os/shared/common/src/com/ngos/shared/common/elf/class.h"                                                                                                                      // Colorize: green
#define ELF_DATA_H                  "src/os/shared/common/src/com/ngos/shared/common/elf/data.h"                                                                                                                      // Colorize: green
#define ELF_FILE_VERSION_H          "src/os/shared/common/src/com/ngos/shared/common/elf/fileversion.h"                                                                                                                      // Colorize: green
#define ELF_VERSION_H               "src/os/shared/common/src/com/ngos/shared/common/elf/version.h"                                                                                                                      // Colorize: green
#define ELF_OS_ABI_H                "src/os/shared/common/src/com/ngos/shared/common/elf/osabi.h"                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
ElfSpecVerifier::ElfSpecVerifier()                                                                                                                                                                       // Colorize: green
    : SpecVerifier()                                                                                                                                                                                     // Colorize: green
    , mElfTypeToNgosTypeMap()                                                                                                                                                                            // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Addr",    "u64");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Off",     "u64");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Half",    "u16");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Word",    "u32");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Sword",   "i32");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Xword",   "u64");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("Elf64_Sxword",  "i64");                                                                                                                                                // Colorize: green
    mElfTypeToNgosTypeMap.insert("unsigned char", "u8");                                                                                                                                                 // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::verify(SpecVerifyThread *thread)                                                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread != nullptr);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QTemporaryDir tempDir;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Create temporary directory                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!tempDir.isValid())                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to create temporary directory for ELF specification");                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Download specification                                                                                                                                                                            // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QNetworkRequest request;                                                                                                                                                                         // Colorize: green
        request.setUrl(QUrl(ELF_SPECIFICATION_URL));                                                                                                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QNetworkAccessManager  manager;                                                                                                                                                                  // Colorize: green
        QNetworkReply         *reply = manager.get(request);                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QEventLoop waitLoop;                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QObject::connect(reply, SIGNAL(finished()),                                 &waitLoop, SLOT(quit()));                                                                                            // Colorize: green
        QObject::connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), &waitLoop, SLOT(quit()));                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        waitLoop.exec();                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (statusCode.toInt() != 200)                                                                                                                                                                   // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError(QString("Failed to get ELF specification from: %1").arg(ELF_SPECIFICATION_URL));                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            delete reply;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QByteArray content = reply->readAll();                                                                                                                                                           // Colorize: green
        delete reply;                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        QFile file(tempDir.path() + "/" + ELF_PDF);                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (!file.open(QIODevice::WriteOnly))                                                                                                                                                            // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to create temporary file for ELF specification");                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        file.write(content);                                                                                                                                                                             // Colorize: green
        file.close();                                                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Convert PDF to text                                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QProcess process;                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        process.setWorkingDirectory(tempDir.path());                                                                                                                                                     // Colorize: green
        process.start("pdftotext", QStringList() << ELF_PDF << ELF_TXT);                                                                                                                                 // Colorize: green
        process.waitForFinished(-1);                                                                                                                                                                     // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString specContent;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Read specification text                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        QFile file(tempDir.path() + "/" + ELF_TXT);                                                                                                                                                      // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (!file.open(QIODevice::ReadOnly))                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to open ELF specification");                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        specContent = QString::fromUtf8(file.readAll());                                                                                                                                                 // Colorize: green
        file.close();                                                                                                                                                                                    // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Replace some unicode characters                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        specContent.replace(QChar(0x2018), QChar('\'')); // Replace left single quotation mark                                                                                                           // Colorize: green
        specContent.replace(QChar(0x2019), QChar('\'')); // Replace right double quotation mark                                                                                                          // Colorize: green
        specContent.replace(QChar(0x201C), QChar('\"')); // Replace left double quotation mark                                                                                                           // Colorize: green
        specContent.replace(QChar(0x201D), QChar('\"')); // Replace right double quotation mark                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    checkWithSpecification(thread, specContent);                                                                                                                                                         // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::checkWithSpecification(SpecVerifyThread *thread, const QString &specContent)                                                                                                       // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread      != nullptr);                                                                                                                                                                    // Colorize: green
    Q_ASSERT(specContent != "");                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString versionText;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init versionText                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        versionText = "ELF-64 Object File Format\n"                                                                                                                                                      // Colorize: green
                    "Version 1.5 Draft 2\n"                                                                                                                                                              // Colorize: green
                    "May 27, 1998";                                                                                                                                                                      // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that specification contains required text                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!specContent.contains(versionText))                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("ELF specification version didn't match with the stored one");                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    checkElfHeader(thread, specContent);                                                                                                                                                                 // Colorize: green
    checkElfHeaderIdentification(thread, specContent);                                                                                                                                                                 // Colorize: green
    checkElfClass(thread, specContent);                                                                                                                                                                 // Colorize: green
    checkElfData(thread, specContent);                                                                                                                                                                 // Colorize: green
    checkElfFileVersion(thread, specContent);                                                                                                                                                                 // Colorize: green
    checkElfVersion(thread, specContent);                                                                                                                                                                 // Colorize: green
    checkElfOsAbi(thread, specContent);                                                                                                                                                                 // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::checkElfHeader(SpecVerifyThread *thread, const QString &specContent)                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread      != nullptr);                                                                                                                                                                    // Colorize: green
    Q_ASSERT(specContent != "");                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString headerText;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init headerText                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        headerText = "typedef struct\n"                                                                                                                                                                  // Colorize: green
                    "{\n"                                                                                                                                                                                // Colorize: green
                    "unsigned char\n"                                                                                                                                                                    // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Word\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Addr\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Off\n"                                                                                                                                                                        // Colorize: green
                    "Elf64_Off\n"                                                                                                                                                                        // Colorize: green
                    "Elf64_Word\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "Elf64_Half\n"                                                                                                                                                                       // Colorize: green
                    "} Elf64_Ehdr;\n"                                                                                                                                                                    // Colorize: green
                    "Figure 2. ELF-64 Header\n"                                                                                                                                                          // Colorize: green
                    "\n"                                                                                                                                                                                 // Colorize: green
                    "e_ident[16];\n"                                                                                                                                                                     // Colorize: green
                    "e_type;\n"                                                                                                                                                                          // Colorize: green
                    "e_machine;\n"                                                                                                                                                                       // Colorize: green
                    "e_version;\n"                                                                                                                                                                       // Colorize: green
                    "e_entry;\n"                                                                                                                                                                         // Colorize: green
                    "e_phoff;\n"                                                                                                                                                                         // Colorize: green
                    "e_shoff;\n"                                                                                                                                                                         // Colorize: green
                    "e_flags;\n"                                                                                                                                                                         // Colorize: green
                    "e_ehsize;\n"                                                                                                                                                                        // Colorize: green
                    "e_phentsize;\n"                                                                                                                                                                     // Colorize: green
                    "e_phnum;\n"                                                                                                                                                                         // Colorize: green
                    "e_shentsize;\n"                                                                                                                                                                     // Colorize: green
                    "e_shnum;\n"                                                                                                                                                                         // Colorize: green
                    "e_shstrndx;";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that specification contains required text                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!specContent.contains(headerText))                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("ELF header specification didn't match with the stored one");                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList lines = headerText.split('\n');                                                                                                                                                          // Colorize: green
    qint64      i     = 0;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Skip lines                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (lines.at(1) != "{")                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to parse ELF header specification");                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        i = 2;                                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList fieldTypes;                                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get field types                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        while (i < lines.size() && lines.at(i) != "} Elf64_Ehdr;")                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            fieldTypes.append(lines.at(i));                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            ++i;                                                                                                                                                                                         // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (i >= lines.size())                                                                                                                                                                           // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to parse ELF header specification");                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        ++i;                                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            i >= lines.size() - 1                                                                                                                                                                        // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            lines.at(i) != "Figure 2. ELF-64 Header"                                                                                                                                                     // Colorize: green
            ||                                                                                                                                                                                           // Colorize: green
            lines.at(i + 1) != ""                                                                                                                                                                        // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to parse ELF header specification");                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        i += 2;                                                                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList fieldNames;                                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get field names                                                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        while (i < lines.size())                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            fieldNames.append(lines.at(i));                                                                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            ++i;                                                                                                                                                                                         // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (fieldTypes.size() != fieldNames.size())                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        thread->addError("Failed to parse ELF header specification");                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return;                                                                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QHash<QString, QString> elfFieldNamesToNgosFieldNames; // ELF field name => NGOS field name                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Fill elfFieldNamesToNgosFieldNames                                                                                                                                                                // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_ident[16]", "identification");                                                                                                                           // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_type",      "type");                                                                                                                                     // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_machine",   "machine");                                                                                                                                  // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_version",   "version");                                                                                                                                  // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_entry",     "entryPoint");                                                                                                                               // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_phoff",     "programHeaderTableOffset");                                                                                                                 // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_shoff",     "sectionHeaderTableOffset");                                                                                                                 // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_flags",     "flags");                                                                                                                                    // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_ehsize",    "headerSize");                                                                                                                               // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_phentsize", "programHeaderTableEntrySize");                                                                                                              // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_phnum",     "programHeaderTableEntryCount");                                                                                                             // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_shentsize", "sectionHeaderTableEntrySize");                                                                                                              // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_shnum",     "sectionHeaderTableEntryCount");                                                                                                             // Colorize: green
        elfFieldNamesToNgosFieldNames.insert("e_shstrndx",  "sectionHeaderTableNamesIndex");                                                                                                             // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList headerLines;                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Prepare lines for comparing with source code                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        headerLines.append("struct ElfHeader");                                                                                                                                                          // Colorize: green
        headerLines.append("{");                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (i = 0; i < fieldTypes.size(); ++i)                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString type = mElfTypeToNgosTypeMap.value(fieldTypes.at(i), "");                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (type == "")                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                thread->addError(QString("Failed to convert ELF type: %1").arg(fieldTypes.at(i)));                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return;                                                                                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            QString fieldName = fieldNames.at(i);                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (!fieldName.endsWith(';'))                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                thread->addError(QString("Unexpected ELF field name: %1").arg(fieldName));                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return;                                                                                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            fieldName.remove(fieldName.length() - 1, 1);                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            QString name = elfFieldNamesToNgosFieldNames.value(fieldName, "");                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (name == "")                                                                                                                                                                              // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                thread->addError(QString("Failed to convert ELF field name: %1").arg(fieldName));                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return;                                                                                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            headerLines.append(QString("    %1 %2;").arg(type, -23, QChar(' ')).arg(name));                                                                                                              // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        headerLines.append("};");                                                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Replace well known types for fields                                                                                                                                                               // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        headerLines.replaceInStrings("    u8                      identification;", "    ElfHeaderIdentification identification;");                                                                      // Colorize: green
        headerLines.replaceInStrings("    u16                     type;",           "    ElfType                 type;");                                                                                // Colorize: green
        headerLines.replaceInStrings("    u16                     machine;",        "    ElfMachine              machine;");                                                                             // Colorize: green
        headerLines.replaceInStrings("    u32                     version;",        "    ElfVersion              version;");                                                                             // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!checkLinesInFile(headerLines, thread->getPath() + "/" + ELF_HEADER_H))                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        thread->addError("Failed to check ELF header with specification");                                                                                                                              // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::checkElfHeaderIdentification(SpecVerifyThread *thread, const QString &specContent)                                                                                                 // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread      != nullptr);                                                                                                                                                                    // Colorize: green
    Q_ASSERT(specContent != "");                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString identificationText;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init identificationText                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        identificationText = "e_ident identify the file as an ELF object file, and provide information\n"                                                                                                // Colorize: green
                            "about the data representation of the object file structures. The bytes of this\n"                                                                                           // Colorize: green
                            "array that have defined meanings are detailed below. The remaining bytes\n"                                                                                                 // Colorize: green
                            "are reserved for future use, and should be set to zero. Each byte of the\n"                                                                                                 // Colorize: green
                            "array is indexed symbolically using the names in the Table 2.\n"                                                                                                            // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "Table 2. ELF Identification, e_ident\n"                                                                                                                                     // Colorize: green
                            "Name\n"                                                                                                                                                                     // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "Value\n"                                                                                                                                                                    // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "Purpose\n"                                                                                                                                                                  // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_MAG0\n"                                                                                                                                                                  // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "0\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "File identification\n"                                                                                                                                                      // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_MAG1\n"                                                                                                                                                                  // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "1\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_MAG2\n"                                                                                                                                                                  // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "2\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_MAG3\n"                                                                                                                                                                  // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "3\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_CLASS\n"                                                                                                                                                                 // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "4\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "File class\n"                                                                                                                                                               // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_DATA\n"                                                                                                                                                                  // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "5\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "Data encoding\n"                                                                                                                                                            // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_VERSION\n"                                                                                                                                                               // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "6\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "File version\n"                                                                                                                                                             // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_OSABI\n"                                                                                                                                                                 // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "7\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "OS/ABI identification\n"                                                                                                                                                    // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_ABIVERSION\n"                                                                                                                                                            // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "8\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "ABI version\n"                                                                                                                                                              // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_PAD\n"                                                                                                                                                                   // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "9\n"                                                                                                                                                                        // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "Start of padding bytes\n"                                                                                                                                                   // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "EI_NIDENT\n"                                                                                                                                                                // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "16\n"                                                                                                                                                                       // Colorize: green
                            "\n"                                                                                                                                                                         // Colorize: green
                            "Size of e_ident[]";                                                                                                                                                         // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that specification contains required text                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!specContent.contains(identificationText))                                                                                                                                                   // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("ELF header identification specification didn't match with the stored one");                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList lines = identificationText.split('\n');                                                                                                                                                          // Colorize: green
    qint64      i     = 0;                                                                                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Skip lines                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (lines.at(11) != "Purpose" || lines.at(12) != "")                                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("Failed to parse ELF header identification specification");                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        i = 13;                                                                                                                                                                                           // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList fields;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Get fields                                                                                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        while (i < lines.size())                                                                                                                                                                         // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString line = lines.at(i);                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            fields.append(line);                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (line.startsWith("EI_MAG") && line != "EI_MAG0")                                                                                                                                          // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                i += 4;                                                                                                                                                                                                         // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                i += 6;                                                                                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList identificationLines;                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Prepare lines for comparing with source code                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        identificationLines.append("struct ElfHeaderIdentification");                                                                                                                                    // Colorize: green
        identificationLines.append("{");                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        if (                                                                                                                                                                                             // Colorize: green
            fields.at(0) == "EI_MAG0"                                                                                                                                                                    // Colorize: green
            &&                                                                                                                                                                                           // Colorize: green
            fields.at(1) == "EI_MAG1"                                                                                                                                                                    // Colorize: green
            &&                                                                                                                                                                                           // Colorize: green
            fields.at(2) == "EI_MAG2"                                                                                                                                                                    // Colorize: green
            &&                                                                                                                                                                                           // Colorize: green
            fields.at(3) == "EI_MAG3"                                                                                                                                                                    // Colorize: green
           )                                                                                                                                                                                             // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            identificationLines.append("    u32            signature;");                                                                                                                                     // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        for (qint64 i = 4; i < fields.size(); ++i)                                                                                                                                                       // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            QString field = fields.at(i);                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            if (field == "EI_CLASS")                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                identificationLines.append("    ElfClass       fileClass;");                                                                                                                                 // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (field == "EI_DATA")                                                                                                                                                                      // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                identificationLines.append("    ElfData        fileData;");                                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (field == "EI_VERSION")                                                                                                                                                                   // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                identificationLines.append("    ElfFileVersion version;");                                                                                                                                   // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (field == "EI_OSABI")                                                                                                                                                                     // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                identificationLines.append("    ElfOsAbi       osAbi;");                                                                                                                                     // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (field == "EI_ABIVERSION")                                                                                                                                                                // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                identificationLines.append("    u8             abiVersion;");                                                                                                                                // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (field == "EI_PAD")                                                                                                                                                                       // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                identificationLines.append("    u8             __pad[7];");                                                                                                                                  // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
            else                                                                                                                                                                                         // Colorize: green
            if (field != "EI_NIDENT")                                                                                                                                                                    // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                thread->addError(QString("Unknown field found in ELF header identification specification: %1").arg(field));                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                return;                                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        identificationLines.append("} __attribute__((packed));");                                                                                                                                        // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList fileLines = readLinesFromFile(thread->getPath() + "/" + ELF_HEADER_IDENTIFICATION_H);                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!checkLinesInFileLines(identificationLines, fileLines))                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        thread->addError("Failed to check ELF header identification with specification");                                                                                                               // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        return;                                                                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString magicNumberText;                                                                                                                                                                          // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init magicNumberText                                                                                                                                                                           // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        magicNumberText = "e_ident[EI_MAG0] through e_ident[EI_MAG3] contain a \"magic number,\"\n"                                                                                                        // Colorize: green
                            "identifying the file as an ELF object file. They contain the characters '\\x7f',\n"                                                                                          // Colorize: green
                            "'E', 'L', and 'F', respectively.";                                                                                                                                          // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that specification contains required text                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!specContent.contains(magicNumberText))                                                                                                                                                      // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("ELF header magic number specification didn't match with the stored one");                                                                                                  // Colorize: green
            thread->addError(specContent);                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList magicNumberLines;                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Prepare lines for comparing with source code                                                                                                                                                                          // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        magicNumberLines.append("#define ELF_SIGNATURE 0x464C457F // 0x7F + ELF");                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!checkLinesInFileLines(magicNumberLines, fileLines))                                                                                                                                             // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        thread->addError("Failed to check ELF header magic number with specification");                                                                                                                  // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::checkElfClass(SpecVerifyThread *thread, const QString &specContent)
{
    Q_ASSERT(thread      != nullptr);
    Q_ASSERT(specContent != "");



    QString classText;

    // Init classText
    {
        classText = "Table 3. Object File Classes, e_ident[EI_CLASS]\n"
                    "Name\n"
                    "\n"
                    "Value\n"
                    "\n"
                    "Meaning\n"
                    "\n"
                    "ELFCLASS32\n"
                    "\n"
                    "1\n"
                    "\n"
                    "32-bit objects\n"
                    "\n"
                    "ELFCLASS64\n"
                    "\n"
                    "2\n"
                    "\n"
                    "64-bit objects";
    }



    // Check that specification contains required text
    {
        if (!specContent.contains(classText))
        {
            thread->addError("ELF class specification didn't match with the stored one");

            return;
        }
    }
}

void ElfSpecVerifier::checkElfData(SpecVerifyThread *thread, const QString &specContent)
{
    Q_ASSERT(thread      != nullptr);
    Q_ASSERT(specContent != "");



    QString dataText;

    // Init dataText
    {
        dataText = "Table 4. Data Encodings, e_ident[EI_DATA]\n"
                    "Name\n"
                    "\n"
                    "Value\n"
                    "\n"
                    "Meaning\n"
                    "\n"
                    "ELFDATA2LSB\n"
                    "\n"
                    "1\n"
                    "\n"
                    "Object file data structures are littleendian\n"
                    "\n"
                    "ELFDATA2MSB\n"
                    "\n"
                    "2\n"
                    "\n"
                    "Object file data structures are bigendian";
    }



    // Check that specification contains required text
    {
        if (!specContent.contains(dataText))
        {
            thread->addError("ELF data specification didn't match with the stored one");

            return;
        }
    }
}

void ElfSpecVerifier::checkElfFileVersion(SpecVerifyThread *thread, const QString &specContent)                                                                                                          // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread      != nullptr);                                                                                                                                                                    // Colorize: green
    Q_ASSERT(specContent != "");                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString versionText;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init versionText                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        versionText = "e_ident[EI_VERSION] identifies the version of the object file format.\n"                                                                                                          // Colorize: green
                        "Currently, this field has the value EV_CURRENT, which is defined with the\n"                                                                                                    // Colorize: green
                        "value 1.";                                                                                                                                                                      // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that specification contains required text                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!specContent.contains(versionText))                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("ELF file version specification didn't match with the stored one");                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList versionLines;                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Prepare lines for comparing with source code                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        versionLines.append("enum class ElfFileVersion: u8");                                                                                                                                            // Colorize: green
        versionLines.append("{");                                                                                                                                                                        // Colorize: green
        versionLines.append("    NONE    = 0,");                                                                                                                                                         // Colorize: green
        versionLines.append("    CURRENT = 1");                                                                                                                                                          // Colorize: green
        versionLines.append("};");                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!checkLinesInFile(versionLines, thread->getPath() + "/" + ELF_FILE_VERSION_H))                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        thread->addError("Failed to check ELF file version with specification");                                                                                                                         // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::checkElfVersion(SpecVerifyThread *thread, const QString &specContent)                                                                                                              // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread      != nullptr);                                                                                                                                                                    // Colorize: green
    Q_ASSERT(specContent != "");                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QString versionText;                                                                                                                                                                                 // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Init versionText                                                                                                                                                                                  // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        versionText = "e_version identifies the version of the object file format. Currently, this\n"                                                                                                    // Colorize: green
                        "field has the value EV_CURRENT, which is defined with the value 1.";                                                                                                            // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Check that specification contains required text                                                                                                                                                   // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        if (!specContent.contains(versionText))                                                                                                                                                          // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            thread->addError("ELF version specification didn't match with the stored one");                                                                                                              // Colorize: green
                                                                                                                                                                                                         // Colorize: green
            return;                                                                                                                                                                                      // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    QStringList versionLines;                                                                                                                                                                            // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    // Prepare lines for comparing with source code                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        versionLines.append("enum class ElfVersion: u32");                                                                                                                                                // Colorize: green
        versionLines.append("{");                                                                                                                                                                        // Colorize: green
        versionLines.append("    NONE    = 0,");                                                                                                                                                         // Colorize: green
        versionLines.append("    CURRENT = 1");                                                                                                                                                          // Colorize: green
        versionLines.append("};");                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (!checkLinesInFile(versionLines, thread->getPath() + "/" + ELF_VERSION_H))                                                                                                                        // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        thread->addError("Failed to check ELF version with specification");                                                                                                                              // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green

void ElfSpecVerifier::checkElfOsAbi(SpecVerifyThread *thread, const QString &specContent)
{
    Q_ASSERT(thread      != nullptr);
    Q_ASSERT(specContent != "");



    QString osAbiText;

    // Init osAbiText
    {
        osAbiText = "Table 5. Operating System and ABI Identifiers, e_ident[EI_OSABI]\n"
                    "Name\n"
                    "\n"
                    "Value\n"
                    "\n"
                    "Meaning\n"
                    "\n"
                    "ELFOSABI_SYSV\n"
                    "\n"
                    "0\n"
                    "\n"
                    "System V ABI\n"
                    "\n"
                    "ELFOSABI_HPUX\n"
                    "\n"
                    "1\n"
                    "\n"
                    "HP-UX operating system\n"
                    "\n"
                    "ELFOSABI_STANDALONE\n"
                    "\n"
                    "255\n"
                    "\n"
                    "Standalone (embedded)\n"
                    "application";
    }



    // Check that specification contains required text
    {
        if (!specContent.contains(osAbiText))
        {
            thread->addError("ELF OS ABI specification didn't match with the stored one");

            return;
        }
    }
}
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
ElfSpecVerifier elfSpecVerifierInstance;                                                                                                                                                                 // Colorize: green
