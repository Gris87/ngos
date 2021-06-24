#include "elfspecverifier.h"                                                                                                                                                                             // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <QDebug>                                                                                                                                                                                          // Colorize: green
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
#define ELF_SPECIFICATION_URL "https://www.uclibc.org/docs/elf-64-gen.pdf" // Version 1.5                                                                                                          // Colorize: green
#define ELF_PDF               "elf.pdf"                                                                                                                                                                  // Colorize: green
#define ELF_TXT               "elf.txt"                                                                                                                                                                  // Colorize: green
                                                                                                                                                                                                          // Colorize: green
#define ELF_HEADER_H "src/os/shared/common/src/com/ngos/shared/common/elf/header.h"                                                                                                                      // Colorize: green
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
    Q_ASSERT(thread != nullptr);                                                                                                                                                                                    // Colorize: green
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
        QFile file(tempDir.path() + "/" + ELF_PDF);                                                                                                                                                         // Colorize: green
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
        process.start("pdftotext", QStringList() << ELF_PDF << ELF_TXT);                                                                                                                             // Colorize: green
        process.waitForFinished(-1);                                                                                                                                                                    // Colorize: green
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
    checkElfHeader(thread, specContent);                                                                                                                                                                 // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
void ElfSpecVerifier::checkElfHeader(SpecVerifyThread *thread, const QString &specContent)                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    Q_ASSERT(thread      != nullptr);                                                                                                                                                                    // Colorize: green
    Q_ASSERT(specContent != "");                                                                                                                                                                         // Colorize: green



    QString headerText = "typedef struct\n"
                        "{\n"
                        "unsigned char\n"
                        "Elf64_Half\n"
                        "Elf64_Half\n"
                        "Elf64_Word\n"
                        "Elf64_Addr\n"
                        "Elf64_Off\n"
                        "Elf64_Off\n"
                        "Elf64_Word\n"
                        "Elf64_Half\n"
                        "Elf64_Half\n"
                        "Elf64_Half\n"
                        "Elf64_Half\n"
                        "Elf64_Half\n"
                        "Elf64_Half\n"
                        "} Elf64_Ehdr;\n"
                        "Figure 2. ELF-64 Header\n"
                        "\n"
                        "e_ident[16];\n"
                        "e_type;\n"
                        "e_machine;\n"
                        "e_version;\n"
                        "e_entry;\n"
                        "e_phoff;\n"
                        "e_shoff;\n"
                        "e_flags;\n"
                        "e_ehsize;\n"
                        "e_phentsize;\n"
                        "e_phnum;\n"
                        "e_shentsize;\n"
                        "e_shnum;\n"
                        "e_shstrndx;";



    // Check that specification contains required text
    {
        if (!specContent.contains(headerText))
        {
            thread->addError("ELF header specification didn't match with the stored one");

            return;
        }
    }



    QStringList lines = headerText.split('\n');
    qint64      i     = 0;



    // Skip lines
    {
        while (i < lines.size() && lines.at(i) != "{")
        {
            ++i;
        }

        if (i >= lines.size())
        {
            thread->addError("Failed to parse ELF header specification");

            return;
        }

        ++i;
    }



    QStringList fieldTypes;

    // Get field types
    {
        while (i < lines.size() && lines.at(i) != "} Elf64_Ehdr;")
        {
            fieldTypes.append(lines.at(i));

            ++i;
        }

        if (i >= lines.size())
        {
            thread->addError("Failed to parse ELF header specification");

            return;
        }

        ++i;

        if (
            i >= lines.size() - 1
            ||
            lines.at(i) != "Figure 2. ELF-64 Header"
            ||
            lines.at(i + 1) != ""
           )
        {
            thread->addError("Failed to parse ELF header specification");

            return;
        }

        i += 2;
    }



    QStringList fieldNames;

    // Get field names
    {
        while (i < lines.size())
        {
            fieldNames.append(lines.at(i));

            ++i;
        }
    }



    if (fieldTypes.size() != fieldNames.size())
    {
        thread->addError("Failed to parse ELF header specification");

        return;
    }



    QHash<QString, QString> elfFieldNamesToNgosFieldNames; // ELF field name => NGOS field name

    // Fill elfFieldNamesToNgosFieldNames
    {
        elfFieldNamesToNgosFieldNames.insert("e_ident[16]", "identification");
        elfFieldNamesToNgosFieldNames.insert("e_type",      "type");
        elfFieldNamesToNgosFieldNames.insert("e_machine",   "machine");
        elfFieldNamesToNgosFieldNames.insert("e_version",   "version");
        elfFieldNamesToNgosFieldNames.insert("e_entry",     "entryPoint");
        elfFieldNamesToNgosFieldNames.insert("e_phoff",     "programHeaderTableOffset");
        elfFieldNamesToNgosFieldNames.insert("e_shoff",     "sectionHeaderTableOffset");
        elfFieldNamesToNgosFieldNames.insert("e_flags",     "flags");
        elfFieldNamesToNgosFieldNames.insert("e_ehsize",    "headerSize");
        elfFieldNamesToNgosFieldNames.insert("e_phentsize", "programHeaderTableEntrySize");
        elfFieldNamesToNgosFieldNames.insert("e_phnum",     "programHeaderTableEntryCount");
        elfFieldNamesToNgosFieldNames.insert("e_shentsize", "sectionHeaderTableEntrySize");
        elfFieldNamesToNgosFieldNames.insert("e_shnum",     "sectionHeaderTableEntryCount");
        elfFieldNamesToNgosFieldNames.insert("e_shstrndx",  "sectionHeaderTableNamesIndex");
    }



    QStringList headerLines;

    // Prepare lines for comparing with source code
    {
        headerLines.append("struct ElfHeader");
        headerLines.append("{");

        for (i = 0; i < fieldTypes.size(); ++i)
        {
            QString type = mElfTypeToNgosTypeMap.value(fieldTypes.at(i), "");

            if (type == "")
            {
                thread->addError(QString("Failed to convert ELF type: %1").arg(fieldTypes.at(i)));

                return;
            }



            QString fieldName = fieldNames.at(i);

            if (!fieldName.endsWith(';'))
            {
                thread->addError(QString("Unexpected ELF field name: %1").arg(fieldName));

                return;
            }

            fieldName.remove(fieldName.length() - 1, 1);



            QString name = elfFieldNamesToNgosFieldNames.value(fieldName, "");

            if (name == "")
            {
                thread->addError(QString("Failed to convert ELF field name: %1").arg(fieldName));

                return;
            }



            headerLines.append(QString("    %1 %2;").arg(type, -23, QChar(' ')).arg(name));
        }

        headerLines.append("};");
    }



    // Replace well known types for fields
    {
        headerLines.replaceInStrings("    u8                      identification;", "    ElfHeaderIdentification identification;");
        headerLines.replaceInStrings("    u16                     type;",           "    ElfType                 type;");
        headerLines.replaceInStrings("    u16                     machine;",        "    ElfMachine              machine;");
        headerLines.replaceInStrings("    u32                     version;",        "    ElfVersion              version;");
    }



    if (!checkLinesInFile(headerLines, thread->getPath() + "/" + ELF_HEADER_H))
    {
        thread->addError("Failed to check ELF header with specifications");
    }
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
ElfSpecVerifier elfSpecVerifierInstance;                                                                                                                                                                 // Colorize: green
