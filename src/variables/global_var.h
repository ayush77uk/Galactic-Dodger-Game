#pragma once

#include <cstdlib>
#include "../entities_structure/ent_struct.h"

//Screen variables------------------------------------------------------
extern int WIDTH;
extern int HEIGHT;
extern int CELL;
extern int towards_player;
extern int away_from_player;
extern int to_top;
extern int to_bottom;

//Game variables-----------------------------------------------
extern int Level;
extern int highscore;
extern int score;
extern int newscore;

//Player variables------------------------------------------------------
extern Player ship;        //instance of player structure
extern int player_size;      //num of pixels of player

//Bullet variables------------------------------------------------------
extern int MAX_BULLETS;
extern Bullet bullets[];

//Enemy variables-------------------------------------------------------
extern int MAX_ENEMIES;
extern Enemy enemies[];

//Bomb variables-----------------------------------------------
extern int MAX_BOMBS;
extern Bomb bomb[];

//Wall variables-----------------------------------------------
extern int MAX_WALL;
extern int WALL_BLOCKS;
extern Wall wall[];

//shooter variables--------------------------------------------
extern Shooter shooter;
extern int max_shooter_bullets;
extern int shooter_size;
