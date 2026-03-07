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
int enemy_spawnRate = 50;
int bomb_spawnRate = 90;


int main(){

    InitWindow(WIDTH*CELL, HEIGHT*CELL, "LED Matrix Shooter");

    SetTargetFPS(16);

    int enemy_spawnTimer = 0;
    int bomb_spawnTimer = 0;
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

        updateBullets();
        updateEnemy();
        updateBomb();

        check_bombHit();
        if(!ship.alive) gameOver = true;
        check_enemyHit();

        if(newscore-score>=4
        ){
            enemy_spawnRate -= 1;
            bomb_spawnRate -= 2;
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
