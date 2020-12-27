#ifndef MISC_H
#define MISC_H

#define MIN_SIZE 0.007
#define PI_OVER2 1.570796327
#define PI_OVER4 0.785398163
#define PI 3.141592654
#define TWO_PI (6.283185308)
#define SQRT_TWO 1.41421356237

#define MINSIZE(A,B) (((A) > (B)) ? (B) : (A))

#define COLOR_COUNT 16
const int COLORS[COLOR_COUNT] = { 0x000000,0x000055,0x005500,0x00aaaa, \
                                  0x550000,0xaa00aa,0xaa5500,0xaaaaaa, \
                                  0x555555,0x0000aa,0x00aa00,0x55ffff, \
                                  0xaa0000,0x5555ff,0xffff55,0xffffff };

enum class Graphical_ObjectType { foreground, background, extra };

#endif
