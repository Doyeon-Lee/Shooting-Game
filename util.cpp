#include "main.h"
//#include "game.h"
#include "util.h"

//���� ȭ�� ���� �� �⺻ �Լ��� 
void init(){
	system("mode con: cols=63 lines=20 | title shooting game");
	setCurrentConsoleFontEx();

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false �Ǵ� 0: �����? 
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
	//���� ���? 
	//PlaySoundA (TEXT("background_music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); 
}

void gotoxy(int x, int y){
	//if(x < 0 || y < 0) cerr << "Out of Screen!";
	
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

void clearScreen(){
    HANDLE hOut;
    COORD Position;
    DWORD Written;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    FillConsoleOutputCharacter(hOut,' ', COLS*ROWS, Position, &Written);

    SetConsoleCursorPosition(hOut, Position);
}

void setCurrentConsoleFontEx(){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 25;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}