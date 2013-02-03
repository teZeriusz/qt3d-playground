#ifndef TEASPOON_H
#define TEASPOON_H

#include "meshobject.h"



class Teaspoon : public MeshObject
{
    Q_OBJECT
public:
    Teaspoon(QObject *parent=0);
    ~Teaspoon() {}
};


#endif // TEASPOON_H
