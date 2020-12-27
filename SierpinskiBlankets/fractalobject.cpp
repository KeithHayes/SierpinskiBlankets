#include "fractalobject.h"

void fractalFill(Graphical *object, int level) {
    Q_UNUSED(level);
    if (object) object->draw();
}

void rFractalFill(Graphical *object, int level) {
    int i;
    QColor save_color = object->getColor();
    for(i=0;i<COLOR_COUNT;i++) { if(object->getColor()==COLORS[i]) break; }
    i = (level + i) % (COLOR_COUNT  - 1) + 1;
    if (i==0) i++;
    object->setColor(COLORS[i]);
    if (object) object->draw();
    object->setColor(save_color);
}

void FractalObject::setInitiator(GraphicalPolygon* object) {
    mObjectptrlist.clear();
    mObjectptrlist.push_back(object);
}

void FractalObject::setReverseInitiator(GraphicalPolygon* object) {
    mObjectptrlist.clear();
    mObjectptrlist.push_back(object);
}

void FractalObject::setEraseInitiator(GraphicalPolygon* object) {
    mErase_object.clear();
    mErase_object.push_back(object);
}

void FractalObject::setGenerator(std::vector<Matrix> transforms) {
    mTransforms = transforms;
}


void FractalObject::draw(void) {
    if(m_action_func == nullptr) setAction(&fractalFill);
    process();
    return;
}

void FractalObject::rdraw(void) {
    if(m_action_func == nullptr) setAction(&rFractalFill);
    process_reverse();
    return;
}

void FractalObject::process(void) {
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

void FractalObject::generate(Matrix &pmatrix,int level) {
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

void FractalObject::process_reverse(void) {
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

void FractalObject::generate_reverse(Matrix &pmatrix,int level) {
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



