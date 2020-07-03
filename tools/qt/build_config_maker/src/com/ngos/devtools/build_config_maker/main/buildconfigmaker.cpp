#include "buildconfigmaker.h"

#include <QFile>
#include <QIODevice>
#include <src/com/ngos/devtools/shared/console/console.h>



BuildConfigMaker::BuildConfigMaker(const QString &buildConfigPath, bool reset, QMap<QString, QString> parameters)
    : mBuildConfigPath(buildConfigPath)
    , mReset(reset)
    , mParameters(parameters)
{
    // Nothing
}

qint64 BuildConfigMaker::process()
{
    QFile file(mBuildConfigPath);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to read file \"%1\"").arg(mBuildConfigPath));

        return 2;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString &line = lines[i];

        if (line.endsWith('\r'))
        {
            line.remove(line.length() - 1, 1);
        }
    }



    if (mReset)
    {
        QString defaultValue;

        for (qint64 i = 0; i < lines.length(); ++i)
        {
            QString &line = lines[i];

            if (line.startsWith(" *** Default: "))
            {
                defaultValue = line.mid(14);
            }
            else
            if (line.startsWith("#define ") && defaultValue != "")
            {
                line         = line.left(line.lastIndexOf(' ') + 1) + defaultValue;
                defaultValue = "";
            }
        }
    }



    QMapIterator<QString, QString> it(mParameters);

    while (it.hasNext())
    {
        it.next();

        QString parameter = it.key();
        QString value     = it.value();

        QString parameterType = "";



        bool found = false;

        for (qint64 i = 0; i < lines.length(); ++i)
        {
            QString &line = lines[i];

            if (line.startsWith(" *** Type: "))
            {
                parameterType = line.mid(11);
            }
            else
            if (line.startsWith("#define " + parameter + ' '))
            {
                found = true;



                qint64 index = parameter.length() + 9;

                while (index < line.length() && line.at(index) == ' ')
                {
                    ++index;
                }



                if (parameterType == "Text")
                {
                    line = line.left(index) + '\"' + value + '\"';
                }
                else
                {
                    line = line.left(index) + value;
                }



                break;
            }
        }

        if (!found)
        {
            Console::err(QString("Parameter \"%1\" not found").arg(parameter));

            return 3;
        }
    }



    QString newContent = lines.join('\n');

    if (newContent != content)
    {
        if (!file.open(QIODevice::WriteOnly))
        {
            Console::err(QString("Failed to write file \"%1\"").arg(mBuildConfigPath));

            return 4;
        }

        file.write(newContent.toUtf8());
        file.close();



        Console::out(QString("%1 file updated").arg(mBuildConfigPath));
    }
    else
    {
        Console::out(QString("%1 file is up to date").arg(mBuildConfigPath));
    }



    return 0;
}
