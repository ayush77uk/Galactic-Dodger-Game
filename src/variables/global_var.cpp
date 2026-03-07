#include <cstdlib>
#include "../entities_structure/ent_struct.h"
#include "global_var.h"

//Screen variables------------------------------------------------------
int WIDTH = 20;
int HEIGHT = 10;
int CELL = 70;
int towards_player = -1;
int away_from_player = 1;
int to_top = -1;
int to_bottom = 1;

//Game variables-----------------------------------------------
int highscore = 0;
int score = 0;
int newscore = 0;

//Player variables------------------------------------------------------
Player ship;        //instance of player structure
int player_size = sizeof(ship.x)/sizeof(ship.x[0]);      //num of pixels of player

//Bullet variables------------------------------------------------------
int MAX_BULLETS = 10;
Bullet bullets[10];

//Enemy variables-------------------------------------------------------
int MAX_ENEMIES = 10;
Enemy enemies[10];

//Bomb variables-----------------------------------------------
int MAX_BOMBS = 5;
Bomb bomb[5];

//Wall variables-----------------------------------------------
int MAX_WALL = 3;
int WALL_BLOCKS = 3;
Wall wall[3];