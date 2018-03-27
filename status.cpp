#include <QtWidgets>
#include <QTimer>
#include <QDebug>
#include "status.h"
#include "ui_status.h"
#include <QFontDatabase>
#include <QTime>

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

    ui->headerLabel->setText("Chart");

    QFont fontSolid;

    fontSolid.setFamily("FontAweasomeSolid");
    fontSolid.setPixelSize(23);

    ui->label->setFont(fontSolid);
    ui->label->setText("\uf105");

    ui->time->setText(QDateTime::currentDateTime().toString("hh:mm:ss dd.MM.yyyy"));
}

status::~status()
{
    delete ui;
}


void status::timer_out()
{
    static bool toggle = true;
    ui->time->setText(QDateTime::currentDateTime().toString("hh:mm:ss dd.MM.yyyy"));
    if (toggle) {
        ui->label->setText("\uf105");
    }
    else {
        ui->label->setText("\uf101");
    }
    toggle = !toggle;
}
