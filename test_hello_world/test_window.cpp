#include "test_window.h"
#include "./ui_test_window.h"

test_window::test_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::test_window)
{
    ui->setupUi(this);
}

test_window::~test_window()
{
    delete ui;
}

