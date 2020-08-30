#include "main.h"
#include "util.h"
#include "game.h"
#include "score.h"
#include "enemy2.h"
#define SCORE_X 0
#define LIFE_X 20
#define SKILL_X 40
#define SCORE_BOARD_Y COLS-1

int score, life, skill;

void initScoreBoard(){
	score = 0;
	life = 3;
	skill = 3;
}

void printScoreBoard(){	
	setColor(white, black);
	//62, 20
	gotoxy(0, COLS-2);
	for(int i = 0;i <= ROWS;i++)
		cout << "=";
	gotoxy(SCORE_X, SCORE_BOARD_Y);
	cout << "SCORE: " << score;
	gotoxy(LIFE_X, SCORE_BOARD_Y);
	cout << "LIFE: " << life;
	gotoxy(SKILL_X, SCORE_BOARD_Y);
	cout << "SKILL: " << skill;
}

void plusScore(){
	score++;
	gotoxy(SCORE_X, SCORE_BOARD_Y);
	cout << "SCORE: " << score;
}

bool lifeLeft(){
	if(life > 0) return true;
	else return false;
}

void minusLife(){
	life--;
	gotoxy(LIFE_X, SCORE_BOARD_Y);
	cout << "LIFE: " << life;	
}
	
bool useSkill(){
	if(skill == 0) return false;
	skill--;
	blinkScreen();
	return true;
}

//enemy, myplane practice
/*
void myplane(){	
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
