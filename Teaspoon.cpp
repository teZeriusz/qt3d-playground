#include "Teaspoon.h"
#include "common.h"



Teaspoon::Teaspoon(QObject *parent)
    : MeshObject(loadBezier(QLatin1String(":/teaspoon.txt")), parent)
{
}
