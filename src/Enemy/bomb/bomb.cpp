#include "../../all_headers.h"
#include "bomb.h"

//spawn bomb at a random position---------------------------------------
void spawnBomb(){
    for(int i=0; i<MAX_BOMBS; i++){
        if(!bomb[i].active){
            bomb[i].x = WIDTH-1;
            bomb[i].y = (rand()%(HEIGHT-2)) + 1;
            bomb[i].active = true;
            break;
        }
    }
}

//check if bomb hit player
void check_bombHit_player(){
    for(int b=0; b<MAX_BOMBS; b++){
        for(int i=0; i<player_size; i++){

            if(bomb[b].active &&
               ship.y[i]==bomb[b].y &&
               abs(ship.x[i]-bomb[b].x)<=1){
                
                ship.alive = false;
            }
        }
    }
}



//move bomb towards player---------------------------------------------
void updateBomb(){
    for(int i=0; i<MAX_BOMBS; i++){
        if(bomb[i].active){
            bomb[i].x--;

            if(bomb[i].x <= 0)
                bomb[i].active = false;

            check_bombHit_player();
        }
    }
}

//check if player hit the bomb
void check_bombHit(){
    for(int i=0; i<MAX_BOMBS; i++){
        for(int b=0; b<MAX_BULLETS; b++){
                if(bullets[b].active && 
                    abs(bullets[b].x-bomb[i].x)<=1 && 
                    bullets[b].y==bomb[i].y){
                    bomb[i].active = false;
                    bullets[b].active = false;
                    ship.alive = false;
                }
            }
    }  
}

//bomb render-----------------------------------------------------------
void renderBomb(){
    for(int i=0; i<MAX_BOMBS; i++){
        if(bomb[i].active){
            DrawRectangle(bomb[i].x*CELL, bomb[i].y*CELL, CELL, CELL, RED);
        }
    }
}