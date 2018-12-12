#include "qemuprocess.h"

#include "src/other/defines.h"
#include "src/other/global.h"



#define QEMU_WORKING_DIRECTORY "tools/vm/qemu/"
#define QEMU_APPLICATION       "start.sh"



QemuProcess::QemuProcess()
    : mProcess()
    , mOutputFile()
    , mOutputBuffer()
{
    // Nothing
}

QemuProcess::~QemuProcess()
{
    mProcess.kill();
    mProcess.waitForFinished();
}

bool QemuProcess::start()
{
    if (!mOutputFile.open())
    {
        return false;
    }



    mProcess.setWorkingDirectory(Global::sProjectDir + '/' + QEMU_WORKING_DIRECTORY);
    mProcess.start("sh -c \"./" QEMU_APPLICATION " " + QString::number(MEMORY_SIZE_MB) + " > " + mOutputFile.fileName() + " 2>&1\""); // Ignore CppOperatorSpacesVerifier // Ignore CppSingleCharVerifier
    mProcess.waitForStarted();

    return true;
}

QString QemuProcess::readLine(bool *ok)
{
    bool firstAttempt = true;

    do
    {
        qint64 index = mOutputBuffer.indexOf('\n');

        if (index < 0)
        {
            if (firstAttempt)
            {
                firstAttempt = false;

                mOutputBuffer.append(mOutputFile.read(4096));

                continue;
            }

            break;
        }



        QString line = QString::fromUtf8(mOutputBuffer.left(index));
        mOutputBuffer.remove(0, index + 1);



        if (line.endsWith('\r'))
        {
            line.remove(line.length() - 1, 1);
        }



        *ok = true;
        return line;
    } while(true);

    *ok = false;
    return "";
}
