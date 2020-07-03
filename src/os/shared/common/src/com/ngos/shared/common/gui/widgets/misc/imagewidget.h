#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_IMAGEWIDGET_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_IMAGEWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class ImageWidget: public Widget
{
public:
    ImageWidget(Image *image, Widget *parent = 0); // TEST: NO
    ImageWidget(Image *image, Image *resizedImage, Widget *parent = 0); // TEST: NO
    ~ImageWidget(); // TEST: NO

    NgosStatus invalidate() override; // TEST: NO
    NgosStatus repaint() override; // TEST: NO

    NgosStatus setImage(Image *image); // TEST: NO
    Image* getImage() const; // TEST: NO

    NgosStatus setResizedImage(Image *image); // TEST: NO

private:
    Image *mImage;
    bool   mPredefined;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_IMAGEWIDGET_H
