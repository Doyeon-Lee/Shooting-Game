#include "main.h"
#include "util.h"
#include "game.h"
#include "score.h"

void score(){	
	int score = 0;
	int life = 3;
	int skill = 3;
	//62, 20
	gotoxy(0, 18);
	for(int i = 0;i < 62;i++)
		cout << "=";
	gotoxy(0, 19);
	cout << "LIFE: " << life << "\t\t\tSCORE: " << score << "\t\tSKILL: " << skill;
}
	
//enemy, myplane practice
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
