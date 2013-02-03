#include "common.h"
#include "qglbuilder.h"
#include <qglteapot.h>


QGLAbstractScene *loadBezier(const QString& fileName)
{
    QGLAbstractScene *scene;
    scene = QGLAbstractScene::loadScene(fileName, QLatin1String("bezier"));
    if (!scene)
        qFatal("Could not load %s, probably plugin could not be found",
               fileName.toLatin1().constData());
    return scene;
}


QGLSceneNode *createTeapot(QObject *parent)
{
    QGLBuilder builder;
    builder << QGLTeapot();
    QGLSceneNode *n = builder.finalizedSceneNode();
    n->setParent(parent);
    return n;
}
