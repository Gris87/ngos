#ifndef BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGGROUPBOX_H
#define BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGGROUPBOX_H



#include <QGroupBox>



class TrackingGroupBox: public QGroupBox
{
    Q_OBJECT

public:
    explicit TrackingGroupBox(const QString &title, QWidget *parent = 0); // TEST: NO

protected:
    void enterEvent(QEvent *event) override; // TEST: NO
    void leaveEvent(QEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // BUILD_CONFIG_GUI_SRC_COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGGROUPBOX_H
