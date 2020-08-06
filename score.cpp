#include "main.h"
#include "util.h"
#include "game.h"
#include "score.h"

void score(){	
	int score = 0;
	int heart = 3;
	int skill = 3;
	//62, 20
	gotoxy(0, 18);
	for(int i = 0;i < 62;i++)
		cout << "=";
	gotoxy(0, 19);
	cout << "생명: " << heart << "\t\t현재 스코어: " << score << "\t\t필살기: " << skill;
}
	
//enemy, myplane 구현 practice
/*
void myplane(){	
	system("cls");
	Player p(15,15);
	gotoxy(p.x, p.y);
	setColor(yellow, black);
	cout << "@";
	
	int player_move_key;
	while(1){
		player_move_key = keyControl();
		switch(player_move_key){
			case LEFT:{
				p.move(-1, 0);
				break;
			}
			case RIGHT:{
				p.move(1, 0);
				break;
			}
			case UP:{
				p.move(0, -1);
				break;
			}
			case DOWN:{
				p.move(0, 1);
				break;
			}
			case SUBMIT:{
				setColor(white, black);
				return;
			}
		}
	}
}

void enemy(){
	system("cls");
	srand(time(0));
	
	int MAXENEMY = 10;
	Enemy *e[MAXENEMY];
	int cur_enemy = 0;

	queue<int> q;
	for(int i = 0;i < 10;i++) q.push(i);

	for(int j = 0;j < 5;j++){
		cout << cur_enemy;
		if(cur_enemy < 10){
			e[q.front()] = new Enemy();
			q.pop();
			cur_enemy++;
		}
		
		for(int i = 0;i < 10;i++){
			if(e[i]->exist) e[i]->move(0, 1);
		}
	}

	setColor(white, black);
}
*/







