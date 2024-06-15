#include <iostream>
#include <memory> // 引入智能指针库
#include <vector>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <random>

using namespace std;

const int WIDTH = 100;
const int HEIGHT = 25; 
const int Fruit_count = 2; 
const int Snake_speed = 10;
const int c_t = CLOCKS_PER_SEC;
const int SpeedEffectTime = 10;
char symbol = 'x';

int grade = 0;
int addlen = 3;
int speed = Snake_speed;
clock_t starttime = clock();
clock_t Speedtime = clock();

class Fruit {
public:
    int x;
    int y;
    int grade = 1;
    
    char t = 'x';

    Fruit(int a, int b) : x(a), y(b) {}
    virtual ~Fruit() {}
};

class Snake {
public:
    int x;
    int y;

    Snake() : x(0), y(0) {}
    Snake(int a, int b) : x(a), y(b) {}
};

class SnakeHead : public Snake {
public:
    int direct;
    bool live = 1;

    bool eat(int fx, int fy) {
        if (fx == this->x && fy == this->y) {
            addlen++;
            starttime = clock();
            return 1;
        }
        else return 0;
    }

    SnakeHead() : Snake(), direct(0) {}
};

vector<Snake> snake;
SnakeHead sh;
vector<shared_ptr<Fruit>> fd; 

class Judge {
public:
    bool isSnake(int x, int y) {
        for (auto& i : snake) { 
            if (x == i.x && y == i.y)
                return true;
        }
        return false;
    }

    int isFruit(int x, int y) {
        for (int i = 0; i < fd.size(); i++) {
            if (fd[i]->x == x && fd[i]->y == y) { 
                return i+1;
            }
        }
        return false;
    }
};
Judge jd;

class FruitTwice : public Fruit {
public:
    FruitTwice(int a, int b) : Fruit(a, b) {
        grade = 10;
       
        t = '$';
    }
};
class FruitSpeed : public Fruit {
public:
    FruitSpeed(int a, int b) : Fruit(a, b) {
      
        t = '%';
    }
    ~FruitSpeed() {
        if(sh.live)
        {
            Speedtime = clock();
            speed = 3 * Snake_speed;
        }
    }
};
class FruitLenth : public Fruit {
public:
    FruitLenth(int a, int b) : Fruit(a, b) {
        
        t = '&';

    }
    ~FruitLenth() {
        addlen = snake.size();
    }
   
};
class NormalFruit : public Fruit {
public:
    NormalFruit (int a, int b) : Fruit(a, b) {
        
        t = '0';

    }
   

};
class FruitReverse : public Fruit {
public:
    FruitReverse(int a, int b) : Fruit(a, b) {

        t = 'X';

    }
    ~FruitReverse() {
        if(!snake.empty())
        {
            Snake sn = *snake.rbegin();
            snake.pop_back();
            reverse(snake.begin(), snake.end());
            snake.emplace_back(sh.x, sh.y);
            sh.x = sn.x;
            sh.y = sn.y;
            sh.direct *= -1;
        }
   }

};
class FruitFuss : public Fruit {
public:
    FruitFuss(int a, int b) : Fruit(a, b) {

        t = 'Q';

    }
    ~FruitFuss() {
        int pre = sh.direct;
       while(1) 
       {
           
           int a = rand() % 5;
           if (a == 2) continue;
           sh.direct = 2-a;
           if (sh.direct == pre || sh.direct == -pre) {
               continue;
           }
           else break;

       }
    }

};





void fruit_initial() {
    int x, y;
    int m;
    while (1)
    {
        m = rand() % 5;
       
        y = rand() % (HEIGHT - 10) + 5; 
        x = rand() % (WIDTH / 2 - 7) + 4; 
        if (jd.isSnake(x, y))
            continue;
        else if ((y == sh.y && x == sh.x))
            continue;
        else if (jd.isFruit(x, y))
            continue;
        else break;
    }
    // 使用智能指针的make_shared创建对象
    if (m == 0)
        fd.push_back(make_shared<FruitTwice>(x, y));
    else if (m == 1)
        fd.push_back(make_shared<FruitSpeed>(x, y));
    else if (m ==2)
        fd.push_back(make_shared<FruitLenth>(x, y));
    else if (m == 3)
        fd.push_back(make_shared<FruitReverse>(x, y));
    else if(m==4)
        fd.push_back(make_shared<FruitFuss>(x, y));
    else fd.push_back(make_shared<NormalFruit>(x, y));
}

void draw() {
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for (int i = 0; i <= HEIGHT; i++) {

        for (int j = 0; j <= WIDTH / 2; j++) {
            if (j == 0 || j == WIDTH / 2)
                cout << "# ";
            else if (i == 0 || i == HEIGHT)
                cout << "# ";
            else
                if (jd.isSnake(j, i)) {
                    cout << "* ";

                }
                else
                    if ((i == sh.y && j == sh.x))
                        cout << "* ";
                    else if (int tt = jd.isFruit(j, i)) {
                        cout << fd[tt-1]->t << " "; 
                    }
                    else
                        cout << "  ";
        }
        cout << "\n";
    }
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void shmove() {
    switch (sh.direct) {
    case -1: sh.y++; break;
    case 1: sh.y--; break;
    case -2: sh.x--; break;
    case 2: sh.x++; break;
    }
    if (jd.isSnake(sh.x, sh.y)) {
        sh.live = 0;
    }
    if (sh.x > WIDTH / 2 - 2 || sh.x < 1)
        sh.live = 0;
    else if (sh.y > HEIGHT - 1 || sh.y < 1)
        sh.live = 0;
}

void move() {
    if (!snake.empty()) {
        for (auto i = snake.rbegin(); i != snake.rend() - 1; i++) {
            i->x = (i + 1)->x;
            i->y = (i + 1)->y;
        }
        snake.begin()->x = sh.x;
        snake.begin()->y = sh.y;
    }
    shmove();
    if (!fd.empty()) {
        for (auto i = fd.begin(); i < fd.end(); i++) {
            if (sh.eat((*i)->x, (*i)->y)) { 
                 grade+=(*i)->grade;
                fd.erase(i);
               
                break;
            }
        }
    }
}

void keyin() {
    while (_kbhit()) {
        int d = sh.direct;
        switch (_getch())
        {
        case 72: sh.direct = 1; break;
        case 80: sh.direct = -1; break;
        case 75: sh.direct = -2; break;
        case 77: sh.direct = 2; break;
        case 'w': sh.direct = 1; break;
        case 's': sh.direct = -1; break;
        case 'a': sh.direct = -2; break;
        case 'd': sh.direct = 2;
        }
        if (sh.direct == -d)
            sh.direct = d;
    }
}

bool gameOver() {
    system("cls");
    for (int i = 0; i < HEIGHT / 2 - 1; i++)
        cout << "\n";
    for (int i = 0; i < WIDTH / 2 - 4; i++)
        cout << " ";
    setColor(10);
    cout << "Grade : " << grade << "\n";
    setColor(7);
    for (int i = 0; i < WIDTH / 2 - 34; i++)
        cout << " ";
    cout << "Press the 'R' key to restart the game or press the spacebar to end the game. ";
    while (true) {
        while (1) {
            char ch = _getch();
            if (ch == 'r' || ch == 'R') {
                system("cls");
                sh.x = 10;
                sh.y = 10;
                grade = 0;
                sh.direct = 1;
                sh.live = 1;
                addlen = 3;
                starttime = clock();
                speed = Snake_speed;
                return 0;
            }
            else if (ch == ' ')
                break;
        }
        return 1;
    }
}

int main() {
    hideCursor();
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < HEIGHT / 2 - 1; i++)
        cout << "\n";
    for (int i = 0; i < WIDTH / 2 - 16; i++)
        cout << " ";
    cout << "Symbol * is your body and x is fruit.\n";
    for (int i = 0; i < WIDTH / 2 - 5; i++)
        cout << " ";
    cout << "Press Enter";
    getchar();
   

    sh.x = 10;
    sh.y = 10;
    sh.direct = 1;
    bool flag = 1;
    clock_t now = clock();
    while (1) {
        now = clock();
        if (float(now - Speedtime) / c_t > SpeedEffectTime) {
            speed = Snake_speed;
        }
        if (sh.live == 0)
        {
            snake.clear();
            fd.clear();
            if (gameOver())
                return 0;
            else
                flag = 1;
        }
        keyin();
        Snake pre;
        if (!snake.empty())
            pre = snake[snake.size() - 1];
        else pre = sh;
        if (float(now - starttime) / c_t > 2 && flag) {
            fruit_initial();
            starttime = now;
        }
        if (fd.size() < Fruit_count) {
            flag = 1;
        }
        else flag = 0;
        move();
        Sleep(1000 / speed);
        draw();
        if (addlen > 0) {
            snake.push_back(pre);
            addlen--;
        }
    }
    return 0;
}

