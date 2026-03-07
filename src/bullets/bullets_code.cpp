#include "../all_headers.h"
#include <raylib.h>
#include "bullets_code.h"

//initializes the position of bullets
void fireBullet(){
    for(int i=0; i<MAX_BULLETS; i++){
        if(!bullets[i].active){
            bullets[i].x = ship.x[0];
            bullets[i].y = ship.y[0];
            bullets[i].active = true;
            break;
        }
    }
}

//update bullet position
void updateBullets(){
    for(int i=0; i<MAX_BULLETS; i++){
        if(bullets[i].active){
            bullets[i].x++;
            if(bullets[i].x > WIDTH-1) bullets[i].active = false;
        }
    }
}

//draw bullets after updating
void renderBullets(){
    for(int i=0; i<MAX_BULLETS; i++){
            if(bullets[i].active){
                DrawRectangle(bullets[i].x*CELL, bullets[i].y*CELL, CELL, CELL, YELLOW);
            }
        }
}