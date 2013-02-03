#include "TeaService.h"
#include <qglmaterial.h>
#include "sceneobject.h"
#include "Teapot.h"
#include "Teacup.h"
#include "Teaspoon.h"
#include "perpixeleffect.h"



enum {
    ObjTeapot,
    ObjTeacup1,
    ObjTeacup2,
    ObjTeaspoon1,
    ObjTeaspoon2
};



TeaService::TeaService(QObject *parent)
    : QObject(parent)
{
    china = new QGLMaterial(this);
    china->setAmbientColor(QColor(192, 150, 128));
    china->setSpecularColor(QColor(60, 60, 60));
    china->setShininess(128);

    chinaHighlight = new QGLMaterial(this);
    chinaHighlight->setAmbientColor(QColor(255, 192, 0));
    chinaHighlight->setSpecularColor(QColor(60, 60, 0));
    chinaHighlight->setShininess(128);

    metal = new QGLMaterial(this);
    metal->setAmbientColor(QColor(255, 255, 255));
    metal->setDiffuseColor(QColor(150, 150, 150));
    metal->setSpecularColor(QColor(255, 255, 255));
    metal->setShininess(128);

    metalHighlight = new QGLMaterial(this);
    metalHighlight->setAmbientColor(QColor(255, 255, 96));
    metalHighlight->setDiffuseColor(QColor(150, 150, 96));
    metalHighlight->setSpecularColor(QColor(255, 255, 255));
    metalHighlight->setShininess(128);

    service = new SceneObject(this);
    teapot = new Teapot(service);
    teacup1 = new Teacup(service);
    teacup2 = new Teacup(service);
    teacup1->setPosition(QVector3D(-2.3f, -0.75f, 0.0f));
    teacup2->setRotationAngle(180);
    teacup2->setRotationVector(QVector3D(0, 1, 0));
    teacup2->setPosition(QVector3D(2.3f, -0.75f, 0.0f));
    teaspoon1 = new Teaspoon(service);
    teaspoon2 = new Teaspoon(service);
    teaspoon1->setRotationAngle(275);
    teaspoon1->setRotationVector(QVector3D(1, 0, 0));
    teaspoon1->setPosition(QVector3D(-1.7f, -0.58f, 0.0f));
    teaspoon2->setRotationAngle(275);
    teaspoon2->setRotationVector(QVector3D(1, 0, 0));
    teaspoon2->setPosition(QVector3D(1.7f, -0.58f, 0.0f));

    teapot->setObjectId(ObjTeapot);
    teacup1->setObjectId(ObjTeacup1);
    teacup2->setObjectId(ObjTeacup2);
    teaspoon1->setObjectId(ObjTeaspoon1);
    teaspoon2->setObjectId(ObjTeaspoon2);

    lighting = new PerPixelEffect();
    changeMaterials(false);

    connect(teapot, SIGNAL(hoverChanged()), this, SIGNAL(changed()));
    connect(teacup1, SIGNAL(hoverChanged()), this, SIGNAL(changed()));
    connect(teacup2, SIGNAL(hoverChanged()), this, SIGNAL(changed()));
    connect(teaspoon1, SIGNAL(hoverChanged()), this, SIGNAL(changed()));
    connect(teaspoon2, SIGNAL(hoverChanged()), this, SIGNAL(changed()));

    connect(teapot, SIGNAL(clicked()), this, SLOT(teapotClicked()));
    connect(teacup1, SIGNAL(clicked()), this, SLOT(teacup1Clicked()));
    connect(teacup2, SIGNAL(clicked()), this, SLOT(teacup2Clicked()));
    connect(teaspoon1, SIGNAL(clicked()), this, SLOT(teaspoon1Clicked()));
    connect(teaspoon2, SIGNAL(clicked()), this, SLOT(teaspoon2Clicked()));
}

TeaService::~TeaService()
{
    delete lighting;
}

void TeaService::changeMaterials(bool perPixel)
{
    teapot->setMaterial(china);
    teapot->setHoverMaterial(chinaHighlight);
    teacup1->setMaterial(china);
    teacup1->setHoverMaterial(chinaHighlight);
    teacup2->setMaterial(china);
    teacup2->setHoverMaterial(chinaHighlight);
    if (perPixel) {
        teapot->setEffect(lighting);
        teacup1->setEffect(lighting);
        teacup2->setEffect(lighting);
    } else
    {
        teapot->setEffect(0);
        teacup1->setEffect(0);
        teacup2->setEffect(0);
    }

    teaspoon1->setMaterial(metal);
    teaspoon1->setHoverMaterial(metalHighlight);
    teaspoon2->setMaterial(metal);
    teaspoon2->setHoverMaterial(metalHighlight);
    if (perPixel) {
        teaspoon1->setEffect(lighting);
        teaspoon2->setEffect(lighting);
    } else
    {
        teaspoon1->setEffect(0);
        teaspoon2->setEffect(0);
    }
}

void TeaService::teapotClicked()
{
    qDebug("teapot clicked");
}

void TeaService::teacup1Clicked()
{
    qDebug("teacup1 clicked");
}

void TeaService::teacup2Clicked()
{
    qDebug("teacup2 clicked");
}

void TeaService::teaspoon1Clicked()
{
    qDebug("teaspoon1 clicked");
}

void TeaService::teaspoon2Clicked()
{
    qDebug("teaspoon2 clicked");
}
