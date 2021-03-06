#ifndef COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_IMAGEWIDGET_H
#define COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_IMAGEWIDGET_H



#include <com/ngos/shared/common/gui/widgets/widget.h>



class ImageWidget: public Widget
{
public:
    ImageWidget(Image *image, Widget *parent = nullptr); // TEST: NO
    ImageWidget(Image *image, Image *resizedImage, Widget *parent = nullptr); // TEST: NO
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



#endif // COM_NGOS_SHARED_COMMON_GUI_WIDGETS_MISC_IMAGEWIDGET_H
