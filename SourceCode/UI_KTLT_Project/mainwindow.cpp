#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->passwordLabel->setEchoMode(QLineEdit::Password);

    lineEdits.append(ui->usernameLabel);
    lineEdits.append(ui->passwordLabel);
    for (auto lineEdit : lineEdits) {
        lineEdit->installEventFilter(this);
    }
    connect(ui->passwordLabel, &QLineEdit::returnPressed, this, &MainWindow::on_pushButton_Login_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString UserName = ui->usernameLabel->text();
    QString PassWord = ui->passwordLabel->text();
    if (UserName == "dbtien" && PassWord == "fithcmus") {
        QMessageBox::information(this, "hello", "Log in successfully!");
    }
    else {
        QMessageBox::information(this, "hello", "Your Username or Password is incorrect!");
    }
}

void MainWindow::on_pushButton_Cancel_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "hello", "Are you sure to close the application?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            // Tìm và di chuyển tới ô nhập tiếp theo
            int currentIndex = lineEdits.indexOf(static_cast<QLineEdit*>(obj));
            if (currentIndex != -1 && currentIndex < lineEdits.size() - 1) {
                lineEdits[currentIndex + 1]->setFocus();
                return true; // Ngăn chặn sự kiện phát tán
            }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

