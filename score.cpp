#include "main.h"
#include "util.h"
#include "game.h"

void score(){
	system("cls");
	cout << "\n\n\n\t\t\tgame start screen\n\n";
	
	int score = 0;
	int heart = 3;
	int skill = 3;
	//62, 20
	gotoxy(0, 18);
	for(int i = 0;i < 62;i++)
		cout << "=";
	gotoxy(0, 19);
	cout << "����: " << heart << "\t\t���� ���ھ�: " << score << "\t\t�ʻ��: " << skill;
	Sleep(3000);
}
