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

bool PciDatabaseGenerator::parseDatabase(const QStringList &lines, PciBaseClasses &baseClasses, PciVendors &vendors)
{
    qint64 i = 0;



    // Parse vendors and devices
    {
        PciVendor *vendor = nullptr;
        PciDevice *device = nullptr;

        while (i < lines.length())
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
            line.replace("\"", "\\\""); // Ignore CppSingleCharVerifier
            line.replace(",", ", "); // Ignore CppSingleCharVerifier
            line.replace(":", ": "); // Ignore CppSingleCharVerifier
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



    if (i >= lines.length())
    {
        Console::err("Failed to parse PCI database");

        return false;
    }



    // Parse base classes, subclasses and interfaces
    {
        PciBaseClass *baseClass = nullptr;
        PciSubClass  *subClass  = nullptr;

        while (i < lines.length())
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
            previousLine.remove(previousLine.length() - 1, 1);
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
            previousLine.remove(previousLine.length() - 1, 1);
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
            lines.append(QString("inline const char8* enumToHumanString(PciSubClass%1 class%1, u8 interfaceId) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
            lines.append("{"); // Ignore CppSingleCharVerifier
            lines.append(QString("    // COMMON_LT((\" | class%1 = %u, interfaceId = %u\", class%1, interfaceId)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')));
        }
        else
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            lines.append(QString("inline const char8* enumToHumanString(PciSubClass%1 class%1) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')));
            lines.append("{"); // Ignore CppSingleCharVerifier
            lines.append(QString("    // COMMON_LT((\" | class%1 = %u\", class%1)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')));
        }



        addThreeBlankLines(lines);

        lines.append(QString("    switch (class%1)").arg(baseClassIdStr, 2, QChar('0')));
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
            previousLine.remove(previousLine.length() - 1, 1);
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
        QString unknownValue = baseClassDescription + " - " + subClass.description;



        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciInterface%1%2 interface%1%2) // TEST: NO").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | interface%1%2 = %u\", interface%1%2)); // Commented to avoid bad looking logs").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (interface%1%2)").arg(baseClassIdStr, 2, QChar('0')).arg(subClassIdStr, 2, QChar('0')));
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
            previousLine.remove(previousLine.length() - 1, 1);
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



    return save(path + FOLDER_PATH + "pcivendor.h", lines);
}

bool PciDatabaseGenerator::generateDevicesFile(const QString &path, quint16 vendorId, const PciVendor &vendor)
{
    QString vendorIdStr = QString("%1").arg(vendorId, 4, 16, QChar('0')).toUpper();



    QStringList lines;



    // Headers
    {
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");
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
            previousLine.remove(previousLine.length() - 1, 1);
        }

        lines.append("};");
    }



    // inline const char8* enumToString(PciDevice device)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToString(PciDevice%1 device%1) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | device%1 = %u\", device%1)); // Commented to avoid bad looking logs").arg(vendorIdStr, 4, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (device%1)").arg(vendorIdStr, 4, QChar('0')));
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
        lines.append(QString("inline const char8* enumToFullString(PciDevice%1 device%1) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | device%1 = %u\", device%1)); // Commented to avoid bad looking logs").arg(vendorIdStr, 4, QChar('0')));

        addThreeBlankLines(lines);

        lines.append("    static char8 res[23];");
        lines.append("");
        lines.append(QString("    sprintf(res, \"%2 (%s)\", (u16)device%1, enumToString(device%1));").arg(vendorIdStr, 4, QChar('0')).arg("0x%04X"));
        lines.append("");
        lines.append("    return res;");
        lines.append("}"); // Ignore CppSingleCharVerifier
        // Ignore CppAlignmentVerifier [END]
    }



    // inline const char8* enumToHumanString(PciDevice device)
    {
        addThreeBlankLines(lines);



        // Ignore CppAlignmentVerifier [BEGIN]
        lines.append(QString("inline const char8* enumToHumanString(PciDevice%1 device%1) // TEST: NO").arg(vendorIdStr, 4, QChar('0')));
        lines.append("{"); // Ignore CppSingleCharVerifier
        lines.append(QString("    // COMMON_LT((\" | device%1 = %u\", device%1)); // Commented to avoid bad looking logs").arg(vendorIdStr, 4, QChar('0')));

        addThreeBlankLines(lines);

        lines.append(QString("    switch (device%1)").arg(vendorIdStr, 4, QChar('0')));
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



    Q_UNUSED(device);
    Q_UNUSED(vendorIdStr);
    Q_UNUSED(deviceIdStr);



    return save(QString(path + FOLDER_PATH + "vendor%1/pcisubdevice%2.h").arg(vendorId, 4, 16, QChar('0')).arg(deviceId, 4, 16, QChar('0')), lines);
}



PciDatabaseGenerator pciDatabaseGeneratorInstance;
