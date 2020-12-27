#include "star.h"
#include "point.h"
#include "matrix.h"
#include <math.h>
#include <array>
#include <vector>


void rStarFill(Graphical *object, int level)
{
    int i;
    QColor save_color = object->getColor();
    switch (level) {
    case 0:
        object->setColor(COLORS[7]);
        break;
    case 1:
        object->setColor(COLORS[12]);
        break;
    case 2:
        object->setColor(COLORS[15]);
        break;
    case 3:
        object->setColor(COLORS[9]);
        break;
    case 4:
        object->setColor(COLORS[12]);
        break;
    case 5:
        object->setColor(COLORS[15]);
        break;
    case 6:
        object->setColor(COLORS[9]);
        break;
    default:
        for(i=0;i<COLOR_COUNT;i++) { if(object->getColor()==COLORS[i]) break; }
        i = (level + i) % (COLOR_COUNT  - 1) + 1;
        if (i==0) i++;
        object->setColor(COLORS[i]);
        break;
    }

    if (object) object->draw();
    object->setColor(save_color);
}

Star::Star()
{
    Matrix arr[3];
    std::vector<Matrix> transforms = std::vector<Matrix>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    float height = sqrt(3)/4;
    transforms[0].scale(1.0/2.0);
    transforms[0].move(-.25, -height/2.0);
    transforms[1].scale(1.0/2.0);
    transforms[1].move(0.25, -height/2.0);
    transforms[2].scale(1.0/2.0);
    transforms[2].move(0.0, height/2.0);
    setGenerator(transforms);
}


void Star::setInitiator(QPainter* painter, QImage* image) {
    float cr = std::cos(2*PI/5.0);
    float sr = std::sin(2*PI/5.0);
    GraphicalPolygon *starpoly = new GraphicalPolygon(painter, image, 10);
    (*starpoly)[0].setXY(0,0.5);
    float r = 0.381966011/2.0;
    (*starpoly)[1].setPoint(-r*std::sin(PI/5.0),r*std::cos(PI/5.0));
    for(int i=0;i<2;i++) {
        (*starpoly)[i].setX(1.054*(*starpoly)[i].getX());
        (*starpoly)[i].setY(1.054*(*starpoly)[i].getY());
    }
    for(int i=0;i<8;i+=2) {
        (*starpoly)[i+2].setX(cr*(*starpoly)[i].getX() - sr*(*starpoly)[i].getY());
        (*starpoly)[i+2].setY(sr*(*starpoly)[i].getX() + cr*(*starpoly)[i].getY());
        (*starpoly)[i+3].setX(cr*(*starpoly)[i+1].getX() - sr*(*starpoly)[i+1].getY());
        (*starpoly)[i+3].setY(sr*(*starpoly)[i+1].getX() + cr*(*starpoly)[i+1].getY());
    }
    setSize(0.439);
    starpoly->setColor(0xaa0000);
    mObjectptrlist.clear();
    mObjectptrlist.push_back(starpoly);
}

void Star::setReverseInitiator(QPainter* painter, QImage* image) {
    Q_UNUSED(painter);
    Q_UNUSED(image);
}

void Star::setEraseInitiator(QPainter* painter, QImage* image) {
    float height = sqrt(3.0)/2.0;
    GraphicalPolygon *triangle = new GraphicalPolygon(painter, image, 3);
    (*triangle)[0].setPoint(-0.5, -height/2.0);
    (*triangle)[1].setPoint( 0.5, -height/2.0);
    (*triangle)[2].setPoint( 0.0,  height/2.0);
    setSize(height/2.0);
    mObjectptrlist.clear();
    mObjectptrlist.push_back(triangle);
    float cr = std::cos(2*PI/5.0);
    float sr = std::sin(2*PI/5.0);
    GraphicalPolygon *starpoly = new GraphicalPolygon(painter, image, 10);
    (*starpoly)[0].setXY(0,0.5);
    float r = 0.381966011/2.0;
    (*starpoly)[1].setPoint(-r*std::sin(PI/5.0),r*std::cos(PI/5.0));
    for(int i=0;i<2;i++) {
        (*starpoly)[i].setX(1.054*(*starpoly)[i].getX());
        (*starpoly)[i].setY(1.054*(*starpoly)[i].getY());
    }
    for(int i=0;i<8;i+=2) {
        (*starpoly)[i+2].setX(cr*(*starpoly)[i].getX() - sr*(*starpoly)[i].getY());
        (*starpoly)[i+2].setY(sr*(*starpoly)[i].getX() + cr*(*starpoly)[i].getY());
        (*starpoly)[i+3].setX(cr*(*starpoly)[i+1].getX() - sr*(*starpoly)[i+1].getY());
        (*starpoly)[i+3].setY(sr*(*starpoly)[i+1].getX() + cr*(*starpoly)[i+1].getY());
    }
    starpoly->scale(0.29);
    starpoly->move(0,-.15);
    setSize(0.439);
    starpoly->setColor(0xaa0000);
    mErase_object.clear();
    mErase_object.push_back(starpoly);
}

void Star::rdraw(void) {
    if(m_action_func == nullptr) setAction(&rStarFill);
    process_reverse();
    return;
}

void Star::process_reverse(void) {
  Matrix save_matrix;
  QColor save_color;
  if (m_action_func==nullptr) return;
    for (int i=0; i<(int)mObjectptrlist.size(); i++) {
      mBase_object = mObjectptrlist[i];
      save_matrix = mBase_object->getMatrix();
      save_color = mBase_object->getColor();
      QColor c = getColor();
      //QColor c = ("#aa0000");
      mBase_object->setColor(c);
      (*m_action_func) (mBase_object,0);
      Matrix x = getMatrix();
      Matrix m = x * save_matrix;
      mBase_object->setMatrix(m);
      generate_reverse(m,0);
      mBase_object->setMatrix(save_matrix);
      mBase_object->setColor(save_color);
    }
    return;
}

void Star::generate_reverse(Matrix &pmatrix,int level) {
    Matrix save_matrix;
    float scale = getSize() * getScaleFactor(pmatrix);
    if((scale<m_min_object_size)||(level >= m_max_level)) { return; }
    level++;
    for (int i=0; i<(int)mErase_object.size(); i++) {
        save_matrix = mErase_object[i]->getMatrix();
        Matrix m = pmatrix * save_matrix;
        mErase_object[i]->setMatrix(m);
        (*m_action_func) (mErase_object[i],level);
        mErase_object[i]->setMatrix(save_matrix);
    }
    Matrix tmatrix;
    Matrix m;
    int ntrans = mTransforms.size();
    for (int i=0; i<ntrans; i++) {
        tmatrix = mTransforms[i];
        m = pmatrix * tmatrix;
        generate_reverse(m,level);
    }
    return;
}
