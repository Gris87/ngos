#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMovie>
#include <QScrollBar>
#include <QSettings>

#include "src/main/aboutdialog.h"
#include "src/main/memorymapdialog.h"



#define MAIN_PAGE    0
#define WAITING_PAGE 1

#define COLUMN_ASSEMBLER_POINT   0
#define COLUMN_ASSEMBLER_ADDRESS 1
#define COLUMN_ASSEMBLER_COMMAND 2
#define COLUMN_ASSEMBLER_DETAILS 3

#define COLUMN_REGISTERS_NAME   0
#define COLUMN_REGISTERS_VALUE  1
#define COLUMN_REGISTERS_VALUE2 2

#define COLUMN_DATA_TYPE     0
#define COLUMN_DATA_HEX      1
#define COLUMN_DATA_SIGNED   2
#define COLUMN_DATA_UNSIGNED 3

#define DATA_INSPECTOR_MAX_STRING_LENGTH 256



QBrush changedCellBrush(QColor("#71AFE2"));
QBrush functionCellBrush(QColor("#FFFFB2"));
QBrush whiteCellBrush(QColor("#FFFFFF"));



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mIsExecuting(false)
    , mWaitingTimer()
    , mRestartThread(0)
    , mQemuProcess(0)
    , mGdbProcess(0)
    , mQemuReaderThread(0)
    , mStartThread(0)
    , mStopThread(0)
    , mStepThread(0)
    , mInterpretThread(0)
    , mRegistersThread(0)
    , mDumpMemoryThread(0)
    , mAddBreakpointThread(0)
    , mDeleteBreakpointThread(0)
    , mWaitForBreakThread(0)
    , mDataInspectorAssemblerPosition(-1)
    , mDataInspectorPosition(-1)
    , mDataInspectorScrollBarValue(-1)
    , mBreakpointsMap()
{
    ui->setupUi(this);



    QMovie *movie = new QMovie(":/assets/images/spinner.gif"); // Ignore CppPunctuationVerifier
    ui->spinnerLabel->setMovie(movie);
    ui->spinnerLabel->setScaledContents(true);



    ui->splitter->setSizes(QList<qint32>()  << 900 << 1000);
    ui->splitter2->setSizes(QList<qint32>() << 480 << 480);
    ui->splitter3->setSizes(QList<qint32>() << 525 << 480);
    ui->splitter4->setSizes(QList<qint32>() << 525 << 480);



    ui->assemblerTableWidget->setColumnWidth(COLUMN_ASSEMBLER_POINT,   30);
    ui->assemblerTableWidget->setColumnWidth(COLUMN_ASSEMBLER_ADDRESS, 100);
    ui->assemblerTableWidget->setColumnWidth(COLUMN_ASSEMBLER_COMMAND, 240);
    ui->assemblerTableWidget->setColumnWidth(COLUMN_ASSEMBLER_DETAILS, 120);

    ui->registersTableWidget->setColumnWidth(COLUMN_REGISTERS_NAME,   60);
    ui->registersTableWidget->setColumnWidth(COLUMN_REGISTERS_VALUE,  310);
    ui->registersTableWidget->setColumnWidth(COLUMN_REGISTERS_VALUE2, 120);

    ui->dataInspectorAssemblerTableWidget->setColumnWidth(COLUMN_DATA_TYPE,     70);
    ui->dataInspectorAssemblerTableWidget->setColumnWidth(COLUMN_DATA_HEX,      90);
    ui->dataInspectorAssemblerTableWidget->setColumnWidth(COLUMN_DATA_SIGNED,   150);
    ui->dataInspectorAssemblerTableWidget->setColumnWidth(COLUMN_DATA_UNSIGNED, 140);

    ui->dataInspectorTableWidget->setColumnWidth(COLUMN_DATA_TYPE,     70);
    ui->dataInspectorTableWidget->setColumnWidth(COLUMN_DATA_HEX,      90);
    ui->dataInspectorTableWidget->setColumnWidth(COLUMN_DATA_SIGNED,   150);
    ui->dataInspectorTableWidget->setColumnWidth(COLUMN_DATA_UNSIGNED, 140);



    connect(&mWaitingTimer, SIGNAL(timeout()), this, SLOT(waitingProgressBarTimeout()));

    loadWindowState();
}

MainWindow::~MainWindow()
{
    saveWindowState();

    stopAllThreads();
    killAllProcesses();



    delete ui->spinnerLabel->movie();

    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionRestart_triggered()
{
    stopAllThreads();
    killAllProcesses();

    goToDisabledMode();



    mIsExecuting = false;
    ui->actionStop->setIcon(QIcon(":/assets/images/start.png")); // Ignore CppPunctuationVerifier
    ui->actionStop->setText(tr("Start"));
    ui->actionStop->setToolTip(tr("Start (Ctrl+P)"));



    mRestartThread = new RestartThread();
    connect(mRestartThread, SIGNAL(finished()), this, SLOT(restartThreadFinished()));
    mRestartThread->start();
}

void MainWindow::on_actionStop_triggered()
{
    Q_ASSERT(mGdbProcess);



    stopStepThread();
    stopInterpretThread();
    stopRegistersThread();
    stopDumpMemoryThread();
    stopAddBreakpointThread();
    stopDeleteBreakpointThread();
    stopWaitForBreakThread();



    if (mIsExecuting)
    {
        stopStartThread();



        if (!mStopThread)
        {
            mStopThread = new StopThread(mGdbProcess);
            connect(mStopThread, SIGNAL(finished()), this, SLOT(stopThreadFinished()));
            mStopThread->start();
        }
    }
    else
    {
        stopStopThread();



        if (!mStartThread)
        {
            ui->actionNext_step->setEnabled(false);



            mStartThread = new StartThread(mGdbProcess);
            connect(mStartThread, SIGNAL(finished()), this, SLOT(startThreadFinished()));
            mStartThread->start();
        }
    }
}

void MainWindow::on_actionNext_step_triggered()
{
    Q_ASSERT(mGdbProcess);



    stopStartThread();
    stopStopThread();
    stopInterpretThread();
    stopRegistersThread();
    stopDumpMemoryThread();
    stopAddBreakpointThread();
    stopDeleteBreakpointThread();
    stopWaitForBreakThread();



    if (!mStepThread)
    {
        mStepThread = new StepThread(mGdbProcess);
        connect(mStepThread, SIGNAL(finished()), this, SLOT(stepThreadFinished()));
        mStepThread->start();
    }
}

void MainWindow::on_actionShow_memory_map_triggered()
{
    MemoryMapDialog dialog(ui->hexGraphicsView, this);
    dialog.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_hexGraphicsView_byteHovered(qint64 position)
{
    if (position >= 0)
    {
        updateDataInspector(position, ui->dataInspectorAddressLabel, ui->dataInspectorSectionLabel, ui->dataInspectorTableWidget);
    }
    else
    {
        updateDataInspector(mDataInspectorPosition, ui->dataInspectorAddressLabel, ui->dataInspectorSectionLabel, ui->dataInspectorTableWidget);
    }
}

void MainWindow::on_hexGraphicsView_byteClicked(qint64 position)
{
    Q_ASSERT(mGdbProcess);



    hideAssemblerDataInspector();
    mDataInspectorPosition = position;
    updateDataInspector(position, ui->dataInspectorAddressLabel, ui->dataInspectorSectionLabel, ui->dataInspectorTableWidget);



    if (!mIsExecuting)
    {
        stopInterpretThread();



        mInterpretThread = new InterpretThread(mGdbProcess, position);
        connect(mInterpretThread, SIGNAL(finished()), this, SLOT(interpretThreadFinished()));
        mInterpretThread->start();
    }
}

void MainWindow::on_backToolButton_clicked()
{
    quint64 position = mGdbProcess->getCurrentPosition();

    ui->hexGraphicsView->jumpToAddress(position);
    ui->hexGraphicsView->selectByte(position);
}

void MainWindow::on_assemblerTableWidget_cellDoubleClicked(qint32 row, qint32 column)
{
    switch (column)
    {
        case COLUMN_ASSEMBLER_POINT:
        {
            QString address = ui->assemblerTableWidget->item(row, COLUMN_ASSEMBLER_ADDRESS)->text();

            quint64 breakpointId = mBreakpointsMap.value(address, 0);

            if (!breakpointId)
            {
                stopAddBreakpointThread();



                mAddBreakpointThread = new AddBreakpointThread(mGdbProcess, address);
                connect(mAddBreakpointThread, SIGNAL(finished()), this, SLOT(addBreakpointThreadFinished()));
                mAddBreakpointThread->start();
            }
            else
            {
                stopDeleteBreakpointThread();



                mDeleteBreakpointThread = new DeleteBreakpointThread(mGdbProcess, address, breakpointId);
                connect(mDeleteBreakpointThread, SIGNAL(finished()), this, SLOT(deleteBreakpointThreadFinished()));
                mDeleteBreakpointThread->start();
            }
        }
        break;

        case COLUMN_ASSEMBLER_ADDRESS:
        {
            QString address = ui->assemblerTableWidget->item(row, column)->text();

            if (address.startsWith("0x"))
            {
                address.remove(0, 2);



                bool ok = false;

                quint64 position = address.toULongLong(&ok, 16);

                if (ok)
                {
                    ui->hexGraphicsView->jumpToAddress(position);
                    ui->hexGraphicsView->selectByte(position);
                }
            }
        }
        break;

        case COLUMN_ASSEMBLER_COMMAND:
        {
            QString command = ui->assemblerTableWidget->item(row, column)->text();

            qint64 index = command.indexOf(' ');

            if (index >= 0)
            {
                QString rightPart = command.mid(index + 1).trimmed();

                if (rightPart.startsWith("0x"))
                {
                    bool ok = false;

                    quint64 position = rightPart.mid(2).toULongLong(&ok, 16);

                    if (ok)
                    {
                        ui->hexGraphicsView->jumpToAddress(position);
                        ui->hexGraphicsView->selectByte(position);
                    }
                }
            }
        }
        break;

        case COLUMN_ASSEMBLER_DETAILS:
        {
            QString details = ui->assemblerTableWidget->item(row, column)->text();

            if (
                details.startsWith("# 0x")
                ||
                details.startsWith("! 0x")
               )
            {
                details.remove(0, 4);



                bool ok = false;

                quint64 position = details.toULongLong(&ok, 16);

                if (ok)
                {
                    ui->hexGraphicsView->jumpToAddress(position);
                    ui->hexGraphicsView->selectByte(position);
                }
            }
        }
        break;

        default:
        {
            qCritical() << "Unknown column:" << column;
        }
        break;
    }
}

void MainWindow::on_assemblerTableWidget_currentCellChanged(qint32 currentRow, qint32 currentColumn, qint32 /*previousRow*/, qint32 /*previousColumn*/)
{
    if (currentColumn == COLUMN_ASSEMBLER_DETAILS)
    {
        QString details = ui->assemblerTableWidget->item(currentRow, currentColumn)->text();

        if (
            details.startsWith("# 0x")
            ||
            details.startsWith("! 0x")
           )
        {
            details.remove(0, 4);



            bool ok = false;

            quint64 position = details.toULongLong(&ok, 16);

            if (ok)
            {
                mDataInspectorAssemblerPosition = position;
                updateDataInspector(position, ui->dataInspectorAssemblerAddressLabel, ui->dataInspectorAssemblerSectionLabel, ui->dataInspectorAssemblerTableWidget);

                ui->dataInspectorAssemblerAddressLabel->setVisible(true);
                ui->dataInspectorAssemblerSectionLabel->setVisible(true);
                ui->dataInspectorAssemblerTableWidget->setVisible(true);
            }
        }
    }
}

void MainWindow::on_registersTableWidget_cellDoubleClicked(qint32 row, qint32 column)
{
    QString address = ui->registersTableWidget->item(row, column)->text();

    if (address.startsWith("0x"))
    {
        address.remove(0, 2);



        bool ok = false;

        quint64 position = address.toULongLong(&ok, 16);

        if (ok)
        {
            ui->hexGraphicsView->jumpToAddress(position);
            ui->hexGraphicsView->selectByte(position);
        }
    }
}

void MainWindow::on_dataInspectorAssemblerTableWidget_cellEntered(qint32 row, qint32 column)
{
    dataInspectorCellEntered(ui->dataInspectorAssemblerTableWidget, row, column, mDataInspectorAssemblerPosition);
}

void MainWindow::on_dataInspectorAssemblerTableWidget_cellClicked(qint32 /*row*/, qint32 /*column*/)
{
    mDataInspectorScrollBarValue = -1;
}

void MainWindow::on_dataInspectorAssemblerTableWidget_leaved()
{
    dataInspectorLeaved();
}

void MainWindow::on_dataInspectorTableWidget_cellEntered(qint32 row, qint32 column)
{
    dataInspectorCellEntered(ui->dataInspectorTableWidget, row, column, mDataInspectorPosition);
}

void MainWindow::on_dataInspectorTableWidget_cellClicked(qint32 /*row*/, qint32 /*column*/)
{
    mDataInspectorScrollBarValue = -1;
}

void MainWindow::on_dataInspectorTableWidget_leaved()
{
    dataInspectorLeaved();
}

void MainWindow::waitingProgressBarTimeout()
{
    ui->waitingProgressBar->setValue(ui->waitingProgressBar->value() + 1);
}

void MainWindow::restartThreadFinished()
{
    mQemuProcess = mRestartThread->takeQemuProcess();
    mGdbProcess  = mRestartThread->takeGdbProcess();

    delete mRestartThread;
    mRestartThread = 0;



    if (mQemuProcess && mGdbProcess)
    {
        goToEnabledMode();

        mBreakpointsMap.clear();

        mQemuReaderThread = new QemuReaderThread(mQemuProcess);
        connect(mQemuReaderThread, SIGNAL(bootParamsAllocated(quint64, quint64)), this, SLOT(bootParamsAllocated(quint64, quint64)));
        connect(mQemuReaderThread, SIGNAL(kernelAllocated(quint64, quint64)),     this, SLOT(kernelAllocated(quint64, quint64)));
        connect(mQemuReaderThread, SIGNAL(kernelRelocated(quint64)),              this, SLOT(kernelRelocated(quint64)));
        mQemuReaderThread->start();

        ui->hexGraphicsView->setGdbProcess(mGdbProcess);
        updateCurrentPosition();
    }
    else
    {
        killAllProcesses();
    }
}

void MainWindow::bootParamsAllocated(quint64 address, quint64 size)
{
    ui->hexGraphicsView->setBootParamsRange(address, size);
}

void MainWindow::kernelAllocated(quint64 address, quint64 size)
{
    ui->hexGraphicsView->setKernelRange(address, size);
}

void MainWindow::kernelRelocated(quint64 address)
{
    mGdbProcess->setKernelLocation(address);

    ui->hexGraphicsView->updateLines();
}

void MainWindow::startThreadFinished()
{
    delete mStartThread;
    mStartThread = 0;



    mIsExecuting = true;
    ui->actionStop->setIcon(QIcon(":/assets/images/stop.png")); // Ignore CppPunctuationVerifier
    ui->actionStop->setText(tr("Stop"));
    ui->actionStop->setToolTip(tr("Stop (Ctrl+P)"));

    ui->assemblerToolbarWidget->setVisible(false);
    ui->assemblerTableWidget->setVisible(false);

    hideAssemblerDataInspector();



    mWaitForBreakThread = new WaitForBreakThread(mGdbProcess);
    connect(mWaitForBreakThread, SIGNAL(finished()), this, SLOT(waitForBreakThreadFinished()));
    mWaitForBreakThread->start();
}

void MainWindow::stopThreadFinished()
{
    delete mStopThread;
    mStopThread = 0;



    mIsExecuting = false;
    ui->actionStop->setIcon(QIcon(":/assets/images/start.png")); // Ignore CppPunctuationVerifier
    ui->actionStop->setText(tr("Start"));
    ui->actionStop->setToolTip(tr("Start (Ctrl+P)"));

    ui->actionNext_step->setEnabled(true);

    ui->assemblerToolbarWidget->setVisible(true);
    ui->assemblerTableWidget->setVisible(true);



    updateCurrentPosition();
    updateMemoryDump();
}

void MainWindow::stepThreadFinished()
{
    delete mStepThread;
    mStepThread = 0;



    updateCurrentPosition();
    updateMemoryDump();
}

void MainWindow::interpretThreadFinished()
{
    Q_ASSERT(mGdbProcess);



    quint64            position = mInterpretThread->getPosition();
    QList<QStringList> rows     = mInterpretThread->getResult();

    delete mInterpretThread;
    mInterpretThread = 0;



    qint64 rowCount = ui->assemblerTableWidget->rowCount();
    ui->assemblerTableWidget->setRowCount(rows.length());

    for (qint64 i = rowCount; i < rows.length(); ++i)
    {
        for (qint64 j = 0; j < ui->assemblerTableWidget->columnCount(); ++j)
        {
            ui->assemblerTableWidget->setItem(i, j, new QTableWidgetItem());
        }
    }



    ElfSymbol *functionSymbol = 0;
    QString    functionName;

    const QHash<QString, ElfSymbol *>& symbols = mGdbProcess->getElfObject().getSymbolMap();
    QHashIterator<QString, ElfSymbol *> it(symbols);

    while (it.hasNext())
    {
        it.next();
        ElfSymbol *symbol = it.value();

        if (
            ELF_SYMBOL_TYPE(symbol->info) == (quint8)ElfSymbolType::FUNC
            &&
            position >= mGdbProcess->getKernelLocation() + symbol->value
            &&
            position < mGdbProcess->getKernelLocation() + symbol->value + symbol->size
           )
        {
            functionSymbol = symbol;
            functionName   = it.key();

            break;
        }
    }

    ui->functionLabel->setText(functionName);



    QIcon emptyIcon;

    for (qint64 i = 0; i < rows.length(); ++i)
    {
        QStringList cells = rows.at(i);

        for (qint64 j = 0; j < cells.length(); ++j)
        {
            QString           cellValue = cells.at(j);
            QTableWidgetItem *item      = ui->assemblerTableWidget->item(i, j);



            if (functionSymbol)
            {
                if (cells.length() > 1)
                {
                    QString address = cells.at(COLUMN_ASSEMBLER_ADDRESS);

                    if (address.startsWith("0x"))
                    {
                        address.remove(0, 2);
                    }



                    bool    ok;
                    quint64 addressInt = address.toULongLong(&ok, 16);

                    if (
                        ok
                        &&
                        addressInt >= mGdbProcess->getKernelLocation() + functionSymbol->value
                        &&
                        addressInt < mGdbProcess->getKernelLocation() + functionSymbol->value + functionSymbol->size
                       )
                    {
                        item->setBackground(functionCellBrush);
                    }
                    else
                    {
                        functionSymbol = 0;

                        item->setBackground(whiteCellBrush);
                    }
                }
                else
                {
                    functionSymbol = 0;

                    item->setBackground(whiteCellBrush);
                }
            }
            else
            {
                item->setBackground(whiteCellBrush);
            }



            if (j == COLUMN_ASSEMBLER_POINT)
            {
                if (mBreakpointsMap.contains(cells.at(COLUMN_ASSEMBLER_ADDRESS)))
                {
                    if (cellValue != "")
                    {
                        item->setIcon(QIcon(":/assets/images/breakpoint_current.png")); // Ignore CppPunctuationVerifier
                        item->setText("");
                        item->setToolTip(cellValue);

                        continue;
                    }

                    item->setIcon(QIcon(":/assets/images/breakpoint.png")); // Ignore CppPunctuationVerifier
                }
                else
                {
                    item->setIcon(emptyIcon);
                }
            }



            if (j == COLUMN_ASSEMBLER_DETAILS && cellValue == "")
            {
                QString command = cells.at(COLUMN_ASSEMBLER_COMMAND);

                qint64 index = command.indexOf(' ');

                if (index >= 0)
                {
                    QString rightPart = command.mid(index + 1).trimmed();

                    if (rightPart.startsWith("0x"))
                    {
                        bool ok = false;

                        quint64 position = rightPart.mid(2).toULongLong(&ok, 16);

                        if (ok)
                        {
                            qint64 minDelta = LONG_LONG_MAX;

                            QHashIterator<QString, ElfSymbol *> it(symbols);

                            while (it.hasNext())
                            {
                                it.next();
                                ElfSymbol *symbol = it.value();

                                qint64 delta = position - (mGdbProcess->getKernelLocation() + symbol->value);

                                if (delta >= 0 && delta < minDelta)
                                {
                                    if (!delta) // delta == 0
                                    {
                                        cellValue = it.key();

                                        break;
                                    }

                                    cellValue = it.key() + " + 0x" + QString::number(delta, 16).toUpper();

                                    minDelta = delta;
                                }
                            }
                        }
                    }
                }
            }



            item->setText(cellValue);
            item->setToolTip(cellValue);
        }
    }



    updateAssemblerAddresses();
}

void MainWindow::registersThreadFinished()
{
    QList<QStringList> rows = mRegistersThread->getResult();

    delete mRegistersThread;
    mRegistersThread = 0;



    qint64 rowCount = ui->registersTableWidget->rowCount();
    ui->registersTableWidget->setRowCount(rows.length());

    for (qint64 i = rowCount; i < rows.length(); ++i)
    {
        QStringList cells = rows.at(i);

        for (qint64 j = 0; j < ui->registersTableWidget->columnCount(); ++j)
        {
            ui->registersTableWidget->setItem(i, j, new QTableWidgetItem(cells.at(j)));
        }
    }



    for (qint64 i = 0; i < rows.length(); ++i)
    {
        QStringList cells = rows.at(i);

        for (qint64 j = 0; j < cells.length(); ++j)
        {
            QString           cellValue = cells.at(j);
            QTableWidgetItem *item      = ui->registersTableWidget->item(i, j);

            if (item->text() != cellValue)
            {
                item->setBackground(changedCellBrush);

                item->setToolTip(tr("Current: %1\nBefore:   %2").arg(cellValue).arg(item->text()));
                item->setText(cellValue);
            }
            else
            {
                item->setBackground(whiteCellBrush);

                item->setToolTip(cellValue);
            }
        }
    }



    updateAssemblerAddresses();
}

void MainWindow::dumpMemoryThreadFinished()
{
    QByteArray memoryDump = mDumpMemoryThread->getResult();

    delete mDumpMemoryThread;
    mDumpMemoryThread = 0;



    ui->hexGraphicsView->setMemoryDump(memoryDump);
    mGdbProcess->setMemoryDump(memoryDump);
}

void MainWindow::addBreakpointThreadFinished()
{
    QString address      = mAddBreakpointThread->getAddress();
    quint64 breakpointId = mAddBreakpointThread->getBreakpointId();

    delete mAddBreakpointThread;
    mAddBreakpointThread = 0;



    mBreakpointsMap.insert(address, breakpointId);

    for (qint64 i = 0; i < ui->assemblerTableWidget->rowCount(); ++i)
    {
        if (ui->assemblerTableWidget->item(i, COLUMN_ASSEMBLER_ADDRESS)->text() == address)
        {
            QTableWidgetItem *item = ui->assemblerTableWidget->item(i, COLUMN_ASSEMBLER_POINT);

            if (item->text() != "")
            {
                item->setIcon(QIcon(":/assets/images/breakpoint_current.png")); // Ignore CppPunctuationVerifier
                item->setText("");
            }
            else
            {
                item->setIcon(QIcon(":/assets/images/breakpoint.png")); // Ignore CppPunctuationVerifier
            }

            break;
        }
    }
}

void MainWindow::deleteBreakpointThreadFinished()
{
    QString address = mDeleteBreakpointThread->getAddress();

    delete mDeleteBreakpointThread;
    mDeleteBreakpointThread = 0;



    mBreakpointsMap.remove(address);

    for (qint64 i = 0; i < ui->assemblerTableWidget->rowCount(); ++i)
    {
        if (ui->assemblerTableWidget->item(i, COLUMN_ASSEMBLER_ADDRESS)->text() == address)
        {
            QTableWidgetItem *item = ui->assemblerTableWidget->item(i, COLUMN_ASSEMBLER_POINT);

            item->setIcon(QIcon());

            if (item->toolTip() != "")
            {
                item->setText(item->toolTip());
            }

            break;
        }
    }
}

void MainWindow::waitForBreakThreadFinished()
{
    delete mWaitForBreakThread;
    mWaitForBreakThread = 0;



    mIsExecuting = false;
    ui->actionStop->setIcon(QIcon(":/assets/images/start.png")); // Ignore CppPunctuationVerifier
    ui->actionStop->setText(tr("Start"));
    ui->actionStop->setToolTip(tr("Start (Ctrl+P)"));

    ui->actionNext_step->setEnabled(true);

    ui->assemblerToolbarWidget->setVisible(true);
    ui->assemblerTableWidget->setVisible(true);



    updateCurrentPosition();
    updateMemoryDump();
}

void MainWindow::stopAllThreads()
{
    stopRestartThread();
    stopQemuReaderThread();
    stopStartThread();
    stopStopThread();
    stopStepThread();
    stopInterpretThread();
    stopRegistersThread();
    stopDumpMemoryThread();
    stopAddBreakpointThread();
    stopDeleteBreakpointThread();
    stopWaitForBreakThread();
}

void MainWindow::stopRestartThread()
{
    if (mRestartThread)
    {
        mRestartThread->blockSignals(true);
        mRestartThread->stop();
        mRestartThread->wait();

        delete mRestartThread;
        mRestartThread = 0;
    }
}

void MainWindow::stopQemuReaderThread()
{
    if (mQemuReaderThread)
    {
        mQemuReaderThread->blockSignals(true);
        mQemuReaderThread->stop();
        mQemuReaderThread->wait();

        delete mQemuReaderThread;
        mQemuReaderThread = 0;
    }
}

void MainWindow::stopStartThread()
{
    if (mStartThread)
    {
        mStartThread->blockSignals(true);
        mStartThread->stop();
        mStartThread->wait();

        delete mStartThread;
        mStartThread = 0;
    }
}

void MainWindow::stopStopThread()
{
    if (mStopThread)
    {
        mStopThread->blockSignals(true);
        mStopThread->stop();
        mStopThread->wait();

        delete mStopThread;
        mStopThread = 0;
    }
}

void MainWindow::stopStepThread()
{
    if (mStepThread)
    {
        mStepThread->blockSignals(true);
        mStepThread->stop();
        mStepThread->wait();

        delete mStepThread;
        mStepThread = 0;
    }
}

void MainWindow::stopInterpretThread()
{
    if (mInterpretThread)
    {
        mInterpretThread->blockSignals(true);
        mInterpretThread->stop();
        mInterpretThread->wait();

        delete mInterpretThread;
        mInterpretThread = 0;
    }
}

void MainWindow::stopRegistersThread()
{
    if (mRegistersThread)
    {
        mRegistersThread->blockSignals(true);
        mRegistersThread->stop();
        mRegistersThread->wait();

        delete mRegistersThread;
        mRegistersThread = 0;
    }
}

void MainWindow::stopDumpMemoryThread()
{
    if (mDumpMemoryThread)
    {
        mDumpMemoryThread->blockSignals(true);
        mDumpMemoryThread->stop();
        mDumpMemoryThread->wait();

        delete mDumpMemoryThread;
        mDumpMemoryThread = 0;
    }
}

void MainWindow::stopAddBreakpointThread()
{
    if (mAddBreakpointThread)
    {
        mAddBreakpointThread->blockSignals(true);
        mAddBreakpointThread->stop();
        mAddBreakpointThread->wait();

        delete mAddBreakpointThread;
        mAddBreakpointThread = 0;
    }
}

void MainWindow::stopDeleteBreakpointThread()
{
    if (mDeleteBreakpointThread)
    {
        mDeleteBreakpointThread->blockSignals(true);
        mDeleteBreakpointThread->stop();
        mDeleteBreakpointThread->wait();

        delete mDeleteBreakpointThread;
        mDeleteBreakpointThread = 0;
    }
}

void MainWindow::stopWaitForBreakThread()
{
    if (mWaitForBreakThread)
    {
        mWaitForBreakThread->blockSignals(true);
        mWaitForBreakThread->stop();
        mWaitForBreakThread->wait();

        delete mWaitForBreakThread;
        mWaitForBreakThread = 0;
    }
}

void MainWindow::killAllProcesses()
{
    if (mQemuProcess)
    {
        delete mQemuProcess;
        mQemuProcess = 0;
    }

    if (mGdbProcess)
    {
        ui->hexGraphicsView->setGdbProcess(0);

        delete mGdbProcess;
        mGdbProcess = 0;
    }
}

void MainWindow::updateCurrentPosition()
{
    Q_ASSERT(mGdbProcess);



    quint64 position = mGdbProcess->getCurrentPosition();

    ui->hexGraphicsView->setCurrentPosition(position);
    ui->hexGraphicsView->selectByte(position);

    updateRegisters();
}

void MainWindow::updateMemoryDump()
{
    Q_ASSERT(mGdbProcess);



    stopDumpMemoryThread();



    mDumpMemoryThread = new DumpMemoryThread(mGdbProcess);
    connect(mDumpMemoryThread, SIGNAL(finished()), this, SLOT(dumpMemoryThreadFinished()));
    mDumpMemoryThread->start();
}

void MainWindow::updateRegisters()
{
    Q_ASSERT(mGdbProcess);



    stopRegistersThread();



    mRegistersThread = new RegistersThread(mGdbProcess);
    connect(mRegistersThread, SIGNAL(finished()), this, SLOT(registersThreadFinished()));
    mRegistersThread->start();
}

void MainWindow::updateAssemblerAddresses()
{
    qint64 lastRegisterRow = -1;



    for (qint64 i = 0; i < ui->assemblerTableWidget->rowCount(); ++i)
    {
        QTableWidgetItem *detailsItem = ui->assemblerTableWidget->item(i, COLUMN_ASSEMBLER_DETAILS);

        if (!detailsItem->text().startsWith("# "))
        {
            QString command = ui->assemblerTableWidget->item(i, COLUMN_ASSEMBLER_COMMAND)->text();

            qint64 index = command.indexOf("(%");

            if (index >= 0)
            {
                qint64 index2 = command.indexOf(')', index + 2);

                if (index2 >= 0)
                {
                    QString reg = command.mid(index + 2, index2 - index - 2);



                    qint64 startRegisterRow = 0;

                    if (lastRegisterRow >= 0)
                    {
                        if (ui->registersTableWidget->item(lastRegisterRow, COLUMN_REGISTERS_NAME)->text() == reg)
                        {
                            startRegisterRow = lastRegisterRow;
                        }
                    }



                    for (qint64 j = startRegisterRow; j < ui->registersTableWidget->rowCount(); ++j)
                    {
                        if (ui->registersTableWidget->item(j, COLUMN_REGISTERS_NAME)->text() == reg)
                        {
                            QString value = ui->registersTableWidget->item(j, COLUMN_REGISTERS_VALUE)->text();



                            qint64 index3 = value.indexOf("0x");

                            if (index3 >= 0)
                            {
                                value = value.mid(index3 + 2);

                                if (value.endsWith(')'))
                                {
                                    value.remove(value.length() - 1, 1);
                                }

                                if (value.length() > 16)
                                {
                                    value.remove(0, value.length() - 16);
                                }



                                qint64 index4 = command.lastIndexOf("0x", index - 2);

                                if (index4 >= 0)
                                {
                                    QString offset = command.mid(index4 + 2, index - index4 - 2);

                                    bool ok1 = false;
                                    bool ok2 = false;

                                    quint64 valueInt  = value.toULongLong(&ok1,  16);
                                    quint64 offsetInt = offset.toULongLong(&ok2, 16);

                                    if (ok1 && ok2)
                                    {
                                        QString details = QString("! 0x%1").arg(valueInt + offsetInt, 8, 16, QChar('0'));

                                        detailsItem->setText(details);
                                        detailsItem->setToolTip(details);
                                    }
                                }
                            }



                            lastRegisterRow = j;

                            break;
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::hideAssemblerDataInspector()
{
    ui->dataInspectorAssemblerAddressLabel->setVisible(false);
    ui->dataInspectorAssemblerSectionLabel->setVisible(false);
    ui->dataInspectorAssemblerTableWidget->setVisible(false);
}

void MainWindow::updateDataInspector(qint64 position, QLabel *addressLabel, QLabel *sectionLabel, QTableWidget *tableWidget)
{
    Q_ASSERT(mGdbProcess);



    addressLabel->setText(tr("Address: 0x%1").arg(position, 16, 16, QChar('0')));



    QString sectionName;

    const QHash<QString, ElfSectionHeaderTableEntry *>& sections = mGdbProcess->getElfObject().getSectionsMap();
    QHashIterator<QString, ElfSectionHeaderTableEntry *> it(sections);

    while (it.hasNext())
    {
        it.next();
        ElfSectionHeaderTableEntry *section = it.value();

        if (
            (section->flags & (quint64)ElfSectionFlag::ALLOC)
            &&
            position >= (qint64)(mGdbProcess->getKernelLocation() + section->virtualAddress)
            &&
            position < (qint64)(mGdbProcess->getKernelLocation() + section->virtualAddress + section->size)
           )
        {
            sectionName = it.key();

            break;
        }
    }

    sectionLabel->setText(sectionName);



    qint64 rowCount = tableWidget->rowCount();

    if (rowCount != 7)
    {
        tableWidget->setRowCount(7);

        for (qint64 i = rowCount; i < tableWidget->rowCount(); ++i)
        {
            for (qint64 j = 0; j < tableWidget->columnCount(); ++j)
            {
                tableWidget->setItem(i, j, new QTableWidgetItem());
            }
        }

        tableWidget->setSpan(4, COLUMN_DATA_SIGNED, 1, 2);
        tableWidget->setSpan(5, COLUMN_DATA_SIGNED, 1, 2);
        tableWidget->setSpan(6, COLUMN_DATA_SIGNED, 1, 2);
    }



    const QByteArray& memoryDump = mGdbProcess->getMemoryDump();

    quint8  valueBit8   = 0;
    quint16 valueBit16  = 0;
    quint32 valueBit32  = 0;
    quint64 valueBit64  = 0;
    float   valueFloat  = 0;
    double  valueDouble = 0;
    QString valueString = "";

    QString valueFloatHex  = "";
    QString valueDoubleHex = "";
    QString valueStringHex = "";

    bool haveValueBit8   = false;
    bool haveValueBit16  = false;
    bool haveValueBit32  = false;
    bool haveValueBit64  = false;
    bool haveValueFloat  = false;
    bool haveValueDouble = false;
    bool haveValueString = false;



    if (position <= qint64(memoryDump.length() - sizeof(valueBit8)))
    {
        valueBit8     = *(quint8 *)((quint64)memoryDump.constData() + position);
        haveValueBit8 = true;
    }



    if (position <= qint64(memoryDump.length() - sizeof(valueBit16)))
    {
        valueBit16     = *(quint16 *)((quint64)memoryDump.constData() + position);
        haveValueBit16 = true;
    }



    if (position <= qint64(memoryDump.length() - sizeof(valueBit32)))
    {
        valueBit32     = *(quint32 *)((quint64)memoryDump.constData() + position);
        haveValueBit32 = true;
    }



    if (position <= qint64(memoryDump.length() - sizeof(valueBit64)))
    {
        valueBit64     = *(quint64 *)((quint64)memoryDump.constData() + position);
        haveValueBit64 = true;
    }



    if (position <= qint64(memoryDump.length() - sizeof(valueFloat)))
    {
        valueFloat     = *(float *)((quint64)memoryDump.constData() + position);
        valueFloatHex  = QString(memoryDump.mid(position, sizeof(valueFloat)).toHex());
        haveValueFloat = true;
    }



    if (position <= qint64(memoryDump.length() - sizeof(valueDouble)))
    {
        valueDouble     = *(double *)((quint64)memoryDump.constData() + position);
        valueDoubleHex  = QString(memoryDump.mid(position, sizeof(valueDouble)).toHex());
        haveValueDouble = true;
    }



    for (qint64 i = position; i < memoryDump.length() && i <= position + DATA_INSPECTOR_MAX_STRING_LENGTH; ++i)
    {
        if (!memoryDump.at(i)) // memoryDump.at(i) == 0
        {
            valueString     = QString((char *)((quint64)memoryDump.constData() + position));
            valueStringHex  = QString(memoryDump.mid(position, i - position + 1).toHex());
            haveValueString = true;

            break;
        }
    }



    tableWidget->item(0, COLUMN_DATA_TYPE)->setText("8 bit");
    tableWidget->item(0, COLUMN_DATA_HEX)->setText(haveValueBit8 ? QString("%1").arg(valueBit8, 2, 16, QChar('0')).toUpper() : QString('-'));
    tableWidget->item(0, COLUMN_DATA_SIGNED)->setText(haveValueBit8 ? QString::number((qint8)valueBit8) : QString('-'));
    tableWidget->item(0, COLUMN_DATA_UNSIGNED)->setText(haveValueBit8 ? QString::number(valueBit8) : QString('-'));

    tableWidget->item(1, COLUMN_DATA_TYPE)->setText("16 bit");
    tableWidget->item(1, COLUMN_DATA_HEX)->setText(haveValueBit16 ? QString("%1").arg(valueBit16, 4, 16, QChar('0')).toUpper() : QString('-'));
    tableWidget->item(1, COLUMN_DATA_SIGNED)->setText(haveValueBit16 ? QString::number((qint16)valueBit16) : QString('-'));
    tableWidget->item(1, COLUMN_DATA_UNSIGNED)->setText(haveValueBit16 ? QString::number(valueBit16) : QString('-'));

    tableWidget->item(2, COLUMN_DATA_TYPE)->setText("32 bit");
    tableWidget->item(2, COLUMN_DATA_HEX)->setText(haveValueBit32 ? QString("%1").arg(valueBit32, 8, 16, QChar('0')).toUpper() : QString('-'));
    tableWidget->item(2, COLUMN_DATA_SIGNED)->setText(haveValueBit32 ? QString::number((qint32)valueBit32) : QString('-'));
    tableWidget->item(2, COLUMN_DATA_UNSIGNED)->setText(haveValueBit32 ? QString::number(valueBit32) : QString('-'));

    tableWidget->item(3, COLUMN_DATA_TYPE)->setText("64 bit");
    tableWidget->item(3, COLUMN_DATA_HEX)->setText(haveValueBit64 ? QString("%1").arg(valueBit64, 16, 16, QChar('0')).toUpper() : QString('-'));
    tableWidget->item(3, COLUMN_DATA_SIGNED)->setText(haveValueBit64 ? QString::number((qint64)valueBit64) : QString('-'));
    tableWidget->item(3, COLUMN_DATA_UNSIGNED)->setText(haveValueBit64 ? QString::number(valueBit64) : QString('-'));

    tableWidget->item(4, COLUMN_DATA_TYPE)->setText("float");
    tableWidget->item(4, COLUMN_DATA_HEX)->setText(haveValueFloat ? valueFloatHex : QString('-'));
    tableWidget->item(4, COLUMN_DATA_SIGNED)->setText(haveValueFloat ? QString::number(valueFloat) : QString('-'));
    tableWidget->item(4, COLUMN_DATA_UNSIGNED)->setText("");

    tableWidget->item(5, COLUMN_DATA_TYPE)->setText("double");
    tableWidget->item(5, COLUMN_DATA_HEX)->setText(haveValueDouble ? valueDoubleHex : QString('-'));
    tableWidget->item(5, COLUMN_DATA_SIGNED)->setText(haveValueDouble ? QString::number(valueDouble) : QString('-'));
    tableWidget->item(5, COLUMN_DATA_UNSIGNED)->setText("");

    tableWidget->item(6, COLUMN_DATA_TYPE)->setText("string");
    tableWidget->item(6, COLUMN_DATA_HEX)->setText(haveValueString ? valueStringHex : QString('-'));
    tableWidget->item(6, COLUMN_DATA_SIGNED)->setText(haveValueString ? valueString : QString('-'));
    tableWidget->item(6, COLUMN_DATA_UNSIGNED)->setText("");



    for (qint64 i = 0; i < tableWidget->rowCount(); ++i)
    {
        for (qint64 j = 0; j < tableWidget->columnCount(); ++j)
        {
            QTableWidgetItem *item = tableWidget->item(i, j);

            item->setToolTip(item->text());
        }
    }
}

void MainWindow::dataInspectorCellEntered(QTableWidget *tableWidget, qint32 row, qint32 column, qint64 position)
{
    if (column == COLUMN_DATA_HEX)
    {
        QString hex = tableWidget->item(row, column)->text();

        if (hex != '-')
        {
            if (mDataInspectorScrollBarValue < 0)
            {
                mDataInspectorScrollBarValue = ui->hexGraphicsView->verticalScrollBar()->value();
            }

            ui->hexGraphicsView->jumpToAddress(position);
            ui->hexGraphicsView->highlightBytes(position, hex.length() >> 1);
        }
        else
        {
            dataInspectorLeaved();
        }
    }
    else
    {
        dataInspectorLeaved();
    }
}

void MainWindow::dataInspectorLeaved()
{
    if (mDataInspectorScrollBarValue >= 0)
    {
        ui->hexGraphicsView->verticalScrollBar()->setValue(mDataInspectorScrollBarValue);
        ui->hexGraphicsView->highlightBytes(-1, 0);

        mDataInspectorScrollBarValue = -1;
    }
}

void MainWindow::goToDisabledMode()
{
    ui->actionStop->setEnabled(false);
    ui->actionNext_step->setEnabled(false);
    ui->actionShow_memory_map->setEnabled(false);

    ui->backToolButton->setEnabled(false);



    ui->waitingProgressBar->setValue(0);
    mWaitingTimer.start(1000);
    ui->spinnerLabel->movie()->start();



    ui->stackedWidget->setCurrentIndex(WAITING_PAGE);
}

void MainWindow::goToEnabledMode()
{
    ui->actionStop->setEnabled(true);
    ui->actionNext_step->setEnabled(true);
    ui->actionShow_memory_map->setEnabled(true);

    ui->backToolButton->setEnabled(true);



    mWaitingTimer.stop();
    ui->spinnerLabel->movie()->stop();



    ui->stackedWidget->setCurrentIndex(MAIN_PAGE);
}

void MainWindow::saveWindowState()
{
    QSettings settings("NGOS", "gdb_debug");

    settings.setValue("MainWindow/geometry",       saveGeometry());
    settings.setValue("MainWindow/windowState",    saveState());
    settings.setValue("MainWindow/splitterState",  ui->splitter->saveState());
    settings.setValue("MainWindow/splitter2State", ui->splitter2->saveState());
    settings.setValue("MainWindow/splitter3State", ui->splitter3->saveState());
    settings.setValue("MainWindow/splitter4State", ui->splitter4->saveState());
}

void MainWindow::loadWindowState()
{
    QSettings settings("NGOS", "gdb_debug");

    // Ignore CppAlignmentVerifier [BEGIN]
    restoreGeometry(            settings.value("MainWindow/geometry").toByteArray());
    restoreState(               settings.value("MainWindow/windowState").toByteArray());
    ui->splitter->restoreState( settings.value("MainWindow/splitterState").toByteArray());
    ui->splitter2->restoreState(settings.value("MainWindow/splitter2State").toByteArray());
    ui->splitter3->restoreState(settings.value("MainWindow/splitter3State").toByteArray());
    ui->splitter4->restoreState(settings.value("MainWindow/splitter4State").toByteArray());
    // Ignore CppAlignmentVerifier [END]
}
