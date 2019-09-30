#ifndef OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_IMAGEWIDGET_H
#define OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_IMAGEWIDGET_H



#include <common/src/bits64/gui/widgets/widget.h>



class ImageWidget: public Widget
{
public:
    ImageWidget(Image *image, Widget *parent = 0); // TEST: NO
    ~ImageWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    Image* getImage() const; // TEST: NO

private:
    Image *mImage;
    Image *mResizedImage;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GUI_WIDGETS_MISC_IMAGEWIDGET_H
