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
private:
	setColor(red,black);
}Enemy[MAXENEMY];

void enemy() {
	bool bfound;
	if(random(100) == 0) {
		for(i = 0; i < MAXENEMY && Enemy[i].exist == TRUE; i++){}
		if(i != MAXENEMY) {
			if(random(2) == 1) {
				Enemy[i].x = 5;
				Enemy[i].delta = 1;
			}
			else {
				Enemy[i].x = 75;
				Enemy[i].delta = -1;
			}
			for(;;) {
				Enemy[i].y = random(10) + 1;
				for(bfound = false, j = 0; j < MAXENEMY; j++) {
					if(Enemy[j].exist == TRUE && Enemy[j].y == Enemy[i].y) {
						bfound = true;
						break;
					}
				}
				if(bfound == false) break;
			}
		}
		Enemy[i].nframe = Enemy[i].nstay = random(6)+1;
		Enemy[i].type = random(sizeof(arEnemy)/sizeof(arEnemy[0]));
		Enemy[i].exist = true;
	}
}
