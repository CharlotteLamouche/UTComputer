#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QCoreApplication::setOrganizationName("Charlotte&Sam");
    QCoreApplication::setApplicationName("UTComputer");
    w.setWindowTitle("UTComputer");
    w.show();
    return a.exec();
}

