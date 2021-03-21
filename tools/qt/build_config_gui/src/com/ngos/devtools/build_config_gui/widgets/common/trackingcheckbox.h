#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGCHECKBOX_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGCHECKBOX_H



#include <QCheckBox>



class TrackingCheckBox: public QCheckBox
{
    Q_OBJECT

public:
    explicit TrackingCheckBox(const QString &text, QWidget *parent = nullptr); // TEST: NO

protected:
    void focusInEvent(QFocusEvent *event) override; // TEST: NO
    void focusOutEvent(QFocusEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGCHECKBOX_H
