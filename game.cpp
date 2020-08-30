#include "main.h"
#include "enemy2.h"
#include "game.h"
#include "util.h"
#include "score.h"
#include "myplane.h"
extern pthread_mutex_t mutex_value;
// [-] player
// <-> enemy 
// <<<->>> boss

void gameStart(){
	resetGame();
	printScoreBoard();
	enemy();
}

void gameover(){
	//when you start the game again, the enemies have to be reset
	resetGame();

	gotoxy(ROWS/2-4, COLS/2-2);
	setColor(yellow, black);
	cout << "Game Over!!";
	Sleep(2000);
	setColor(white, black);
}

void printKeyHelp(){
	gotoxy(0, COLS-1);
	cout << "LEFT: ¡ç  RIGHT: ¡æ  UP: ¡è  DOWN: ¡é\n" << "SELECT: SPACEBAR  EXIT: ESC";
}

void printHelpPage(int &cur_page, int &total_page){
	clearScreen();
	printKeyHelp();
	gotoxy(ROWS/2-2, 2);
	cout << cur_page << "/" << total_page << "\n\n\n";

	switch(cur_page){
		case 1:{
			//first help page
			cout << "This game is \"space shooter\", which you can attack the flying \nenemies. ";
			cout << "There is a scoreboard at the bottom of the screen.\n";
			cout << "You can shoot the bullets toward the enemies by pressing the\nEnter key. ";
			cout << "The score will increase if the bullet hits an enemy.";
			break;
		}
		case 2:{
			//second help page
			cout << "If you collide with an enemy, the life will be decreased and\nthe location "
				 << "of the player plane will move to the initial\nposition. ";
			cout << "You can use a skill three times by pressing 's' key.\n";
			cout << "This skill will erase all the enemies on the screen after a\nshort blink. ";
			cout << "The highscore will be storaged while the console\nscreen is turned on.";
			break;
		}
		case 3:{
			//third help page
			cout << "Programmers: Lee Doyeon, º¹¿µºó, Á¤¼ÒÀ±\n\n";
			cout << "If you find any kind of bugs, please contact me here.\n";
			cout << ">> dyl1229@naver.com\n\n";
			cout << "Enjoy playing!";
			break;
		}
	}

	while(1){
		int page_control = keyControl();
		switch(page_control){
			case LEFT:{
				if(cur_page > 1) printHelpPage(--cur_page, total_page);
				break;
			}
			case RIGHT:{
				if(cur_page <= total_page) printHelpPage(++cur_page, total_page);
				break;
			}
			case ESC: return;
		}
		if(cur_page > total_page) break;
	}
}

void help(){
	int cur_page = 1;
	int total_page = 3;
	int page_control = 0;
	printHelpPage(cur_page, total_page);
}

int keyControl() {
	char temp;

	if(kbhit()){
		temp = getch();	

		if (temp == 72) return UP;
		else if (temp == 75) return LEFT;
		else if (temp == 77) return RIGHT;
		else if (temp == 80) return DOWN;
		else if (temp == 27) return ESC;
		else if (temp == 's') return SKILL;
		else if (temp == ' ') return SUBMIT;
	}
	return -1;
}

void titleDraw() {
	cout << "\n\n\n\n";
	
	cout << "\t    ######  #    #  ######  ######  ######\n";
	cout << "\t    #       #    #  #    #  #    #    ##  \n";
	cout << "\t    ######  ######  #    #  #    #    ##  \n";
	cout << "\t         #  #    #  #    #  #    #    ##  \n";
	cout << "\t    ######  #    #  ######  ######    ##  \n";

	printKeyHelp();
}

int menuDraw(){
    int x = 24;
    int y = 12;
    gotoxy(x-2,y); //-2 for "> "
    cout << "> GAME START";
    gotoxy(x,y+1);
    cout << "HELP";
    gotoxy(x,y+2);
    cout << "HIGH SCORE";
    gotoxy(x,y+3);
    cout << "EXIT";
    while(1){
		int n = keyControl();
		switch(n){
			case UP: {
				if(y>12){//12<=y<=15
					gotoxy(x-2,y);
					cout << " "; //erase >
					gotoxy(x-2,--y);
					cout << ">";
				}
				break;
			}		
			case DOWN:{
					if(y<15){
							gotoxy(x-2,y);
							cout << " ";
							gotoxy(x-2,++y);
							cout << ">";
					}
					break;
		}
			case SUBMIT:{
				return y-12; // gamestart:0, help:1, highscore:2, exit:3
			}
		}
	}
}
