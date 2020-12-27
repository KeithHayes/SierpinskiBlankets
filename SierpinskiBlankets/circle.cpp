#include "circle.h"
#include "objectcolor.h"


void rCircleFractalFill(Graphical *object, int level) {
    QColor save_color = object->getColor();

    ObjectColor object_colors(level);
    Graphical_ObjectType type = object->getType();
    QColor newcolor = object_colors.getColor(type);
    object->setColor(newcolor);

    if (object) object->draw();
    object->setColor(save_color);
}

Circle::Circle(ShapeType type) {
    switch(type){
    case ShapeType::gasket:
        setGenerator(gasketTransform());
        break;
    case ShapeType::carpet:
        setGenerator(carpetTransform());
        break;
    default:
        break;
    }
}

void Circle::rdraw(void) {
    if(m_action_func == nullptr) setAction(&rCircleFractalFill);
    process_reverse();
    return;
}

std::vector<Matrix> Circle::gasketTransform() {
    Matrix arr[3];
    std::vector<Matrix> transforms = std::vector<Matrix>(arr, arr + sizeof(arr)/sizeof(arr[0]));
    float height = sqrt(3)/4;
    transforms[0].scale(1.0/2.0);
    transforms[0].move(-.25, -height/2.0);
    transforms[1].scale(1.0/2.0);
    transforms[1].move(0.25, -height/2.0);
    transforms[2].scale(1.0/2.0);
    transforms[2].move(0.0, height/2.0);
    return transforms;
}

std::vector<Matrix> Circle::carpetTransform() {
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
    return transforms;
}

void Circle::setInitiator(QPainter* painter, QImage* image) {
    GraphicalPolygon *circle_point = new GraphicalPolygon(painter, image);
    circle_point->setPoint(Point(0.0, 0.0));
    circle_point->setCircleWidth(1.0);
    setSize(1.0);
    mObjectptrlist.clear();
    mObjectptrlist.push_back(circle_point);
}

void Circle::setReverseInitiator(QPainter* painter, QImage* image) {
    GraphicalPolygon *square = new GraphicalPolygon(painter, image, 4);
    square->setType(Graphical_ObjectType::background);
    (*square)[0].setPoint(-0.5,-0.5);
    (*square)[1].setPoint( 0.5,-0.5);
    (*square)[2].setPoint( 0.5, 0.5);
    (*square)[3].setPoint(-0.5, 0.5);
    setSize(1.0);
    mObjectptrlist.clear();
    mObjectptrlist.push_back(square);
}

void Circle::setEraseInitiator(QPainter* painter, QImage* image) {
    mErase_object.clear();
    GraphicalPolygon *outer_circle = new GraphicalPolygon(painter, image);
    outer_circle->setType(Graphical_ObjectType::foreground);
    outer_circle->setPoint(Point(0.0, 0.0));
    outer_circle->setCircleWidth(1/3.0);
    mErase_object.push_back(outer_circle);
    GraphicalPolygon *inner_circle = new GraphicalPolygon(painter, image);
    inner_circle->setType(Graphical_ObjectType::background);
    inner_circle->setPoint(Point(0.0, 0.0));
    inner_circle->setCircleWidth(1/3.0);
    inner_circle->scale(.87);
    mErase_object.push_back(inner_circle);
    GraphicalPolygon *bar_1 = new GraphicalPolygon(painter, image, 4);
    bar_1->setType(Graphical_ObjectType::foreground);
    (*bar_1)[0].setPoint(-0.19, 0.28);
    (*bar_1)[1].setPoint( 0.19, 0.28);
    (*bar_1)[2].setPoint( 0.27, 0.34);
    (*bar_1)[3].setPoint(-0.27, 0.34);
    bar_1->scale(1/3.0);
    mErase_object.push_back(bar_1);
    GraphicalPolygon *bar_2 = new GraphicalPolygon(painter, image, 4);
    bar_2->setType(Graphical_ObjectType::foreground);
    (*bar_2)[0].setPoint(-0.19, -0.28);
    (*bar_2)[1].setPoint( 0.19, -0.28);
    (*bar_2)[2].setPoint( 0.27, -0.34);
    (*bar_2)[3].setPoint(-0.27, -0.34);
    bar_2->scale(1/3.0);
    mErase_object.push_back(bar_2);
    GraphicalPolygon *bar_3 = new GraphicalPolygon(painter, image, 4);
    bar_3->setType(Graphical_ObjectType::foreground);
    (*bar_3)[0].setPoint(-0.27,  0.34);
    (*bar_3)[1].setPoint(-0.19,  0.34);
    (*bar_3)[2].setPoint( 0.27, -0.34);
    (*bar_3)[3].setPoint( 0.19, -0.34);
    bar_3->scale(1/3.0);
    mErase_object.push_back(bar_3);
    GraphicalPolygon *bar_4 = new GraphicalPolygon(painter, image, 4);
    bar_4->setType(Graphical_ObjectType::foreground);
    (*bar_4)[0].setPoint( 0.27,  0.34);
    (*bar_4)[1].setPoint( 0.19,  0.34);
    (*bar_4)[2].setPoint(-0.27, -0.34);
    (*bar_4)[3].setPoint(-0.19, -0.34);
    bar_4->scale(1/3.0);
    mErase_object.push_back(bar_4);
    setSize(.0625);
}
void Circle::process(void) {
    Matrix save_matrix;
    if (m_action_func==nullptr) return;
    for (int i=0; i<(int)mObjectptrlist.size(); i++) {
        mBase_object = mObjectptrlist[i];
        save_matrix = mBase_object->getMatrix();
        Matrix m = getMatrix() * save_matrix;
        generate(m,0);
    }
    return;
}

void Circle::generate(Matrix &pmatrix,int level) {
    float scale = getSize() * getScaleFactor(pmatrix);
    if((scale<m_min_object_size)||(level >= m_max_level)) {
      mBase_object->setMatrix(pmatrix);
      (*m_action_func) (mBase_object,level);
      return;
    }
    level++;
    Matrix tmatrix,m;
    int ntrans = mTransforms.size();
    for (int i=0; i<ntrans; i++) {
        m = pmatrix * mTransforms[i];
        generate(m,level);
    }
}


void Circle::process_reverse(void) {
  Matrix save_matrix;
  if (m_action_func==nullptr) return;
    for (int i=0; i<(int)mObjectptrlist.size(); i++) {
      mBase_object = mObjectptrlist[i];
      save_matrix = mBase_object->getMatrix();
      (*m_action_func) (mBase_object,0);
      Matrix x = getMatrix();
      Matrix m = x * save_matrix;
      mBase_object->setMatrix(m);
      generate_reverse(m,0);
      mBase_object->setMatrix(save_matrix);
    }
    return;
}

void Circle::generate_reverse(Matrix &pmatrix,int level) {
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
