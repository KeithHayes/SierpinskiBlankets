#include "graphical.h"
#include "misc.h"

Graphical::Graphical(void) {
  this->mColor = QColor("#aa5500");
}

void Graphical::setColor(QString colorStr) {
    this->mColor = QColor(colorStr);
}

void Graphical::setColor(QColor color) {
    this->mColor = color;
}

void Graphical::setColor(int colorVar) {
    this->mColor = QColor(colorVar);
}

void Graphical::draw(void) {

}

void GraphicalPolygon::draw(void) {
    int maxX = mImage->width();
    int maxY = mImage->height();
    int centerX = maxX/2;
    int centerY = maxY/2;
    int scale = 1.5 * MINSIZE(centerX,centerY);
    int pointcount = mPoints.size();
    vectorType pointVec;
    Matrix m = getMatrix();
    QPainter painter(mImage);
    QPainterPath path;
    if (pointcount>1) {
        std::vector<Point> screen_point;
        for(int i=0;i<pointcount;i++) {
            pointVec.clear();
            mPoints[i].getCoords(pointVec);
            pointVec = m * pointVec;
            float x =  scale * pointVec[0] + centerX;
            float y = -scale * pointVec[1] + centerY;
            screen_point.push_back(Point(x, y));
        }
        path.moveTo(screen_point[0].getX(),screen_point[0].getY());
        for(int i=1;i<pointcount;i++) {
            path.lineTo(screen_point[i].getX(),screen_point[i].getY());
        }
        path.lineTo(screen_point[0].getX(),screen_point[0].getY());
    } else {
        mPoints[0].getCoords(pointVec);
        pointVec[0] = -mDiameter/2.0 + pointVec[0];
        pointVec[1] =  mDiameter/2.0 + pointVec[1];
        pointVec = m * pointVec;
        float size = getScaleFactor(m);
        int radii = size * scale * mDiameter;
        int x = ( scale * pointVec[0]) + centerX;
        int y = (-scale * pointVec[1]) + centerY;
        path.addEllipse( x, y, radii, radii );
    }
    painter.setPen (QPen (QColor (this->mColor)));
    painter.fillPath (path, QBrush (QColor (this->mColor)));
}
