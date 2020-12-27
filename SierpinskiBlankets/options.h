#ifndef OPTIONS_H
#define OPTIONS_H

enum class ShapeType { star, reverse_star, circle, reverse_circle, gasket, reverse_gasket, carpet, reverse_carpet };

class Options
{

private:
    ShapeType mtype;
    int level;

public:
    Options(){};
    void setType(ShapeType t) { mtype = t; };
    ShapeType getType() { return mtype; };
    void setLevel(int l) { level = l; };
    int getLevel() { return level; };
};

#endif
