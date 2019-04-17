#include "gdbprocess.h"

#include <QDebug>
#include <QTemporaryFile>

#include "src/other/defines.h"
#include "src/other/global.h"



#define PATH_TO_CONFIGURE_ELF "src/os/configure/build/configure.elf"



GdbProcess::GdbProcess(const QStringList &qemuOutput)
    : mQemuOutput(qemuOutput)
    , mMutex()
    , mProcess()
    , mElfObject()
    , mMemoryDump()
    , mKernelLocation(0)
    , mCurrentPosition(0)
{
    // Nothing
}

GdbProcess::~GdbProcess()
{
    mProcess.kill();
    mProcess.waitForFinished();
}

void GdbProcess::start(bool *isRunning)
{
    mProcess.setWorkingDirectory(Global::sProjectDir);
    mProcess.start("gdb 2>&1");
    mProcess.waitForStarted();



    if (isRunning && !(*isRunning))
    {
        return;
    }



    if (!mElfObject.read(Global::sProjectDir + '/' + PATH_TO_CONFIGURE_ELF, isRunning))
    {
        qDebug() << "Failed to read file: " << PATH_TO_CONFIGURE_ELF;

        return;
    }



    QByteArray programBytes        = mElfObject.getProgramBytes();
    ElfSymbol *gdbBreakpointSymbol = mElfObject.getSymbol("gdbDebugBreakpointFunction");



    if (isRunning && !(*isRunning))
    {
        return;
    }



    readOutput(isRunning);



    if (isRunning && !(*isRunning))
    {
        return;
    }



    executeCommand("set architecture i386:x86-64:intel", isRunning); // Ignore CppPunctuationVerifier
    updateCurrentPositionFromOutput(executeCommand("target remote :1234", isRunning)); // Ignore CppPunctuationVerifier



    if (isRunning && !(*isRunning))
    {
        return;
    }



    quint64 kernelLocation = 0;

    for (qint64 i = mQemuOutput.length() - 1; i >= 0; --i)
    {
        QString line = mQemuOutput.at(i);

        qint64 index = line.indexOf("Kernel started at address");

        if (index >= 0)
        {
            QString kernelAddress = line.mid(index + 25).trimmed();

            if (kernelAddress.startsWith("0x"))
            {
                kernelAddress.remove(0, 2);
            }



            bool ok = false;

            kernelLocation = kernelAddress.toULongLong(&ok, 16);

            if (ok)
            {
                break;
            }
        }
    }



    if (gdbBreakpointSymbol)
    {
        executeCommand("break *0x" + QString("%1").arg(kernelLocation + gdbBreakpointSymbol->value, 16, 16, QChar('0')), isRunning);
        continueExecution(isRunning);

        readOutput(isRunning);
        executeCommand("delete breakpoints", isRunning);

        updateCurrentPositionFromOutput(executeCommand("finish"));
    }



    QTemporaryFile tempFile;

    tempFile.open();
    QString tempFilePath = tempFile.fileName();
    tempFile.close();



    if (isRunning && !(*isRunning))
    {
        return;
    }



    executeCommand("dump binary memory " + tempFilePath + " 0x0000000000000000 0x" + QString("%1").arg(MEMORY_SIZE_MB * MB_SIZE, 16, 16, QChar('0')), isRunning);



    if (isRunning && !(*isRunning))
    {
        return;
    }



    QFile file(tempFilePath);

    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd() && (!isRunning || *isRunning))
        {
            mMemoryDump.append(file.read(4096));
        }

        file.close();
    }



    if (
        kernelLocation < (quint64)mMemoryDump.length()
        &&
        programBytes.length() // programBytes.length() > 0
        &&
        mMemoryDump.mid(kernelLocation, 10) == programBytes.mid(0, 10)
       )
    {
        mKernelLocation = kernelLocation;
    }
    else
    {
        qDebug() << "Kernel location not found";

        return;
    }
}

void GdbProcess::lock()
{
    mMutex.lock();
}

void GdbProcess::unlock()
{
    mMutex.unlock();
}

QString GdbProcess::executeCommand(const QString &command, bool *isRunning)
{
    mProcess.write(command.toUtf8());
    mProcess.write("\n"); // Ignore CppSingleCharVerifier
    mProcess.waitForBytesWritten();

    return readOutput(isRunning);
}

QString GdbProcess::readOutput(bool *isRunning)
{
    QByteArray res;

    while (!isRunning || *isRunning)
    {
        mProcess.waitForReadyRead(100);

        res.append(mProcess.readAll());

        if (res.endsWith("(gdb) "))
        {
            break;
        }
        else
        if (res == "Continuing.\n")
        {
            return "Continuing.";
        }
    }



    if (isRunning && !(*isRunning))
    {
        return "";
    }



    res.remove(res.length() - 6, 6);

    if (res.endsWith('\n'))
    {
        res.remove(res.length() - 1, 1);
    }



    return QString::fromUtf8(res);
}

void GdbProcess::updateCurrentPositionFromOutput(const QString &output)
{
    qint64 index = output.lastIndexOf("0x");

    if (index < 0)
    {
        qCritical() << "Failed to update current position";

        return;
    }



    qint64 index2 = output.indexOf(" in ", index + 2);

    if (index2 < 0)
    {
        qCritical() << "Failed to update current position";

        return;
    }



    bool ok = false;

    quint64 currentPosition = output.mid(index + 2, index2 - index - 1).toULongLong(&ok, 16);

    if (ok)
    {
        mCurrentPosition = currentPosition;
    }
    else
    {
        qCritical() << "Failed to update current position";
    }
}

void GdbProcess::terminateExecution(bool *isRunning)
{
    QProcess killProcess;

    killProcess.start("kill", QStringList() << "-SIGINT" << QString::number(mProcess.pid())); // Send Ctrl+C to the GDB process



    while (!isRunning || *isRunning)
    {
        if (killProcess.waitForFinished(100))
        {
            break;
        }
    }
}

void GdbProcess::continueExecution(bool *isRunning)
{
    executeCommand("continue", isRunning);
}

void GdbProcess::setMemoryDump(const QByteArray &memoryDump)
{
    mMemoryDump = memoryDump;
}

void GdbProcess::setKernelLocation(quint64 address)
{
    mKernelLocation = address;
}

const ElfObject& GdbProcess::getElfObject() const
{
    return mElfObject;
}

const QByteArray& GdbProcess::getMemoryDump() const
{
    return mMemoryDump;
}

quint64 GdbProcess::getKernelLocation() const
{
    return mKernelLocation;
}

quint64 GdbProcess::getCurrentPosition() const
{
    return mCurrentPosition;
}
