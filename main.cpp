#include "mainwindow.h"
#include <QApplication>
#include "status.h"
#include "navigation.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow mainwindow;
   mainwindow.show();

    return a.exec();
}
