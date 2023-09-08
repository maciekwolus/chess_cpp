#include "confirmationwindow.h"
#include "ui_confirmationwindow.h"
#include "gamewindow.h"

ConfirmationWindow::ConfirmationWindow(GameWindow *gameWindow, ConfirmationStatus givenGameStatus, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationWindow)
{
    gameWindowStore = gameWindow;
    ui->setupUi(this);
    gameStatus = givenGameStatus;
    ui->massege_label->setText(setTextMassege());
}

ConfirmationWindow::~ConfirmationWindow()
{
    delete ui;
}

// When button 'yes' clicked
void ConfirmationWindow::on_pushButton_yes_clicked()
{
    // if exit game is true then whole app is closed
    if (gameStatus == EXIT_GAME)
    {
       QCoreApplication::quit();
    }

    // else if the confirmation windows close and the game window shows again
    else
    {
        gameWindowStore->close();
        gameWindowStore = NULL;
        gameWindowStore = new GameWindow(this);
        gameWindowStore->show();
        hide();
    }

    // back to default
    gameStatus = EMPTY;
}

// When button 'no' clicked it comes back to the game
void ConfirmationWindow::on_pushButton_no_clicked()
{
    // Restarting or exiting
    if (gameStatus == EXIT_GAME || gameStatus == RESTART_GAME)
    {
        gameWindowStore->show();
        hide();
        gameStatus = EMPTY;
    }
    // Game ended and no one want to restart
    else
    {
        QCoreApplication::quit();
    }
}

// Set text massege
QString ConfirmationWindow::setTextMassege()
{
    if (gameStatus == EXIT_GAME)
    {
       return "Are you sure you want to exit?";
    }
    else if (gameStatus == RESTART_GAME)
    {
       return "Are you sure you want to restart?";
    }
    else if (gameStatus == WHITE_WON)
    {
        return "Congratulations! White won! Do you want to restart the game?";
    }
    else if (gameStatus == BLACK_WON)
    {
       return "Congratulations! Black won! Do you want to restart the game?";
    }
    else if (gameStatus == STALEMATE)
    {
       return "Stalemate! Do you want to restart the game?";
    }
    return "noting";
}
