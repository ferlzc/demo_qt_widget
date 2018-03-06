#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts/QSplineSeries>
#include <QtCharts/QChartView>
#include <QWidget>

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QSplineSeries* series = new QSplineSeries();
    series ->append(0,6);
    series ->append(1,3);
    series ->append(2,4);
    series ->append(3,8);

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("gráfico simples");
    chart->createDefaultAxes();
    chart->axisY()->setRange(0,10);
    chart->setTheme(QChart::ChartThemeDark);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->chartLayout->addWidget(chartView);

}

MainWindow::~MainWindow()
{
    delete ui;
}
