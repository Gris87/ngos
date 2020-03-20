#include "tablewidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/gui.h>
#include <common/src/bits64/gui/widgets/misc/tablecellwidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/linkage.h>



#define INVALID_ROW 0xFFFFFFFFFFFFFFFF



TableWidget::TableWidget(Image *backgroundImage, Image *headerImage, Widget *parent)
    : Widget(parent)
    , mBackgroundImage(backgroundImage)
    , mHeaderImage(headerImage)
    , mState(WidgetState::NORMAL)
    , mRowHeight(0)
    , mColumnWidth()
    , mTotalColumnWidth(0)
    , mHeaders()
    , mContentWrapperWidget(nullptr)
    , mScrollWrapperWidget(nullptr)
    , mRows()
    , mSelectedRow(0)
    , mHighlightedRow(INVALID_ROW)
    , mKeyboardEventHandler(nullptr)
{
    COMMON_LT((" | backgroundImage = 0x%p, headerImage = 0x%p, parent = 0x%p", backgroundImage, headerImage, parent));

    COMMON_ASSERT(backgroundImage, "backgroundImage is null");
    COMMON_ASSERT(headerImage,     "headerImage is null");
    COMMON_ASSERT(parent,          "parent is null");
}

TableWidget::~TableWidget()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    if (mResultImage)
    {
        delete mResultImage;
    }
}

NgosStatus TableWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    COMMON_ASSERT_EXECUTION(Graphics::resizeImage(mBackgroundImage, mWidth, mHeight, &mOwnResultImage), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus TableWidget::repaint()
{
    COMMON_LT((""));



    COMMON_TEST_ASSERT(mOwnResultImage != nullptr, NgosStatus::ASSERTION);



    if (mResultImage)
    {
        delete mResultImage;
    }

    mResultImage = new Image(*mOwnResultImage);



    ListElement<Widget *> *element = mChildren.getHead();

    while (element)
    {
        Widget *widget = element->getData();

        COMMON_ASSERT_EXECUTION(drawWidget(widget, widget->getPositionX(), widget->getPositionY()), NgosStatus::ASSERTION);

        element = element->getNext();
    }



    return NgosStatus::OK;
}

NgosStatus TableWidget::onKeyboardEvent(const UefiInputKey &key)
{
    COMMON_LT((" | key = ..."));



    switch (key.scanCode)
    {
        case UefiInputKeyScanCode::UP:
        {
            if (mSelectedRow <= 0)
            {
                return NgosStatus::NO_EFFECT;
            }



            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(setSelectedRow(mSelectedRow - 1), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(scrollToSelectedRow(),            NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::DOWN:
        {
            if (mSelectedRow >= mRows.getSize() - 1)
            {
                return NgosStatus::NO_EFFECT;
            }



            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(setSelectedRow(mSelectedRow + 1), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(scrollToSelectedRow(),            NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::HOME:
        {
            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(setSelectedRow(0),     NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(scrollToSelectedRow(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::END:
        {
            COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(setSelectedRow(mRows.getSize() - 1), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(scrollToSelectedRow(),               NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);



            return NgosStatus::OK;
        }
        break;

        case UefiInputKeyScanCode::PAGE_UP:   return pageUp();
        case UefiInputKeyScanCode::PAGE_DOWN: return pageDown();

        default:
        {
            // Nothing
        }
        break;
    }



    return NgosStatus::NO_EFFECT;
}

NgosStatus TableWidget::onMouseScrollEvent(i32 delta)
{
    COMMON_LT((" | delta = %d", delta));

    COMMON_ASSERT(delta != 0, "delta is zero", NgosStatus::ASSERTION);



    if (delta > 0)
    {
        i64 positionY = mScrollWrapperWidget->getPositionY() - mRowHeight * delta;

        if (positionY < (i64)(mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight()))
        {
            positionY = mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight();
        }

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);
    }
    else
    {
        i64 positionY = mScrollWrapperWidget->getPositionY() - mRowHeight * delta;

        if (positionY > 0)
        {
            positionY = 0;
        }

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TableWidget::scrollToSelectedRow()
{
    COMMON_LT((""));



    i64 localPositionY  = mSelectedRow * mRowHeight;
    i64 globalPositionY = localPositionY + mScrollWrapperWidget->getPositionY();

    if (globalPositionY < 0)
    {
        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, -localPositionY), NgosStatus::ASSERTION);

        if (!GUI::getPressedWidget())
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }
    else
    if (globalPositionY + (i64)mRowHeight > (i64)mContentWrapperWidget->getHeight())
    {
        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, (i64)mContentWrapperWidget->getHeight() - localPositionY - mRowHeight), NgosStatus::ASSERTION);

        if (!GUI::getPressedWidget())
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TableWidget::pageUp()
{
    COMMON_LT((""));



    u64 visibleRow = mContentWrapperWidget->getHeight() / mRowHeight;

    if (visibleRow < 1)
    {
        visibleRow = 1;
    }



    if (visibleRow >= mRows.getSize())
    {
        COMMON_ASSERT_EXECUTION(setSelectedRow(0), NgosStatus::ASSERTION);
    }
    else
    {
        u64 selectedRow;

        if (mSelectedRow <= visibleRow)
        {
            selectedRow = 0;
        }
        else
        {
            selectedRow = mSelectedRow - visibleRow;
        }



        i64 positionY = mScrollWrapperWidget->getPositionY() + visibleRow * mRowHeight;

        if (positionY > 0)
        {
            positionY = 0;
        }



        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(setSelectedRow(selectedRow),                     NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);

        if (!GUI::getPressedWidget())
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TableWidget::pageDown()
{
    COMMON_LT((""));



    u64 visibleRow = mContentWrapperWidget->getHeight() / mRowHeight;

    if (visibleRow < 1)
    {
        visibleRow = 1;
    }



    if (visibleRow >= mRows.getSize())
    {
        COMMON_ASSERT_EXECUTION(setSelectedRow(mRows.getSize() - 1), NgosStatus::ASSERTION);
    }
    else
    {
        u64 selectedRow;

        if (mSelectedRow >= mRows.getSize() - visibleRow)
        {
            selectedRow = mRows.getSize() - 1;
        }
        else
        {
            selectedRow = mSelectedRow + visibleRow;
        }



        i64 positionY = mScrollWrapperWidget->getPositionY() - visibleRow * mRowHeight;

        if (positionY < (i64)(mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight()))
        {
            positionY = mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight();
        }



        COMMON_ASSERT_EXECUTION(GUI::lockUpdates(), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(setSelectedRow(selectedRow),                     NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);

        if (!GUI::getPressedWidget())
        {
            COMMON_ASSERT_EXECUTION(GUI::detectHoveredWidget(), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(GUI::unlockUpdates(), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

bool TableWidget::isFocusable()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

NgosStatus TableWidget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;



        TableRowWidget *selectedRow = mRows.at(mSelectedRow);

        switch (mState)
        {
            case WidgetState::NORMAL:
            {
                COMMON_ASSERT_EXECUTION(setHighlightedRow(INVALID_ROW), NgosStatus::ASSERTION);

                switch (selectedRow->getState())
                {
                    case WidgetState::FOCUSED: COMMON_ASSERT_EXECUTION(selectedRow->setState(WidgetState::INACTIVE), NgosStatus::ASSERTION); break;

                    case WidgetState::INACTIVE:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    case WidgetState::FOCUSED_HOVERED:
                    case WidgetState::INACTIVE_HOVERED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::FOCUSED:
            {
                COMMON_ASSERT_EXECUTION(setHighlightedRow(INVALID_ROW), NgosStatus::ASSERTION);

                switch (selectedRow->getState())
                {
                    case WidgetState::INACTIVE: COMMON_ASSERT_EXECUTION(selectedRow->setState(WidgetState::FOCUSED), NgosStatus::ASSERTION); break;

                    case WidgetState::FOCUSED:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    case WidgetState::FOCUSED_HOVERED:
                    case WidgetState::INACTIVE_HOVERED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::FOCUSED_HOVERED:
            {
                switch (selectedRow->getState())
                {
                    case WidgetState::INACTIVE:         COMMON_ASSERT_EXECUTION(selectedRow->setState(WidgetState::FOCUSED),         NgosStatus::ASSERTION); break;
                    case WidgetState::INACTIVE_HOVERED: COMMON_ASSERT_EXECUTION(selectedRow->setState(WidgetState::FOCUSED_HOVERED), NgosStatus::ASSERTION); break;

                    case WidgetState::FOCUSED:
                    case WidgetState::FOCUSED_HOVERED:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::PRESSED:
            {
                if (mHighlightedRow != INVALID_ROW)
                {
                    COMMON_ASSERT_EXECUTION(setSelectedRow(mHighlightedRow), NgosStatus::ASSERTION);
                }
            }
            break;

            case WidgetState::HOVERED:
            {
                switch (selectedRow->getState())
                {
                    case WidgetState::FOCUSED:         COMMON_ASSERT_EXECUTION(selectedRow->setState(WidgetState::INACTIVE),         NgosStatus::ASSERTION); break;
                    case WidgetState::FOCUSED_HOVERED: COMMON_ASSERT_EXECUTION(selectedRow->setState(WidgetState::INACTIVE_HOVERED), NgosStatus::ASSERTION); break;

                    case WidgetState::INACTIVE:
                    case WidgetState::INACTIVE_HOVERED:
                    {
                        // Nothing
                    }
                    break;

                    case WidgetState::NONE:
                    case WidgetState::NORMAL:
                    case WidgetState::HOVERED:
                    case WidgetState::PRESSED:
                    {
                        COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;

                    default:
                    {
                        COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(selectedRow->getState()), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }
            break;

            case WidgetState::NONE:
            case WidgetState::INACTIVE:
            case WidgetState::INACTIVE_HOVERED:
            {
                COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(mState), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(mState), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }
    }



    return NgosStatus::OK;
}

WidgetState TableWidget::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus TableWidget::setRowHeight(u64 height)
{
    COMMON_LT((" | height = %u", height));

    COMMON_ASSERT(height > 0, "height is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mRowHeight            == 0,       NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mContentWrapperWidget == nullptr, NgosStatus::ASSERTION);



    mRowHeight = height;



    mContentWrapperWidget = new WrapperWidget(this);

    COMMON_ASSERT_EXECUTION(mContentWrapperWidget->setPosition(0, mRowHeight),            NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(mContentWrapperWidget->setSize(mWidth, mHeight - mRowHeight), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

u64 TableWidget::getRowHeight() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mRowHeight;
}

NgosStatus TableWidget::setColumnCount(u64 columns)
{
    COMMON_LT((" | columns = %u", columns));

    COMMON_ASSERT(columns > 0, "columns is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mColumnWidth.getSize() == 0, NgosStatus::ASSERTION);



    for (i64 i = 0; i < (i64)columns; ++i)
    {
        mColumnWidth.append(0);
        mHeaders.append(nullptr);
    }



    return NgosStatus::OK;
}

u64 TableWidget::getColumnCount() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mColumnWidth.getSize();
}

NgosStatus TableWidget::setColumnWidth(u64 column, u64 width)
{
    COMMON_LT((" | column = %u, width = %u", column, width));

    COMMON_ASSERT(width > 0, "width is zero", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mColumnWidth.at(column) == 0, NgosStatus::ASSERTION);
    mColumnWidth[column] = width;

    mTotalColumnWidth += width;



    return NgosStatus::OK;
}

u64 TableWidget::getColumnWidth(u64 column) const
{
    // COMMON_LT((" | column = %u", column)); // Commented to avoid too frequent logs



    return mColumnWidth.at(column);
}

NgosStatus TableWidget::setHeaderText(u64 column, const char8 *text)
{
    COMMON_LT((" | column = %u, text = 0x%p", column, text));

    COMMON_ASSERT(text, "text is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(mHeaders.at(column)     == nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(mColumnWidth.at(column) > 0,        NgosStatus::ASSERTION);



    u64 positionX = 0;

    for (i64 i = 0; i < (i64)column; ++i)
    {
        COMMON_TEST_ASSERT(mColumnWidth.at(i) > 0, NgosStatus::ASSERTION);

        positionX += mColumnWidth.at(i);
    }



    TableHeaderWidget *header = new TableHeaderWidget(mHeaderImage, text, this);

    COMMON_ASSERT_EXECUTION(header->setPosition(positionX, 0),                    NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(header->setSize(mColumnWidth.at(column), mRowHeight), NgosStatus::ASSERTION);

    mHeaders[column] = header;



    return NgosStatus::OK;
}

NgosStatus TableWidget::setRowCount(u64 rows)
{
    COMMON_LT((" | rows = %u", rows));



    if (!mScrollWrapperWidget)
    {
        COMMON_TEST_ASSERT(mContentWrapperWidget != nullptr, NgosStatus::ASSERTION);

        mScrollWrapperWidget = new WrapperWidget(mContentWrapperWidget);
    }



    for (i64 i = mRows.getSize(); i < (i64)rows; ++i)
    {
        TableRowWidget *rowWidget = new TableRowWidget(mScrollWrapperWidget);

        if (i == (i64)mSelectedRow)
        {
            COMMON_ASSERT_EXECUTION(rowWidget->setState(isFocused() ? WidgetState::FOCUSED : WidgetState::INACTIVE), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(rowWidget->setPosition(0, i * mRowHeight),         NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(rowWidget->setSize(mTotalColumnWidth, mRowHeight), NgosStatus::ASSERTION);



        u64 positionX = 0;

        for (i64 j = 0; j < (i64)mColumnWidth.getSize(); ++j)
        {
            u64 columnWidth = mColumnWidth.at(j);



            TableCellWidget *cellWidget = new TableCellWidget(rowWidget);

            COMMON_ASSERT_EXECUTION(cellWidget->setPosition(positionX, 0),        NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(cellWidget->setSize(columnWidth, mRowHeight), NgosStatus::ASSERTION);

            COMMON_ASSERT_EXECUTION(rowWidget->addCell(cellWidget), NgosStatus::ASSERTION);



            positionX += columnWidth;
        }



        mRows.append(rowWidget);
    }



    for (i64 i = mRows.getSize(); i > (i64)rows; --i)
    {
        TableRowWidget *rowWidget = mRows.at(i - 1);

        mScrollWrapperWidget->getChildren().remove(rowWidget);



        COMMON_ASSERT_EXECUTION(mRows.setCapacity(i - 1), NgosStatus::ASSERTION);

        delete rowWidget;
    }



    if (rows > 0)
    {
        if (mSelectedRow >= rows)
        {
            mSelectedRow = rows - 1;

            COMMON_ASSERT_EXECUTION(mRows.at(mSelectedRow)->setState(isFocused() ? WidgetState::FOCUSED : WidgetState::INACTIVE), NgosStatus::ASSERTION);
        }

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setSize(mTotalColumnWidth, rows * mRowHeight), NgosStatus::ASSERTION);
    }
    else
    {
        mSelectedRow = 0;

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setSize(mTotalColumnWidth, 1), NgosStatus::ASSERTION);
    }



    if (mScrollWrapperWidget->getPositionY() < (i64)(mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight()))
    {
        i64 positionY = mContentWrapperWidget->getHeight() - mScrollWrapperWidget->getHeight();

        if (positionY > 0)
        {
            positionY = 0;
        }

        COMMON_ASSERT_EXECUTION(mScrollWrapperWidget->setPosition(0, positionY), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

u64 TableWidget::getRowCount() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mRows.getSize();
}

const ArrayList<TableRowWidget *>& TableWidget::getRows() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mRows;
}

NgosStatus TableWidget::setCellWidget(u64 row, u64 column, Widget *widget)
{
    COMMON_LT((" | row = %u, column = %u, widget = 0x%p", row, column, widget));

    COMMON_ASSERT(widget, "widget is null", NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(widget->getPositionX() == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(widget->getPositionY() == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(widget->getWidth()     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(widget->getHeight()    == 0, NgosStatus::ASSERTION);



    TableCellWidget *cell = mRows.at(row)->getCell(column);

    COMMON_ASSERT_EXECUTION(widget->setParent(cell),                                      NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(widget->setPosition(1, 1),                                    NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(widget->setSize(cell->getWidth() - 2, cell->getHeight() - 2), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

Widget* TableWidget::getCellWidget(u64 row, u64 column) const
{
    // COMMON_LT((" | row = %u, column = %u", row, column)); // Commented to avoid too frequent logs



    TableCellWidget *cell = mRows.at(row)->getCell(column);

    COMMON_TEST_ASSERT(cell->getChildren().getHead(), nullptr);



    return cell->getChildren().getHead()->getData();
}

NgosStatus TableWidget::setSelectedRow(u64 row)
{
    COMMON_LT((" | row = %u", row));



    if (mSelectedRow != row)
    {
        TableRowWidget *previousRow = mRows.at(mSelectedRow);
        TableRowWidget *newRow      = mRows.at(row);

        mSelectedRow = row;



        if (previousRow)
        {
            switch (previousRow->getState())
            {
                case WidgetState::FOCUSED:          COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::NORMAL),  NgosStatus::ASSERTION); break;
                case WidgetState::FOCUSED_HOVERED:  COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::HOVERED), NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE:         COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::NORMAL),  NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE_HOVERED: COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::HOVERED), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::NORMAL:
                case WidgetState::HOVERED:
                case WidgetState::PRESSED:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(previousRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(previousRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }



        if (newRow)
        {
            switch (newRow->getState())
            {
                case WidgetState::NORMAL:  COMMON_ASSERT_EXECUTION(newRow->setState(isFocused() ? WidgetState::FOCUSED         : WidgetState::INACTIVE),         NgosStatus::ASSERTION); break;
                case WidgetState::HOVERED: COMMON_ASSERT_EXECUTION(newRow->setState(isFocused() ? WidgetState::FOCUSED_HOVERED : WidgetState::INACTIVE_HOVERED), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::PRESSED:
                case WidgetState::FOCUSED:
                case WidgetState::FOCUSED_HOVERED:
                case WidgetState::INACTIVE:
                case WidgetState::INACTIVE_HOVERED:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(newRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(newRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }
    }



    return NgosStatus::OK;
}

u64 TableWidget::getSelectedRow() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mSelectedRow;
}

NgosStatus TableWidget::setHighlightedRow(u64 row)
{
    COMMON_LT((" | row = %u", row));



    if (mHighlightedRow != row)
    {
        TableRowWidget *previousRow = mHighlightedRow < mRows.getSize() ? mRows.at(mHighlightedRow) : nullptr;
        TableRowWidget *newRow      = row             < mRows.getSize() ? mRows.at(row)             : nullptr;

        mHighlightedRow = row;



        if (previousRow)
        {
            switch (previousRow->getState())
            {
                case WidgetState::HOVERED:          COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::NORMAL),   NgosStatus::ASSERTION); break;
                case WidgetState::FOCUSED_HOVERED:  COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::FOCUSED),  NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE_HOVERED: COMMON_ASSERT_EXECUTION(previousRow->setState(WidgetState::INACTIVE), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::NORMAL:
                case WidgetState::PRESSED:
                case WidgetState::FOCUSED:
                case WidgetState::INACTIVE:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(previousRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(previousRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }



        if (newRow)
        {
            switch (newRow->getState())
            {
                case WidgetState::NORMAL:   COMMON_ASSERT_EXECUTION(newRow->setState(WidgetState::HOVERED),          NgosStatus::ASSERTION); break;
                case WidgetState::FOCUSED:  COMMON_ASSERT_EXECUTION(newRow->setState(WidgetState::FOCUSED_HOVERED),  NgosStatus::ASSERTION); break;
                case WidgetState::INACTIVE: COMMON_ASSERT_EXECUTION(newRow->setState(WidgetState::INACTIVE_HOVERED), NgosStatus::ASSERTION); break;

                case WidgetState::NONE:
                case WidgetState::HOVERED:
                case WidgetState::PRESSED:
                case WidgetState::FOCUSED_HOVERED:
                case WidgetState::INACTIVE_HOVERED:
                {
                    COMMON_LF(("Unexpected widget state: %s, %s:%u", enumToFullString(newRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;

                default:
                {
                    COMMON_LF(("Unknown widget state: %s, %s:%u", enumToFullString(newRow->getState()), __FILE__, __LINE__));

                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                }
                break;
            }
        }
    }



    return NgosStatus::OK;
}

u64 TableWidget::getHighlightedRow() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mHighlightedRow;
}

NgosStatus TableWidget::setKeyboardEventHandler(keyboard_event_handler handler)
{
    COMMON_LT((" | handler = 0x%p", handler));



    mKeyboardEventHandler = handler;



    return NgosStatus::OK;
}

keyboard_event_handler TableWidget::getKeyboardEventHandler() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mKeyboardEventHandler;
}
