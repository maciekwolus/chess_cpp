#ifndef CONFIRMATIONWINDOW_H
#define CONFIRMATIONWINDOW_H

#include <QDialog>

class GameWindow;

namespace Ui {
class ConfirmationWindow;
}

enum ConfirmationStatus
{
    EMPTY,
    RESTART_GAME,
    EXIT_GAME,
    WHITE_WON,
    BLACK_WON,
    STALEMATE
};

class ConfirmationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmationWindow(GameWindow *gameWindow, ConfirmationStatus givenGameStatus, QWidget *parent = nullptr);
    ~ConfirmationWindow();

    QString setTextMassege(); // void to give massege that you want to show

private slots:
    void on_pushButton_yes_clicked(); // when 'yes' button clicked
    void on_pushButton_no_clicked(); // when 'no' button clicked

private:
    Ui::ConfirmationWindow *ui;
    GameWindow* gameWindowStore; // Member variable to store the reference
    ConfirmationStatus gameStatus; // Status to check the game (one window to all things)
};

#endif // CONFIRMATIONWINDOW_H
