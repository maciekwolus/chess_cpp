#include "test_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test_window w;
    w.show();
    return a.exec();
}
