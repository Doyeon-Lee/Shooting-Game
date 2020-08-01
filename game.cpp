#include "game.h"

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
	cout << "        ��������  ��    ��������  ��";
	cout << "        �������� �� ��  �������� �� ��" ;
	cout << "        �������� ������ �������� ������";
	cout << "        ��������  ����  ��������  ����";
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