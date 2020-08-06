#include "enemy.h"
<<<<<<< HEAD
/*
=======

queue<int> q;

>>>>>>> 57ceec29b1aaa4c8687043b8cef8f8be2aed6fcb
class Enemy {
public:
	bool exist = true;
	int x, y;
	string view = "<->";
}Enemy[MAXENEMY];

struct arg_struct {
	int i;
	int j;
	int ene;
};

void* move_enemy(void* arguments) {
	arg_struct *args = (arg_struct *)arguments;
	int i = args->i;
	int j = args->j;
	int e = args->ene;
	clock_t start;
	while(i < 60 && j < 18 && Enemy[e].exist == true) {
		Enemy[e].x = i; Enemy[e].y = j;
		gotoxy(i, j);
		cout << Enemy[e].view;
		start = clock();
		Sleep(500);		
		gotoxy(i, j);
		cout << "   ";
		j++;
		start = clock();
	}
	if(Enemy[e].y == 18 || Enemy[e].exist == false)
		q.push(e);
}

void enemy() {
	int i, j, ene;
	bool bfound;
	arg_struct args;
	pthread_t thread_t;
	clock_t start = clock();
	setColor(red, black);
	srand(time(0));
	
	ene = 0;
	while(ene < 11) {
		q.push(ene);
		ene++;
	}
	//62, 20
	while(!q.empty()) {
		args.i = rand() % 60; args.j = 0;
		if((clock()-start)/CLOCKS_PER_SEC > 2) {
			args.ene = q.front();
			q.pop();
			Enemy[ene].exist == true;
			if(pthread_create(&thread_t, NULL, move_enemy,(void*)&args)<0) {
				perror("thread create error:");
        		exit(0);
			}
			start = clock();
		}
	}
	setColor(white, black);
}
*/
