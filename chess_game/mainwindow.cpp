#include "mainwindow.h"
#include "./ui_mainwindow.h"

/**
 * @brief Constructor for MainWindow class.
 *
 * @param parent The parent widget.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief Destructor for MainWindow class.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Slot for the "Start Game" button click event.
 */
void MainWindow::on_pushButton_clicked()
{
    hide();
    game_window = new GameWindow(this);
    game_window->show();
}
