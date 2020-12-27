#include "carpet.h"
#include "point.h"

Carpet::Carpet() {
    Matrix arr[8];
    std::vector<Matrix> transforms = std::vector<Matrix>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    transforms[0].scale(1/3.0);
    transforms[1].scale(1/3.0);
    transforms[2].scale(1/3.0);
    transforms[3].scale(1/3.0);
    transforms[4].scale(1/3.0);
    transforms[5].scale(1/3.0);
    transforms[6].scale(1/3.0);
    transforms[7].scale(1/3.0);
    transforms[0].move(-1/3.0, -1/3.0);
    transforms[1].move(0.0, -1/3.0);
    transforms[2].move(1/3.0, -1/3.0);
    transforms[3].move(-1/3.0, 0.0);
    transforms[4].move(1/3.0, 0.0);
    transforms[5].move(-1/3.0, 1/3.0);
    transforms[6].move(0.0, 1/3.0);
    transforms[7].move(1/3.0, 1/3.0);
    setGenerator(transforms);
}

void Carpet::setInitiator(QPainter* painter, QImage* image) {
    GraphicalPolygon *square = new GraphicalPolygon(painter, image, 4);
    (*square)[0].setPoint(-0.5,-0.5);
    (*square)[1].setPoint( 0.5,-0.5);
    (*square)[2].setPoint( 0.5, 0.5);
    (*square)[3].setPoint(-0.5, 0.5);
    setSize(1.0);
    mObjectptrlist.clear();
    mObjectptrlist.push_back(square);
}

void Carpet::setReverseInitiator(QPainter* painter, QImage* image) {
    Q_UNUSED(painter);
    Q_UNUSED(image);
}

void Carpet::setEraseInitiator(QPainter* painter, QImage* image) {
    GraphicalPolygon *square = new GraphicalPolygon(painter, image, 4);
    square->setPoints((*mObjectptrlist.crbegin())->getPoints());
    square->scale(1/3.0);
    square->setColor(0);
    mErase_object.clear();
    mErase_object.push_back(square);
}
