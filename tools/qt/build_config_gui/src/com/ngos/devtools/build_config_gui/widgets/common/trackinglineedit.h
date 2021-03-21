#ifndef COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGLINEEDIT_H
#define COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGLINEEDIT_H



#include <QLineEdit>



class TrackingLineEdit: public QLineEdit
{
    Q_OBJECT

public:
    explicit TrackingLineEdit(const QString &contents, QWidget *parent = nullptr); // TEST: NO

protected:
    void focusInEvent(QFocusEvent *event) override; // TEST: NO
    void focusOutEvent(QFocusEvent *event) override; // TEST: NO

signals:
    void entered(); // TEST: NO
    void leaved(); // TEST: NO
};



#endif // COM_NGOS_DEVTOOLS_BUILD_CONFIG_GUI_WIDGETS_COMMON_TRACKINGLINEEDIT_H
