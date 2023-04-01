#ifndef TEST_WINDOW_H
#define TEST_WINDOW_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class test_window; }
QT_END_NAMESPACE

class test_window : public QMainWindow
{
    Q_OBJECT

public:
    test_window(QWidget *parent = nullptr);
    ~test_window();

private:
    Ui::test_window *ui;
};
#endif // TEST_WINDOW_H
