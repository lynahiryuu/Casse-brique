#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H
#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <GL/glu.h>
#include "model.h"
#include <cstdio>

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    MyGLWidget(QWidget * parent = nullptr);
    void setSpeedVector(Point p);
    int speedToInt(Point p);
    Point getSpeedVector();
protected:
    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier
    void keyPressEvent(QKeyEvent * event);

    void updateModel(const float timeInDays);

private:
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer_;
    Point speedVector_;
    Model* model_;
};

#endif // MYGLWIDGET_H
