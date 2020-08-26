#include "enemy.h"
#include "myplane.h"
extern pthread_mutex_t mutex_value;
queue<int> q;

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
		pthread_mutex_lock(&mutex_value);
	
		Enemy[e].x = i; Enemy[e].y = j;
		gotoxy(i, j);
		setColor(red,black);
		cout << Enemy[e].view;
		sleep(1);		
		gotoxy(i, j);
		cout << "   ";
		j++;
		start = clock();
		
		pthread_mutex_unlock(&mutex_value);
	}
	if(Enemy[e].y == 18 || Enemy[e].exist == false)
		q.push(e);

	return (void*)0;
}

void enemy() {
	int i, j, ene;
	bool bfound;
	arg_struct args;
	pthread_t thread_t;
	Myplane me(30,17);
	clock_t start = clock();
	srand(time(0));
	
	ene = 0;
	while(ene < 11) {
		q.push(ene);
		ene++;
	}
	//62, 20
	while(!q.empty()) {
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
