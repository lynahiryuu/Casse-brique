#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    height_ = ui->openGLWidget->maximumHeight();
    width_ = ui->openGLWidget->maximumWidth();
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
