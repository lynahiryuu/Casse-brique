#include "myglwidget.h"
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>

using namespace std;

// Declarations des constantes
const unsigned int WIN_WIDTH  = 15;
const unsigned int WIN_HEIGHT = 6;
const float MAX_DIMENSION     = 15.0f;


MyGLWidget::MyGLWidget(QWidget * parent) : QGLWidget(parent)
{
    // Connexion du timer
    connect(&m_AnimationTimer_,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f / 12.0f;
        //updateModel(m_TimeElapsed);
        updateGL();
    });

    m_AnimationTimer_.setInterval(10);
    m_AnimationTimer_.start();

//    setFixedSize(WIN_WIDTH,WIN_HEIGHT);
    move(QApplication::desktop()->screen()->rect().center()-rect().center());
    model_=new Model();

}

void MyGLWidget::updateModel(const float timeInDays){
    model_->update(timeInDays);
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
//         glOrtho(-MAX_DIMENSION, MAX_DIMENSION,-6.0,6.0,0.0,10.0);
        glOrtho(-MAX_DIMENSION, MAX_DIMENSION, -MAX_DIMENSION * height / static_cast<float>(width), MAX_DIMENSION * height / static_cast<float>(width), -MAX_DIMENSION * 2.0f, MAX_DIMENSION * 2.0f);
//        glOrtho(0.0,30.0,0.0,30.0,-5.0,5.0);

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
    //cout<<"on est dans paint"<<endl;
    updateModel(m_TimeElapsed);
    //model_->Display();
}


// Fonction de gestion d'interactions clavier
void MyGLWidget::keyPressEvent(QKeyEvent * event)
{
    switch(event->key())
    {

        case Qt::Key_Left:
        {
            model_->setDirectionPaddle(1);
            break;
        }

        case Qt::Key_Right:
        {
            model_->setDirectionPaddle(-1);
            break;
        }

        // Activation/Arret de l'animation
        case Qt::Key_Space:
        {
            if(m_AnimationTimer_.isActive())
                m_AnimationTimer_.stop();
            else
                m_AnimationTimer_.start();

            break;
        }

    case Qt::Key_Up:
    {
        model_->setDirectionPaddle(0);
        break;
    }

        // Cas par defaut
        default:
        {
            // Ignorer l'evenement
            event->ignore();
            return;
        }
    }

    // Acceptation de l'evenement et mise a jour de la scene
    event->accept();
    updateGL();
}

void MyGLWidget::setSpeedVector(Point p){
    speedVector_=p;
}
