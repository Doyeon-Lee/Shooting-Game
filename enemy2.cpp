#include "main.h"
#include "enemy2.h"
#include "util.h"
#include "myplane.h"
#include "game.h"

class EnemyClass {
public:
	bool exist = false;
    int idx;
	int x, y;
	string view = "<->";
    time_t print_time;
}Enemy[MAXENEMY];

queue<int> q;
deque<pair<int, int>> bulletPos;

void eraseEnemy(int &i){
    gotoxy(Enemy[i].x, Enemy[i].y);
    cout << "   ";
    Enemy[i].exist = false;
    q.push(i);
}

void resetGame(){
    clearScreen();

    int idx;
    //erase all enemy
    for(int i = 0;i < MAXENEMY;i++){
        if(Enemy[i].exist)
            Enemy[i].exist = false;
    }
    //init queue
    while(!q.empty()) q.pop();

    //erase all bullet
    for(int i = 0;i < bulletPos.size();i++){
        gotoxy(bulletPos[i].first, bulletPos[i].second);
        cout << " ";
    }

    bulletPos.clear();
}

void drawEnemy(class EnemyClass &e){
    if(e.x < 0 || e.x >= ROWS-3 || e.y < 0 || e.y >= COLS-2){
        q.push(e.idx);
        e.exist = false;
        return;
    }

    gotoxy(e.x, e.y);
    setColor(red,black);
    cout << "\e[1m" << e.view;
    setColor(white, black);
}

bool collision(class Myplane &p){
    int px = p.x;
    int py = p.y;

    //player collide with enemy
    for(int i = 0;i < MAXENEMY;i++){
        if(Enemy[i].y == py && Enemy[i].exist){
            if(abs(Enemy[i].x-px) < 3) return true;
        }
    }
    return false;
    //player collide with enemy's attack
    /*code here*/
}

void shootBullet(class Myplane &p){
    //shoot bullet in front of the plane & push the position in the vector
    int bx = p.x+1;
    int by = p.y-1;
    bulletPos.push_back(make_pair(bx,by)); //front middle of the plane
    gotoxy(bx, by);
    cout << "*";
}

//is the bullet in the screen?
bool checkBullet(int &i){
    int bx = bulletPos[i].first;
    int by = bulletPos[i].second;

    if(bx < 0 || bx > ROWS || by < 0 || by > COLS){
        auto iter = bulletPos.begin() + i;
        bulletPos.erase(iter);
        return false;
    }
    return true;
}

bool bulletHit(int &i, int &en){
    for(int j = 0;j < MAXENEMY;j++){
        int bx = bulletPos[i].first; int by = bulletPos[i].second;
        int ex = Enemy[j].x; int ey = Enemy[j].y;
        if(Enemy[j].exist && by == ey && bx >= ex && bx <= ex+3){
            en = j;
            return true;
        }
    }
    return false;
}

void moveBullet(){
    if(bulletPos.empty()) return;

    for(int i = 0;i < bulletPos.size();i++){
        gotoxy(bulletPos[i].first, bulletPos[i].second);
        cout << " ";
    }

    for(int i = 0;i < bulletPos.size();i++)
        bulletPos[i].second--;

    for(int i = 0;i < bulletPos.size();i++){
        if(checkBullet(i)){
            gotoxy(bulletPos[i].first, bulletPos[i].second);
            cout << "*";
        }
    }
}

void eraseBullet(int &i){
    gotoxy(bulletPos[i].first, bulletPos[i].second);
    cout << " ";
    auto iter = bulletPos.begin();
    iter += i;
    bulletPos.erase(iter);
}

void enemy(){
    for(int i = 0;i < MAXENEMY;i++) q.push(i);

    //make random_device to get seed value
    random_device rd;
    //init rand engine through random_device
    mt19937 gen(rd());
    //0~COLS 균등 분포 정의
    uniform_int_distribution<int> dis(0,(ROWS-3)*3);

    clock_t cur_time;
    clock_t enemy_time = clock();
    clock_t bullet_time = clock();
    Myplane p(ROWS/2-1, COLS-3);
    initPlane(p);

    while(1){
        int plane_move_key = keyControl();
        switch(plane_move_key){
            case LEFT:
                {plane_move(&p.x, &p.y, -3, 0);
                break;}
            case RIGHT:
                {plane_move(&p.x, &p.y, 3, 0);
                break;}
            case UP:
                {plane_move(&p.x, &p.y, 0, -1);
                break;}
            case DOWN:
                {plane_move(&p.x, &p.y, 0, 1);
                break;}
            case SUBMIT:
                {shootBullet(p); break;}
            case ESC:{
                clearScreen();
                setColor(white, black);
                return;}
        }

        if(collision(p)){
            gameover();
            break;
        }

        cur_time = clock();
        if(cur_time - bullet_time >= 400){
            moveBullet();
            bullet_time = clock();
        }

        for(int i = 0;i < bulletPos.size();i++){
            int en; //enemy_number
            if(bulletHit(i, en)){
                //erase bullet
                eraseBullet(i);

                //erase enemy
                  eraseEnemy(en);
            }
        }

        if(cur_time - enemy_time < 1000) continue;

        if(!q.empty()){
            int idx = q.front(); q.pop();
            Enemy[idx].idx = idx;
            Enemy[idx].exist = true;
            Enemy[idx].x = dis(gen)/3;
            Enemy[idx].y = -1;
        }

        for(int i = 0;i < MAXENEMY;i++){
            if(Enemy[i].exist == true){
                gotoxy(Enemy[i].x, Enemy[i].y);
                cout << "   ";
                Enemy[i].y++;
                drawEnemy(Enemy[i]);
            }
        }
        enemy_time = clock();
    }
}