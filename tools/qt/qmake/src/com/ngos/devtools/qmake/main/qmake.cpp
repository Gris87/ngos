#include "qmake.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <QXmlStreamReader>
#include <buildconfig.h>
#include <console/console.h>

#include "src/com/ngos/devtools/qmake/threads/searchdependenciesthread.h"



QMake::QMake(const QString &pathToProFile)
    : mPathToProFile(pathToProFile)
    , mCommentRegexp("^((?:[^\\\"#]+(?:\\\"[^\\\"]*\\\")?)*)#.*$")
    , mEntryRegexp("^ *(\\w+) *([+-]?=) *(.*)$")
    , mEntryValueRegexp("(\\\"[^\\\"]*\\\"|[^ ]+)")
    , mIncludeRegexp("^ *include\\((.*)\\).*$")
    , mEntries()
    , mSourceToObjectMap()
    , mMakefileDependencies()
{
    // Nothing
}

qint64 QMake::process()
{
    QFileInfo fileInfo         = QFileInfo(mPathToProFile);
    QString   workingDirectory = fileInfo.absolutePath();



    qint64 res = processInWorkingDirectory(workingDirectory, fileInfo.fileName());

    if (res != 0)
    {
        return res;
    }



    return generateMakefile(workingDirectory);
}

qint64 QMake::processInWorkingDirectory(const QString &workingDirectory, const QString &proFileName)
{
    QString pathToProFile = workingDirectory + '/' + proFileName;

    mMakefileDependencies.append(pathToProFile);



    QFile file(pathToProFile);

    if (!file.open(QIODevice::ReadOnly))
    {
        Console::err(QString("Failed to read file \"%1\"").arg(pathToProFile));

        return 1;
    }

    QString content = QString::fromUtf8(file.readAll());
    file.close();



    QStringList lines = content.split('\n');

    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i).trimmed();

        QRegularExpressionMatch match = mCommentRegexp.match(line);

        if (match.hasMatch())
        {
            line = match.captured(1).trimmed();
        }

        lines[i] = line;
    }



    return processLines(workingDirectory, lines);
}

qint64 QMake::processLines(const QString &workingDirectory, const QStringList &lines)
{
    for (qint64 i = 0; i < lines.length(); ++i)
    {
        QString line = lines.at(i);



        if (line == "")
        {
            continue;
        }



        QRegularExpressionMatch match = mEntryRegexp.match(line);

        if (match.hasMatch())
        {
            QString entryName     = match.captured(1);
            QString entryOperator = match.captured(2);
            QString entryValue    = match.captured(3);



            while (entryValue.endsWith('\\'))
            {
                do
                {
                    entryValue.remove(entryValue.length() - 1, 1);
                } while(entryValue.endsWith('\\'));

                entryValue = entryValue.trimmed();

                ++i;

                if (i < lines.length())
                {
                    entryValue = entryValue + ' ' + lines.at(i);
                }
            }



            qint64 res = parseEntry(workingDirectory, entryName, entryOperator, entryValue);

            if (res != 0)
            {
                return res;
            }



            continue;
        }



        match = mIncludeRegexp.match(line);

        if (match.hasMatch())
        {
            QString includePath = match.captured(1);
            includePath.remove("$$PWD/");

            QFileInfo fileInfo            = QFileInfo(workingDirectory + '/' + includePath);
            QString   workingSubDirectory = fileInfo.absolutePath();



            qint64 res = processInWorkingDirectory(workingSubDirectory, fileInfo.fileName());

            if (res != 0)
            {
                return res;
            }



            continue;
        }



        Console::err(QString("Ignoring line: %1").arg(line));
    }



    return 0;
}

qint64 QMake::parseEntry(const QString &workingDirectory, const QString &entryName, const QString &entryOperator, const QString &entryValue)
{
    QStringList                     values;
    QRegularExpressionMatchIterator matches = mEntryValueRegexp.globalMatch(entryValue);

    while (matches.hasNext())
    {
        QRegularExpressionMatch match = matches.next();

        QString value = match.captured(0);
        value.replace("$$PWD", workingDirectory);

        values.append(value);
    }

    values.removeDuplicates();



    if (entryOperator == '=')
    {
        mEntries.insert(entryName, values);
    }
    else
    if (entryOperator == "+=")
    {
        QStringList &entryValues = mEntries[entryName];
        entryValues.append(values);
        entryValues.removeDuplicates();
    }
    else
    if (entryOperator == "-=")
    {
        QStringList &entryValues = mEntries[entryName];

        for (qint64 i = 0; i < values.length(); ++i)
        {
            entryValues.removeOne(values.at(i));
        }
    }
    else
    {
        Console::err(QString("Unexpected operator %1").arg(entryOperator));
    }



    return 0;
}

qint64 QMake::generateMakefile(const QString &workingDirectory)
{
    if (!mEntries.contains("TEMPLATE"))
    {
        Console::err("TEMPLATE not specified in pro file");

        return 1;
    }



    QString templateValue = mEntries.value("TEMPLATE").join(' ');

    if (templateValue == "subdirs")
    {
        return generateSubdirsMakefile(workingDirectory);
    }

    if (
        templateValue == "app"
        ||
        templateValue == "lib"
        ||
        templateValue == "uefi"
        ||
        templateValue == "kernel"
       )
    {
        return generateApplicationMakefile(workingDirectory, templateValue);
    }



    Console::err(QString("Unexpected TEMPLATE value: %1").arg(templateValue));

    return 1;
}

qint64 QMake::generateSubdirsMakefile(const QString &workingDirectory)
{
    if (!mEntries.contains("SUBDIRS"))
    {
        Console::err("SUBDIRS not specified in pro file");

        return 1;
    }



    QStringList lines;

    lines.append("####################################");
    lines.append("# Makefile definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("QMAKE = " + qApp->applicationFilePath());
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Project specific definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("SUBDIRS = " + mEntries.value("SUBDIRS").join(' '));
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append(".NOTPARALLEL:");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Targets:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("all: Makefile $(SUBDIRS)");
    lines.append("");
    lines.append("clean: Makefile $(SUBDIRS)");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("$(SUBDIRS):");
    lines.append("\tbash -c \"cd $@ && lupdate -noobsolete $@.pro && lrelease $@.pro && $(QMAKE) $@.pro && make -j`nproc` $(MAKECMDGOALS)\"");



    return save(workingDirectory, lines, "$(SUBDIRS)");
}

qint64 QMake::generateApplicationMakefile(const QString &workingDirectory, const QString &templateValue)
{
    if (!mEntries.contains("SOURCES"))
    {
        Console::err("SOURCES not specified in pro file");

        return 1;
    }

    if (!mEntries.contains("TARGET"))
    {
        Console::err("TARGET not specified in pro file");

        return 1;
    }



    // Ignore CppAlignmentVerifier [BEGIN]
    QStringList lines;

    lines.append("####################################");
    lines.append("# Makefile definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("QMAKE = " + qApp->applicationFilePath());
    lines.append("");
    lines.append("CC    = x86_64-elf-gcc");
    lines.append("CXX   = x86_64-elf-g++");
    lines.append("LD    = x86_64-elf-ld");
    lines.append("");
    lines.append("MKDIR = mkdir -p");
    lines.append("RMDIR = rm -rf");
    lines.append("CAT   = cat");
    lines.append("GZIP  = gzip");
    lines.append("XZ    = xz");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Project specific definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("TARGET              = " + mEntries.value("TARGET").join(' '));
    lines.append("");
    // Ignore CppAlignmentVerifier [END]



    QString tail;



    const QStringList &config = mEntries.value("CONFIG");

    if (config.contains("c++17"))
    {
        lines.append("CPP_STANDARD        = -std=c++17");
    }
    else
    if (config.contains("c++14"))
    {
        lines.append("CPP_STANDARD        = -std=c++14");
    }
    else
    if (config.contains("c++11"))
    {
        lines.append("CPP_STANDARD        = -std=c++11");
    }
    else
    {
        lines.append("CPP_STANDARD        = -std=c++17");
    }

    tail += " $(CPP_STANDARD)";



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    lines.append("DEBUG_FLAGS         = -g");

    tail += " $(DEBUG_FLAGS)";
#endif



#if NGOS_BUILD_OPTIMIZATION_LEVEL == OPTION_OPTIMIZATION_LEVEL_0
    lines.append("OPTIMIZATION_FLAGS  = -O0");
#elif NGOS_BUILD_OPTIMIZATION_LEVEL == OPTION_OPTIMIZATION_LEVEL_1
    lines.append("OPTIMIZATION_FLAGS  = -O1");
#elif NGOS_BUILD_OPTIMIZATION_LEVEL == OPTION_OPTIMIZATION_LEVEL_2
    lines.append("OPTIMIZATION_FLAGS  = -O2");
#elif NGOS_BUILD_OPTIMIZATION_LEVEL == OPTION_OPTIMIZATION_LEVEL_3
    lines.append("OPTIMIZATION_FLAGS  = -O3");
#else
#error Unexpected value for NGOS_BUILD_OPTIMIZATION_LEVEL parameter
#endif

    tail += " $(OPTIMIZATION_FLAGS)";



    QString vectorizationFlags = "-msse -msse2 -mfpmath=sse";

    if (templateValue != "uefi")
    {
#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_SSE3
        vectorizationFlags += " -msse3 -mssse3";
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_SSE4
        vectorizationFlags += " -msse4 -msse4.1 -msse4.2";
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX
        vectorizationFlags += " -mavx";
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX2
        vectorizationFlags += " -mavx2";
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V1
        vectorizationFlags += " -mavx512f -mavx512cd -mavx512er -mavx512pf";
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V2
        vectorizationFlags += " -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl";
#endif

#if NGOS_BUILD_X86_64_VECTORIZATION_MODE >= OPTION_X86_64_VECTORIZATION_MODE_AVX_512_V3
        vectorizationFlags += " -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -mavx512ifma -mavx512vbmi";
#endif
    }

    lines.append("VECTORIZATION_FLAGS = " + vectorizationFlags);

    tail += " $(VECTORIZATION_FLAGS)";



    if (templateValue == "uefi")
    {
        lines.append("FMA_FLAGS           = -mno-fma");
    }
    else
    {
#if NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_NONE
        lines.append("FMA_FLAGS           = -mno-fma");
#elif NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA4
        lines.append("FMA_FLAGS           = -mfma4");
#elif NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD == OPTION_X86_64_FUSED_MULTIPLY_ADD_FMA3
        lines.append("FMA_FLAGS           = -mfma");
#else
#error Unexpected value for NGOS_BUILD_X86_64_FUSED_MULTIPLY_ADD parameter
#endif
    }

    tail += " $(FMA_FLAGS)";



    const QStringList &defines = mEntries.value("DEFINES");

    if (defines.length() > 0)
    {
        if (defines.length() > 1)
        {
            lines.append("");
            lines.append("DEFINES             = \\");

            for (qint64 i = 0; i < defines.length(); ++i)
            {
                lines.append("\t-D" + defines.at(i) + (i < defines.length() - 1 ? " \\" : ""));
            }
        }
        else
        {
            lines.append("DEFINES             = -D" + defines.at(0));
        }

        tail += " $(DEFINES)";
    }



    const QStringList &includes = mEntries.value("INCLUDEPATH");

    if (includes.length() > 0)
    {
        lines.append("");
        lines.append("# Includes:");
        lines.append("# .                               # " + workingDirectory);

        for (qint64 i = 0; i < includes.length(); ++i)
        {
            QString include = includes.at(i);

            lines.append(QString("# %1 %2 # %3").arg(include).arg("", 30 - include.length(), QChar(' ')).arg(QFileInfo(workingDirectory + '/' + include).absoluteFilePath()));
        }



        lines.append("INCLUDES            = \\");
        lines.append("\t-I . \\");

        for (qint64 i = 0; i < includes.length(); ++i)
        {
            lines.append("\t-I " + includes.at(i) + (i < includes.length() - 1 ? " \\" : ""));
        }
    }
    else
    {
        if (defines.length() > 1)
        {
            lines.append("");
        }

        lines.append("INCLUDES            = -I .    # " + workingDirectory);
    }

    tail += " $(INCLUDES)";



    lines.append("");
    lines.append("CFLAGS              = " + mEntries.value("QMAKE_CFLAGS").join(' ') + tail);
    lines.append("CXXFLAGS            = -m64 -W -Wall -Werror -Wno-address-of-packed-member -nostdinc -mno-red-zone -fPIE -ffreestanding -fno-strict-aliasing -fno-stack-protector -fomit-frame-pointer -fno-exceptions -fno-asynchronous-unwind-tables -fno-unwind-tables " + mEntries.value("QMAKE_CXXFLAGS").join(' ') + tail);
    lines.append("LFLAGS              = " + mEntries.value("QMAKE_LFLAGS").join(' '));
    lines.append("");
    lines.append("OUTPUT_DIR          = build");
    lines.append("");



    qint64 res = addApplicationObjectsDefinitions(workingDirectory, lines);

    if (res != 0)
    {
        return res;
    }



    res = addApplicationBuildTargets(workingDirectory, templateValue, lines);

    if (res != 0)
    {
        return res;
    }



    return save(workingDirectory, lines);
}

qint64 QMake::addApplicationObjectsDefinitions(const QString & /*workingDirectory*/, QStringList &lines)
{
    lines.append("OBJECTS             = \\");



    if (mEntries.contains("RESOURCES"))
    {
        lines.append("\t$(OUTPUT_DIR)/assets/assets.o \\");
    }



    const QStringList &sources = mEntries.value("SOURCES");

    for (qint64 i = 0; i < sources.length(); ++i)
    {
        QString originalSource = sources.at(i);
        QString source         = originalSource;



        if (source.endsWith(".cpp"))
        {
            source.remove(source.length() - 4, 4);
        }
        else
        if (source.endsWith(".S"))
        {
            source.remove(source.length() - 2, 2);
        }
        else
        {
            Console::err(QString("Unexpected source: %1").arg(source));

            return 1;
        }

        if (source.startsWith('/'))
        {
            source.remove(0, 1);
        }



        QString object = "$(OUTPUT_DIR)/" + source + ".o";

        mSourceToObjectMap.insert(originalSource, object);
        lines.append('\t' + object + (i < sources.length() - 1 ? " \\" : ""));
    }



    return 0;
}

qint64 QMake::addApplicationBuildTargets(const QString &workingDirectory, const QString &templateValue, QStringList &lines)
{
    bool   hasErrors    = false;
    qint64 workersCount = QThread::idealThreadCount();

    SearchDependenciesThread::init(mEntries.value("INCLUDEPATH"), mEntries.value("SOURCES"), workersCount);



    QList<SearchDependenciesThread *> threads;

    for (qint64 i = 0; i < workersCount; ++i)
    {
        SearchDependenciesThread *thread = new SearchDependenciesThread(workingDirectory);
        thread->start();
        threads.append(thread);
    }



    QString     additionalLdDependencies = "";
    QStringList lFlags                   = mEntries.value("QMAKE_LFLAGS");

    for (qint64 i = 0; i < lFlags.length(); ++i)
    {
        const QString &flag = lFlags.at(i);

        if (flag == "-T")
        {
            if (i < lFlags.length() - 1)
            {
                ++i;

                additionalLdDependencies += ' ' + lFlags.at(i);
            }
        }
    }



    QString extension;

    if (templateValue == "uefi" || templateValue == "kernel")
    {
        extension = ".elf";
    }
    else
    if (templateValue == "app")
    {
        extension = ".ngexe";
    }
    else
    if (templateValue == "lib")
    {
        extension = ".ngso";
    }
    else
    {
        Console::err(QString("Unexpected template value: %1").arg(templateValue));

        hasErrors = true;
    }



    QString compression;

    if (templateValue == "kernel")
    {
#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_NONE
        // Nothing
#elif NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP
        compression = ".gz";
#elif NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ
        compression = ".xz";
#else
#error Unexpected value for NGOS_BUILD_KERNEL_COMPRESSION parameter
#endif
    }



    // Ignore CppAlignmentVerifier [BEGIN]
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("####################################");
    lines.append("# Target definitions:");
    lines.append("####################################");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("all: Makefile $(OUTPUT_DIR)/$(TARGET)" + extension + compression);
    lines.append("");
    lines.append("clean: Makefile");
    lines.append("\t$(RMDIR) $(OUTPUT_DIR)");
    lines.append("");
    lines.append("");
    lines.append("");
    lines.append("$(OUTPUT_DIR)/$(TARGET)" + extension + compression + ": $(OBJECTS)" + additionalLdDependencies);
    lines.append("\t$(LD) $(LFLAGS) $(OBJECTS) -o $(OUTPUT_DIR)/$(TARGET)" + extension);
    // Ignore CppAlignmentVerifier [END]

    if (templateValue == "kernel")
    {
#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_NONE
        // Nothing
#elif NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP
        lines.append("\t$(CAT) $(OUTPUT_DIR)/$(TARGET)" + extension + " | $(GZIP) -n -f -9 > $@");
#elif NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ
#if NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
        lines.append("\t$(CAT) $(OUTPUT_DIR)/$(TARGET)" + extension + " | $(XZ) --x86 --lzma2=dict=128MiB > $@");
#else
        lines.append("\t$(CAT) $(OUTPUT_DIR)/$(TARGET)" + extension + " | $(XZ) --lzma2=dict=128MiB > $@");
#endif
#else
#error Unexpected value for NGOS_BUILD_KERNEL_COMPRESSION parameter
#endif
    }



    qint64 res = addResourcesBuildTargets(workingDirectory, lines);

    if (res != 0)
    {
        hasErrors = true;
    }



    for (qint64 i = 0; i < threads.length(); ++i)
    {
        SearchDependenciesThread *thread = threads.at(i);
        thread->wait();



        QStringList errors = thread->getErrors();

        for (qint64 j = 0; j < errors.length(); ++j)
        {
            Console::err(errors.at(j));
        }



        delete thread;
    }



    if (hasErrors)
    {
        return 1;
    }



    QHash<QString, QStringList> dependenciesMap = SearchDependenciesThread::buildDependenciesMap();

    QMapIterator<QString, QString> it(mSourceToObjectMap);

    while (it.hasNext())
    {
        it.next();

        QString source = it.key();
        QString object = it.value();



        if (!dependenciesMap.contains(source))
        {
            Console::err(QString("Dependencies not found for source: %1").arg(source));

            return 1;
        }

        QStringList dependencies = dependenciesMap.value(source);



        lines.append("");
        lines.append("");
        lines.append("");
        lines.append(QString("%1: %2 %3").arg(object).arg(source).arg(dependencies.join(' ')));

        if (source.endsWith(".cpp"))
        {
            lines.append("\t$(MKDIR) $(@D)");
            lines.append("\t$(CXX) -c $(CXXFLAGS) -E $< -o $@.cpp");
            lines.append("\t$(CXX) -c $(CXXFLAGS) -S $< -o $@.S");
            lines.append("\t$(CXX) -c $(CXXFLAGS) $< -o $@");
        }
        else
        if (source.endsWith(".S"))
        {
            lines.append("\t$(MKDIR) $(@D)");
            lines.append("\t$(CC) -c $(CFLAGS) $< -o $@");
        }
        else
        {
            Console::err(QString("Unexpected source: %1").arg(source));

            return 1;
        }
    }



    return 0;
}

qint64 QMake::addResourcesBuildTargets(const QString &workingDirectory, QStringList &lines)
{
    const QStringList &resources = mEntries.value("RESOURCES");

    if (resources.length() > 0)
    {
        if (!QDir().mkpath(workingDirectory + "/build/assets"))
        {
            Console::err("Failed to create build/assets directory");

            return 1;
        }



        QFile assetsFile(workingDirectory + "/build/assets/assets.S");

        if (!assetsFile.open(QIODevice::WriteOnly))
        {
            Console::err("Failed to create build/assets/assets.S file");

            return 1;
        }



        qint64 fileId = 0;

        // Ignore CppAlignmentVerifier [BEGIN]
        assetsFile.write(".section \".assets\", \"a\"                                                                                    # assets section (a - allocatable)\n");
        assetsFile.write("                                                                                                           #\n");
        assetsFile.write("# ======================================================================================================== # =============================================================================\n");
        // Ignore CppAlignmentVerifier [END]



        QString assetsDependencies = resources.join(' ');

        for (qint64 i = 0; i < resources.length(); ++i)
        {
            QString resource = resources.at(i);
            mMakefileDependencies.append(resource);



            QFile resourceFile(workingDirectory + '/' + resource);

            if (!resourceFile.open(QIODevice::ReadOnly))
            {
                Console::err(QString("Failed to open %1 file").arg(resource));

                assetsFile.close();

                return 1;
            }



            QXmlStreamReader xml(&resourceFile);

            while (!xml.atEnd() && !xml.hasError())
            {
                QXmlStreamReader::TokenType token = xml.readNext();

                if (token == QXmlStreamReader::StartElement)
                {
                    if (xml.name() == "file")
                    {
                        QString asset;

                        while (token != QXmlStreamReader::EndElement)
                        {
                            token = xml.readNext();

                            if (token == QXmlStreamReader::Characters)
                            {
                                asset += xml.text();
                            }
                        }

                        QString assetPath  =  workingDirectory + '/' + asset;
                        assetsDependencies += ' ' + assetPath;

                        if (asset.startsWith("assets/"))
                        {
                            asset.remove(0, 7);
                        }



                        ++fileId;

                        // Ignore CppAlignmentVerifier [BEGIN]
                        assetsFile.write("                                                                                                           #\n");
                        assetsFile.write(QString("    .ascii  \"%1\" %2 # File %1\n").arg(asset).arg("", 91 - asset.length(), QChar(' ')).toUtf8());
                        assetsFile.write("    .byte   0                                                                                              # Terminate file name with zero\n");
                        assetsFile.write(QString("    .quad   label_%1_end - label_%1_begin %2 # File size\n").arg(fileId).arg("", 68 - (QString::number(fileId).length() * 2), QChar(' ')).toUtf8());
                        assetsFile.write("                                                                                                           #\n");
                        assetsFile.write(QString("label_%1_begin: %2 # Begin of the file\n").arg(fileId).arg("", 92 - QString::number(fileId).length(), QChar(' ')).toUtf8());
                        assetsFile.write(QString("    .incbin  \"%1\" %2 # Including bytes of the file\n").arg(assetPath).arg("", 90 - assetPath.length(), QChar(' ')).toUtf8());
                        assetsFile.write(QString("label_%1_end: %2 # End of the file\n").arg(fileId).arg("", 94 - QString::number(fileId).length(), QChar(' ')).toUtf8());
                        assetsFile.write("                                                                                                           #\n");
                        assetsFile.write("# -------------------------------------------------------------------------------------------------------- # -----------------------------------------------------------------------------\n");
                        // Ignore CppAlignmentVerifier [END]
                    }
                }
            }
        }



        lines.append("");
        lines.append("");
        lines.append("");
        lines.append("$(OUTPUT_DIR)/assets/assets.o: " + assetsDependencies);
        lines.append("\t$(MKDIR) $(@D)");
        lines.append("\t$(CC) -c $(CFLAGS) $(OUTPUT_DIR)/assets/assets.S -o $@");



        assetsFile.close();
    }

    return 0;
}

qint64 QMake::save(const QString &workingDirectory, const QStringList &lines, const QString &phony)
{
    QFile file(workingDirectory + "/Makefile");

    if (!file.open(QIODevice::WriteOnly))
    {
        Console::err("Failed to create Makefile");

        return 1;
    }



    file.write("####################################\n");
    file.write("# Makefile generated by qmake (NGOS)\n");
    file.write("####################################\n");
    file.write("\n\n\n");
    file.write(lines.join('\n').toUtf8());
    file.write("\n"); // Ignore CppSingleCharVerifier

    if (phony != "")
    {
        file.write("\n\n\n");
        file.write(QString(".PHONY: %1\n").arg(phony).toUtf8());
    }

    file.write("\n\n\n");
    file.write("####################################\n");
    file.write("# Makefile target:\n");
    file.write("####################################\n");
    file.write("\n\n\n");
    file.write(QString("Makefile: $(QMAKE) %1\n").arg(mMakefileDependencies.join(' ')).toUtf8());
    file.write(QString("\t$(QMAKE) %1\n").arg(mMakefileDependencies.at(0)).toUtf8());



    file.close();

    return 0;
}
