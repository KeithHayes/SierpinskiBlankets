#ifndef FRACTALOBJECT_H
#define FRACTALOBJECT_H
#include "graphical.h"
#include "misc.h"


void fractalFill(Graphical, int level);
void rFractalFill(Graphical, int level);

class FractalObject : public Graphical
{

protected:
  int m_max_level;
  float m_min_object_size;
  GraphicalPolygon *mBase_object;
  std::vector<GraphicalPolygon*> mObjectptrlist;
  std::vector<GraphicalPolygon*> mErase_object;
  std::vector<Matrix> mTransforms;


protected:
  void (*m_action_func)(Graphical *,int);
  float mObjectSize;

public:
    FractalObject() {
        m_min_object_size = MIN_SIZE;
        m_action_func = nullptr;
    };
    void setSize(float s) { mObjectSize = s; };
    float getSize(void) { return mObjectSize; };
    virtual void setInitiator(QPainter* painter, QImage* image) = 0;
    virtual void setReverseInitiator(QPainter* painter, QImage* image) = 0;
    virtual void setEraseInitiator(QPainter* painter, QImage* image) = 0;
    void setInitiator(GraphicalPolygon*);
    void setReverseInitiator(GraphicalPolygon*);
    void setEraseInitiator(GraphicalPolygon*);
    void setGenerator(std::vector<Matrix> transforms);
    void setMaxLevel(int ml) { m_max_level = ml; };
    void setAction(void (*actionFuncIn)(Graphical *,int)) { m_action_func = actionFuncIn; }
    void draw(void);
    virtual void rdraw(void);
    virtual void process(void);
    virtual void generate(Matrix&, int);
    virtual void process_reverse(void);
    virtual void generate_reverse(Matrix&, int);
};

#endif
