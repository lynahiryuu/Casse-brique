#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    height_ = ui->GameWindow->maximumHeight();
    width_ = ui->GameWindow->maximumWidth();
}


MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getWidth(){
    return width_;
}

int MainWindow::getHeight(){
    return height_;
}
