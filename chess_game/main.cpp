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
- frontend - make buttons work!!

- backend - make move for every piece
- backend - think if i should delete squre or not
*/
