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
        // shooter.shooting = true;
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

//fire shooters bullets-------------------------------------------
void shooter_fireBullet()
{
    if(!shooter.bullet.active){

        shooter.bullet.x = shooter.x[0];
        shooter.bullet.y = shooter.y[0];

        shooter.bullet.active = true;
    }
}


//move the shooter up and down--------------------------------------------
void update_shooter()
{
    switch(shooter.position){

        case Shooter::mid:
        {
            shooter_fireBullet();   // SHOOT

            for(int i=0;i<shooter_size;i++)
                shooter.y[i] += to_bottom;

            if(shooter.y[3] >= HEIGHT-1)
                shooter.position = Shooter::bottom;

            break;
        }

        case Shooter::bottom:
        {
            // NO SHOOT

            for(int i=0;i<shooter_size;i++)
                shooter.y[i] += to_top;

            if(shooter.y[2] <= 0)
                shooter.position = Shooter::top;

            break;
        }

        case Shooter::top:
        {
            shooter_fireBullet();  // SHOOT

            for(int i=0;i<shooter_size;i++)
                shooter.y[i] += to_bottom;

            if(shooter.y[0] >= 4)
                shooter.position = Shooter::mid;

            break;
        }
    }
}


//move shooter bullets---------------------------------------------
void update_shooter_bullet()
{
    if(shooter.bullet.active){

        shooter.bullet.x += towards_player;

        if(shooter.bullet.x <= 0)
            shooter.bullet.active = false;
    }
}


void render_shooter_bullet()
{
    if(shooter.bullet.active){

        DrawRectangle(
            shooter.bullet.x * CELL,
            shooter.bullet.y * CELL,
            CELL, CELL,
            LIME
        );
    }
}


//check if bullet hit player-------------------------------------------
void check_shooterHit_player()
{
    if(shooter.bullet.active){

        for(int p = 0; p < player_size; p++){

            if(shooter.bullet.y == ship.y[p] &&
               abs(shooter.bullet.x - ship.x[p]) <= 1){

                ship.alive = false;
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

//reset the shooter after gameover
void reset_shooter()
{
    shooter.alive = false;
    shooter.health = 50;
    shooter.position = Shooter::mid;

    shooter.bullet.active = false;

    shooter.x[0] = 18;
    shooter.x[1] = 19;
    shooter.x[2] = 19;
    shooter.x[3] = 19;

    shooter.y[0] = 4;
    shooter.y[1] = 4;
    shooter.y[2] = 3;
    shooter.y[3] = 5;

}
