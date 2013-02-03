#ifndef TEACUP_H
#define TEACUP_H

#include "meshobject.h"


class Teacup : public MeshObject
{
    Q_OBJECT
public:
    Teacup(QObject *parent=0);
    ~Teacup() {}
};

#endif // TEACUP_H
