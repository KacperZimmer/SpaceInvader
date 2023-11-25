
#include "../Headers/constValues.h"
#include "../Headers/enemy.h"
#include "../Headers/MainPlayer.h"
#include "../Headers/gamePanel.h"
#include <memory>
#include "raylib.h"


void runGame(){
    InitWindow(WIDTH, HEIGHT, "SPACE INVADERS");
    Texture2D mainPlayerText = LoadTexture("../sprites/mainPlayerTxt.png");

    MainPlayer mainPlayer(mainPlayerText, MIDDLEXPOS - 50, 
            HEIGHT - mainPlayerText.height / mainPlayer.scaleVector);

    Enemy enemy(10.f,0.f); 
    SetTargetFPS(60);


    std::vector<std::vector<std::unique_ptr<Enemy>>> enemyMatrix{};
    int numRows = 5; 
    int numCols = 2;  

    GamePanel::initizeEnemy(enemyMatrix,numCols,numRows,0.f,0.f); 

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);

        GamePanel::drawEnemies(enemyMatrix,mainPlayer);
        GamePanel::moveEnemies(enemyMatrix,numRows,numCols); 
        
        mainPlayer.Render(); 
        EndDrawing();
    }

    UnloadTexture(mainPlayerText);
    CloseWindow();
}