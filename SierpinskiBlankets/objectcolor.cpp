#include "objectcolor.h"

ObjectColor::ObjectColor(int level) {
    mLevel = level;
    for(int i=0;i<COLOR_COUNT;i++){ mColors[i]=COLORS[i]; }
    for(int i=0;i<7;i++){ r_circle_foreground[i]=COLORS[12]; }
    for(int i=0;i<7;i++){ r_circle_background[i]=COLORS[7]; }
    for(int i=0;i<7;i++){ r_circle_extra[i]=COLORS[0]; }
    r_circle_foreground[1]=0x005500;
    r_circle_foreground[2]=0xaa0000;
    r_circle_foreground[3]=0x0000aa;
}

QColor ObjectColor::getColor(Graphical_ObjectType type) {
    int color_code = COLORS[0];
    switch(type) {
    case Graphical_ObjectType::foreground :
        color_code =  r_circle_foreground[mLevel];
        break;
    case Graphical_ObjectType::background :
        color_code =  r_circle_background[mLevel];
        break;
    case Graphical_ObjectType::extra :
        color_code =  r_circle_extra[mLevel];
        break;
    default :
        break;
    }
    QColor color(color_code);
    return color;
}
