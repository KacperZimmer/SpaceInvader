
#include "../Headers/constValues.h"
#include "../Headers/enemy.h"
#include "../Headers/MainPlayer.h"
#include "../Headers/gamePanel.h"
#include <unistd.h>
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

//    GamePanel::initizeEnemy(enemyMatrix,numCols,numRows,0.f,0.f);

    GamePanel gamePanel(numRows,numCols);

    gamePanel.initizeEnemy(enemyMatrix,numCols,numRows,0.f,0.f);

    while (!WindowShouldClose() ) {
        // TODO put msg drawing logic into a function
        BeginDrawing();
        ClearBackground(BLACK);


        if(gamePanel.getNumberOfEnemiesInMatrix() == 0){



//            DrawText("Hello")
            char* textWinning = "YOU WON ! ";

            DrawText(textWinning, MIDDLEXPOS - 50, MIDDLEYPOS, 20, GREEN);
            EndDrawing();
            sleep(5);

            break;
        }
        if(gamePanel.isShouldTerminate()){
            char* textLoosing = "YOU lost ! ";

            DrawText(textLoosing, MIDDLEXPOS - 50, MIDDLEYPOS, 20, RED);



            EndDrawing();
            sleep(5);
            break;
        }

        gamePanel.drawEnemies(enemyMatrix,mainPlayer);
        gamePanel.moveEnemies(enemyMatrix,numRows,numCols);

        mainPlayer.Render();
        EndDrawing();
    }

    UnloadTexture(mainPlayerText);
    CloseWindow();
}