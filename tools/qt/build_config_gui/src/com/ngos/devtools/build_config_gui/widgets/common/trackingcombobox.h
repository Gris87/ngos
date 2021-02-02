#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGCOMBOBOX_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGCOMBOBOX_H



#include <QComboBox>



class TrackingComboBox: public QComboBox
{
    Q_OBJECT

public:
    explicit TrackingComboBox(QWidget *parent = 0); // TEST: NO

protected:
    void focusInEvent(QFocusEvent *event) override; // TEST: NO
    void focusOutEvent(QFocusEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGCOMBOBOX_H
