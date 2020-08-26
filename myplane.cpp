#include "main.h"
#include "util.h"
#include "game.h"
#include "myplane.h"
extern pthread_mutex_t mutex_value;

Myplane::Myplane(int a, int b){
        x = a;
        y = b;
}

void move(int *x, int *y, int m, int n){
    if((*x+m) >= 0 && (*x+m) < 59 && (*y+n) >= 0 && (*y+n) < 18){
    	pthread_mutex_lock(&mutex_value);
    	
		gotoxy(*x,*y);
        cout << "   ";
        setColor(yellow, black);
        gotoxy(*x+m, *y+n);
        cout << "[-]";
        *x += m;
        *y += n;
		
		pthread_mutex_unlock(&mutex_value);
	 }
}

void myplane(){
    //system("cls");

    gotoxy(30,17);
    setColor(yellow,black);
    cout << "[-]";
    setColor(white,black);
}
