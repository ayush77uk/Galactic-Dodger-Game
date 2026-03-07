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

void drawGameOverScores()
{
    int fontSize = 40;

    int screenWidth = WIDTH * CELL;
    int screenHeight = HEIGHT * CELL;

    const char* scoreText = TextFormat("Score: %d", newscore);
    const char* highscoreText = TextFormat("High Score: %d", highscore);

    int scoreWidth = MeasureText(scoreText, fontSize);
    int highWidth = MeasureText(highscoreText, fontSize);

    int x1 = (screenWidth - scoreWidth) / 2;
    int x2 = (screenWidth - highWidth) / 2;

    int y = (screenHeight / 2) + 80;

    DrawText(scoreText, x1, y, fontSize, WHITE);
    DrawText(highscoreText, x2, y + 50, fontSize, YELLOW);
}

void drawRestartText()
{
    const char* text = "Press ENTER to start a new game";
    int fontSize = 30;

    int screenWidth = WIDTH * CELL;
    int screenHeight = HEIGHT * CELL;

    int textWidth = MeasureText(text, fontSize);

    int x = (screenWidth - textWidth) / 2;
    int y = screenHeight - 80;

    DrawText(text, x, y, fontSize, LIGHTGRAY);
}


enum GameState{
    gameOver,
    play
};

GameState gameState = play;

int enemy_spawnTimer = 0;
int bomb_spawnTimer = 0;
int wall_spawnTimer = 0;

int enemy_spawnRate = 50, 
    reset_enemy_spawnRate = 50;
int bomb_spawnRate = 100, 
    reset_bomb_spawnRate = 100;
int wall_spawnRate = 90, 
    reset_wall_spawnRate = 90;

void resetGame(){
    resetPlayer();
    resetBullets();
    resetEnemy();
    resetBomb();
    resetWall();
    
    enemy_spawnTimer = 0;
    bomb_spawnTimer = 0;
    wall_spawnTimer = 0;

    enemy_spawnRate = reset_enemy_spawnRate;
    bomb_spawnRate = reset_bomb_spawnRate;
    wall_spawnRate = reset_wall_spawnRate;

}



int main(){

    InitWindow(WIDTH*CELL, HEIGHT*CELL, "LED Matrix Shooter");

    SetTargetFPS(12);

    // int bulletTimer = 0;

    while(!WindowShouldClose()){

        if(gameState == play){

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

        if(!ship.alive) gameState = gameOver;

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

     } //if ! gameState playing closes

     else if(gameState == gameOver)
        { 
            if(newscore>highscore) highscore = newscore;
            
            BeginDrawing();
            ClearBackground(BLACK);
            drawGameOver();
            drawGameOverScores();
            drawRestartText();

            if(IsKeyPressed(KEY_ENTER)){
                gameState = play;
                resetGame();
                newscore = score = 0;
            }
            EndDrawing();
        }
        }

    CloseWindow();
}
