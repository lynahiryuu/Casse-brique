#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>

using namespace std;

// Declarations des constantes
const unsigned int WIN_WIDTH  = 30;
const unsigned int WIN_HEIGHT = 12;
const float MAX_DIMENSION     = 15.0f;


MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
//    setFixedSize(WIN_WIDTH,WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center()-rect().center());
    model_=new Model();

}

// Fonction d'initialisation
void MyGLWidget::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.1f, 0.6f, 0.4f, 0.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat blanc[]={1,1,1};
    glLightfv(GL_LIGHT0,GL_AMBIENT,blanc);


    //Activation des textures
    glEnable(GL_TEXTURE_2D);
}


// Fonction de redimensionnement
void MyGLWidget::resizeGL(int width, int height)
{
    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);
       // glOrtho(0.0,30.0,0.0,30.0,-5.0,5.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

// Fonction d'affichage
void MyGLWidget::paintGL()
{
    glClearColor(0.8f, 0.6f, 0.4f, 0.0f);
    glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    // Definition de la position de la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // Placement de la caméra
    gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,-1.0,0.0);
    model_->Display();
}
