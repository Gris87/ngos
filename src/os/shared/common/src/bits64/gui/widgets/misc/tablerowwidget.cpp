#include "tablerowwidget.h"

#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/gui/widgets/controls/tablewidget.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



TableRowWidget::TableRowWidget(Widget *parent)
    : Widget(parent)
    , mCells()
    , mState(WidgetState::NORMAL)
{
    COMMON_LT((" | parent = 0x%p", parent));

    COMMON_ASSERT(parent, "parent is null");
}

TableRowWidget::~TableRowWidget()
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

NgosStatus TableRowWidget::invalidate()
{
    COMMON_LT((""));



    if (mOwnResultImage)
    {
        delete mOwnResultImage;
    }

    mOwnResultImage = new Image(mWidth, mHeight, true, false);



    if (mState == WidgetState::NORMAL)
    {
        COMMON_ASSERT_EXECUTION(mOwnResultImage->clearBuffer(), NgosStatus::ASSERTION);
    }
    else
    {
        RgbaPixel color;

        switch (mState)
        {
            case WidgetState::HOVERED:          color.red = 0x90; color.green = 0x90; color.blue = 0x90; color.alpha = 0xDD; break;
            case WidgetState::PRESSED:          color.red = 0x60; color.green = 0x60; color.blue = 0x60; color.alpha = 0xDD; break;
            case WidgetState::FOCUSED:          color.red = 0x40; color.green = 0x60; color.blue = 0x90; color.alpha = 0xDD; break;
            case WidgetState::FOCUSED_HOVERED:  color.red = 0x30; color.green = 0x40; color.blue = 0x60; color.alpha = 0xDD; break;
            case WidgetState::INACTIVE:         color.red = 0xC0; color.green = 0xC0; color.blue = 0xC0; color.alpha = 0xDD; break;
            case WidgetState::INACTIVE_HOVERED: color.red = 0xE0; color.green = 0xE0; color.blue = 0xE0; color.alpha = 0xDD; break;

            case WidgetState::NONE:
            case WidgetState::NORMAL:
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

        COMMON_ASSERT_EXECUTION(mOwnResultImage->fill(color), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus TableRowWidget::repaint()
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

bool TableRowWidget::isAcceptMouseEvents()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return true;
}

Widget* TableRowWidget::getOwnerWidget()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    COMMON_TEST_ASSERT(getParent(),                           nullptr);
    COMMON_TEST_ASSERT(getParent()->getParent(),              nullptr);
    COMMON_TEST_ASSERT(getParent()->getParent()->getParent(), nullptr);

    Widget *widget = getParent()->getParent()->getParent();

    do
    {
        COMMON_TEST_ASSERT(widget, nullptr);

        if (widget->isFocusable())
        {
            break;
        }

        widget = widget->getParent();
    } while(true);

    TableWidget *tableWidget = (TableWidget *)widget;



    const ArrayList<TableRowWidget *> &rows = tableWidget->getRows();

    for (i64 i = 0; i < (i64)rows.getSize(); ++i)
    {
        if (rows.at(i) == this)
        {
            COMMON_ASSERT_EXECUTION(tableWidget->setHighlightedRow(i), nullptr);

            break;
        }
    }



    return tableWidget;
}

NgosStatus TableRowWidget::setState(WidgetState state)
{
    COMMON_LT((" | state = %u", state));



    if (mState != state)
    {
        mState = state;

        if (
            mWidth // mWidth > 0
            &&
            mHeight // mHeight > 0
           )
        {
            COMMON_ASSERT_EXECUTION(invalidate(), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(repaint(),    NgosStatus::ASSERTION);

            if (isVisible())
            {
                COMMON_ASSERT_EXECUTION(update(), NgosStatus::ASSERTION);
            }
        }
    }



    return NgosStatus::OK;
}

WidgetState TableRowWidget::getState() const
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return mState;
}

NgosStatus TableRowWidget::addCell(TableCellWidget *cell)
{
    COMMON_LT((" | cell = 0x%p", cell));

    COMMON_ASSERT(cell, "cell is null", NgosStatus::ASSERTION);



    return mCells.append(cell);
}

TableCellWidget* TableRowWidget::getCell(u64 column) const
{
    // COMMON_LT((" | column = %u", column)); // Commented to avoid too frequent logs



    return mCells.at(column);
}
