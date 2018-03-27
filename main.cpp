#include "mainwindow.h"
#include <QApplication>
#include "status.h"
#include "navigation.h"
#include <QFontDatabase>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow mainwindow;

   QFontDatabase::addApplicationFont(":Ubuntu-R.ttf");
   QFont font;
   font.setFamily("Ubuntu-R");

   mainwindow.show();
   mainwindow.setFont(font);

   return a.exec();
}
