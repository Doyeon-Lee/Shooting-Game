#include "main.h"

#ifndef SCREEN_SIZE
#define SCREEN_SIZE

#define COLS 62
#define LINES 20
#endif

#ifndef __COLOR_LIST__
#define __COLOR_LIST__

enum{
	black, blue, green, cyan, 
	red, purple, brown, lightgray, 
	darkgray, lightblue, lightgreen, lightcyan, 
	lightred, lightpurple, yellow, white
};

#endif

void init();
void gotoxy(int, int);
void setColor(int, int);