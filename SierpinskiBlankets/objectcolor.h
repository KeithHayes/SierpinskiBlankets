#ifndef OBJECTCOLOR_H
#define OBJECTCOLOR_H
#include "misc.h"
#include <QColor>

class ObjectColor
{
public:
   int mColors[COLOR_COUNT];
   int r_circle_foreground[7];
   int r_circle_background[7];
   int r_circle_extra[7];


private:
   int mLevel;

public:
    ObjectColor(int level);
    QColor getColor(Graphical_ObjectType type);
};

#endif
