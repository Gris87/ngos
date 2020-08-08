#include "pcidatabasegenerator.h"

#include <QFile>
#include <QProcess>
#include <QTemporaryDir>
#include <QTemporaryFile>

#include <com/ngos/devtools/shared/console/console.h>



#define FOLDER_PATH "/src/os/shared/common/src/com/ngos/shared/common/pci/database/generated/"

#define SPECIFICATION_URL "http://fpga-faq.narod.ru/PCI_Rev_30.pdf"



PciDatabaseGenerator::PciDatabaseGenerator()
    : CommonGenerator()
    , mBaseClassTitleRegExp("D\\.\\d+\\. *Base Class [0-9a-fA-F]+h")
{
    // Nothing
}

bool PciDatabaseGenerator::generate(const QString & path)
{
    PciBaseClasses baseClasses;

    if (!obtainBaseClasses(baseClasses))
    {
        return false;
    }

    return generateBaseClasses(path, baseClasses);
}

bool PciDatabaseGenerator::obtainBaseClasses(PciBaseClasses &baseClasses)
{
    QStringList lines;

    if (!prepareSpecification(lines))
    {
        return false;
    }

    return parseSpecification(lines, baseClasses);
}

bool PciDatabaseGenerator::prepareSpecification(QStringList &lines)
{
    QTemporaryFile tempFile;
    QTemporaryDir  tempDir;



    tempFile.open();
    QString tempFilePath = tempFile.fileName();
    tempFile.close();



    QProcess process;
    process.start("wget", QStringList() << "-O" << tempFilePath << SPECIFICATION_URL);
    process.waitForFinished(-1);

    if (process.exitCode() != 0)
    {
        Console::err(QString("Failed to download specification from %1:\n%2").arg(SPECIFICATION_URL).arg(QString::fromUtf8(process.readAllStandardError())));

        return false;
    }



    process.start("pdftohtml", QStringList() << "-s" << "-i" << tempFilePath << tempDir.path() + "/pci.html");
    process.waitForFinished(-1);

    if (process.exitCode() != 0)
    {
        Console::err(QString("Failed to convert PDF file to html:\n%1").arg(QString::fromUtf8(process.readAllStandardError())));

        return false;
    }



    QFile file(tempDir.path() + "/pci-html.html");

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to open file: %1").arg(tempDir.path() + "/pci-html.html"));

        return false;
    }

    QString content = QString::fromUtf8(file.readAll());
    content.replace("&#160;", " "); // Ignore CppSingleCharVerifier
    file.close();



    lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.length() - 1, 1);
        }
    }



    return true;
}

bool PciDatabaseGenerator::parseSpecification(const QStringList &lines, PciBaseClasses &baseClasses)
{
    qint64 i = 0;



    // Search for appendix D in PCI specification
    {
        while (i < lines.length())
        {
            if (lines.at(i).contains("D. Class Codes"))
            {
                break;
            }

            ++i;
        }

        if (i >= lines.length())
        {
            Console::err("Failed to find appendix D in PCI specification");

            return false;
        }
    }



    QList<qint64> ranges;



    // Search for section ranges in appendix D in PCI specification
    {
        ranges.append(i);



        while (i < lines.length())
        {
            if (lines.at(i).contains("E. System Transaction Ordering"))
            {
                break;
            }

            if (mBaseClassTitleRegExp.match(lines.at(i)).hasMatch())
            {
                ranges.append(i);
            }

            ++i;
        }

        if (i >= lines.length())
        {
            Console::err("Failed to find appendix E in PCI specification");

            return false;
        }



        ranges.append(i);
    }



    if (ranges.length() <= 2)
    {
        Console::err("Failed to find section ranges in appendix D in PCI specification");

        return false;
    }



    // Parse base classes with the found section ranges
    {
        for (qint64 j = 2; j < ranges.length(); ++j)
        {
            if (!parseBaseClass(lines, ranges.at(j - 1), ranges.at(j), baseClasses))
            {
                return false;
            }
        }
    }



    // Getting information about whole base class from first section range
    {
        if (!parseBaseClassFallback(lines, ranges.at(0), ranges.at(1), baseClasses))
        {
            return false;
        }
    }



    return true;
}

bool PciDatabaseGenerator::parseBaseClass(const QStringList &lines, qint64 start, qint64 end, PciBaseClasses &baseClasses)
{
    Q_UNUSED(lines);
    Q_UNUSED(start);
    Q_UNUSED(end);
    Q_UNUSED(baseClasses);

    return true;
}

bool PciDatabaseGenerator::parseBaseClassFallback(const QStringList &lines, qint64 start, qint64 end, PciBaseClasses &baseClasses)
{
    Q_UNUSED(lines);
    Q_UNUSED(start);
    Q_UNUSED(end);
    Q_UNUSED(baseClasses);

    return true;
}

bool PciDatabaseGenerator::generateBaseClasses(const QString &path, const PciBaseClasses &baseClasses)
{
    // Iterate over base classes and generate sub classes
    {
        QMapIterator<quint16, PciSubClasses> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint16              baseClassId = it.key();
            const PciSubClasses &subClasses  = it.value();

            if (!generateSubClasses(path, baseClassId, subClasses))
            {
                return false;
            }
        }
    }

    return generateBaseClassesFile(path, baseClasses);
}

bool PciDatabaseGenerator::generateSubClasses(const QString &path, quint16 baseClassId, const PciSubClasses &subClasses)
{
    // Iterate over sub classes and generate interfaces
    {
        QMapIterator<quint16, PciInterfaces> it(subClasses);

        while (it.hasNext())
        {
            it.next();

            quint16              subClassId = it.key();
            const PciInterfaces &interfaces = it.value();

            if (
                interfaces.size() > 1
                ||
                !interfaces.contains(0xFFFF)
               )
            {
                if (!generateInterfacesFile(path, baseClassId, subClassId, interfaces))
                {
                    return false;
                }
            }
        }
    }

    return generateSubClassesFile(path, baseClassId, subClasses);
}

bool PciDatabaseGenerator::generateBaseClassesFile(const QString &path, const PciBaseClasses &baseClasses)
{
    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/log/assert.h>");
        lines.append("#include <com/ngos/shared/common/log/log.h>");
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");

        QMapIterator<quint16, PciSubClasses> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint16 baseClassId = it.key();

            lines.append(QString("#include <com/ngos/shared/common/pci/database/generated/baseclass%1/pcisubclass%1.h>").arg(baseClassId, 2, 16, QChar('0')));
        }

        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciBaseClass
    {
        addThreeBlankLines(lines);



        lines.append("enum class PciBaseClass: u8");
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!baseClasses.contains(0))
        {
            lines.append("    NONE          = 0,");
        }

        QMapIterator<quint16, PciSubClasses> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint16 baseClassId    = it.key();
            QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();

            lines.append(QString("    BASE_CLASS_%1 = 0x%1%2").arg(baseClassIdStr, 2, QChar('0')).arg(it.hasNext() ? "," : "")); // Ignore CppSingleCharVerifier
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciBaseClass baseClass)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToString(PciBaseClass baseClass) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | baseClass = %u\", baseClass)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (baseClass)");
        lines.append("    {");

        if (!baseClasses.contains(0))
        {
            lines.append("        case PciBaseClass::NONE:          return \"NONE\";");
        }

        QMapIterator<quint16, PciSubClasses> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint16 baseClassId    = it.key();
            QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();

            lines.append(QString("        case PciBaseClass::BASE_CLASS_%1: return \"BASE_CLASS_%1\";").arg(baseClassIdStr, 2, QChar('0')));
        }

        lines.append("");
        lines.append("        default: return \"UNKNOWN\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToFullString(PciBaseClass baseClass)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToFullString(PciBaseClass baseClass) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | baseClass = %u\", baseClass)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    static char8 res[21];");
        lines.append("");
        lines.append("    sprintf(res, \"0x%02X (%s)\", (u8)baseClass, enumToString(baseClass));");
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciBaseClass baseClass, u8 subClassId, u8 interfaceId)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToHumanString(PciBaseClass baseClass, u8 subClassId, u8 interfaceId) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | baseClass = %u, subClassId = %u, interfaceId = %u\", baseClass, subClassId, interfaceId)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (baseClass)");
        lines.append("    {");

        QMapIterator<quint16, PciSubClasses> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint16 baseClassId    = it.key();
            QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();

            lines.append(QString("        case PciBaseClass::BASE_CLASS_%1: return enumToHumanString((PciSubClass%1)subClassId, interfaceId);").arg(baseClassIdStr, 2, QChar('0')));
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(path + FOLDER_PATH + "pcibaseclass.h", lines);
}

bool PciDatabaseGenerator::generateSubClassesFile(const QString &path, quint16 baseClassId, const PciSubClasses &subClasses)
{
    QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();

    if (baseClassId < 16)
    {
        baseClassIdStr = "0" + baseClassIdStr; // Ignore CppSingleCharVerifier
    }



    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/log/assert.h>");
        lines.append("#include <com/ngos/shared/common/log/log.h>");
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");

        QMapIterator<quint16, PciInterfaces> it(subClasses);

        while (it.hasNext())
        {
            it.next();

            quint16              subClassId = it.key();
            const PciInterfaces &interfaces = it.value();

            if (
                interfaces.size() > 1
                ||
                !interfaces.contains(0xFFFF)
               )
            {
                lines.append(QString("#include <com/ngos/shared/common/pci/database/generated/baseclass%1/pciinterface%1%2.h>").arg(baseClassId, 2, 16, QChar('0')).arg(subClassId, 2, 16, QChar('0')));
            }
        }

        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciSubClass
    {
        addThreeBlankLines(lines);



        lines.append(QString("enum class PciSubClass%1: u8").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!subClasses.contains(0))
        {
            lines.append("    NONE         = 0,");
        }

        QMapIterator<quint16, PciInterfaces> it(subClasses);

        while (it.hasNext())
        {
            it.next();

            quint16 subClassId    = it.key();
            QString subClassIdStr = QString::number(subClassId, 16).toUpper();

            lines.append(QString("    SUB_CLASS_%1 = 0x%1%2").arg(subClassIdStr, 2, QChar('0')).arg(it.hasNext() ? "," : "")); // Ignore CppSingleCharVerifier
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciSubClass subClass)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciSubClass%1 class%1) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | class%1 = %u\", class%1)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (class%1)").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("    {");

        if (!subClasses.contains(0))
        {
            lines.append(QString("        case PciSubClass%1::NONE:         return \"NONE\";").arg(baseClassIdStr, 2, QChar('0')));
        }

        QMapIterator<quint16, PciInterfaces> it(subClasses);

        while (it.hasNext())
        {
            it.next();

            quint16 subClassId    = it.key();
            QString subClassIdStr = QString::number(subClassId, 16).toUpper();

            lines.append(QString("        case PciSubClass%1::SUB_CLASS_%2: return \"SUB_CLASS_%2\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        }

        lines.append("");
        lines.append("        default: return \"UNKNOWN\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToFullString(PciSubClass subClass)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToFullString(PciSubClass%1 class%1) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | class%1 = %u\", class%1)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append("    static char8 res[20];");
        lines.append("");
        lines.append(QString("    sprintf(res, \"%2 (%s)\", (u8)class%1, enumToString(class%1));").arg(baseClassIdStr, 2, QChar('0')).arg("0x%02X"));
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciSubClass subClass, u8 interfaceId)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciSubClass%1 class%1, u8 interfaceId) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | class%1 = %u, interfaceId = %u\", class%1, interfaceId)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (class%1)").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("    {");

        QMapIterator<quint16, PciInterfaces> it(subClasses);

        while (it.hasNext())
        {
            it.next();

            quint16              subClassId = it.key();
            const PciInterfaces &interfaces = it.value();

            QString subClassIdStr = QString::number(subClassId, 16).toUpper();

            if (
                interfaces.size() > 1
                ||
                !interfaces.contains(0xFFFF)
               )
            {
                lines.append(QString("        case PciSubClass%1::SUB_CLASS_%2: return enumToHumanString((PciInterface%1%2)interfaceId);").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
            }
            else
            {
                lines.append(QString("        case PciSubClass%1::SUB_CLASS_%2: return \"%3\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg(interfaces.value(0xFFFF)));
            }
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(QString(path + FOLDER_PATH + "baseclass%1/pcisubclass%1.h").arg(baseClassId, 2, 16, QChar('0')), lines);
}

bool PciDatabaseGenerator::generateInterfacesFile(const QString &path, quint16 baseClassId, quint16 subClassId, const PciInterfaces &interfaces)
{
    QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();
    QString subClassIdStr  = QString::number(subClassId,  16).toUpper();

    if (baseClassId < 16)
    {
        baseClassIdStr = "0" + baseClassIdStr; // Ignore CppSingleCharVerifier
    }

    if (subClassId < 16)
    {
        subClassIdStr = "0" + subClassIdStr; // Ignore CppSingleCharVerifier
    }



    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/log/assert.h>");
        lines.append("#include <com/ngos/shared/common/log/log.h>");
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");
        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciInterface
    {
        addThreeBlankLines(lines);



        lines.append(QString("enum class PciInterface%1%2: u8").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!interfaces.contains(0))
        {
            lines.append("    NONE         = 0,");
        }

        QMapIterator<quint16, QString> it(interfaces);

        while (it.hasNext())
        {
            it.next();

            quint16 interfaceId = it.key();

            if (interfaceId != 0xFFFF)
            {
                QString interfaceIdStr = QString::number(interfaceId, 16).toUpper();

                lines.append(QString("    INTERFACE_%1 = 0x%1%2").arg(interfaceIdStr, 2, QChar('0')).arg(it.hasNext() ? "," : "")); // Ignore CppSingleCharVerifier
            }
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciInterface interface)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciInterface%1%2 interface%1%2) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | interface%1%2 = %u\", interface%1%2)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (interface%1%2)").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("    {");

        if (!interfaces.contains(0))
        {
            lines.append(QString("        case PciInterface%1%2::NONE:         return \"NONE\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        }

        QMapIterator<quint16, QString> it(interfaces);

        while (it.hasNext())
        {
            it.next();

            quint16 interfaceId = it.key();

            if (interfaceId != 0xFFFF)
            {
                QString interfaceIdStr = QString::number(interfaceId, 16).toUpper();

                lines.append(QString("        case PciInterface%1%2::INTERFACE_%3: return \"INTERFACE_%3\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg(interfaceIdStr, 2, QChar('0')));
            }
        }

        lines.append("");
        lines.append("        default: return \"UNKNOWN\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToFullString(PciInterface interface)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToFullString(PciInterface%1%2 interface%1%2) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | interface%1%2 = %u\", interface%1%2)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append("    static char8 res[20];");
        lines.append("");
        lines.append(QString("    sprintf(res, \"%3 (%s)\", (u8)interface%1%2, enumToString(interface%1%2));").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg("0x%02X"));
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciInterface interface)
    {
        QString unknownValue = "Unknown device";



        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciInterface%1%2 interface%1%2) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | interface%1%2 = %u\", interface%1%2)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (interface%1%2)").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("    {");

        QMapIterator<quint16, QString> it(interfaces);

        while (it.hasNext())
        {
            it.next();

            quint16 interfaceId = it.key();
            QString description = it.value();

            if (interfaceId != 0xFFFF)
            {
                QString interfaceIdStr = QString::number(interfaceId, 16).toUpper();

                lines.append(QString("        case PciInterface%1%2::INTERFACE_%3: return \"%4\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg(interfaceIdStr, 2, QChar('0')).arg(description));
            }
            else
            {
                unknownValue = description;
            }
        }

        lines.append("");
        lines.append(QString("        default: return \"%1\";").arg(unknownValue));
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(QString(path + FOLDER_PATH + "baseclass%1/pciinterface%1%2.h").arg(baseClassId, 2, 16, QChar('0')).arg(subClassId, 2, 16, QChar('0')), lines);
}



PciDatabaseGenerator pciDatabaseGeneratorInstance;
