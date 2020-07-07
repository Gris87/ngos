#include "mdstructureverifier.h"

#include <QDir>
#include <QFile>
#include <QFileInfo>

#include <com/ngos/devtools/docs_verifier/other/docsverificationfiletype.h>



MdStructureVerifier::MdStructureVerifier()
    : BaseDocsVerifier(DocsVerificationFileType::MD)
    , mSectionIdRegExp("^(\\d+\\.).*$")
    , mLinkRegExp("\\[([^\\]]*)\\]\\(([^)]*)\\)")
{
    // Nothing
}

void MdStructureVerifier::verify(DocsWorkerThread *worker, const QString &path, const QString &/*content*/, const QStringList &lines)
{
    QString parentFolder = path.left(path.lastIndexOf('/') + 1);

    qint64 startPos = 0;



    qint64 index = path.indexOf("/docs/");

    if (index >= 0)
    {
        QString relativePath = path.mid(index + 6);



        if (relativePath.endsWith("README.md"))
        {
            relativePath.remove(relativePath.length() - 9, 9);
        }
        else
        {
            worker->addError(path, -1, "File name should be README.md");
        }



        if (relativePath.endsWith('/'))
        {
            relativePath.remove(relativePath.length() - 1, 1);
        }



        if (
            !lines.length() // lines.length() <= 0
            ||
            lines.at(0) != "NGOS"
           )
        {
            worker->addError(path, 0, "Invalid line. Expected: NGOS");
        }



        if (
            lines.length() <= 1
            ||
            lines.at(1) != "===="
           )
        {
            worker->addError(path, 1, "Invalid line. Expected: ====");
        }



        if (
            lines.length() <= 2
            ||
            lines.at(2) != ""
           )
        {
            worker->addWarning(path, 2, "Expected blank line after section");
        }



        QStringList pathParts = relativePath.split('/');

        if (
            pathParts.length() == 1
            &&
            pathParts.at(0) == ""
           )
        {
            startPos = 3;
        }
        else
        {
            startPos = 6;



            QString sectionName;

            for (qint64 i = 0; i < pathParts.length() - 1; ++i)
            {
                QString                 pathPart = pathParts.at(i);
                QRegularExpressionMatch match    = mSectionIdRegExp.match(pathPart);

                if (match.hasMatch())
                {
                    sectionName.append(match.captured(1));
                }
                else
                {
                    worker->addError(path, -1, QString("Section name %1 should start with digit").arg(pathPart));
                }
            }



            QString                 lastPathPart = pathParts.at(pathParts.length() - 1);
            QRegularExpressionMatch match        = mSectionIdRegExp.match(lastPathPart);

            if (match.hasMatch())
            {
                sectionName.append(lastPathPart);
            }
            else
            {
                worker->addError(path, -1, QString("Section name %1 should start with digit").arg(lastPathPart));
            }



            if (
                lines.length() <= 3
                ||
                lines.at(3) != sectionName
               )
            {
                worker->addError(path, 3, QString("Invalid line. Expected: %1").arg(sectionName));
            }



            QString sectionHeader(sectionName.length(), '-');

            if (
                lines.length() <= 4
                ||
                lines.at(4) != sectionHeader
               )
            {
                worker->addError(path, 4, QString("Invalid line. Expected: %1").arg(sectionHeader));
            }



            if (
                lines.length() <= 5
                ||
                lines.at(5) != ""
               )
            {
                worker->addWarning(path, 5, "Expected blank line after section");
            }
        }



        QDir docDir(parentFolder);
        QStringList subFolders = docDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

        for (qint64 i = 0; i < subFolders.length(); ++i)
        {
            QString subFolder = subFolders.at(i);

            if (QFile::exists(parentFolder + '/' + subFolder + "/README.md"))
            {
                QString sectionName = subFolder.mid(subFolder.indexOf('.') + 1).trimmed();
                QString sectionLink = subFolder.replace(' ', "%20") + "/README.md";



                QString search = QString("* [%1](%2)").arg(sectionName).arg(sectionLink);

                bool found = false;

                for (qint64 j = startPos; j < lines.length(); ++j)
                {
                    QString line        = lines.at(j);
                    QString lineTrimmed = line.trimmed();

                    if (lineTrimmed.startsWith(search))
                    {
                        found = true;

                        break;
                    }
                }



                if (!found)
                {
                    worker->addError(path, -1, QString("Link to subsection not found: %1").arg(search));
                }
            }
        }
    }
    else
    {
        QString sectionName = lines.length() ? lines.at(0) : ""; // lines.length() > 0

        if (sectionName != "")
        {
            startPos = 3;



            QString sectionHeader(sectionName.length(), '=');

            if (
                lines.length() <= 1
                ||
                lines.at(1) != sectionHeader
               )
            {
                worker->addError(path, 1, QString("Invalid line. Expected: %1").arg(sectionHeader));
            }



            if (
                lines.length() <= 2
                ||
                lines.at(2) != ""
               )
            {
                worker->addWarning(path, 2, "Expected blank line after section");
            }
        }
        else
        {
            worker->addError(path, 0, "First line should be a header");
        }
    }



    for (qint64 i = startPos; i < lines.length(); ++i)
    {
        QString line        = lines.at(i);
        QString lineTrimmed = line.trimmed();



        if (
            line.startsWith('=')
            ||
            line.startsWith('-')
           )
        {
            bool isHeader = true;

            for (qint64 j = 1; j < lineTrimmed.length(); ++j)
            {
                if (lineTrimmed.at(j) != lineTrimmed.at(0))
                {
                    isHeader = false;

                    break;
                }
            }



            if (isHeader)
            {
                QString sectionName = i > 0 ? lines.at(i - 1) : "";

                if (sectionName != "")
                {
                    QString sectionHeader(sectionName.length(), line.at(0));

                    if (line != sectionHeader)
                    {
                        worker->addError(path, i, QString("Invalid line. Expected: %1").arg(sectionHeader));
                    }



                    QString nextLine = i + 1 < lines.length() ? lines.at(i + 1) : "";

                    if (nextLine == "")
                    {
                        ++i;

                        continue;
                    }
                    else
                    {
                        worker->addWarning(path, i + 1, "Expected blank line after section");
                    }
                }
                else
                {
                    worker->addWarning(path, i, "Section name not found");
                }
            }
        }



        QRegularExpressionMatchIterator matches = mLinkRegExp.globalMatch(line);

        while (matches.hasNext())
        {
            QRegularExpressionMatch match = matches.next();

            QString linkText = match.captured(1).trimmed();
            QString linkUrl  = match.captured(2).trimmed();

            QString linkUrlOriginal = linkUrl;



            if (linkText == "")
            {
                worker->addError(path, i, QString("Empty text specified for link: %1").arg(linkUrlOriginal));
            }



            if (
                !linkUrl.startsWith("http://") // Ignore CppPunctuationVerifier
                &&
                !linkUrl.startsWith("https://") // Ignore CppPunctuationVerifier
               )
            {
                QString linkMarker;



                qint64 index2 = linkUrl.indexOf('#');

                if (index2 >= 0)
                {
                    linkMarker = linkUrl.mid(index2 + 1);
                    linkUrl    = linkUrl.left(index2);
                }



                QString targetFile = parentFolder + '/' + linkUrl.replace("%20", QChar(' '));

                if (QFileInfo(targetFile).exists())
                {
                    if (linkMarker != "")
                    {
                        QFile file(targetFile);

                        if (file.open(QIODevice::ReadOnly))
                        {
                            QString anotherContent = QString::fromUtf8(file.readAll());
                            file.close();



                            QStringList anotherLines = anotherContent.split('\n');



                            bool found = false;

                            for (qint64 j = 0; j < anotherLines.length(); ++j)
                            {
                                QString anotherLine = anotherLines.at(j).trimmed();
                                QString sectionName;



                                if (anotherLine.startsWith('#'))
                                {
                                    sectionName = anotherLine;

                                    while (sectionName.startsWith('#'))
                                    {
                                        sectionName.remove(0, 1);
                                    }

                                    sectionName = sectionName.trimmed();
                                }
                                else
                                if (
                                    j < anotherLines.length() - 1
                                    &&
                                    (
                                     (
                                      anotherLines.at(j + 1).startsWith('-')
                                      &&
                                      anotherLines.at(j + 1) == QString(anotherLine.length(), '-')
                                     )
                                     ||
                                     (
                                      anotherLines.at(j + 1).startsWith('=')
                                      &&
                                      anotherLines.at(j + 1) == QString(anotherLine.length(), '=')
                                     )
                                    )
                                   )
                                {
                                    sectionName = anotherLine;
                                }



                                if (sectionName != "")
                                {
                                    sectionName = sectionName.toLower().replace(' ', '-').remove('.').remove('=');

                                    if (sectionName == linkMarker)
                                    {
                                        found = true;

                                        break;
                                    }
                                }
                            }

                            if (!found)
                            {
                                worker->addError(path, i, QString("Invalid marker specified in link: %1").arg(linkUrlOriginal));
                            }
                        }
                        else
                        {
                            worker->addError(path, i, QString("Invalid link specified: %1").arg(linkUrlOriginal));
                        }
                    }
                }
                else
                {
                    worker->addError(path, i, QString("Invalid link specified: %1").arg(linkUrlOriginal));
                }
            }
        }
    }
}



MdStructureVerifier mdStructureVerifierInstance;
