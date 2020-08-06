#include "enemy.h"
#include "myplane.h"

queue<int> q;

class Enemy {
public:
	bool exist = true;
	int x, y;
	string view = "<->";
}Enemy[MAXENEMY];

void* move_enemy(void* ene) {
	int e = *(int *)ene;
	
	while(Enemy[e].x < 60 && Enemy[e].y < 18 && Enemy[e].exist == true) {
		gotoxy(Enemy[e].x, Enemy[e].y);
		setColor(red,black);
		cout << Enemy[e].view;
		sleep(1);
		gotoxy(Enemy[e].x, Enemy[e].y);
		cout << "   ";
		Enemy[e].y++;
	}
	
	if(Enemy[e].y == 18 || Enemy[e].exist == false)
		q.push(e);
}

void enemy() {
	int i, j, ene, status;
	pthread_t thread_t;
	Myplane me(30,17);
	clock_t start = clock();
	srand(time(0));
	
	ene = 0;
	while(ene < 10) {
		q.push(ene);
		ene++;
	}
	//62, 20
	while(!q.empty()) {
		if(kbhit()) {	//move my character
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
	
	            }
	        }
        }

		if((clock()-start)/CLOCKS_PER_SEC > 2) {	//make enemies
			ene = q.front(); q.pop();
			Enemy[ene].x = rand() % 60;
			Enemy[ene].y = 0;
			Enemy[ene].exist = true;
			if(pthread_create(&thread_t, NULL, move_enemy,(void*)&ene)<0) {
				perror("thread create error:");
        		exit(0);
			}
			start = clock();
		}
	}
	pthread_join(thread_t, (void **)&status);
	setColor(white, black);
}
