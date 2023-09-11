#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Main window of the chess game application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for MainWindow class.
     *
     * @param parent The parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow class.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot for the "Start Game" button click event.
     */
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    GameWindow *game_window;
};
#endif // MAINWINDOW_H
