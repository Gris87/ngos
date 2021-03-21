#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGGROUPBOX_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGGROUPBOX_H



#include <QGroupBox>



class TrackingGroupBox: public QGroupBox
{
    Q_OBJECT

public:
    explicit TrackingGroupBox(const QString &title, QWidget *parent = nullptr); // TEST: NO

protected:
    void focusInEvent(QFocusEvent *event) override; // TEST: NO
    void focusOutEvent(QFocusEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGGROUPBOX_H
