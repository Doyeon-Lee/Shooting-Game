#include <string>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
#include <queue>
#include "main.h"
#include "util.h"
//#include "game.h"

#define MAXENEMY 10
#define MAXBALL 20 

void enemy();
void eraseEnemy(class Enemy&);
void drawEnemy(class Enemy&);