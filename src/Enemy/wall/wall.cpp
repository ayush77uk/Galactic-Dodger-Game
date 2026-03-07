#include "../../all_headers.h"
#include "wall.h"

//spawn wall at a random position---------------------------------------
void spawnWall()
{
    for(int i=0; i<MAX_WALL; i++){
         int top_block = (rand()%(HEIGHT-2));

        if(!wall[i].active){
            for(int w=0; w<3; w++){
                wall[i].x[w] = WIDTH-1;

                wall[i].y[w] = top_block;
                top_block++;

                wall[i].active = true;       
            }
            break;
        }       
    }
}

//check if wall hit player
void check_wallHit_player()
{
    for(int w=0; w<MAX_WALL; w++){
        if(wall[w].active){
            for(int i=0; i<player_size; i++){
                for(int block=0; block<3; block++){
                    if(ship.y[i]==wall[w].y[block] &&
                        abs(ship.x[i]-wall[w].x[block])<=1){
                
                        ship.alive = false;
                    }
                }
            }
        }
    }
}



//move wall towards player---------------------------------------------
void updatewall()
{
    for(int i=0; i<MAX_WALL; i++){
        for(int block=0; block<3; block++){
            if(wall[i].active){
            wall[i].x[block] += towards_player;

            if(wall[i].x[block] <= 0)
                wall[i].active = false;

            check_wallHit_player();
        }
        }
        
    }
}

//wall render-----------------------------------------------------------
void renderWall()
{
    for(int i=0; i<MAX_WALL; i++){
        if(wall[i].active){
            for(int block=0; block<3; block++){
                DrawRectangle(wall[i].x[block]*CELL, wall[i].y[block]*CELL, CELL, CELL, DARKGREEN);
            }
        }
    }
}