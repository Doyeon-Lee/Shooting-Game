#include "main.h"
#include "game.h"
#include "util.h"
#include "score.h"
#include "enemy.h"
#include "myplane.h"
extern pthread_mutex_t mutex_value;
// [-] player
// <-> enemy 
// <<<->>> boss

void gameStart(){
	system("cls");
	score();
	myplane();
	enemy();
}

void printHelpPage(int &cur_page, int &total_page){
	clearScreen();
	cout << "\n\n\t\t\t" << cur_page << "/" << total_page << "\n\n\n";
	switch(cur_page){
		case 1:{
			cout << "first help page\n";
			break;
		}
		case 2:{
			cout << "second help page\n";
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
		}
		if(cur_page > total_page) break;
	}
}

void help(){
	int cur_page = 1;
	int total_page = 2;
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
