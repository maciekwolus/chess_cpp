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


/*
LIST OF THINGS TO DO (for now)
- frontend - make deleting objects
- frontend - make better code, add functions

- backend - make move for every piece
*/
