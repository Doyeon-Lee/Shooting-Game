#include "main.h"
#include "util.h"
#include "game.h"
#include "score.h"

void score(){	
	int score = 0;
	int life = 3;
	int skill = 3;
	//62, 20
	gotoxy(0, COLS-2);
	for(int i = 0;i <= ROWS;i++)
		cout << "=";
	gotoxy(0, COLS-1);
	cout << "LIFE: " << life << "\t\t\tSCORE: " << score << "\t\tSKILL: " << skill;
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
