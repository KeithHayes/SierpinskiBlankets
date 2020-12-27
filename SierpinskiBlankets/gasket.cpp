#include "gasket.h"
#include "point.h"

Gasket::Gasket()
{
    Matrix arr[3];
    std::vector<Matrix> transforms = std::vector<Matrix>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    float height = sqrt(.75);
    transforms[0].scale(1.0/2.0);
    transforms[0].move(-.25, -height/4.0);
    transforms[1].scale(1.0/2.0);
    transforms[1].move(0.25, -height/4.0);
    transforms[2].scale(1.0/2.0);
    transforms[2].move(0.0, height/4.0);
    setGenerator(transforms);
}

void Gasket::setInitiator(QPainter* painter, QImage* image) {
    float height = sqrt(3.0)/2.0;
    GraphicalPolygon *triangle = new GraphicalPolygon(painter, image, 3);
    (*triangle)[0].setPoint(-0.5, -height/2.0);
    (*triangle)[1].setPoint( 0.5, -height/2.0);
    (*triangle)[2].setPoint( 0.0,  height/2.0);
    setSize(height/2.0);
    mObjectptrlist.clear();
    mObjectptrlist.push_back(triangle);
}

void Gasket::setReverseInitiator(QPainter* painter, QImage* image) {
    Q_UNUSED(painter);
    Q_UNUSED(image);
}

void Gasket::setEraseInitiator(QPainter* painter, QImage* image) {
    GraphicalPolygon *triangle = new GraphicalPolygon(painter, image, 3);
    triangle->setPoints((*mObjectptrlist.crbegin())->getPoints());
    triangle->rotateCW(PI);
    triangle->scale(0.5);
    triangle->move(0,-sqrt(3.0)/8.0);
    mErase_object.clear();
    mErase_object.push_back(triangle);
}
