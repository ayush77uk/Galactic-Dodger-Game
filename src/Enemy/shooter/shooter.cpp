#include "../../all_headers.h"
#include "shooter.h"

//spawn the shooter-----------------------------------------
void spawn_shooter()
{
    if(!shooter.alive){
        // for(int i=0; i<shooter_size; i++){
        //     DrawRectangle(shooter.x[i]*CELL, shooter.y[i]*CELL, CELL, CELL, DARKPURPLE);
        // }
        shooter.alive = true;
        shooter.position = Shooter::mid;
        shooter.shooting = true;
    }
}

//render the shooter------------------------------------------------------
void render_shooter()
{
    if(shooter.alive){
        for(int i=0; i<shooter_size; i++){
            DrawRectangle(shooter.x[i]*CELL, shooter.y[i]*CELL, CELL, CELL, DARKPURPLE);
        }
    }
}

//move the shooter up and down--------------------------------------------
void update_shooter()
{
    switch(shooter.position){
        case Shooter::mid :{
            if(!shooter.shooting){
                for(int i=0; i<shooter_size; i++){
                shooter.y[i] += to_bottom;
                }
                if(shooter.y[3]==HEIGHT-1){
                    shooter.position = Shooter::bottom;
                }
            }
            
            break;
        }

        case Shooter::bottom :{
            for(int i=0; i<shooter_size; i++){
                shooter.y[i] += to_top;
            }
            if(shooter.y[2]==0){
                shooter.position = Shooter::top;
            }
            break;
        }

        case Shooter::top :{
            for(int i=0; i<shooter_size; i++){
                shooter.y[i] += to_bottom;
            }
            if(shooter.y[0]==4){
                shooter.position = Shooter::mid;
                shooter.shooting = true;
            }
            break;
        }
    }
}

//fire shooters bullets-------------------------------------------
void shooter_fireBullets()
{
    if(shooter.shooting){
        for(int i=0; i<max_shooter_bullets; i++){
            if(!shooter.shooter_bullets[i].active){
                shooter.shooter_bullets[i].x = shooter.x[0];
                shooter.shooter_bullets[i].y = shooter.y[0];
                shooter.shooter_bullets[i].active = true;

                if(i==max_shooter_bullets-1){
                    shooter.shooting = false;
                }
                break;
            }
        }
    }
}

//move shooter bullets---------------------------------------------
void update_shooter_bullets()
{
    for(int i=0; i<max_shooter_bullets; i++){
        if(shooter.shooter_bullets[i].active){
            shooter.shooter_bullets[i].x += towards_player;
        }

        if(shooter.shooter_bullets[i].x == 0) shooter.shooter_bullets[i].active = false;
    }
}

void render_shooter_bullets()
{
    for(int b=0; b<max_shooter_bullets; b++){
        if(shooter.shooter_bullets[b].active){
            DrawRectangle(shooter.shooter_bullets[b].x*CELL, shooter.shooter_bullets[b].y*CELL, CELL, CELL, LIME);
        }       
    }
}

//check if bullet hit player-------------------------------------------
void check_shooterHit_player()
{
    for(int i=0; i<max_shooter_bullets; i++){
        if(shooter.shooter_bullets[i].active){
            for(int p=0; p<player_size; p++){
                if(shooter.shooter_bullets[i].y==ship.y[p] &&
                abs(shooter.shooter_bullets[i].x - ship.x[p])<=1){
                    ship.alive = false;
                }
            }
        }
    }
}

//void check if shooter got hit
void check_shooterHit()
{
    for(int s=0; s<shooter_size; s++){
        for(int b=0; b<MAX_BULLETS; b++){
            if(bullets[b].active){
                if(bullets[b].y==shooter.y[s] &&
                    abs(shooter.x[s]-bullets[b].x)<=1){
                        shooter.health--;
                    }
                if (shooter.health <= 0){
                    shooter.alive = false;
                    break;
                }
            }
        }
    }
}