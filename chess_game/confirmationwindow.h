#ifndef CONFIRMATIONWINDOW_H
#define CONFIRMATIONWINDOW_H

#include <QDialog>

class GameWindow;

namespace Ui {
class ConfirmationWindow;
}

/**
 * @brief Enumeration representing the confirmation status for the ConfirmationWindow.
 */
enum ConfirmationStatus
{
    EMPTY,
    RESTART_GAME,
    EXIT_GAME,
    WHITE_WON,
    BLACK_WON,
    STALEMATE
};

/**
 * @brief Class representing a confirmation dialog window.
 */
class ConfirmationWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for ConfirmationWindow class.
     *
     * @param gameWindow A pointer to the GameWindow associated with this confirmation dialog.
     * @param givenGameStatus The confirmation status (e.g., EXIT_GAME, RESTART_GAME).
     * @param parent The parent widget.
     */
    explicit ConfirmationWindow(GameWindow *gameWindow, ConfirmationStatus givenGameStatus, QWidget *parent = nullptr);

    /**
     * @brief Destructor for ConfirmationWindow class.
     */
    ~ConfirmationWindow();

    /**
     * @brief Set the text message to display in the confirmation window.
     *
     * @return The text message to display.
     */
    QString setTextMessage();

private slots:
    /**
     * @brief Slot for the "Yes" button click event.
     */
    void on_pushButton_yes_clicked();

    /**
     * @brief Slot for the "No" button click event.
     */
    void on_pushButton_no_clicked();

private:
    Ui::ConfirmationWindow *ui;
    GameWindow* gameWindowStore; ///< Member variable to store the reference
    ConfirmationStatus gameStatus; ///< Status to check the game (one window for all things)
};

#endif // CONFIRMATIONWINDOW_H
