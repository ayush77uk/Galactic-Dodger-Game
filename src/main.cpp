#include "all_headers.h"

void drawGameOver()
{
    const char* text = "GAME OVER";
    int fontSize = 120;

    int screenWidth = WIDTH * CELL;
    int screenHeight = HEIGHT * CELL;

    int textWidth = MeasureText(text, fontSize);

    int x = (screenWidth - textWidth) / 2;
    int y = (screenHeight / 2) - (fontSize / 2);

    DrawText(text, x, y, fontSize, RED);
}

bool gameOver = false;

int enemy_spawnTimer = 0;
int bomb_spawnTimer = 0;
int wall_spawnTimer = 0;

int enemy_spawnRate = 50;
int bomb_spawnRate = 100;
int wall_spawnRate = 90;


int main(){

    InitWindow(WIDTH*CELL, HEIGHT*CELL, "LED Matrix Shooter");

    SetTargetFPS(12);

    // int bulletTimer = 0;

    while(!WindowShouldClose()){

        if(!gameOver){

        // controls
        if(IsKeyDown(KEY_W)){
            move_up();
        }

        if(IsKeyDown(KEY_S)){
           move_down();
        }

        // shooting
        // bulletTimer++;
        // if(bulletTimer > 10){
        //     fireBullet();
        //     bulletTimer = 0;
        // }

        if(IsKeyDown(KEY_ENTER)){
            fireBullet();
        }

        enemy_spawnTimer++;
        if(enemy_spawnTimer > enemy_spawnRate){
            spawnEnemy();
            enemy_spawnTimer = 0;
        }

        bomb_spawnTimer++;
        if(bomb_spawnTimer>bomb_spawnRate){
            spawnBomb();
            bomb_spawnTimer = 0;
        }

        wall_spawnTimer++;
        if(wall_spawnTimer > wall_spawnRate){
            spawnWall();
            wall_spawnTimer = 0;
        }

        updateBullets();
        updateEnemy();
        updateBomb();
        updatewall();

        check_bombHit();
        check_enemyHit();
        check_wallHit_player();
        if(!ship.alive) gameOver = true;

        if(newscore-score>=4
        ){
            enemy_spawnRate -= 5;
            bomb_spawnRate -= 4;
            wall_spawnRate -= 4;
            score = newscore;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        //draw player
        render_player();

        // draw bullets
        renderBullets();
        
        // draw enemies
        renderEnemy();

        //draw bomb
        renderBomb();

        //render wall
        renderWall();

        EndDrawing();

     } //if ! gameover closes

     else{ bool end = false;
        while(!end){
            BeginDrawing();
            ClearBackground(BLACK);
            drawGameOver();
            if(IsKeyDown(KEY_ENTER)) end = true;
            EndDrawing();
        }
     }
    }


    CloseWindow();
}
