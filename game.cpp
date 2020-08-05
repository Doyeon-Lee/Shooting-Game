#include "main.h"
#include "game.h"
#include "util.h"
#include "score.h"
#include "enemy.h"

// [-] player
// <-> enemy 
// <<<->>> boss

void gameStart(){
	enemy();
	//myplane();
	score();
}

void printHelpPage(int &cur_page, int &total_page){
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
}

void help(){
	system("cls");
	int cur_page = 1;
	int total_page = 2;
	int page_control;
	printHelpPage(cur_page, total_page);

	while(1){
		page_control = keyControl();
		switch(page_control){
			case LEFT:{
				if(cur_page > 1) cur_page--;
				break;
			}
			case RIGHT:{
				if(cur_page <= total_page) cur_page++;
				break;
			}
		}
		if(cur_page > total_page) break;
		
		system("cls");
		printHelpPage(cur_page, total_page);
	}
}


int keyControl() {
	char temp = getch();

	if (temp == 72) {
		return UP;
	}
	else if (temp == 75) {
		return LEFT;
	}
	else if (temp == 77) {
		return RIGHT;
	}
	else if (temp == 80) {
		return DOWN;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
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

