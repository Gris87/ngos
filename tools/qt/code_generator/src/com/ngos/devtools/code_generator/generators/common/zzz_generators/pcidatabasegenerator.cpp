#include "pcidatabasegenerator.h"

#include <QEventLoop>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QProcess>
#include <QTemporaryDir>
#include <QTemporaryFile>

#include <com/ngos/devtools/shared/console/console.h>



#define FOLDER_PATH "/src/os/shared/common/src/com/ngos/shared/common/pci/database/generated/"

#define DATABASE_URL "https://pci-ids.ucw.cz/v2.2/pci.ids"



PciDatabaseGenerator::PciDatabaseGenerator()
    : CommonGenerator()
{
    // Nothing
}

bool PciDatabaseGenerator::generate(const QString &path)
{
    QStringList lines;

    if (!prepareDatabase(lines))
    {
        return false;
    }



    PciBaseClasses baseClasses;
    PciVendors     vendors;

    if (!parseDatabase(lines, baseClasses, vendors))
    {
        return false;
    }



    if (!generateBaseClasses(path, baseClasses))
    {
        return false;
    }

    if (!generateVendors(path, vendors))
    {
        return false;
    }



    return true;
}

bool PciDatabaseGenerator::prepareDatabase(QStringList &lines)
{
    QNetworkRequest request;
    request.setUrl(QUrl(DATABASE_URL));

    QNetworkAccessManager  manager;
    QNetworkReply         *reply = manager.get(request);



    QEventLoop waitLoop;

    QObject::connect(reply, SIGNAL(finished()),                                 &waitLoop, SLOT(quit()));
    QObject::connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), &waitLoop, SLOT(quit()));

    waitLoop.exec();



    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (statusCode.toInt() != 200)
    {
        Console::err(QString("Failed to get PCI database from: %1").arg(DATABASE_URL));

        delete reply;

        return false;
    }



    QString content = QString::fromUtf8(reply->readAll());
    delete reply;



    lines = content.split('\n');

    for (qint64 i = 0; i < lines.size(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.size() - 1, 1);
        }
    }



    return true;
}

bool PciDatabaseGenerator::parseDatabase(const QStringList &lines, PciBaseClasses &baseClasses, PciVendors &vendors)
{
    qint64 i = 0;



    // Parse vendors and devices
    {
        PciVendor *vendor = nullptr;
        PciDevice *device = nullptr;

        while (i < lines.size())
        {
            QString line = lines.at(i);



            if (line == "# List of known device classes, subclasses and programming interfaces")
            {
                break;
            }



            if (
                line.startsWith('#')
                ||
                line == ""
               )
            {
                ++i;

                continue;
            }



            bool isVendor    = false;
            bool isDevice    = false;
            bool isSubDevice = false;

            bool    ok;
            quint32 id = 0;



            // Try to get type of the line
            {
                if (line.startsWith("\t\t"))
                {
                    isSubDevice = true;

                    line.remove(0, 2);



                    id = line.left(4).toUShort(&ok, 16) << 16;

                    if (!ok)
                    {
                        Console::err("Failed to parse line in PCI database: " + lines.at(i));

                        return false;
                    }

                    line.remove(0, 5);
                }
                else
                if (line.startsWith('\t'))
                {
                    isDevice = true;

                    line.remove(0, 1);
                }
                else
                {
                    isVendor = true;
                }
            }



            id |= line.left(4).toUShort(&ok, 16);

            if (!ok)
            {
                Console::err("Failed to parse line in PCI database: " + lines.at(i));

                return false;
            }



            line.remove(0, 6);
            line.replace(QChar(0x2010), QChar('-')); // Replace some strange '-' character
            line.replace(QChar(0x2013), QChar('-')); // Replace some strange '-' character
            line.replace(QChar(0x00AE), QChar('*')); // Replace some strange '*' character
            line.replace(QChar(0x00D7), QChar('x')); // Replace some strange 'x' character
            line.replace(QChar(0x00B2), "^2");       // Replace '^2' character
            line.replace(QChar(0x2076), "^6");       // Replace '^6' character
            line.replace("\"", "\\\"");              // Ignore CppSingleCharVerifier
            line.replace(",", ", ");                 // Ignore CppSingleCharVerifier
            line.replace(":", ": ");                 // Ignore CppSingleCharVerifier
            line = line.simplified();



            if (isVendor)
            {
                vendor              = &vendors[id];
                vendor->description = line;
            }
            else
            if (isDevice)
            {
                device              = &vendor->devices[id];
                device->description = line;
            }
            else
            if (isSubDevice)
            {
                device->subdevices[id].description = line;
            }
            else
            {
                Console::err("Failed to parse line in PCI database: " + lines.at(i));

                return false;
            }



            ++i;
        }
    }



    if (i >= lines.size())
    {
        Console::err("Failed to parse PCI database");

        return false;
    }



    // Parse base classes, subclasses and interfaces
    {
        PciBaseClass *baseClass = nullptr;
        PciSubClass  *subClass  = nullptr;

        while (i < lines.size())
        {
            QString line = lines.at(i);



            if (
                line.startsWith('#')
                ||
                line == ""
               )
            {
                ++i;

                continue;
            }



            bool isBaseClass = false;
            bool isSubClass  = false;
            bool isInterface = false;



            // Try to get type of the line
            {
                if (line.startsWith("C "))
                {
                    isBaseClass = true;

                    line.remove(0, 2);
                }
                else
                if (line.startsWith("\t\t"))
                {
                    isInterface = true;

                    line.remove(0, 2);
                }
                else
                if (line.startsWith('\t'))
                {
                    isSubClass = true;

                    line.remove(0, 1);
                }
                else
                {
                    Console::err("Failed to parse line in PCI database: " + lines.at(i));

                    return false;
                }
            }



            bool   ok;
            quint8 id = line.left(2).toUShort(&ok, 16);

            if (!ok)
            {
                Console::err("Failed to parse line in PCI database: " + lines.at(i));

                return false;
            }



            line.remove(0, 4);
            line.replace(QChar(0x2010), QChar('-')); // Replace some strange '-' character
            line.replace("\"", "\\\""); // Ignore CppSingleCharVerifier
            line.replace(",", ", "); // Ignore CppSingleCharVerifier
            line.replace(":", ": "); // Ignore CppSingleCharVerifier
            line = line.simplified();



            if (isBaseClass)
            {
                baseClass              = &baseClasses[id];
                baseClass->description = line;
            }
            else
            if (isSubClass)
            {
                subClass              = &baseClass->subClasses[id];
                subClass->description = line;
            }
            else
            if (isInterface)
            {
                subClass->interfaces[id].description = line;
            }
            else
            {
                Console::err("Failed to parse line in PCI database: " + lines.at(i));

                return false;
            }



            ++i;
        }
    }



    return true;
}

bool PciDatabaseGenerator::generateBaseClasses(const QString &path, const PciBaseClasses &baseClasses)
{
    // Iterate over base classes and generate subclasses
    {
        QMapIterator<quint8, PciBaseClass> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint8              baseClassId = it.key();
            const PciBaseClass &baseClass   = it.value();

            if (!baseClass.subClasses.isEmpty())
            {
                if (!generateSubClasses(path, baseClassId, baseClass))
                {
                    return false;
                }
            }
        }
    }

    return generateBaseClassesFile(path, baseClasses);
}

bool PciDatabaseGenerator::generateSubClasses(const QString &path, quint8 baseClassId, const PciBaseClass &baseClass)
{
    // Iterate over subclasses and generate interfaces
    {
        QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

        while (it.hasNext())
        {
            it.next();

            quint8             subClassId = it.key();
            const PciSubClass &subClass   = it.value();

            if (!subClass.interfaces.isEmpty())
            {
                if (!generateInterfacesFile(path, baseClassId, baseClass.description, subClassId, subClass))
                {
                    return false;
                }
            }
        }
    }

    return generateSubClassesFile(path, baseClassId, baseClass);
}

bool PciDatabaseGenerator::generateVendors(const QString &path, const PciVendors &vendors)
{
    // Iterate over vendors and generate devices
    {
        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16          vendorId = it.key();
            const PciVendor &vendor   = it.value();

            if (!vendor.devices.isEmpty())
            {
                if (!generateDevices(path, vendorId, vendor))
                {
                    return false;
                }
            }
        }
    }

    return generateVendorsFile(path, vendors);
}

bool PciDatabaseGenerator::generateDevices(const QString &path, quint16 vendorId, const PciVendor &vendor)
{
    // Iterate over subclasses and generate interfaces
    {
        QMapIterator<quint16, PciDevice> it(vendor.devices);

        while (it.hasNext())
        {
            it.next();

            quint16          deviceId = it.key();
            const PciDevice &device   = it.value();

            if (!device.subdevices.isEmpty())
            {
                if (!generateSubDevicesFile(path, vendorId, deviceId, device))
                {
                    return false;
                }
            }
        }
    }

    return generateDevicesFile(path, vendorId, vendor);
}

bool PciDatabaseGenerator::generateBaseClassesFile(const QString &path, const PciBaseClasses &baseClasses)
{
    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");

        QMapIterator<quint8, PciBaseClass> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint8              baseClassId = it.key();
            const PciBaseClass &baseClass   = it.value();

            if (!baseClass.subClasses.isEmpty())
            {
                lines.append(QString("#include <com/ngos/shared/common/pci/database/generated/baseclass%1/pcisubclass%1.h>").arg(baseClassId, 2, 16, QChar('0')));
            }
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

        QMapIterator<quint8, PciBaseClass> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint8  baseClassId    = it.key();
            QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();

            lines.append(QString("    BASE_CLASS_%1 = 0x%1,").arg(baseClassIdStr, 2, QChar('0')));
        }

        // Remove ',' from the previous line
        {
            QString &previousLine = lines.last();
            previousLine.remove(previousLine.size() - 1, 1);
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

        QMapIterator<quint8, PciBaseClass> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint8  baseClassId    = it.key();
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

        QMapIterator<quint8, PciBaseClass> it(baseClasses);

        while (it.hasNext())
        {
            it.next();

            quint8              baseClassId = it.key();
            const PciBaseClass &baseClass   = it.value();

            QString baseClassIdStr = QString::number(baseClassId, 16).toUpper();



            if (!baseClass.subClasses.isEmpty())
            {
                bool interfaceIdUsed = false;

                // Check that interfaceId used
                {
                    QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

                    while (it.hasNext())
                    {
                        it.next();

                        const PciSubClass &subClass = it.value();

                        if (!subClass.interfaces.isEmpty())
                        {
                            interfaceIdUsed = true;

                            break;
                        }
                    }
                }



                if (interfaceIdUsed)
                {
                    lines.append(QString("        case PciBaseClass::BASE_CLASS_%1: return enumToHumanString((PciSubClass%1)subClassId, interfaceId);").arg(baseClassIdStr, 2, QChar('0')));
                }
                else
                {
                    lines.append(QString("        case PciBaseClass::BASE_CLASS_%1: return enumToHumanString((PciSubClass%1)subClassId);").arg(baseClassIdStr, 2, QChar('0')));
                }
            }
            else
            {
                lines.append(QString("        case PciBaseClass::BASE_CLASS_%1: return \"%2\";").arg(baseClassIdStr, 2, QChar('0')).arg(baseClass.description));
            }
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(path + FOLDER_PATH + "pcibaseclass.h", lines);
}

bool PciDatabaseGenerator::generateSubClassesFile(const QString &path, quint8 baseClassId, const PciBaseClass &baseClass)
{
    QString baseClassIdStr = QString("%1").arg(baseClassId, 2, 16, QChar('0')).toUpper();



    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");

        QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

        while (it.hasNext())
        {
            it.next();

            quint8             subClassId = it.key();
            const PciSubClass &subClass   = it.value();

            if (!subClass.interfaces.isEmpty())
            {
                lines.append(QString("#include <com/ngos/shared/common/pci/database/generated/baseclass%1/pciinterface%1%2.h>").arg(baseClassId, 2, 16, QChar('0')).arg(subClassId, 2, 16, QChar('0')));
            }
        }

        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciSubClass
    {
        addThreeBlankLines(lines);



        lines.append(QString("enum class PciSubClass%1: u8 // Ignore CppEnumVerifier").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!baseClass.subClasses.contains(0))
        {
            lines.append("    NONE         = 0,");
        }

        QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

        while (it.hasNext())
        {
            it.next();

            quint8  subClassId    = it.key();
            QString subClassIdStr = QString::number(subClassId, 16).toUpper();

            lines.append(QString("    SUB_CLASS_%1 = 0x%1,").arg(subClassIdStr, 2, QChar('0')));
        }

        // Remove ',' from the previous line
        {
            QString &previousLine = lines.last();
            previousLine.remove(previousLine.size() - 1, 1);
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciSubClass subClass)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciSubClass%1 subClass) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | subClass = %u\", subClass)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (subClass)");
        lines.append("    {");

        if (!baseClass.subClasses.contains(0))
        {
            lines.append(QString("        case PciSubClass%1::NONE:         return \"NONE\";").arg(baseClassIdStr, 2, QChar('0')));
        }

        QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

        while (it.hasNext())
        {
            it.next();

            quint8  subClassId    = it.key();
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
        lines.append(QString("inline const char8* enumToFullString(PciSubClass%1 subClass) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | subClass = %u\", subClass)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    static char8 res[20];");
        lines.append("");
        lines.append("    sprintf(res, \"0x%02X (%s)\", (u8)subClass, enumToString(subClass));");
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciSubClass subClass, u8 interfaceId)
    {
        QString unknownValue = baseClass.description;



        addThreeBlankLines(lines);



        bool interfaceIdUsed = false;

        // Check that interfaceId used
        {
            QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

            while (it.hasNext())
            {
                it.next();

                const PciSubClass &subClass = it.value();

                if (!subClass.interfaces.isEmpty())
                {
                    interfaceIdUsed = true;

                    break;
                }
            }
        }



        if (interfaceIdUsed)
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            lines.append(QString("inline const char8* enumToHumanString(PciSubClass%1 subClass, u8 interfaceId) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
            lines.append("{"); // Ignore CppSingleCharVerifier
            lines.append("    // COMMON_LT((\" | subClass = %u, interfaceId = %u\", subClass, interfaceId)); // Commented to avoid bad looking logs");
        }
        else
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            lines.append(QString("inline const char8* enumToHumanString(PciSubClass%1 subClass) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
            lines.append("{"); // Ignore CppSingleCharVerifier
            lines.append("    // COMMON_LT((\" | subClass = %u\", subClass)); // Commented to avoid bad looking logs");
        }



        addThreeBlankLines(lines);

        lines.append("    switch (subClass)");
        lines.append("    {");

        QMapIterator<quint8, PciSubClass> it(baseClass.subClasses);

        while (it.hasNext())
        {
            it.next();

            quint8             subClassId = it.key();
            const PciSubClass &subClass   = it.value();

            QString subClassIdStr = QString::number(subClassId, 16).toUpper();

            if (!subClass.interfaces.isEmpty())
            {
                lines.append(QString("        case PciSubClass%1::SUB_CLASS_%2: return enumToHumanString((PciInterface%1%2)interfaceId);").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
            }
            else
            {
                lines.append(QString("        case PciSubClass%1::SUB_CLASS_%2: return \"%3 - %4\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg(unknownValue).arg(subClass.description));
            }
        }

        lines.append("");
        lines.append(QString("        default: return \"%1\";").arg(unknownValue));
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(QString(path + FOLDER_PATH + "baseclass%1/pcisubclass%1.h").arg(baseClassId, 2, 16, QChar('0')), lines);
}

bool PciDatabaseGenerator::generateInterfacesFile(const QString &path, quint8 baseClassId, const QString &baseClassDescription, quint8 subClassId, const PciSubClass &subClass)
{
    QString baseClassIdStr = QString("%1").arg(baseClassId, 2, 16, QChar('0')).toUpper();
    QString subClassIdStr  = QString("%1").arg(subClassId,  2, 16, QChar('0')).toUpper();



    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");
        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciInterface
    {
        addThreeBlankLines(lines);



        lines.append(QString("enum class PciInterface%1%2: u8 // Ignore CppEnumVerifier").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!subClass.interfaces.contains(0))
        {
            lines.append("    NONE         = 0,");
        }

        QMapIterator<quint8, PciInterface> it(subClass.interfaces);

        while (it.hasNext())
        {
            it.next();

            quint8  interfaceId    = it.key();
            QString interfaceIdStr = QString::number(interfaceId, 16).toUpper();

            lines.append(QString("    INTERFACE_%1 = 0x%1,").arg(interfaceIdStr, 2, QChar('0')));
        }

        // Remove ',' from the previous line
        {
            QString &previousLine = lines.last();
            previousLine.remove(previousLine.size() - 1, 1);
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciInterface interface)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciInterface%1%2 interface) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | interface = %u\", interface)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (interface)");
        lines.append("    {");

        if (!subClass.interfaces.contains(0))
        {
            lines.append(QString("        case PciInterface%1%2::NONE:         return \"NONE\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        }

        QMapIterator<quint8, PciInterface> it(subClass.interfaces);

        while (it.hasNext())
        {
            it.next();

            quint8  interfaceId    = it.key();
            QString interfaceIdStr = QString::number(interfaceId, 16).toUpper();

            lines.append(QString("        case PciInterface%1%2::INTERFACE_%3: return \"INTERFACE_%3\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg(interfaceIdStr, 2, QChar('0')));
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
        lines.append(QString("inline const char8* enumToFullString(PciInterface%1%2 interface) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | interface = %u\", interface)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    static char8 res[20];");
        lines.append("");
        lines.append("    sprintf(res, \"0x%02X (%s)\", (u8)interface, enumToString(interface));");
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciInterface interface)
    {
        QString unknownValue = baseClassDescription + " - " + subClass.description;



        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciInterface%1%2 interface) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | interface = %u\", interface)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (interface)");
        lines.append("    {");

        QMapIterator<quint8, PciInterface> it(subClass.interfaces);

        while (it.hasNext())
        {
            it.next();

            quint8              interfaceId = it.key();
            const PciInterface &interface   = it.value();

            QString interfaceIdStr = QString::number(interfaceId, 16).toUpper();

            lines.append(QString("        case PciInterface%1%2::INTERFACE_%3: return \"%4 - %5\";").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')).arg(interfaceIdStr, 2, QChar('0')).arg(unknownValue).arg(interface.description));
        }

        lines.append("");
        lines.append(QString("        default: return \"%1\";").arg(unknownValue));
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(QString(path + FOLDER_PATH + "baseclass%1/pciinterface%1%2.h").arg(baseClassId, 2, 16, QChar('0')).arg(subClassId, 2, 16, QChar('0')), lines);
}

bool PciDatabaseGenerator::generateVendorsFile(const QString &path, const PciVendors &vendors)
{
    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");

        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16          vendorId = it.key();
            const PciVendor &vendor   = it.value();

            if (!vendor.devices.isEmpty())
            {
                lines.append(QString("#include <com/ngos/shared/common/pci/database/generated/vendor%1/pcidevice%1.h>").arg(vendorId, 4, 16, QChar('0')));
            }
        }

        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciVendor
    {
        addThreeBlankLines(lines);



        lines.append("enum class PciVendor: u16");
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!vendors.contains(0))
        {
            lines.append("    NONE        = 0,");
        }

        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16 vendorId    = it.key();
            QString vendorIdStr = QString::number(vendorId, 16).toUpper();

            lines.append(QString("    VENDOR_%1 = 0x%1,").arg(vendorIdStr, 4, QChar('0')));
        }

        // Remove ',' from the previous line
        {
            QString &previousLine = lines.last();
            previousLine.remove(previousLine.size() - 1, 1);
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciVendor vendor)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToString(PciVendor vendor) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | vendor = %u\", vendor)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (vendor)");
        lines.append("    {");

        if (!vendors.contains(0))
        {
            lines.append("        case PciVendor::NONE:        return \"NONE\";");
        }

        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16 vendorId    = it.key();
            QString vendorIdStr = QString::number(vendorId, 16).toUpper();

            lines.append(QString("        case PciVendor::VENDOR_%1: return \"VENDOR_%1\";").arg(vendorIdStr, 4, QChar('0')));
        }

        lines.append("");
        lines.append("        default: return \"UNKNOWN\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToFullString(PciVendor vendor)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToFullString(PciVendor vendor) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | vendor = %u\", vendor)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    static char8 res[21];");
        lines.append("");
        lines.append("    sprintf(res, \"0x%04X (%s)\", (u16)vendor, enumToString(vendor));");
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciVendor vendor)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToHumanString(PciVendor vendor) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | vendor = %u\", vendor)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (vendor)");
        lines.append("    {");

        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16          vendorId = it.key();
            const PciVendor &vendor   = it.value();

            QString vendorIdStr = QString::number(vendorId, 16).toUpper();

            lines.append(QString("        case PciVendor::VENDOR_%1: return \"%2\";").arg(vendorIdStr, 4, QChar('0')).arg(vendor.description));
        }

        lines.append("");
        lines.append("        default: return \"Unknown vendor\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciVendor vendor, u16 deviceId)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToHumanString(PciVendor vendor, u16 deviceId) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | vendor = %u, deviceId = %u\", vendor, deviceId)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (vendor)");
        lines.append("    {");

        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16          vendorId = it.key();
            const PciVendor &vendor   = it.value();

            QString vendorIdStr = QString::number(vendorId, 16).toUpper();



            if (!vendor.devices.isEmpty())
            {
                lines.append(QString("        case PciVendor::VENDOR_%1: return enumToHumanString((PciDevice%1)deviceId);").arg(vendorIdStr, 4, QChar('0')));
            }
            else
            {
                lines.append(QString("        case PciVendor::VENDOR_%1: return \"Unknown device\";").arg(vendorIdStr, 4, QChar('0')));
            }
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciVendor vendor, u16 deviceId, PciVendor subsystemVendorID, u16 subDeviceId)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append("inline const char8* enumToHumanString(PciVendor vendor, u16 deviceId, PciVendor subsystemVendorID, u16 subDeviceId) // TEST: NO");
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | vendor = %u, deviceId = %u, subsystemVendorID = %u, subDeviceId = %u\", vendor, deviceId, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (vendor)");
        lines.append("    {");

        QMapIterator<quint16, PciVendor> it(vendors);

        while (it.hasNext())
        {
            it.next();

            quint16          vendorId = it.key();
            const PciVendor &vendor   = it.value();

            QString vendorIdStr = QString::number(vendorId, 16).toUpper();



            bool subDevicesExists = false;

            QMapIterator<quint16, PciDevice> it2(vendor.devices);

            while (it2.hasNext())
            {
                it2.next();

                const PciDevice &device = it2.value();

                if (!device.subdevices.isEmpty())
                {
                    subDevicesExists = true;

                    break;
                }
            }



            if (subDevicesExists)
            {
                lines.append(QString("        case PciVendor::VENDOR_%1: return enumToHumanString((PciDevice%1)deviceId, (u16)subsystemVendorID, subDeviceId);").arg(vendorIdStr, 4, QChar('0')));
            }
            else
            {
                lines.append(QString("        case PciVendor::VENDOR_%1: return \"Unknown device\";").arg(vendorIdStr, 4, QChar('0')));
            }
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(path + FOLDER_PATH + "pcivendor.h", lines);
}

bool PciDatabaseGenerator::generateDevicesFile(const QString &path, quint16 vendorId, const PciVendor &vendor)
{
    QString vendorIdStr = QString("%1").arg(vendorId, 4, 16, QChar('0')).toUpper();



    QStringList lines;

    bool subDevicesExists = false;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");

        QMapIterator<quint16, PciDevice> it(vendor.devices);

        while (it.hasNext())
        {
            it.next();

            quint16          deviceId = it.key();
            const PciDevice &device   = it.value();

            if (!device.subdevices.isEmpty())
            {
                subDevicesExists = true;

                lines.append(QString("#include <com/ngos/shared/common/pci/database/generated/vendor%1/pcisubdevice%1%2.h>").arg(vendorId, 4, 16, QChar('0')).arg(deviceId, 4, 16, QChar('0')));
            }
        }

        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciDevice
    {
        addThreeBlankLines(lines);



        lines.append(QString("enum class PciDevice%1: u16 // Ignore CppEnumVerifier").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!vendor.devices.contains(0))
        {
            lines.append("    NONE        = 0,");
        }

        QMapIterator<quint16, PciDevice> it(vendor.devices);

        while (it.hasNext())
        {
            it.next();

            quint16 deviceId    = it.key();
            QString deviceIdStr = QString::number(deviceId, 16).toUpper();

            lines.append(QString("    DEVICE_%1 = 0x%1,").arg(deviceIdStr, 4, QChar('0')));
        }

        // Remove ',' from the previous line
        {
            QString &previousLine = lines.last();
            previousLine.remove(previousLine.size() - 1, 1);
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciDevice device)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciDevice%1 device) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | device = %u\", device)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (device)");
        lines.append("    {");

        if (!vendor.devices.contains(0))
        {
            lines.append(QString("        case PciDevice%1::NONE:        return \"NONE\";").arg(vendorIdStr, 4, QChar('0')));
        }

        QMapIterator<quint16, PciDevice> it(vendor.devices);

        while (it.hasNext())
        {
            it.next();

            quint16 deviceId    = it.key();
            QString deviceIdStr = QString::number(deviceId, 16).toUpper();

            lines.append(QString("        case PciDevice%1::DEVICE_%2: return \"DEVICE_%2\";").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
        }

        lines.append("");
        lines.append("        default: return \"UNKNOWN\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToFullString(PciDevice device)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToFullString(PciDevice%1 device) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | device = %u\", device)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    static char8 res[23];");
        lines.append("");
        lines.append("    sprintf(res, \"0x%04X (%s)\", (u16)device, enumToString(device));");
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciDevice device)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciDevice%1 device) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | device = %u\", device)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (device)");
        lines.append("    {");

        QMapIterator<quint16, PciDevice> it(vendor.devices);

        while (it.hasNext())
        {
            it.next();

            quint16          deviceId = it.key();
            const PciDevice &device   = it.value();

            QString deviceIdStr = QString::number(deviceId, 16).toUpper();

            lines.append(QString("        case PciDevice%1::DEVICE_%2: return \"%3\";").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')).arg(device.description));
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciDevice device, u16 subsystemVendorID, u16 subDeviceId)
    {
        if (subDevicesExists)
        {
            addThreeBlankLines(lines);



            // Ignore CppAlignmentVerifier [BEGIN]
            lines.append(QString("inline const char8* enumToHumanString(PciDevice%1 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
            lines.append("{"); // Ignore CppSingleCharVerifier
            lines.append("    // COMMON_LT((\" | device = %u, subsystemVendorID = %u, subDeviceId = %u\", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs");

            addThreeBlankLines(lines);

            lines.append("    switch (device)");
            lines.append("    {");

            QMapIterator<quint16, PciDevice> it(vendor.devices);

            while (it.hasNext())
            {
                it.next();

                quint16          deviceId = it.key();
                const PciDevice &device   = it.value();

                QString deviceIdStr = QString::number(deviceId, 16).toUpper();



                if (!device.subdevices.isEmpty())
                {
                    lines.append(QString("        case PciDevice%1::DEVICE_%2: return enumToHumanString((PciSubDevice%1%2)(subsystemVendorID << 16 | subDeviceId));").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
                }
                else
                {
                    lines.append(QString("        case PciDevice%1::DEVICE_%2: return \"Unknown device\";").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
                }
            }

            lines.append("");
            lines.append("        default: return \"Unknown device\";");
            lines.append("    }");
            lines.append("}"); // Ignore CppSingleCharVerifier
            // Ignore CppAlignmentVerifier [END]
        }
    }



    return save(QString(path + FOLDER_PATH + "vendor%1/pcidevice%1.h").arg(vendorId, 4, 16, QChar('0')), lines);
}

bool PciDatabaseGenerator::generateSubDevicesFile(const QString &path, quint16 vendorId, quint16 deviceId, const PciDevice &device)
{
    QString vendorIdStr = QString("%1").arg(vendorId, 4, 16, QChar('0')).toUpper();
    QString deviceIdStr = QString("%1").arg(deviceId, 4, 16, QChar('0')).toUpper();



    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");
        lines.append("#include <com/ngos/shared/common/printf/printf.h>");
    }



    // enum class PciSubDevice
    {
        addThreeBlankLines(lines);



        lines.append(QString("enum class PciSubDevice%1%2: u32 // Ignore CppEnumVerifier").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier

        if (!device.subdevices.contains(0))
        {
            lines.append("    NONE               = 0,");
        }

        QMapIterator<quint32, PciSubDevice> it(device.subdevices);

        while (it.hasNext())
        {
            it.next();

            quint32 subDeviceId    = it.key();
            QString subDeviceIdStr = QString::number(subDeviceId, 16).toUpper();

            lines.append(QString("    SUBDEVICE_%1 = 0x%1,").arg(subDeviceIdStr, 8, QChar('0')));
        }

        // Remove ',' from the previous line
        {
            QString &previousLine = lines.last();
            previousLine.remove(previousLine.size() - 1, 1);
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciSubDevice subDevice)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciSubDevice%1%2 subDevice) // TEST: NO").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | subDevice = %u\", subDevice)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (subDevice)");
        lines.append("    {");

        if (!device.subdevices.contains(0))
        {
            lines.append(QString("        case PciSubDevice%1%2::NONE:               return \"NONE\";").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
        }

        QMapIterator<quint32, PciSubDevice> it(device.subdevices);

        while (it.hasNext())
        {
            it.next();

            quint32 subDeviceId    = it.key();
            QString subDeviceIdStr = QString::number(subDeviceId, 16).toUpper();

            lines.append(QString("        case PciSubDevice%1%2::SUBDEVICE_%3: return \"SUBDEVICE_%3\";").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')).arg(subDeviceIdStr, 8, QChar('0')));
        }

        lines.append("");
        lines.append("        default: return \"UNKNOWN\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToFullString(PciSubDevice subDevice)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToFullString(PciSubDevice%1%2 subDevice) // TEST: NO").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | subDevice = %u\", subDevice)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    static char8 res[32];");
        lines.append("");
        lines.append("    sprintf(res, \"0x%08X (%s)\", (u32)subDevice, enumToString(subDevice));");
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciSubDevice subDevice)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciSubDevice%1%2 subDevice) // TEST: NO").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append("    // COMMON_LT((\" | subDevice = %u\", subDevice)); // Commented to avoid bad looking logs");

        addThreeBlankLines(lines);

        lines.append("    switch (subDevice)");
        lines.append("    {");

        QMapIterator<quint32, PciSubDevice> it(device.subdevices);

        while (it.hasNext())
        {
            it.next();

            quint32             subDeviceId = it.key();
            const PciSubDevice &subDevice   = it.value();

            QString subDeviceIdStr = QString::number(subDeviceId, 16).toUpper();

            lines.append(QString("        case PciSubDevice%1%2::SUBDEVICE_%3: return \"%4\";").arg(vendorIdStr, 4, QChar('0')).arg(deviceIdStr, 4, QChar('0')).arg(subDeviceIdStr, 8, QChar('0')).arg(subDevice.description));
        }

        lines.append("");
        lines.append("        default: return \"Unknown device\";");
        lines.append("    }");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    return save(QString(path + FOLDER_PATH + "vendor%1/pcisubdevice%1%2.h").arg(vendorId, 4, 16, QChar('0')).arg(deviceId, 4, 16, QChar('0')), lines);
}



PciDatabaseGenerator pciDatabaseGeneratorInstance;
