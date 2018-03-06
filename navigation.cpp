#include "navigation.h"
#include "ui_navigation.h"
#include <QStackedWidget>
#include <QLabel>
#include <QDebug>
#include <QFontDatabase>

navigation::navigation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::navigation)
{
    ui->setupUi(this);

    if (QFontDatabase::addApplicationFont(":/FontAwesome.otf") < 0)
        qWarning() << "FontAwesome cannot be loaded !";

    QFont font;
    font.setFamily("FontAweasome");
    font.setPixelSize(86);

    ui->nav1->setFont(font);
    ui->nav1->setText("\uf080");

    ui->nav2->setFont(font);
    ui->nav2->setText("\uf0ad");

}

navigation::~navigation()
{
    delete ui;
}

void navigation::on_nav1_clicked()
{
    QStackedWidget *stack = parentWidget()->findChild<QStackedWidget *>("mainStack");
    QLabel *label = parentWidget()->findChild<QLabel*>("headerLabel");
    stack->setCurrentIndex(0);
   label->setText("page 1");
    qDebug() << "page 1";
}

void navigation::on_nav2_clicked()
{
    QStackedWidget *stack = parentWidget()->findChild<QStackedWidget *>("mainStack");
    QLabel *label = parentWidget()->findChild<QLabel*>("headerLabel");
    stack->setCurrentIndex(1);
    label->setText("page 2");
    qDebug() << "page 2";
}
