#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getWidth();
    int getHeight();

private:
    Ui::MainWindow *ui;
    int height_;
    int width_;
};

#endif // MAINWINDOW_H
