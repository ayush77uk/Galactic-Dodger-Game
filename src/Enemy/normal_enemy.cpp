#include "../all_headers.h"
#include "normal_enemy.h"
#include <raylib.h>

//spawn enemy at a random position---------------------------------------
void spawnEnemy(){
    for(int i=0; i<MAX_ENEMIES; i++){
        if(!enemies[i].alive){
            enemies[i].x = WIDTH-1;
            enemies[i].y = (rand()%(HEIGHT-2)) + 1;
            enemies[i].alive = true;
            break;
        }
    }
}

//check if enemy hit player
void check_enemyHit_player(){
    for(int e=0; e<MAX_ENEMIES; e++){
        for(int i=0; i<player_size; i++){

            if(enemies[e].alive &&
               ship.y[i]==enemies[e].y &&
               abs(ship.x[i]-enemies[e].x)<=1){
                
                ship.alive = false;
            }
        }
    }
}


//move enemy towards player---------------------------------------------
void updateEnemy(){
    for(int i=0; i<MAX_ENEMIES; i++){
        if(enemies[i].alive){
            enemies[i].x--;

            if(enemies[i].x <= 0)
                enemies[i].alive = false;

            check_enemyHit_player();
            
        }
    }
}

void check_enemyHit(){
    for(int i=0; i<MAX_ENEMIES; i++){
        for(int b=0; b<MAX_BULLETS; b++){
                if(bullets[b].active && 
                    abs(bullets[b].x-enemies[i].x)<=1 && 
                    bullets[b].y==enemies[i].y){
                    enemies[i].alive = false;
                    bullets[b].active = false;
                    newscore++;
                }
            }
    }  
}

//enemy render-----------------------------------------------------------
void renderEnemy(){
    for(int i=0; i<MAX_ENEMIES; i++){
        if(enemies[i].alive){
            DrawRectangle(enemies[i].x*CELL, enemies[i].y*CELL, CELL, CELL, PURPLE);
        }
    }
}