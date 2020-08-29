#include <string>
#include <random>
#include <chrono>
#include <deque>
#include <vector>
#include "main.h"
#include "util.h"
#include "game.h"

#define MAXENEMY 10
#define MAXBALL 20

void enemy();
void eraseEnemy(class EnemyClass&);
void drawEnemy(class EnemyClass&);
void eraseAllEnemy();
void eraseBullet();