#include <string>
#include <ctime>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include "main.h"
#include "util.h"
#include "game.h"

#define MAXENEMY 10
#define MAXBALL 20 

using namespace std;

void enemy();
void* move_enemy(void*);

