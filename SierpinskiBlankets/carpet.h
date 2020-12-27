#ifndef CARPET_H
#define CARPET_H
#include "fractalobject.h"


class Carpet : public FractalObject
{

public:
    Carpet();
    void setInitiator(QPainter* painter, QImage* image);
    void setReverseInitiator(QPainter* painter, QImage* image);
    void setEraseInitiator(QPainter* painter, QImage* image);
};
#endif
