#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QDialog>

namespace Ui {
class MainPage; // Forward declaration of MainPage inside Ui namespace
}

class MainPage : public QDialog
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private:
    Ui::MainPage *ui; // Corrected type for the UI object pointer
};

#endif // MAINPAGE_H
