#include "main.h"

class Myplane{
public:
    int x;
    int y;
    int life;
    Myplane(int a, int b);
};

void plane_move(int*, int*, int, int);

void initPlane(class Myplane&);
