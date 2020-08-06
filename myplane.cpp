#include "main.h"
#include "util.h"
#include "game.h"
#include "myplane.h"

Myplane::Myplane(int a, int b){
        x = a;
        y = b;
}

void move(int *x, int *y, int m, int n){
    if((*x+m) >= 0 && (*x+m) < 59 && (*y+n) >= 0 && (*y+n) < 20){
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
    system("cls");
    Myplane me(30,19);
    gotoxy(30,19);
    setColor(yellow,black);
    cout << "[-]";
    int play = 1;
    while(play){
        int k = keyControl();
        switch(k){
            case UP:{
                move(&me.x, &me.y, 0, -1);
                break;
            }
            case DOWN:{
                move(&me.x, &me.y, 0, 1);
                break;
            }
            case LEFT:{
                move(&me.x, &me.y, -1, 0);
                break;
            }
            case RIGHT:{
                move(&me.x, &me.y, 1, 0);
                break;
            }
            case SUBMIT:{
                setColor(white, black);
                play = 0;
            }
        }
    }
}
