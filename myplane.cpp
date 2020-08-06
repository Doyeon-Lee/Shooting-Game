#include "main.h"
#include "util.h"
#include "game.h"
#include "myplane.h"

Myplane::Myplane(int a, int b){
        x = a;
        y = b;
}

void move(int *x, int *y, int m, int n){
    if((*x+m) >= 0 && (*x+m) < 59 && (*y+n) >= 0 && (*y+n) < 18){
        gotoxy(*x,*y);
        cout << "   ";
        setColor(yellow, black);
        gotoxy(*x+m, *y+n);
        cout << "[-]";
        *x += m;
        *y += n;
    }
}

void myplane(){
    //system("cls");
    gotoxy(30,17);
    setColor(yellow,black);
    cout << "[-]";
    setColor(white,black);
}
