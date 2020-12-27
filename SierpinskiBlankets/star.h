#ifndef STARS_H
#define STARS_H
#include "fractalobject.h"

void rStarFill(Graphical *object, int level);

class Star : public FractalObject
{

public:
    Star(void);
    void setInitiator(QPainter* painter, QImage* image);
    void setReverseInitiator(QPainter* painter, QImage* image);
    void setEraseInitiator(QPainter* painter, QImage* image);
    void rdraw(void);
    void process_reverse(void);
    void generate_reverse(Matrix&, int);
};

#endif
