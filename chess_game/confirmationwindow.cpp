#include "confirmationwindow.h"
#include "ui_confirmationwindow.h"
#include "gamewindow.h"

/**
 * @brief Constructor for ConfirmationWindow class.
 *
 * @param gameWindow A pointer to the GameWindow associated with this confirmation dialog.
 * @param givenGameStatus The confirmation status (e.g., EXIT_GAME, RESTART_GAME).
 * @param parent The parent widget.
 */
ConfirmationWindow::ConfirmationWindow(GameWindow *gameWindow, ConfirmationStatus givenGameStatus, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmationWindow)
{
    gameWindowStore = gameWindow;
    ui->setupUi(this);
    gameStatus = givenGameStatus;
    ui->massege_label->setText(setTextMessage());
}

/**
 * @brief Destructor for ConfirmationWindow class.
 */
ConfirmationWindow::~ConfirmationWindow()
{
    delete ui;
}

/**
 * @brief Slot for the "Yes" button click event.
 */
void ConfirmationWindow::on_pushButton_yes_clicked()
{
    // if exit game is true then the whole app is closed
    if (gameStatus == EXIT_GAME)
    {
       QCoreApplication::quit();
    }
    // else if the confirmation window closes and the game window shows again
    else
    {
        gameWindowStore->close();
        gameWindowStore = nullptr;
        gameWindowStore = new GameWindow(this);
        gameWindowStore->show();
        hide();
    }
    // Reset to default
    gameStatus = EMPTY;
}

/**
 * @brief Slot for the "No" button click event.
 */
void ConfirmationWindow::on_pushButton_no_clicked()
{
    // Restarting or exiting
    if (gameStatus == EXIT_GAME || gameStatus == RESTART_GAME)
    {
        gameWindowStore->show();
        hide();
        gameStatus = EMPTY;
    }
    // Game ended and no one wants to restart
    else
    {
        QCoreApplication::quit();
    }
}

/**
 * @brief Set the text message to display in the confirmation window.
 *
 * @return The text message to display.
 */
QString ConfirmationWindow::setTextMessage()
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
    return "nothing";
}
