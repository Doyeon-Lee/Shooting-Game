#include "main.h"
//#include "game.h"
#include "util.h"

//시작 화면 설정 및 기본 함수들 
void init(){
	system("mode con: cols=62 lines=20 | title 탈출 게임");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false 또는 0: 숨기기 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	//루프 재생 
	//PlaySoundA (TEXT("background_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); 
}


void gotoxy(int x, int y){
	if(x < 0 || y < 0) cerr << "Out of Screen!";
	
	HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consolehandle,pos);
}

//글자, 배경색 
void setColor(int forground, int background){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}


