#ifndef CIRCLE_H
#define CIRCLE_H
#include "fractalobject.h"

void rCircleFractalFill(Graphical, int level);

class Circle : public FractalObject
{

protected:
    GraphicalPolygon *mBase_object;
    float mObjectSize;

public:
    Circle(ShapeType);
    std::vector<Matrix> gasketTransform();
    std::vector<Matrix> carpetTransform();
    void setSize(float s) { mObjectSize = s; };
    float getSize(void) { return mObjectSize; };
    void setInitiator(QPainter* painter, QImage* image);
    void setReverseInitiator(QPainter* painter, QImage* image);
    void setEraseInitiator(QPainter* painter, QImage* image);
    void rdraw(void);
    void process(void);
    void generate(Matrix&, int);
    void process_reverse(void);
    void generate_reverse(Matrix&, int);

};

#endif
