#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_COMMON_TRACKINGCOMBOBOX_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_COMMON_TRACKINGCOMBOBOX_H



#include <QComboBox>



class TrackingComboBox : public QComboBox
{
    Q_OBJECT

public:
    explicit TrackingComboBox(QWidget *parent = 0); // TEST: NO

protected:
    void enterEvent(QEvent *event) override; // TEST: NO
    void leaveEvent(QEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_COMMON_TRACKINGCOMBOBOX_H
