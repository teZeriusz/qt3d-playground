#include "Teacup.h"
#include "common.h"


Teacup::Teacup(QObject *parent)
    : MeshObject(loadBezier(QLatin1String(":/teacup.txt")), parent)
{
}
