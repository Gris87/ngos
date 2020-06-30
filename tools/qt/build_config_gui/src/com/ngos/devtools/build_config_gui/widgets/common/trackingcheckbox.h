#ifndef BUILD_CONFIG_GUI_SRC_WIDGETS_COMMON_TRACKINGCHECKBOX_H
#define BUILD_CONFIG_GUI_SRC_WIDGETS_COMMON_TRACKINGCHECKBOX_H



#include <QCheckBox>



class TrackingCheckBox: public QCheckBox
{
    Q_OBJECT

public:
    explicit TrackingCheckBox(const QString &text, QWidget *parent = 0); // TEST: NO

protected:
    void enterEvent(QEvent *event) override; // TEST: NO
    void leaveEvent(QEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // BUILD_CONFIG_GUI_SRC_WIDGETS_COMMON_TRACKINGCHECKBOX_H
