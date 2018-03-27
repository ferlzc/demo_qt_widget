#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QWidget>

namespace Ui {
class navigation;
}

class navigation : public QWidget
{
    Q_OBJECT

public:
    explicit navigation(QWidget *parent = 0);
    ~navigation();

private slots:

    void on_chart_clicked();

    void on_dial_menu_clicked();

    void on_config_clicked();

private:
    Ui::navigation *ui;
};

#endif // NAVIGATION_H
