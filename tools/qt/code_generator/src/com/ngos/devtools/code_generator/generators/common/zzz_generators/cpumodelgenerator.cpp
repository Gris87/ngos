#include "cpumodelgenerator.h"

#include <QDomDocument>
#include <QEventLoop>
#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <com/ngos/devtools/shared/console/console.h>



#define INTEL_FILE_PATH "/src/os/shared/common/src/com/ngos/shared/common/cpu/lib/generated/intelcpumodel.h"
#define AMD_FILE_PATH   "/src/os/shared/common/src/com/ngos/shared/common/cpu/lib/generated/amdcpumodel.h"

#define INTEL_DATABASE_URL "https://en.wikichip.org/wiki/intel/cpuid"
#define AMD_DATABASE_URL   "https://en.wikichip.org/wiki/amd/cpuid"

#define INTEL_SEARCH_START_LINE "<h3><span class=\"mw-headline\" id=\"Family_6\">Family 6</span><span class=\"mw-editsection\"><span class=\"mw-editsection-bracket\">[</span><a href=\"/w/index.php?title=intel/cpuid&amp;action=edit&amp;section=4\" title=\"Edit section: Family 6\">edit</a><span class=\"mw-editsection-bracket\">]</span></span></h3>"
#define INTEL_SEARCH_END_LINE   "<h3><span class=\"mw-headline\" id=\"Family_5\">Family 5</span><span class=\"mw-editsection\"><span class=\"mw-editsection-bracket\">[</span><a href=\"/w/index.php?title=intel/cpuid&amp;action=edit&amp;section=9\" title=\"Edit section: Family 5\">edit</a><span class=\"mw-editsection-bracket\">]</span></span></h3>"

#define AMD_SEARCH_START_LINE "<h3><span class=\"mw-headline\" id=\"Family_25_.2819h.29\">Family 25 (19h)</span><span class=\"mw-editsection\"><span class=\"mw-editsection-bracket\">[</span><a href=\"/w/index.php?title=amd/cpuid&amp;action=edit&amp;section=2\" title=\"Edit section: Family 25 (19h)\">edit</a><span class=\"mw-editsection-bracket\">]</span></span></h3>"
#define AMD_SEARCH_END_LINE   "<h3><span class=\"mw-headline\" id=\"Family_22_.2816h.29\">Family 22 (16h)</span><span class=\"mw-editsection\"><span class=\"mw-editsection-bracket\">[</span><a href=\"/w/index.php?title=amd/cpuid&amp;action=edit&amp;section=5\" title=\"Edit section: Family 22 (16h)\">edit</a><span class=\"mw-editsection-bracket\">]</span></span></h3>"



CpuModelGenerator::CpuModelGenerator()
    : CommonGenerator()
    , mFamilyRegExp(".*Family *(\\d+).*?")
{
    // Nothing
}

bool CpuModelGenerator::generate(const QString &path)
{
    return generateVendorModels("intel", path + INTEL_FILE_PATH, INTEL_DATABASE_URL, INTEL_SEARCH_START_LINE, INTEL_SEARCH_END_LINE);

    /*
    return generateVendorModels("intel", path + INTEL_FILE_PATH, INTEL_DATABASE_URL, INTEL_SEARCH_START_LINE, INTEL_SEARCH_END_LINE)
            &&
            generateVendorModels("amd", path + AMD_FILE_PATH, AMD_DATABASE_URL, AMD_SEARCH_START_LINE, AMD_SEARCH_END_LINE);
            */
}

bool CpuModelGenerator::generateVendorModels(const QString &vendor, const QString &path, const QString &url, const QString &searchStartLine, const QString &searchEndLine)
{
    QStringList lines;

    // Download database
    {
        if (!prepareDatabase(url, lines))
        {
            return false;
        }
    }



    QList<CpuModel> models;

    // Parse downloaded database to internal structure
    {
        if (!parseDatabase(vendor, lines, searchStartLine, searchEndLine, models))
        {
            return false;
        }
    }



    return generateModels(vendor, path, models);
}

bool CpuModelGenerator::prepareDatabase(const QString &url, QStringList &lines)
{
    QNetworkAccessManager  manager;
    QNetworkReply         *reply;

    // Send network request
    {
        QNetworkRequest request;
        request.setUrl(QUrl(url));
        reply = manager.get(request);
    }



    // Wait for finish
    {
        QEventLoop waitLoop;

        QObject::connect(reply, SIGNAL(finished()),                                 &waitLoop, SLOT(quit()));
        QObject::connect(reply, SIGNAL(errorOccurred(QNetworkReply::NetworkError)), &waitLoop, SLOT(quit()));

        waitLoop.exec();
    }



    // Check status code
    {
        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

        if (statusCode.toInt() != 200)
        {
            Console::err(QString("Failed to get CPU models database from: %1")
                                    .arg(url)
            );

            delete reply;

            return false;
        }
    }



    QString content = QString::fromUtf8(reply->readAll());
    delete reply;



    // Get lines of content
    {
        lines = content.split('\n');

        for (qint64 i = 0; i < lines.size(); ++i)
        {
            QString &line = lines[i];

            if (line.endsWith('\r'))
            {
                line.remove(line.length() - 1, 1);
            }
        }
    }



    return true;
}

bool CpuModelGenerator::parseDatabase(const QString &vendor, const QStringList &lines, const QString &searchStartLine, const QString &searchEndLine, QList<CpuModel> &models)
{
    qint64 i = 0;

    // Skip lines
    {
        while (i < lines.size() && lines.at(i) != searchStartLine)
        {
            ++i;
        }

        if (i >= lines.size())
        {
            Console::err(QString("Failed to find start position to parse %1 processors")
                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
            );

            return false;
        }
    }



    QDomDocument xml;

    // Prepare XML document
    {
        QString xmlContent = "<html>\n";

        while (i < lines.size())
        {
            QString line = lines.at(i);

            if (line == searchEndLine)
            {
                break;
            }

            xmlContent.append(line);
            xmlContent.append("\n");

            ++i;
        }

        if (i >= lines.size())
        {
            Console::err(QString("Failed to find end position to parse %1 processors")
                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
            );

            return false;
        }

        xmlContent.append("</html>");



        QString errorMessage;
        int     errorLine;
        int     errorColumn;

        if (!xml.setContent(xmlContent, &errorMessage, &errorLine, &errorColumn))
        {
            Console::err(QString("Failed to parse XML document for %1 processors at %2:%3 : %4")
                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                    .arg(errorLine)
                                    .arg(errorColumn)
                                    .arg(errorMessage)
            );

            return false;
        }
    }



    // Parse models from XML
    {
        qint64 family = -1;

        QDomElement doc  = xml.documentElement();
        QDomNode    node = doc.firstChild();

        while (!node.isNull())
        {
            QDomElement element = node.toElement();

            if (!element.isNull())
            {
                if (element.tagName() == "h3")
                {
                    // Parse family
                    {
                        QString elementText = element.text();

                        QRegularExpressionMatch match = mFamilyRegExp.match(elementText);

                        if (match.hasMatch())
                        {
                            family = match.captured(1).toLongLong();
                        }
                        else
                        {
                            Console::err(QString("Failed to parse family for %1 processors: %2")
                                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                                    .arg(elementText)
                            );

                            return false;
                        }
                    }
                }
                else
                if (element.tagName() == "table")
                {
                    qint64 model = -1;

                    qint64 microArchitectureColumn = -1;
                    qint64 nameColumn              = -1;
                    qint64 modelColumn             = -1;
                    qint64 extendedModelColumn     = -1;

                    qint64 microArchitectureRowSpan = -1;
                    qint64 nameRowSpan              = -1;
                    qint64 modelRowSpan             = -1;
                    qint64 extendedModelRowSpan     = -1;

                    QString microArchitectureStr;
                    QString nameStr;
                    QString modelStr;
                    QString extendedModelStr;

                    // Parse table
                    {
                        QDomNodeList children = node.childNodes();

                        // Check that there is only tbody element inside table
                        {
                            if (
                                children.size() != 1
                                ||
                                children.at(0).toElement().tagName() != "tbody"
                               )
                            {
                                Console::err(QString("Failed to parse table for %1 processors")
                                                        .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                );

                                return false;
                            }
                        }



                        QDomNode tableNode = children.at(0).firstChild();

                        // First row contains header
                        {
                            children = tableNode.childNodes();

                            for (qint64 i = 0; i < children.size(); ++i)
                            {
                                element = children.at(i).toElement();

                                if (!element.isNull())
                                {
                                    QString elementText = element.text().remove(' ').remove('\n');

                                    if (elementText == "Microarchitecture")
                                    {
                                        if (microArchitectureColumn >= 0)
                                        {
                                            Console::err(QString("Microarchitecture column already found for %1 processors")
                                                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                            );

                                            return false;
                                        }

                                        microArchitectureColumn = i;
                                    }
                                    else
                                    if (
                                        elementText == "Core"
                                        ||
                                        elementText == "Products"
                                        ||
                                        elementText == "Codename"
                                        ||
                                        elementText == "Design"
                                       )
                                    {
                                        if (nameColumn >= 0)
                                        {
                                            Console::err(QString("Name column already found for %1 processors")
                                                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                            );

                                            return false;
                                        }

                                        nameColumn = i;
                                    }
                                    else
                                    if (
                                        elementText == "BaseModel"
                                        ||
                                        elementText == "Model"
                                       )
                                    {
                                        if (modelColumn >= 0)
                                        {
                                            Console::err(QString("Model column already found for %1 processors")
                                                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                            );

                                            return false;
                                        }

                                        modelColumn = i;
                                    }
                                    else
                                    if (elementText == "ExtendedModel")
                                    {
                                        if (extendedModelColumn >= 0)
                                        {
                                            Console::err(QString("Extended model column already found for %1 processors")
                                                                    .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                            );

                                            return false;
                                        }

                                        extendedModelColumn = i;
                                    }
                                }
                            }

                            tableNode = tableNode.nextSibling();
                        }



                        // Check that all columns are found
                        {
                            if (
                                microArchitectureColumn < 0
                                ||
                                nameColumn < 0
                                ||
                                modelColumn < 0
                                ||
                                extendedModelColumn < 0
                               )
                            {
                                Console::err(QString("Required columns not found for %1 processors")
                                                        .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                );

                                return false;
                            }
                        }



                        // Parse table rows with models
                        {
                            while (!tableNode.isNull())
                            {
                                qint64 microArchitectureNewRowSpan = microArchitectureRowSpan;
                                qint64 nameNewRowSpan              = nameRowSpan;
                                qint64 modelNewRowSpan             = modelRowSpan;
                                qint64 extendedModelNewRowSpan     = extendedModelRowSpan;



                                // Get model parameters
                                {
                                    children = tableNode.childNodes();

                                    // Get Microarchitecture
                                    {
                                        if (microArchitectureRowSpan <= 0)
                                        {
                                            qint64 realColumn = microArchitectureColumn;

                                            if (nameColumn < microArchitectureColumn && nameRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (modelColumn < microArchitectureColumn && modelRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (extendedModelColumn < microArchitectureColumn && extendedModelRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (realColumn < children.size())
                                            {
                                                element = children.at(realColumn).toElement();

                                                microArchitectureStr        = element.text().simplified().toUpper();
                                                microArchitectureNewRowSpan = element.attribute("rowspan", "1").toLongLong();
                                            }
                                            else
                                            {
                                                microArchitectureStr        = "";
                                                microArchitectureNewRowSpan = 1;
                                            }
                                        }
                                    }

                                    // Get Name
                                    {
                                        if (nameRowSpan <= 0)
                                        {
                                            qint64 realColumn = nameColumn;

                                            if (microArchitectureColumn < nameColumn && microArchitectureRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (modelColumn < nameColumn && modelRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (extendedModelColumn < nameColumn && extendedModelRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (realColumn < children.size())
                                            {
                                                element = children.at(realColumn).toElement();

                                                nameStr        = element.text().simplified().toUpper();
                                                nameNewRowSpan = element.attribute("rowspan", "1").toLongLong();
                                            }
                                            else
                                            {
                                                nameStr        = "";
                                                nameNewRowSpan = 1;
                                            }
                                        }
                                    }

                                    // Get Model
                                    {
                                        if (modelRowSpan <= 0)
                                        {
                                            qint64 realColumn = modelColumn;

                                            if (microArchitectureColumn < modelColumn && microArchitectureRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (nameColumn < modelColumn && nameRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (extendedModelColumn < modelColumn && extendedModelRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (realColumn < children.size())
                                            {
                                                element = children.at(realColumn).toElement();

                                                modelStr        = element.text().simplified();
                                                modelNewRowSpan = element.attribute("rowspan", "1").toLongLong();
                                            }
                                            else
                                            {
                                                modelStr        = "";
                                                modelNewRowSpan = 1;
                                            }
                                        }
                                    }

                                    // Get Extended Model
                                    {
                                        if (extendedModelRowSpan <= 0)
                                        {
                                            qint64 realColumn = extendedModelColumn;

                                            if (microArchitectureColumn < extendedModelColumn && microArchitectureRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (nameColumn < extendedModelColumn && nameRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (modelColumn < extendedModelColumn && modelRowSpan > 0)
                                            {
                                                --realColumn;
                                            }

                                            if (realColumn < children.size())
                                            {
                                                element = children.at(realColumn).toElement();

                                                extendedModelStr        = element.text().simplified();
                                                extendedModelNewRowSpan = element.attribute("rowspan", "1").toLongLong();
                                            }
                                            else
                                            {
                                                extendedModelStr        = "";
                                                extendedModelNewRowSpan = 1;
                                            }
                                        }
                                    }
                                }



                                // Update row spans
                                {
                                    microArchitectureRowSpan = microArchitectureNewRowSpan - 1;
                                    nameRowSpan              = nameNewRowSpan - 1;
                                    modelRowSpan             = modelNewRowSpan - 1;
                                    extendedModelRowSpan     = extendedModelNewRowSpan - 1;
                                }



                                // Check row spans
                                {
                                    if (
                                        microArchitectureRowSpan < 0
                                        ||
                                        nameRowSpan < 0
                                        ||
                                        modelRowSpan < 0
                                        ||
                                        extendedModelRowSpan < 0
                                       )
                                    {
                                        Console::err(QString("Error in row spans for %1 processors")
                                                                .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                        );

                                        return false;
                                    }
                                }



                                // Create models
                                {
                                    if (modelStr != "" && extendedModelStr != "")
                                    {
                                        // Get and verify model value
                                        {
                                            if (
                                                !modelStr.startsWith("0x")
                                                ||
                                                !extendedModelStr.startsWith("0x")
                                               )
                                            {
                                                Console::err(QString("Model value must be in HEX for %1 processors")
                                                                        .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                                );

                                                return false;
                                            }

                                            bool ok1;
                                            bool ok2;

                                            model = (extendedModelStr.mid(2).toLongLong(&ok1, 16) << 4) + modelStr.mid(2).toLongLong(&ok2, 16);

                                            if (!ok1 || !ok2)
                                            {
                                                Console::err(QString("Model value must be in HEX for %1 processors")
                                                                        .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                                );

                                                return false;
                                            }

                                            if (model > 255)
                                            {
                                                Console::err(QString("Model value is more than 255 for %1 processors")
                                                                        .arg(vendor.at(0).toUpper() + vendor.mid(1))
                                                );

                                                return false;
                                            }
                                        }



                                        // Get models names and create CpuModel for them
                                        {
                                            microArchitectureStr = microArchitectureStr.replace(' ', '_').remove('(').remove(')');

                                            // Remove brackets from name
                                            {
                                                do
                                                {
                                                    qint64 index = nameStr.indexOf('(');

                                                    if (index < 0)
                                                    {
                                                        break;
                                                    }

                                                    qint64 index2 = nameStr.indexOf(')', index + 1);

                                                    if (index2 < 0)
                                                    {
                                                        break;
                                                    }

                                                    nameStr.remove(index, index2 - index + 1);
                                                } while(true);

                                                do
                                                {
                                                    qint64 index = nameStr.indexOf('[');

                                                    if (index < 0)
                                                    {
                                                        break;
                                                    }

                                                    qint64 index2 = nameStr.indexOf(']', index + 1);

                                                    if (index2 < 0)
                                                    {
                                                        break;
                                                    }

                                                    nameStr.remove(index, index2 - index + 1);
                                                } while(true);
                                            }

                                            nameStr.remove('?');



                                            if (nameStr != "")
                                            {
                                                QStringList names = nameStr.split(',');

                                                for (qint64 i = 0; i < names.length(); ++i)
                                                {
                                                    QString name = names.at(i).trimmed();



                                                    // Update name
                                                    {
                                                        qint64 index  = nameStr.indexOf('\"');
                                                        qint64 index2 = nameStr.indexOf('\"', index + 1);

                                                        if (index >= 0 && index2 >= 0)
                                                        {
                                                            name = name.mid(index + 1, index2 - index - 1);
                                                        }

                                                        name = name.replace(' ', '_');
                                                    }



                                                    if (name.length() > 3 && name != "GT3E")
                                                    {
                                                        if (name != "ENGINEERING_SAMPLE")
                                                        {
                                                            CpuModel cpuModel;

                                                            cpuModel.name = QString("FAMILY_%1_%2")
                                                                                    .arg(family)
                                                                                    .arg(name);

                                                            cpuModel.family = family;
                                                            cpuModel.model  = model;

                                                            models.append(cpuModel);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        CpuModel cpuModel;

                                                        cpuModel.name = QString("FAMILY_%1_%2_%3")
                                                                                .arg(family)
                                                                                .arg(microArchitectureStr)
                                                                                .arg(name);

                                                        cpuModel.family = family;
                                                        cpuModel.model  = model;

                                                        models.append(cpuModel);
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (microArchitectureStr != "")
                                                {
                                                    CpuModel cpuModel;

                                                    cpuModel.name = QString("FAMILY_%1_%2")
                                                                            .arg(family)
                                                                            .arg(microArchitectureStr);

                                                    cpuModel.family = family;
                                                    cpuModel.model  = model;

                                                    models.append(cpuModel);
                                                }
                                            }
                                        }
                                    }
                                }



                                tableNode = tableNode.nextSibling();
                            }
                        }
                    }
                }
            }

            node = node.nextSibling();
        }
    }



    // Sort and optimize models
    {
        std::sort(models.begin(), models.end());

        for (qint64 i = 0; i < models.size(); ++i)
        {
            const CpuModel &cpuModel = models.at(i);

            for (qint64 j = i + 1; j < models.size(); ++j)
            {
                if (cpuModel.name == models.at(j).name)
                {
                    models.removeAt(i);

                    --i;

                    break;
                }
            }
        }
    }



    return true;
}

bool CpuModelGenerator::generateModels(const QString &/*vendor*/, const QString &/*path*/, const QList<CpuModel> &/*models*/)
{
    QStringList lines;



    // Add include lines
    {
        lines.append("#include <com/ngos/shared/common/cpu/lib/cpufamily.h>");
        lines.append("#include <com/ngos/shared/common/log/assert.h>");
        lines.append("#include <com/ngos/shared/common/log/log.h>");
        lines.append("#include <com/ngos/shared/common/ngos/types.h>");
        lines.append("#include <com/ngos/shared/common/printf/printf.h>");

        addThreeBlankLines(lines);
    }



    // qDebug() << lines.join('\n').toUtf8().data();



    // return save(path, lines);
    return true;
}



CpuModelGenerator cpuModelGeneratorInstance;
