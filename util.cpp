#include "main.h"
//#include "game.h"
#include "util.h"

//���� ȭ�� ���� �� �⺻ �Լ��� 
void init(){
	system("mode con: cols=62 lines=20 | title shooting game");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false �Ǵ� 0: ����� 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	//���� ��� 
	//PlaySoundA (TEXT("background_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); 
}


void gotoxy(int x, int y){
	if(x < 0 || y < 0) cerr << "Out of Screen!";
	
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolehandle,pos);
}

//����, ���� 
void setColor(int forground, int background){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}



