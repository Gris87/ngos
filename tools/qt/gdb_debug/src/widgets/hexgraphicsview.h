#ifndef GDB_DEBUG_SRC_WIDGETS_HEXGRAPHICSVIEW_H
#define GDB_DEBUG_SRC_WIDGETS_HEXGRAPHICSVIEW_H



#include <QGraphicsView>

#include <QGraphicsSimpleTextItem>
#include <QList>

#include "src/processes/gdbprocess.h"



class HexGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit HexGraphicsView(QWidget *parent = 0); // TEST: NO
    ~HexGraphicsView(); // TEST: NO

    void setGdbProcess(GdbProcess *gdbProcess); // TEST: NO
    void setMemoryDump(const QByteArray &memoryDump); // TEST: NO
    void setCurrentPosition(quint64 position); // TEST: NO
    void jumpToAddress(quint64 position); // TEST: NO

    void updateLinesFull(); // TEST: NO
    void updateLines(); // TEST: NO

    void hoverByte(qint64 position); // TEST: NO
    void selectByte(qint64 position); // TEST: NO
    void highlightBytes(qint64 position, qint64 count); // TEST: NO
    void setBootParamsRange(qint64 position, qint64 count); // TEST: NO
    void setKernelRange(qint64 position, qint64 count); // TEST: NO

    QBrush* getBrushForByte(qint64 address, qint64 *lastSection = 0, const QList<ElfSectionHeaderTableEntry *> *sections = 0); // TEST: NO

    GdbProcess* getGdbProcess(); // TEST: NO

protected:
    void resizeEvent(QResizeEvent *event) override; // TEST: NO
    void mouseMoveEvent(QMouseEvent *event) override; // TEST: NO
    void mouseReleaseEvent(QMouseEvent *event) override; // TEST: NO
    void leaveEvent(QEvent *event) override; // TEST: NO

private slots:
    void verticalScrollBarValueChanged(qint32 position); // TEST: NO

private:
    GdbProcess                        *mGdbProcess;
    QByteArray                         mBytes;
    QByteArray                         mBytesOld;
    QGraphicsScene                    *mScene;
    QList<QList<QGraphicsRectItem *>>  mHexBlocks;
    QList<QList<QGraphicsRectItem *>>  mCharsBlocks;
    QGraphicsRectItem                 *mHexUnderscore;
    QGraphicsRectItem                 *mCharsUnderscore;
    QList<QGraphicsSimpleTextItem *>   mLines;
    QFont                              mHexFont;
    double                             mCharWidth;
    qint64                             mLineHeight;
    double                             mUnderscoreWidth;
    qint64                             mHoveredByte;
    qint64                             mSelectedByte;
    qint64                             mHighlightStart;
    qint64                             mHighlightEnd;
    qint64                             mBootParamsStart;
    qint64                             mBootParamsEnd;
    qint64                             mKernelStart;
    qint64                             mKernelEnd;

signals:
    void byteHovered(qint64 position); // TEST: NO
    void byteClicked(qint64 position); // TEST: NO
};



#endif // GDB_DEBUG_SRC_WIDGETS_HEXGRAPHICSVIEW_H
