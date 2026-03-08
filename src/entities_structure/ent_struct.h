#pragma once

struct Player{
    int x[4] = {1,0,0,0};
    int y[4] = {4,4,3,5};
    bool alive = true;
};
//----------------------------------------------------

struct Bullet{
    int x;
    int y;
    bool active;
};
//----------------------------------------------------

struct Enemy{
    int x;
    int y;
    bool alive;
};
//----------------------------------------------------

struct Bomb{
    int x;
    int y;
    int active;
};
//----------------------------------------------------

struct Wall{
    int x[3];
    int y[3];
    int active;
};
//----------------------------------------------------

struct Shooter{
    int x[4] = {18,19,19,19};
    int y[4] = {4,4,3,5};
    int health = 50;

    bool alive;
    bool shooting;

    struct Bullets{
        int x; int y; int active;
    };
    Bullets shooter_bullets[5];

    enum Position{
        top, mid, bottom
    };
    Position position;
};
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------
//----------------------------------------------------