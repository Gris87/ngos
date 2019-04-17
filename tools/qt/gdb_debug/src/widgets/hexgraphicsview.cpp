#include "hexgraphicsview.h"

#include <QFontMetrics>
#include <QMouseEvent>
#include <QScrollBar>
#include <QtMath>

#include "src/generated/hexarrays.h"



#define ADDRESS_LENGTH 16
#define CHARS_PER_LINE 16

#define UNDERSCORE_MARGIN 1

#define BLOCKS_Z_LEVEL     0
#define UNDERSCORE_Z_LEVEL 1
#define CHARS_Z_LEVEL      2

#define BLOCK_COLORS_COUNT 17



QBrush blockColors[BLOCK_COLORS_COUNT] =
{
    QBrush(QColor("#E0E0E0")),
    QBrush(QColor("#FFCCCC")),
    QBrush(QColor("#CEFFFF")),
    QBrush(QColor("#E5FFCC")),
    QBrush(QColor("#E5CCFF")),
    QBrush(QColor("#FFF2CC")),
    QBrush(QColor("#CCFFD8")),
    QBrush(QColor("#CCD8FF")),
    QBrush(QColor("#FFCCF2")),
    QBrush(QColor("#FFDECC")),
    QBrush(QColor("#F9FFCC")),
    QBrush(QColor("#D2FFCC")),
    QBrush(QColor("#CCFFEB")),
    QBrush(QColor("#CCECFF")),
    QBrush(QColor("#D1CCFF")),
    QBrush(QColor("#F8CCFF")),
    QBrush(QColor("#FFCCDF"))
};

QBrush underscoreBrush(QColor("#66BFFF"));

QBrush hoveredBrush(QColor("#B0B0F0"));
QBrush selectedBrush(QColor("#8080D0"));
QBrush highlightedBrush(QColor("#40F0F0"));
QBrush changedBrush(QColor("#71AFE2"));
QBrush bootParamsBrush(QColor("#FFA54C"));
QBrush kernelBrush(QColor("#EEEEEE"));



HexGraphicsView::HexGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , mGdbProcess(0)
    , mBytes()
    , mBytesOld()
    , mScene(new QGraphicsScene())
    , mHexBlocks()
    , mCharsBlocks()
    , mHexUnderscore(0)
    , mCharsUnderscore(0)
    , mLines()
    , mHexFont("Monospace", 12, QFont::Normal, false)
    , mCharWidth(-1)
    , mLineHeight(-1)
    , mUnderscoreWidth(-1)
    , mHoveredByte(-1)
    , mSelectedByte(-1)
    , mHighlightStart(-1)
    , mHighlightEnd(-1)
    , mBootParamsStart(-1)
    , mBootParamsEnd(-1)
    , mKernelStart(-1)
    , mKernelEnd(-1)
{
    setScene(mScene);



    QFontMetrics fontMetrics(mHexFont);

    mCharWidth       = fontMetrics.width("0000000000000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |........  ........|") / 88.0;
    mLineHeight      = fontMetrics.height();
    mUnderscoreWidth = mCharWidth - UNDERSCORE_MARGIN;



    mHexUnderscore   = mScene->addRect(0, 0, (mCharWidth * 2.0) - (UNDERSCORE_MARGIN << 1), mUnderscoreWidth, QPen(Qt::NoPen), underscoreBrush);
    mCharsUnderscore = mScene->addRect(0, 0, (mCharWidth)       - (UNDERSCORE_MARGIN << 1), mUnderscoreWidth, QPen(Qt::NoPen), underscoreBrush);

    mHexUnderscore->setZValue(UNDERSCORE_Z_LEVEL);
    mCharsUnderscore->setZValue(UNDERSCORE_Z_LEVEL);

    mHexUnderscore->setVisible(false);
    mCharsUnderscore->setVisible(false);

    setMouseTracking(true);

    connect(verticalScrollBar(), SIGNAL(valueChanged(qint32)), this, SLOT(verticalScrollBarValueChanged(qint32)));
}

HexGraphicsView::~HexGraphicsView()
{
    delete mScene;
}

void HexGraphicsView::setGdbProcess(GdbProcess *gdbProcess)
{
    mGdbProcess = gdbProcess;



    if (mGdbProcess)
    {
        mBytes    = mGdbProcess->getMemoryDump();
        mBytesOld = mBytes;

        qint64 linesCount = qCeil(mBytes.length() / (double)CHARS_PER_LINE);
        mScene->setSceneRect(0, 0, mCharWidth * 88, linesCount * mLineHeight);
    }
    else
    {
        mBytes.clear();
        mBytesOld.clear();
    }



    updateLinesFull();
}

void HexGraphicsView::setMemoryDump(const QByteArray &memoryDump)
{
    mBytesOld = mBytes;
    mBytes    = memoryDump;

    updateLines();
}

void HexGraphicsView::setCurrentPosition(quint64 position)
{
    qint64 column = position % CHARS_PER_LINE;
    qint64 row    = (position - column) / CHARS_PER_LINE;



    quint8 skip = 0;

    if (column >= (CHARS_PER_LINE >> 1))
    {
        skip = 2;
    }



    mHexUnderscore->setPos((ADDRESS_LENGTH + column * 3 + (skip >> 1) + 2) * mCharWidth + UNDERSCORE_MARGIN, (row + 1) * mLineHeight - mUnderscoreWidth - UNDERSCORE_MARGIN);
    mHexUnderscore->setVisible(true);

    mCharsUnderscore->setPos((ADDRESS_LENGTH + CHARS_PER_LINE * 3 + column + skip + 5) * mCharWidth + UNDERSCORE_MARGIN, (row + 1) * mLineHeight - mUnderscoreWidth - UNDERSCORE_MARGIN);
    mCharsUnderscore->setVisible(true);



    verticalScrollBar()->setValue(row * mLineHeight);
}

void HexGraphicsView::jumpToAddress(quint64 position)
{
    qint64 column = position % CHARS_PER_LINE;
    qint64 row    = (position - column) / CHARS_PER_LINE;

    verticalScrollBar()->setValue(row * mLineHeight);
}

void HexGraphicsView::updateLinesFull()
{
    qint64 rowCount = qCeil(height() / (double)mLineHeight) + 1;



    while (mLines.length() > rowCount)
    {
        // Removing blocks
        {
            QList<QGraphicsRectItem *> row;



            row = mHexBlocks.takeLast();

            for (qint64 i = 0; i < row.length(); ++i)
            {
                QGraphicsItem *item = row.at(i);

                mScene->removeItem(item);
                delete item;
            }



            row = mCharsBlocks.takeLast();

            for (qint64 i = 0; i < row.length(); ++i)
            {
                QGraphicsItem *item = row.at(i);

                mScene->removeItem(item);
                delete item;
            }
        }

        // Removing line
        {
            QGraphicsItem *item = mLines.takeLast();

            mScene->removeItem(item);
            delete item;
        }
    }



    while (mLines.length() < rowCount)
    {
        // Adding blocks
        {
            QList<QGraphicsRectItem *> row;

            for (qint64 i = 0; i < CHARS_PER_LINE; ++i)
            {
                QGraphicsRectItem *item = mScene->addRect(0, 0, mCharWidth * 3, mLineHeight, QPen(Qt::NoPen));

                item->setZValue(BLOCKS_Z_LEVEL);
                row.append(item);
            }

            mHexBlocks.append(row);



            row.clear();

            for (qint64 i = 0; i < CHARS_PER_LINE; ++i)
            {
                QGraphicsRectItem *item = mScene->addRect(0, 0, mCharWidth, mLineHeight, QPen(Qt::NoPen));

                item->setZValue(BLOCKS_Z_LEVEL);
                row.append(item);
            }

            mCharsBlocks.append(row);
        }

        // Adding line
        {
            QGraphicsSimpleTextItem *item = mScene->addSimpleText("", mHexFont);

            item->setZValue(CHARS_Z_LEVEL);
            mLines.append(item);
        }
    }



    updateLines();
}

void HexGraphicsView::updateLines()
{
    if (!mGdbProcess) // mGdbProcess == 0
    {
        return;
    }



    qint64 startIndex  = qFloor(verticalScrollBar()->value() / (double)mLineHeight);
    qint64 linesCount  = qCeil(mBytes.length() / (double)CHARS_PER_LINE);
    qint64 lastSection = 0;

    QList<ElfSectionHeaderTableEntry *> sections = mGdbProcess->getElfObject().getSections();



    for (qint64 i = 0; i < mLines.length(); ++i)
    {
        qint64 lineIndex = startIndex + i;

        if (lineIndex < linesCount)
        {
            qint64 offset = lineIndex * CHARS_PER_LINE;



            // Updating blocks
            {
                QList<QGraphicsRectItem *> hexRow   = mHexBlocks.at(i);
                QList<QGraphicsRectItem *> charsRow = mCharsBlocks.at(i);



                for (qint64 j = 0; j < CHARS_PER_LINE; ++j)
                {
                    QGraphicsRectItem *hexBlock  = hexRow.at(j);
                    QGraphicsRectItem *charBlock = charsRow.at(j);



                    qint64  address = offset + j;
                    QBrush *brush   = getBrushForByte(address, &lastSection, &sections);

                    if (brush)
                    {
                        quint8 skip = 0;

                        if (j >= (CHARS_PER_LINE >> 1))
                        {
                            skip = 2;
                        }



                        hexBlock->setPos((ADDRESS_LENGTH + j * 3 + 2) * mCharWidth, lineIndex * mLineHeight);
                        hexBlock->setBrush(*brush);
                        hexBlock->setVisible(true);

                        charBlock->setPos((ADDRESS_LENGTH + CHARS_PER_LINE * 3 + j + skip + 5) * mCharWidth, lineIndex * mLineHeight);
                        charBlock->setBrush(*brush);
                        charBlock->setVisible(true);
                    }
                    else
                    {
                        hexBlock->setVisible(false);
                        charBlock->setVisible(false);
                    }
                }
            }

            // Updating line
            {
                QGraphicsSimpleTextItem *line = mLines.at(i);

                line->setPos(0, lineIndex * mLineHeight);
                line->setVisible(true);



                QString hexLine;
                QString charLine;

                for (qint64 j = offset; j < mBytes.length() && j < offset + CHARS_PER_LINE; ++j)
                {
                    quint8 byte = mBytes.at(j);

                    if (j == offset + (CHARS_PER_LINE >> 1))
                    {
                        hexLine.append(' ');

                        charLine.append("  ");
                    }

                    hexLine.append(hexArray[byte]);
                    hexLine.append(' ');
                    charLine.append(charArray[byte]);
                }



                QString resultLine;

                if (hexLine != "")
                {
                    resultLine = QString("%1  %2 |%3|").arg(offset, ADDRESS_LENGTH, 16, QChar('0')).arg(hexLine, -(CHARS_PER_LINE * 3 + 1), QChar(' ')).arg(charLine, -(CHARS_PER_LINE + 2), QChar(' ')); // Ignore CppOperatorSpacesVerifier
                }



                line->setText(resultLine);
            }
        }
        else
        {
            // Updating blocks
            {
                QList<QGraphicsRectItem *> row;



                row = mHexBlocks.at(i);

                for (qint64 j = 0; j < row.length(); ++j)
                {
                    row.at(j)->setVisible(false);
                }



                row = mCharsBlocks.at(i);

                for (qint64 j = 0; j < row.length(); ++j)
                {
                    row.at(j)->setVisible(false);
                }
            }

            // Updating line
            {
                mLines.at(i)->setVisible(false);
            }
        }
    }
}

void HexGraphicsView::hoverByte(qint64 position)
{
    if (mHoveredByte != position)
    {
        mHoveredByte = position;

        updateLines();

        emit byteHovered(position);
    }
}

void HexGraphicsView::selectByte(qint64 position)
{
    if (mSelectedByte != position)
    {
        mSelectedByte = position;

        updateLines();

        if (position >= 0)
        {
            emit byteClicked(position);
        }
    }
}

void HexGraphicsView::highlightBytes(qint64 position, qint64 count)
{
    if (mHighlightStart != position || mHighlightEnd != position + count - 1)
    {
        mHighlightStart = position;
        mHighlightEnd   = position + count - 1;

        updateLines();
    }
}

void HexGraphicsView::setBootParamsRange(qint64 position, qint64 count)
{
    if (mBootParamsStart != position || mBootParamsEnd != position + count - 1)
    {
        mBootParamsStart = position;
        mBootParamsEnd   = position + count - 1;

        updateLines();
    }
}

void HexGraphicsView::setKernelRange(qint64 position, qint64 count)
{
    if (mKernelStart != position || mKernelEnd != position + count - 1)
    {
        mKernelStart = position;
        mKernelEnd   = position + count - 1;

        updateLines();
    }
}

QBrush* HexGraphicsView::getBrushForByte(qint64 address, qint64 *lastSection, const QList<ElfSectionHeaderTableEntry *> *sections)
{
    if (!sections)
    {
        sections = &(mGdbProcess->getElfObject().getSections());
    }



    if (address == mHoveredByte)
    {
        return &hoveredBrush;
    }

    if (address >= mHighlightStart && address <= mHighlightEnd)
    {
        return &highlightedBrush;
    }

    if (address == mSelectedByte)
    {
        return &selectedBrush;
    }

    if (
        address >= 0
        &&
        address < mBytes.length()
        &&
        address < mBytesOld.length()
        &&
        mBytes.at(address) != mBytesOld.at(address)
       )
    {
        return &changedBrush;
    }

    if (address >= mBootParamsStart && address <= mBootParamsEnd)
    {
        return &bootParamsBrush;
    }

    // Color sections
    {
        qint64 startSection = 0;

        if (lastSection)
        {
            startSection = *lastSection;
        }



        for (qint64 k = startSection; k < sections->length(); ++k)
        {
            ElfSectionHeaderTableEntry *section = sections->at(k);

            if (
                (section->flags & (quint64)ElfSectionFlag::ALLOC)
                &&
                address >= (qint64)(mGdbProcess->getKernelLocation() + section->virtualAddress)
                &&
                address < (qint64)(mGdbProcess->getKernelLocation() + section->virtualAddress + section->size)
               )
            {
                if (lastSection)
                {
                    *lastSection = k;
                }

                return &blockColors[k % BLOCK_COLORS_COUNT];
            }
        }

        for (qint64 k = 0; k < startSection; ++k)
        {
            ElfSectionHeaderTableEntry *section = sections->at(k);

            if (
                (section->flags & (quint64)ElfSectionFlag::ALLOC)
                &&
                address >= (qint64)(mGdbProcess->getKernelLocation() + section->virtualAddress)
                &&
                address < (qint64)(mGdbProcess->getKernelLocation() + section->virtualAddress + section->size)
               )
            {
                if (lastSection)
                {
                    *lastSection = k;
                }

                return &blockColors[k % BLOCK_COLORS_COUNT];
            }
        }
    }

    if (address >= mKernelStart && address <= mKernelEnd)
    {
        return &kernelBrush;
    }

    return 0;
}

GdbProcess* HexGraphicsView::getGdbProcess()
{
    return mGdbProcess;
}

void HexGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    updateLinesFull();
}

void HexGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);



    QPointF scenePosition = mapToScene(event->pos());

    double posX = scenePosition.x();
    double posY = scenePosition.y();

    double hexLeft  = (ADDRESS_LENGTH + 2) * mCharWidth;
    double hexRight = hexLeft + CHARS_PER_LINE * 3 * mCharWidth;



    qint8 selectedChar = -1;

    if (posX >= hexLeft && posX <= hexRight)
    {
        selectedChar = qFloor((posX - hexLeft) / (mCharWidth * 3));
    }
    else
    {
        double charsLeft  = hexRight + 3 * mCharWidth;
        double charsRight = charsLeft + (CHARS_PER_LINE + 2) * mCharWidth;

        if (posX >= charsLeft && posX <= charsRight)
        {
            selectedChar = qFloor((posX - charsLeft) / mCharWidth);

            if (selectedChar >= 8)
            {
                if (selectedChar >= 10)
                {
                    selectedChar -= 2;
                }
                else
                {
                    selectedChar = -1;
                }
            }
        }
    }



    if (selectedChar >= 0)
    {
        qint64 selectedAddress = qFloor(posY / mLineHeight) * CHARS_PER_LINE + selectedChar;

        if (selectedAddress >= 0 && selectedAddress < mBytes.length())
        {
            hoverByte(selectedAddress);
        }
        else
        {
            hoverByte(-1);
        }
    }
    else
    {
        hoverByte(-1);
    }
}

void HexGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);

    if (mHoveredByte >= 0)
    {
        selectByte(mHoveredByte);
    }
}

void HexGraphicsView::leaveEvent(QEvent *event)
{
    QGraphicsView::leaveEvent(event);

    hoverByte(-1);
}

void HexGraphicsView::verticalScrollBarValueChanged(qint32 /*position*/)
{
    updateLines();
}
