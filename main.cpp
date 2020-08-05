#include "main.h"
#include "game.h"
#include "util.h"

int main() {
	init();	

	while(1){
		titleDraw();
		int menuCode = menuDraw();
		if(menuCode == 0){ //게임 시작
			//gameStart();
		} else if(menuCode == 1){
			//help(); // help
		} else if(menuCode == 2){
			//highScore(); // highscore
		}else if(menuCode == 3){
			return 0; //exit
		}
		system("cls");
	}
	return 0;
}

