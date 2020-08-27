#include "main.h"
#include "util.h"
#include "game.h"
#include "myplane.h"
extern pthread_mutex_t mutex_value;

Myplane::Myplane(int a, int b){
    x = a;
    y = b;
}

void plane_move(int *x, int *y, int m, int n){
    if((*x+m) >= 0 && (*x+m) < ROWS-2 && (*y+n) >= 0 && (*y+n) < COLS-2){    	
		gotoxy(*x,*y);
        cout << "   ";
        setColor(yellow, black);
        gotoxy(*x+m, *y+n);
        cout << "[-]";
        *x += m;
        *y += n;
	 }
}

void initPlane(class Myplane &p){
    //p = Myplane(30, 17);
    gotoxy(p.x, p.y);
    setColor(yellow,black);
    cout << "[-]";
    setColor(white,black);
}
