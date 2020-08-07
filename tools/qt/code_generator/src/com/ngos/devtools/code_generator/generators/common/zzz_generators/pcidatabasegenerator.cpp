#include "pcidatabasegenerator.h"

#include <com/ngos/devtools/shared/console/console.h>



#define FOLDER_PATH "/src/os/shared/common/src/com/ngos/shared/common/pci/database/generated/"



PciDatabaseGenerator::PciDatabaseGenerator()
    : CommonGenerator()
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
    PciSubClasses subClasses00;

    PciInterfaces interfaces0000;
    PciInterfaces interfaces0001;

    interfaces0000.insert(0, "All currently implemented devices except VGA-compatible devices");
    interfaces0001.insert(0, "VGA-compatible device");

    subClasses00.insert(0, interfaces0000);
    subClasses00.insert(1, interfaces0001);

    baseClasses.insert(0, subClasses00);



    PciSubClasses subClasses01;

    PciInterfaces interfaces0100;
    PciInterfaces interfaces0101;
    PciInterfaces interfaces0102;
    PciInterfaces interfaces0103;
    PciInterfaces interfaces0104;
    PciInterfaces interfaces0105;
    PciInterfaces interfaces0106;
    PciInterfaces interfaces0180;

    interfaces0100.insert(0,      "SCSI bus controller");
    interfaces0101.insert(0xFFFF, "IDE controller");
    interfaces0102.insert(0,      "Floppy disk controller");
    interfaces0103.insert(0,      "IPI bus controller");
    interfaces0104.insert(0,      "RAID controller");
    interfaces0105.insert(32,     "ATA controller with single DMA");
    interfaces0105.insert(48,     "ATA controller with chained DMA");
    interfaces0106.insert(0,      "Serial ATA Direct Port Access (DPA)");
    interfaces0180.insert(0,      "Other mass storage controller");

    subClasses01.insert(0,   interfaces0100);
    subClasses01.insert(1,   interfaces0101);
    subClasses01.insert(2,   interfaces0102);
    subClasses01.insert(3,   interfaces0103);
    subClasses01.insert(4,   interfaces0104);
    subClasses01.insert(5,   interfaces0105);
    subClasses01.insert(6,   interfaces0106);
    subClasses01.insert(128, interfaces0180);

    baseClasses.insert(1, subClasses01);



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
