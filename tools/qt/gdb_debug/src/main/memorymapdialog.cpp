#include "memorymapdialog.h"
#include "ui_memorymapdialog.h"

#include "src/other/defines.h"



#define WORKERS_COUNT 8
#define SCENE_WIDTH   4096



MemoryMapDialog::MemoryMapDialog(HexGraphicsView *hexgraphicsview, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MemoryMapDialog())
    , mHexgraphicsview(hexgraphicsview)
    , mWorkers()
    , mWorkersCompleted(0)
{
    ui->setupUi(this);

    setWindowFlags(
                    Qt::Dialog
                    | Qt::CustomizeWindowHint
                    | Qt::WindowTitleHint
                    | Qt::WindowSystemMenuHint
                    | Qt::WindowCloseButtonHint
    );



    quint64 total = MEMORY_SIZE_MB * MB_SIZE;
    quint64 part  = total / WORKERS_COUNT;

    for (qint64 i = 0; i < WORKERS_COUNT; ++i)
    {
        MemoryMapThread *worker = new MemoryMapThread(mHexgraphicsview, i * part, (i + 1) * part);
        connect(worker, SIGNAL(finished()), this, SLOT(workerFinished()));
        worker->start(QThread::HighestPriority);

        mWorkers.append(worker);
    }
}

MemoryMapDialog::~MemoryMapDialog()
{
    for (qint64 i = 0; i < WORKERS_COUNT; ++i)
    {
        MemoryMapThread *worker = mWorkers.at(i);

        worker->blockSignals(true);
        worker->stop();
        worker->wait();

        delete worker;
    }

    delete ui;
}

void MemoryMapDialog::on_graphicsView_doubleClicked(quint64 x, quint64 y)
{
    QPointF point = ui->graphicsView->mapToScene(x, y);

    if (ui->graphicsView->sceneRect().contains(point))
    {
        mHexgraphicsview->jumpToAddress((qRound(point.y()) - 1) * SCENE_WIDTH + qRound(point.x()) - 1);

        accept();
    }
}

void MemoryMapDialog::workerFinished()
{
    ++mWorkersCompleted;

    if (mWorkersCompleted == WORKERS_COUNT)
    {
        QList<MemoryMapInfo> memoryMapBlocks;

        for (qint64 i = 0; i < WORKERS_COUNT; ++i)
        {
            MemoryMapThread *worker = mWorkers.at(i);

            QList<MemoryMapInfo> memoryMapPartBlocks = worker->getResult();

            if (memoryMapPartBlocks.length()) // memoryMapPartBlocks.length() > 0
            {
                if (memoryMapBlocks.length()) // memoryMapBlocks.length() > 0
                {
                    MemoryMapInfo &lastBlock  = memoryMapBlocks.last();
                    MemoryMapInfo &firstBlock = memoryMapPartBlocks.first();

                    if (lastBlock.brush == firstBlock.brush)
                    {
                        lastBlock.count += firstBlock.count;
                        memoryMapPartBlocks.removeFirst();
                    }
                }

                memoryMapBlocks.append(memoryMapPartBlocks);
            }
        }



        QGraphicsScene *scene = new QGraphicsScene(0, 0, SCENE_WIDTH + 2, MEMORY_SIZE_MB * MB_SIZE / SCENE_WIDTH + 2, this);

        scene->addRect(0, 0, scene->sceneRect().width() - 1, scene->sceneRect().height() - 1, QPen(QColor("#000000")), QBrush(QColor("#F0F0F0")));



        quint64 position = 0;

        for (qint64 i = 0; i < memoryMapBlocks.length(); ++i)
        {
            const MemoryMapInfo &memoryMapBlock = memoryMapBlocks.at(i);



            quint64 start = position;
            quint64 end   = position + memoryMapBlock.count;

            position = end;



            if (memoryMapBlock.brush)
            {
                quint64 startAligned = start & ~(SCENE_WIDTH - 1);
                quint64 endAligned   = end   & ~(SCENE_WIDTH - 1);

                quint64 startY = startAligned / SCENE_WIDTH + 1;

                if (startAligned == endAligned)
                {
                    scene->addLine(start - startAligned + 1, startY, end - endAligned, startY, QPen(*memoryMapBlock.brush, 1));
                }
                else
                {
                    quint64 endY = endAligned / SCENE_WIDTH + 1;

                    if (start != startAligned)
                    {
                        scene->addLine(start - startAligned + 1, startY, SCENE_WIDTH, startY, QPen(*memoryMapBlock.brush, 1));
                        ++startY;
                    }

                    if (end != endAligned)
                    {
                        scene->addLine(1, endY, end - endAligned, endY, QPen(*memoryMapBlock.brush, 1));
                        --endY;
                    }

                    if (startY == endY)
                    {
                        scene->addLine(1, startY, SCENE_WIDTH, startY, QPen(*memoryMapBlock.brush, 1));
                    }
                    else
                    if (startY < endY)
                    {
                        scene->addRect(1, startY, SCENE_WIDTH - 1, endY - startY, QPen(*memoryMapBlock.brush, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin), *memoryMapBlock.brush);
                    }
                }
            }
        }



        ui->graphicsView->setScene(scene);
    }
}
