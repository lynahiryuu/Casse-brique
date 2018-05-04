#include "mainwindow.h"
#include "myglwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Creation de l'application QT
    QApplication a(argc, argv);

    MyGLWidget glWidget;
    glWidget.show();

    return a.exec();
}
