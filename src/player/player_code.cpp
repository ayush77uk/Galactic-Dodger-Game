#include <cstdlib>
#include <raylib.h>
#include "../entities_structure/ent_struct.h"
#include "../variables/global_var.h"

#include "player_code.h"

// draw player-------------------------------------------------------------
void render_player(){
    for(int i=0;i<player_size;i++){
        DrawRectangle(ship.x[i]*CELL, ship.y[i]*CELL, CELL, CELL, GREEN);
    }
}

//controls-----------------------------------------------------------------
void move_up(){
    if(ship.y[2]>0){
    for(int i=0;i<player_size;i++) ship.y[i]--;
    }
}

void move_down(){
    if(ship.y[3]<9){
    for(int i=0; i<player_size; i++) ship.y[i]++;
    }
}

//reset player
void resetPlayer()
{
    ship.alive = true;

    int default_x[] = {1,0,0,0};
    int default_y[] = {4,4,3,5};

    for(int i=0; i<player_size; i++){
        ship.x[i] = default_x[i];
        ship.y[i] = default_y[i];
    }
}