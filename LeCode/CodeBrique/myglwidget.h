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

/*
* Classe héritée de QGLWidget permettant de créer l'interface graphique du jeu et d'interagir avec l'utilisateur.
*/

class MyGLWidget : public QGLWidget
{
    Q_OBJECT

public:

    //Constructeur
    MyGLWidget(QWidget * parent = nullptr);

    //Setters
    void setSpeedVector(Point p);

    // Méthode permettant de transformer un objet Point en un int. Le but est de récupérer la direction du vecteur enregistré par la caméra
    int speedToInt(Point p);

    //Getters
    Point getSpeedVector();
protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    // Fonction de gestion d'interactions clavier (Ne fonctionne pas avec lorsque la caméra est activée)
    void keyPressEvent(QKeyEvent * event);

    //Méthode appelant la méthode update() de la classe Model afin de mettre à jour les composants
    void updateModel();

private:
    // Timer d'animation
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer_;

    //Attribut contenant la vitesse du vecteur enregistré par la caméra
    Point speedVector_;

    //Pointeur permettant de créer un model dans la fenêtre
    Model* model_;
};

#endif // MYGLWIDGET_H
