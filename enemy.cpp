#include "enemy.h"

class Enemy {
public:
	bool exist;
	int x, y;
	string view = "<->";
	void move(int, int);
}Enemy[MAXENEMY];

void move(int i, int j, int e) {
	Enemy[e].x = i; Enemy[e].y = j;
	while(i < 60 && j < 20) {
		gotoxy(i, j);
		cout << Enemy[e].view;
		Sleep(500);
		gotoxy(i, j);
		cout << "   ";
		j++;
	}
}

void enemy() {
	system("cls");
	int i, j, ene, ene_num;
	bool bfound;
	srand(time(0));
	setColor(red, black);
	ene_num = 0; ene = 0;
	//62, 20
	while(1) {
		thread t(move);
		i = rand() % 60; j = 0;
		move(i, j, ene);
		ene++; ene_num++;
		if(Enemy[ene].y == 21) ene_num--;
		if(ene > 9) ene = 0;
	}
	setColor(white, black);
}
