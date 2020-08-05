#include "main.h"

/*
class UNIT{
	public:
		int x;
		int y;
		int life;
		int color;
};

class Player : public UNIT{
public:
	Player(int a, int b){
		x = a;
		y = b;
	}
		
	void move(int a, int b) {Move(a, b);}
private:
	Move(int _x, int _y){
		//62,20
		if(x+_x >= 0 && x+_x < 62 && y+_y >= 0 && y+_y < 20){
			gotoxy(x, y);
			cout << " ";
			gotoxy(x+_x, y+_y);
			setColor(yellow, black);
			cout << "@";
				
			x += _x;
			y += _y;
		}
	}
};

class Enemy : public UNIT{
public:
	bool exist;
	string view;
	void move(int a, int b){Move(a, b);}
	Enemy(){
		//·£´ýÇÏ°Ô ÁÂÇ¥ »ý¼º
		x = rand() % 60;
		y = 0;
		exist = true;
		view = "<->";
	}
private:
	Move(int _x, int _y){
		if(x+_x >= 0 && x+_x < 62 && y+_y >= 0 && y+_y < 20){
			gotoxy(x, y);
			cout << "     ";
			gotoxy(x+_x, y+_y);
			setColor(yellow, black);
			cout << view;
					
			x += _x;
			y += _y;
		}
	}	
};
*/

void score();
//void myplane();
//void enemy();
