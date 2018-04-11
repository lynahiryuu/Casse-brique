#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QWidget>
#include <QOpenGLWidget>

class OpenGLView
{
public:
    OpenGLView();
    void Refresh();
private:
    QOpenGLWidget *widget;
};

#endif // OPENGLVIEW_H
