#include <QtCharts/QSplineSeries>
#include <QtCharts/QChartView>
#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QFontDatabase>
#include <QNetworkInterface>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chart.h"
#include <sys/sysinfo.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QChart *chart = new Chart;
    chart->legend()->hide();
    chart->createDefaultAxes();
    chart->axisY()->setRange(0,100);
    chart->setTheme(QChart::ChartThemeDark);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartLayout->addWidget(chartView);

    QFont font;
    font.setFamily("FontAweasomeSolid");
    font.setPixelSize(70);

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this, SLOT(timer_out())
            );

    timer->start(1000);
    ui->ramUsage->setValue(0);

    ui->mainStack->setCurrentIndex(0);

    ui->dial_config->setFocusPolicy(Qt::NoFocus);

    ui->led->setFocusPolicy(Qt::NoFocus);
    ui->led->setFont(font);
    ui->led->setText("\uf204");

    network_find();

    /*GPIO Test */

    QFile file("/sys/class/gpio/gpio59/value");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&file);
    out << "0";
}

void MainWindow::network_find()
{
    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
        {
            qDebug() << address.toString();
            ui->IP->setText(address.toString());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timer_out()
{
    network_find();

    const double megabyte = 1024 * 1024;
    struct sysinfo si;
    sysinfo(&si);
    unsigned long totalram = si.totalram / megabyte;
    unsigned long freeram = si.freeram /megabyte ;
    unsigned long used =  totalram - freeram;
    int fraction = 100*((float)used / (float)totalram);

    ui->ramUsage->setValue(fraction);

    qDebug() << "freeram:" << freeram;
    qDebug() << "totalram:" << totalram;
    qDebug() << "used:" << used;
    qDebug() << "percentage:" << fraction ;

}

void MainWindow::on_led_clicked()
{
    static bool toggle = true;

    /*GPIO Test */
    QFile file("/sys/class/gpio/gpio59/value");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream out(&file);

    if (toggle) {
        out << "1";
        ui->led->setText("\uf205");
    }
    else {
        out << "0";
        ui->led->setText("\uf204");
    }

    file.close();
    toggle = !toggle;
}
