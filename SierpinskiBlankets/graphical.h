#ifndef GRAPHICAL_H
#define GRAPHICAL_H
#include "misc.h"
#include "matrix.h"
#include "viewscreen.h"
#include <vector>
#include <QPaintEvent>

class Graphical : public Matrix
{

private:
    Graphical_ObjectType mType;

protected:
    QPainter* mPainter;
    QImage* mImage;
    QColor mColor;

public:
    Graphical(void);
    void setType(Graphical_ObjectType type) { mType = type; };
    Graphical_ObjectType getType(void) { return mType; };
    void setColor(QString colorStr);
    void setColor(QColor color);
    void setColor(int colorVar);
    QColor getColor(void) { return mColor; };
    Matrix& getMatrix() { return *this; };
    virtual void draw(void);
};

class GraphicalPolyline : public Graphical {

protected:
    bool mClosed;
    std::vector<Point> mPoints;
    float mDiameter;

public:
    GraphicalPolyline(int n) {
        setType(Graphical_ObjectType::extra);
        mClosed = false;
        Point arr[n];
        mPoints = std::vector<Point>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    };
    Point& operator[](unsigned int index) { return mPoints[index]; };
    std::vector<Point> getPoints(void) { return mPoints; };
    void setPoints( std::vector<Point> points) { mPoints = points; };
    void setPoint(Point point) { mPoints[0] = point; };
    void setCircleWidth(float width) { mDiameter = width; };
};

class GraphicalPolygon : public GraphicalPolyline {

public:
    GraphicalPolygon(QPainter* painter, QImage* image, int p) : GraphicalPolyline(p) {
        mPainter = painter;
        mImage = image;
        mClosed = true;
    };
    GraphicalPolygon(QPainter* painter, QImage* image) : GraphicalPolyline(1) {
        mPainter = painter;
        mImage = image;
    };
    void draw(void) override;
};

#endif
