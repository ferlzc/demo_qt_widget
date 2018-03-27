#ifndef STATUS_H
#define STATUS_H

#include <QWidget>

namespace Ui {
class status;
}

class status : public QWidget
{
    Q_OBJECT

public:
    explicit status(QWidget *parent = 0);
    ~status();

private slots:
    void timer_out();

private:
    Ui::status *ui;
};


#endif // STATUS_H
