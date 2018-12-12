#ifndef GDB_DEBUG_SRC_PROCESSES_QEMUPROCESS_H
#define GDB_DEBUG_SRC_PROCESSES_QEMUPROCESS_H



#include <QProcess>
#include <QTemporaryFile>



class QemuProcess
{
public:
    QemuProcess(); // TEST: NO
    ~QemuProcess(); // TEST: NO

    bool start(); // TEST: NO

    QString readLine(bool *ok); // TEST: NO

private:
    QProcess       mProcess;
    QTemporaryFile mOutputFile;
    QByteArray     mOutputBuffer;
};



#endif // GDB_DEBUG_SRC_PROCESSES_QEMUPROCESS_H
