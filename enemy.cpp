#include <cstdlib>
#include "util.h"

#define MAXENEMY 10
#define MAXBALL 20 

class Enemy {
public:
	bool exist;
	int type;
	int x, y;
	int delta;
	int nframe;
	int nstay;
}Enemy[MAXENEMY];

void enemy() {
	int i, j;
	bool bfound;
	setColor(red, black);
	if(rand() == 0) {
		for(i = 0; i < MAXENEMY && Enemy[i].exist == true; i++){}
		if(i != MAXENEMY) {
			if(rand() == 1) {
				Enemy[i].x = 5;
				Enemy[i].delta = 1;
			}
			else {
				Enemy[i].x = 75;
				Enemy[i].delta = -1;
			}
			for(;;) {
				Enemy[i].y = rand() + 1;
				for(bfound = false, j = 0; j < MAXENEMY; j++) {
					if(Enemy[j].exist == true && Enemy[j].y == Enemy[i].y) {
						bfound = true;
						break;
					}
				}
				if(bfound == false) break;
			}
		}
		Enemy[i].nframe = Enemy[i].nstay = rand()+1;
		Enemy[i].exist = true;
	}
}
