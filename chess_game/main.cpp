#include "mainwindow.h"

#include <QApplication>

/**
 * @brief The entry point of the application.
 *
 * This function initializes the QApplication, sets the application display name,
 * creates the MainWindow, and shows it.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 * @return The exit status of the application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("Chess Game - Uni Project");
    MainWindow w;
    w.show();
    return a.exec();
}
