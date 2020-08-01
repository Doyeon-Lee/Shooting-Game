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
	cout << "        ¦¢¦¢¦¢¦¢  ¥Ë    ¦¢¦¢¦¢¦¢  ¥Ë";
	cout << "        ¦§¦«¦©¦¢ £¯ ¡¬  ¦§¦«¦©¦§ £¯ ¡¬" ;
	cout << "        ¦¢¦¢¦¢¦¢ ¦¨¦¡¦¨ ¦¢¦¢¦¢¦¢ ¦¨¦¡¦¨";
	cout << "        ¦¦¦ª¦¥¦¢  £¼£¾  ¦¦¦ª¦¥¦¢  £¼£¾";
}