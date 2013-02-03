#include "Teapot.h"
#include "common.h"


Teapot::Teapot(QObject *parent)
    : MeshObject(createTeapot(parent), parent)
{
}
