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

    if (QFontDatabase::addApplicationFont(":/FontAwesomeSolid.otf") < 0)
        qWarning() << "FontAwesome cannot be loaded !";

    QFont font;
    font.setFamily("FontAweasomeSolid");
    font.setPixelSize(70);

    ui->chart->setFocusPolicy(Qt::NoFocus);
    ui->config->setFocusPolicy(Qt::NoFocus);
    ui->dial_menu->setFocusPolicy(Qt::NoFocus);

    ui->chart->setFont(font);
    ui->chart->setText("\uf080");

    ui->dial_menu->setFont(font);
    ui->dial_menu->setText("\uf3fd");

    ui->config->setFont(font);
    ui->config->setText("\uf0ad");

}

navigation::~navigation()
{
    delete ui;
}

void navigation::on_chart_clicked()
{
    QStackedWidget *stack = parentWidget()->findChild<QStackedWidget *>("mainStack");
    QLabel *label = parentWidget()->findChild<QLabel*>("headerLabel");
    stack->setCurrentIndex(0);
    label->setText("Chart");
}

void navigation::on_config_clicked()
{
    QStackedWidget *stack = parentWidget()->findChild<QStackedWidget *>("mainStack");
    QLabel *label = parentWidget()->findChild<QLabel*>("headerLabel");
    stack->setCurrentIndex(1);
    label->setText("Config");
}

void navigation::on_dial_menu_clicked()
{
    QStackedWidget *stack = parentWidget()->findChild<QStackedWidget *>("mainStack");
    QLabel *label = parentWidget()->findChild<QLabel*>("headerLabel");
    stack->setCurrentIndex(2);
    label->setText("Controls");
}
