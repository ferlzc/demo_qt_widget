#include <QtWidgets>
#include <QTimer>
#include <QDebug>
#include "status.h"
#include "ui_status.h"
#include <QFontDatabase>

status::status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::status)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this, SLOT(timer_out())
            );
    timer->start(1000);

    ui->headerLabel->setText("page 1");

    if (QFontDatabase::addApplicationFont(":/FontAwesome.otf") < 0)
        qWarning() << "FontAwesome cannot be loaded !";

    QFont font;
    font.setFamily("FontAweasome");
    font.setPixelSize(48);

}

status::~status()
{
    delete ui;
}

void status::timer_out()
{

    static bool toogle = true;
    qDebug() << "timer out!";

    if (toogle) {
    ui->statusAnimation->setStyleSheet("background-color: rgb(52, 101, 164)");
    }
    else {
    ui->statusAnimation->setStyleSheet("background-color: rgb(91, 150, 240)");
    }

    toogle = !toogle;
}
