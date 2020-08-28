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

void eraseEnemy(class EnemyClass &e){
    gotoxy(e.x, e.y);
    cout << "   ";
    e.y++;
}

void drawEnemy(class EnemyClass &e){
    if(e.x < 0 || e.x >= ROWS-3 || e.y < 0 || e.y >= COLS-3){
        q.push(e.idx);
        e.exist = false;
        return;
    }

    gotoxy(e.x, e.y);
    setColor(red,black);
    cout << e.view;
    setColor(white, black);
}

bool collision(class Myplane &p){
    int px = p.x;
    int py = p.y;

    //player collide with enemy
    for(int i = 0;i < MAXENEMY;i++){
        if(Enemy[i].y == py){
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


void enemy(){
    for(int i = 0;i < MAXENEMY;i++) q.push(i);

    //make random_device to get seed value
    random_device rd;
    //init rand engine through random_device
    mt19937 gen(rd());
    //0~COLS 균등 분포 정의
    uniform_int_distribution<int> dis(0,(ROWS-3)*3);

    clock_t cur_time;
    clock_t gen_time = clock();
    Myplane p(30, 17);
    initPlane(p);

    while(1){
        int plane_move_key = keyControl();
        switch(plane_move_key){
            case LEFT:
                {plane_move(&p.x, &p.y, -1, 0);
                break;}
            case RIGHT:
                {plane_move(&p.x, &p.y, 1, 0);
                break;}
            case UP:
                {plane_move(&p.x, &p.y, 0, -1);
                break;}
            case DOWN:
                {plane_move(&p.x, &p.y, 0, 1);
                break;}
            case SUBMIT:
                {shootBullet(p); break;}
            case ESC:
                {setColor(white, black);
                return;}
        }

        if(collision(p)){
            gameover();
            break;
        }

        cur_time = clock();
        if(cur_time - gen_time < 1000) continue;

        moveBullet();

        if(!q.empty()){
            int idx = q.front();
            q.pop();
            Enemy[idx].idx = idx;
            Enemy[idx].exist = true;
            Enemy[idx].x = dis(gen)/3;
            Enemy[idx].y = -1;
        }

        //if(cur_time - gen_time > 500){
            for(int i = 0;i < MAXENEMY;i++){
                if(Enemy[i].exist == true){
                    eraseEnemy(Enemy[i]);
                    drawEnemy(Enemy[i]);
                }
            }
            gen_time = clock();
        //} //if문 close
    }
    setColor(white,black);
}

void eraseEnemy(){
    for(int i = 0;i < MAXENEMY;i++){
        if(Enemy[i].exist){
            Enemy[i].exist = false;
            q.push(Enemy[i].idx);
        }
    }
}