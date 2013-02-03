#ifndef TEAPOT_H
#define TEAPOT_H

#include "meshobject.h"



class Teapot : public MeshObject
{
    Q_OBJECT
public:
    Teapot(QObject *parent=0);
    ~Teapot() {}
};

#endif // TEAPOT_H
