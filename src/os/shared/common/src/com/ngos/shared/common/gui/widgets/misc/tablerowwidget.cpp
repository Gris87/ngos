#include "tablerowwidget.h"

#include <com/ngos/shared/common/graphics/graphics.h>
#include <com/ngos/shared/common/gui/other/defines.h>
#include <com/ngos/shared/common/gui/widgets/controls/tablewidget.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>



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
            case WidgetState::HOVERED:          color.value32 = HOVERED_COLOR;          break;
            case WidgetState::PRESSED:          color.value32 = PRESSED_COLOR;          break;
            case WidgetState::FOCUSED:          color.value32 = FOCUSED_COLOR;          break;
            case WidgetState::FOCUSED_HOVERED:  color.value32 = FOCUSED_HOVERED_COLOR;  break;
            case WidgetState::INACTIVE:         color.value32 = INACTIVE_COLOR;         break;
            case WidgetState::INACTIVE_HOVERED: color.value32 = INACTIVE_HOVERED_COLOR; break;

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

    for (bad_int64 i = 0; i < (bad_int64)rows.getSize(); ++i)
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
            mWidth > 0
            &&
            mHeight > 0
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

TableCellWidget* TableRowWidget::getCell(bad_uint64 column) const
{
    // COMMON_LT((" | column = %u", column)); // Commented to avoid too frequent logs



    return mCells.at(column);
}
