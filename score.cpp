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
*/
void enemy(){
	system("cls");
	srand(time(0));
	
	int MAXENEMY = 10;
	Enemy e[MAXENEMY];
	int cur_enemy = 0;

	queue<int> q;
	for(int i = 0;i < 10;i++) q.push(i);
	
	
	for(int i = 0;i < 13;i++){		
		if(cur_enemy < 10){
			clock_t t = clock();
			Enemy tmp(t);
			e[q.front()] = tmp;
			q.pop();
			cur_enemy++;
		}
		
		for(int j = 0;j < 10;j++){
			if(e[j].exist == true){
				e[j].move(0,1);
				Sleep(500);
			}	
		}
		
	}
	setColor(white, black);
}








