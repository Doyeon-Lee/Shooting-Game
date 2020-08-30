#ifndef KEY_CODE
#define KEY_CODE

//value of keyboard
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4	//spacebar
#define ESC 5
#define SKILL 6
#endif

void gameStart();
void gameover();
int keyControl();
void titleDraw();
int menuDraw();
void infoDraw();
void help();
void updateHighScore();
void printHighScore();