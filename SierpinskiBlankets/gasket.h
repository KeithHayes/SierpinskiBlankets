#ifndef GASKET_H
#define GASKET_H
#include "fractalobject.h"


class Gasket : public FractalObject
{

public:
    Gasket(void);
    void setInitiator(QPainter* painter, QImage* image);
    void setReverseInitiator(QPainter* painter, QImage* image);
    void setEraseInitiator(QPainter* painter, QImage* image);
};

#endif
