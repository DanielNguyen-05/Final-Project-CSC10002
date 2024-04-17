#include "mainpage.h"
#include "ui_mainpage.h" // Include the generated UI header file

MainPage::MainPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainPage) // Initialize ui pointer
{
    ui->setupUi(this); // Call setupUi() using the ui pointer
}

MainPage::~MainPage()
{
    delete ui;
}
