#ifndef TEASERVICE_H
#define TEASERVICE_H

#include <QObject>


class SceneObject;
class Teapot;
class Teacup;
class Teaspoon;
class PerPixelEffect;
class QGLMaterial;



class TeaService : public QObject {
    Q_OBJECT
public:
    TeaService(QObject *parent=0);
    ~TeaService();

    SceneObject *service;

    Teapot *teapot;
    Teacup *teacup1;
    Teacup *teacup2;
    Teaspoon *teaspoon1;
    Teaspoon *teaspoon2;
    PerPixelEffect *lighting;

    void changeMaterials(bool perPixel);

signals:
    void changed();

private slots:
    void teapotClicked();
    void teacup1Clicked();
    void teacup2Clicked();
    void teaspoon1Clicked();
    void teaspoon2Clicked();

private:
    QGLMaterial *china;
    QGLMaterial *chinaHighlight;
    QGLMaterial *metal;
    QGLMaterial *metalHighlight;
};

#endif // TEASERVICE_H
