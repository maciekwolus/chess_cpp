#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("Chess Game - Uni Project");
    MainWindow w;
    w.show();
    return a.exec();
}


