#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_CONSOLEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_CONSOLEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class ConsoleWidget: public Widget
{
public:
    ConsoleWidget(Image *image, Widget *parent = 0); // TEST: NO
    ~ConsoleWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    Image* getResizedImage() const; // TEST: NO

private:
    Image *mImage;
    Image *mResizedImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_CONSOLEWIDGET_H
